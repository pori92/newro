function	script	advrefine	{
	disable_items;
	.@npc_name$ = getarg(0);
	mes .@npc_name$;
	mes "I am the Armsmith";
	mes "I can refine all kinds of weapons,";
	mes "armor and equipment, so let me";
	mes "know what you want to refine.";
	next;

	setarray .@indices[1], EQI_HEAD_TOP, EQI_ARMOR, EQI_HAND_L, EQI_HAND_R, EQI_GARMENT, EQI_SHOES, EQI_ACC_L, EQI_ACC_R, EQI_HEAD_MID, EQI_HEAD_LOW;
	for(set .@i,1; .@i<=10; set .@i,.@i+1) {
		if (getequipisequiped(.@indices[.@i])) {
			set .@menu$, .@menu$ + F_getpositionname(.@indices[.@i]) + "-[" + getequipname(.@indices[.@i]) + "]";
			set .@equipped,1;
		}
		set .@menu$, .@menu$ + ":";
	}
	if (.@equipped == 0) {
		mes .@npc_name$;
		mes "I don't think I can refine any items you have...";
		close;
	}
	set .@part, .@indices[ select(.@menu$) ];

	if (!getequipisequiped(.@part)) //custom check
		close;
	if (!getequipisenableref(.@part)) {
		mes .@npc_name$;
		mes "Go find another Blacksmith. You can't refine this thing.";
		close;
	}
	if (getequiprefinerycnt(.@part) >= 10) {
		mes .@npc_name$;
		mes "Hmm... someone perfected this already. I don't think I can work on it further.";
		close;
	}

	.@refineitemid = getequipid(.@part); // save id of the item
	.@refinerycnt = getequiprefinerycnt(.@part); //save refinery count
	.@price = getequiprefinecost(.@part, REFINE_COST_ENRICHED, REFINE_ZENY_COST);
	.@material = getequiprefinecost(.@part, REFINE_COST_ENRICHED, REFINE_MATERIAL_ID);

	// Make sure you have the necessary items and Zeny to refine your items
	// Determines chance of failure and verifies that you want to continue.
	callsub S_RefineValidate,getequipweaponlv(.@part),.@material,.@price,.@part,.@refineitemid,.@refinerycnt;

	mes .@npc_name$;
	mes "Clang! Clang! Clang!";
	if (getequippercentrefinery(.@part, true) > rand(100)) { 
		successrefitem .@part;
		next;
		emotion ET_BEST;
		mes .@npc_name$;
		mes "There you go! It's done.";
		mes "It's been a while since I've made such a fine "+((getequipweaponlv(.@part))?"weapon":"armor")+". You must be happy because it has become stronger!";
		close;
	}
	failedrefitem .@part;
	next;
	emotion (!rand(5))?ET_MONEY:ET_HUK;
	mes .@npc_name$;
	mes "Uuuuuuuuuummmmmph!!!";
	next;
	mes .@npc_name$;
	mes "...";
	mes ".....";
	mes ".......Huhuhuhuhu~";
	mes "........It was your choice and my ability, no regret.";
	close;

S_RefineValidate:
	.@weapon_lvl = getarg(0);
	.@item_req = getarg(1);
	.@price = getarg(2);
	.@part = getarg(3);
	setarray .@card[0], getequipcardid(.@part,0), getequipcardid(.@part,1), getequipcardid(.@part,2), getequipcardid(.@part,3);

	// If the VIP system is enabled, the prices for non-VIP players are considerably higher.
	if (VIP_SCRIPT && !vip_status(VIP_STATUS_ACTIVE)) {
		switch(.@weapon_lvl){
			case 0: set .@price, .@price * 10; break;
			case 1: set .@price, .@price * 40; break;
			case 2: set .@price, .@price * 50; break;
			case 3: set .@price, .@price * 2; break;
			case 4: set .@price, .@price * 2; break;
		}
	}

	mes .@npc_name$;
	if (.@weapon_lvl)
		mes "You want to refine a level "+ .@weapon_lvl +" weapon?";
	mes "To refine that, you'll need to have one ^ff9999"+ getitemname(.@item_req) +"^000000 and "+ .@price +" zeny.";
	mes "Would you like to continue?";
	next;
	if(select("Yes:No") == 1) {
		if (getequippercentrefinery(.@part) < 100) {
			if (.@weapon_lvl) {
				mes .@npc_name$;
				mes "Wow!!";
				mes "This weapon probably";
				mes "looks like it's been refined...";
				mes "many times...";
				mes "It may break if";
				mes "you refine it again.";
				next;
				mes "And if it breaks,";
				mes "you can't use it anymore!";
				mes "All the cards in it and the properties ^ff0000will be lost^000000!";
				mes "^ff0000Besides, the equipment will break!^000000";
				mes "Are you sure you still want to continue?";
				next;
				if(select("Yes:No") == 2) {
					mes .@npc_name$;
					mes "Good.";
					mes "Because if the weapon breaks from unreasonable refining, then I get a bad mood, too.";
					close;
				}
			} else {
				mes .@npc_name$;
				mes "Giggle. Giggle. Oh, you have guts, daring to refine this.";
				mes "You know it's pretty risky, don't you?";
				next;
				mes "If your defensive equipment is broken, you'll never be able to use it again.";
				mes "Even your cards and your modifications will ^ff0000completely disappear^000000.";
				//mes "Everything will disappear. As in... GONE!";
				mes "Do you really wish to continue?";
				next;
				if(select("Yes:No") == 2) {
					mes .@npc_name$;
					mes "What nonsense. You waste my precious time.";
					mes "Get lost, punk.";
					close;
				}
			}
		}
		if (countitem(.@item_req) > 0 && Zeny > .@price) {
			delitem .@item_req,1;
			set Zeny, Zeny - .@price;

			// anti-hack
			if (callfunc("F_IsEquipIDHack", .@part, getarg(4)) ||
				callfunc("F_IsEquipRefineHack", .@part, getarg(5)) || callfunc("F_IsEquipCardHack", .@part, .@card[0], .@card[1], .@card[2], .@card[3])) {
				mes "[Holink]";
				emotion ET_FRET;
				mes "Wait a second...";
				mes "Do you think I'm stupid?!";
				mes "You switched the item while I wasn't looking! Get out of here!";
				close;
			}

			return;
		}
		mes .@npc_name$;
		mes "Are these all you have?";
		mes "I'm very sorry, but I can't do anything without all the materials. Besides, I deserve some payments for my work, don't I?";
		close;
	}
	mes .@npc_name$;
	mes "I can't help it even if you're not happy about it...";
	close;
}