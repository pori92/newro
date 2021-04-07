//===== rAthena Script =======================================
//= War of Emperium TE - Template File
//===== Description: =========================================
//= [Official Conversion]
//= Like agit_main, this file is required
//= for TE castles to function.
//= - Enables AGIT Manager.
//= - Enables Stewards to invest.
//= - Enables Kafra Services inside Guild.
//= - Treasure Chest spawning.
//= - Flag Template.
//= - GM NPC.
//===== Changelogs: ==========================================
//= 1.0 First Version. [Capuche]
//============================================================

-	script	Manager_TE	-1,{
OnAgitInit3:
	.@map$ = strnpcinfo(4);
	if (.@map$ == "") end;
	.@npc_name$ = strnpcinfo(0);
	.@guild_id = getcastledata(.@map$,CD_GUILD_ID);
	if (.@guild_id == 0) {
		killmonster .@map$, .@npc_name$ +"::OnMyMobDead";
		donpcevent strnpcinfo(0)+"::OnEmpSpawn";
		if (compare(.@map$,"te_aldecas")) {
			monster .@map$,0,0,"Evil Druid",1117,10,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Khalitzburg",1132,4,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Abysmal Knight",1219,2,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Executioner",1205,1,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Penomena",1216,10,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Alarm",1193,18,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Clock",1269,9,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Raydric Archer",1276,7,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Wanderer",1208,3,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Alice",1275,1,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Bloody Knight",1268,1,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Dark Lord",1272,1,.@npc_name$ +"::OnMyMobDead";
			if (.@map$ == "te_aldecas1") { setarray .@emproom[0],216,23; }
			else if (.@map$ == "te_aldecas2") { setarray .@emproom[0],213,23; }
			else if (.@map$ == "te_aldecas3") { setarray .@emproom[0],205,31; }
			else if (.@map$ == "te_aldecas4") { setarray .@emproom[0],36,217; }
			else if (.@map$ == "te_aldecas5") { setarray .@emproom[0],27,101; }
			monster .@map$,.@emproom[0],.@emproom[1],"Dark Lord",1272,1,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,.@emproom[0],.@emproom[1],"Tower Keeper",1270,4,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,.@emproom[0],.@emproom[1],"Bloody Knight",1268,1,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,.@emproom[0],.@emproom[1],"Abysmal Knight",1219,1,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,.@emproom[0],.@emproom[1],"Raydric Archer",1276,5,.@npc_name$ +"::OnMyMobDead";
		}
		else if (compare(.@map$,"te_prtcas")) {
			monster .@map$,0,0,"Raydric",1163,10,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Khalitzburg",1132,10,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Abysmal Knight",1219,5,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Bloody Knight",1268,5,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Stormy Knight",1251,1,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Hatii",1252,1,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Raydric Archer",1276,5,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Gryphon",1259,2,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Chimera",1283,2,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Alice",1275,1,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,0,0,"Zealotus",1200,1,.@npc_name$ +"::OnMyMobDead";
			if (.@map$ == "te_prtcas01") { setarray .@emproom[0],197,197; }
			else if (.@map$ == "te_prtcas02") { setarray .@emproom[0],157,174; }
			else if (.@map$ == "te_prtcas03") { setarray .@emproom[0],16,220; }
			else if (.@map$ == "te_prtcas04") { setarray .@emproom[0],291,14; }
			else if (.@map$ == "te_prtcas05") { setarray .@emproom[0],266,266; }
			monster .@map$,.@emproom[0],.@emproom[1],"Guardian Knight of Emperium",1268,1,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,.@emproom[0],.@emproom[1],"Chief Guardian Knight of Emperium",1251,1,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,.@emproom[0],.@emproom[1],"Hatii",1252,1,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,.@emproom[0],.@emproom[1],"Guardian Knight of Emperium",1219,2,.@npc_name$ +"::OnMyMobDead";
			monster .@map$,.@emproom[0],.@emproom[1],"Raydric Archer",1276,5,.@npc_name$ +"::OnMyMobDead";
		}
		disablenpc "Kafra Employee#"+ replacestr(.@map$, "cas", "");
	}
	else {
		requestguildinfo .@guild_id;
		donpcevent "::OnFlagTE" + strnpcinfo(2);// Guild emblem on flags.
		if (getcastledata(.@map$,CD_ENABLED_KAFRA)  == 0)
			disablenpc "Kafra Employee#"+ replacestr(.@map$, "cas", "");

		// Load purchased Guardian in castles.
		if (.@map$ == "te_aldecas1") donpcevent "Clode::OnSpawnGuardians";
		else if (.@map$ == "te_aldecas2") donpcevent "Lares::OnSpawnGuardians";
		else if (.@map$ == "te_aldecas3") donpcevent "Valerian::OnSpawnGuardians";
		else if (.@map$ == "te_aldecas4") donpcevent "Alpores::OnSpawnGuardians";
		else if (.@map$ == "te_aldecas5") donpcevent "Anpere::OnSpawnGuardians";
		else if (.@map$ == "te_prtcas01") donpcevent "Kurbe::OnSpawnGuardians";
		else if (.@map$ == "te_prtcas02") donpcevent "Kamiyu::OnSpawnGuardians";
		else if (.@map$ == "te_prtcas03") donpcevent "Eduare::OnSpawnGuardians";
		else if (.@map$ == "te_prtcas04") donpcevent "Casate::OnSpawnGuardians";
		else if (.@map$ == "te_prtcas05") donpcevent "Pisaro::OnSpawnGuardians";
	}
	end;

OnEmpSpawn:
	.@map$ = strnpcinfo(4);
	if (!mobcount( .@map$, strnpcinfo(0) +"::OnAgitBreak" )) {
		if (.@map$ == "te_aldecas1") { setarray .@emproom[0],216,23; }
		else if (.@map$ == "te_aldecas2") { setarray .@emproom[0],213,23; }
		else if (.@map$ == "te_aldecas3") { setarray .@emproom[0],205,31; }
		else if (.@map$ == "te_aldecas4") { setarray .@emproom[0],36,217; }
		else if (.@map$ == "te_aldecas5") { setarray .@emproom[0],27,101; }
		else if (.@map$ == "te_prtcas01") { setarray .@emproom[0],197,197; }
		else if (.@map$ == "te_prtcas02") { setarray .@emproom[0],157,174; }
		else if (.@map$ == "te_prtcas03") { setarray .@emproom[0],16,220; }
		else if (.@map$ == "te_prtcas04") { setarray .@emproom[0],291,14; }
		else if (.@map$ == "te_prtcas05") { setarray .@emproom[0],266,266; }
		monster .@map$,.@emproom[0],.@emproom[1],"Emperium",1288,1, strnpcinfo(0) +"::OnAgitBreak";
	}
	end;

OnAgitStart3:
	.@map$ = strnpcinfo(4);
	if (.@map$ == "") end;
	if (agitcheck3()) {
		maprespawnguildid .@map$, getcastledata(.@map$,CD_GUILD_ID),2;// warp all non-guild members
		gvgon3 .@map$;
		donpcevent strnpcinfo(0)+"::OnEmpSpawn";
		callsub S_Message,"OnCommandOn";
	}
	end;

OnAgitEnd3:
	.@map$ = strnpcinfo(4);
	if (.@map$ == "") end;
	gvgoff3 .@map$;
	if (getcastledata(.@map$,CD_GUILD_ID))
		killmonster .@map$, strnpcinfo(0) +"::OnAgitBreak";
	callsub S_Message,"OnReset";
	end;

OnAgitBreak:
	.@guild_id = getcharid(2);
	.@map$ = strnpcinfo(4);

	.@economy = getcastledata(.@map$,CD_CURRENT_ECONOMY) - 5;// Adjust economy Invest Level for Castle
	if (.@economy < 1)
		setcastledata .@map$, CD_CURRENT_ECONOMY,1;
	else
		setcastledata .@map$, CD_CURRENT_ECONOMY,.@economy;
	.@defense = getcastledata(.@map$,CD_CURRENT_DEFENSE) - 5;// Adjust Defense Invest Level for Castle
	if (.@defense < 1)
		setcastledata .@map$, CD_CURRENT_DEFENSE,1;
	else
		setcastledata .@map$, CD_CURRENT_DEFENSE,.@defense;
	setcastledata .@map$,CD_GUILD_ID,.@guild_id;

	// Reset Invest information and refresh castle data
	for ( .@i = CD_INVESTED_ECONOMY; .@i < CD_ENABLED_GUARDIAN00; .@i++ )
		setcastledata .@map$,.@i,0;
	donpcevent strnpcinfo(0) +"::OnAgitInit3";// spawn guardians / monsters

	// Erase Guardian Database information if the new owners do not have Guardian Research.
	if (getgdskilllv(.@guild_id,10002) == 0) {
		for ( .@i = CD_ENABLED_GUARDIAN00; .@i < CD_MAX; .@i++ )
			setcastledata .@map$,.@i,0;
	}

	mapannounce .@map$,"Emperium has been destroyed.",bc_map,"0x00FF00",FW_BOLD,20,0,40;
	maprespawnguildid .@map$,.@guild_id,2;// Respawn all but new castle-occupants, don't remove monsters.

	sleep 500;
	if (agitcheck3())
		donpcevent strnpcinfo(0) +"::OnEmpSpawn";
	sleep 7000;
	announce "The [" + getcastlename(.@map$) + "] castle has been conquered by the [" + getguildName(.@guild_id) + "] guild.",bc_all|bc_woe;
	end;

OnGuildBreak:
	.@map$ = strnpcinfo(4);
	if (.@map$ == "") end;
	.@tmp$ = replacestr(.@map$, "cas", "");
	killmonster .@map$, "Kafra Employee#"+ .@tmp$ +"::OnGuardianDied";
	disablenpc "Kafra Employee#"+ .@tmp$;
	setcastledata .@map$,CD_GUILD_ID,0;
	sleep 7000;
	announce "Guild Base [" + getcastlename(.@map$) + "] has been abandoned.",bc_all;
	donpcevent strnpcinfo(0) +"::OnAgitInit3";
	end;

S_Message:
	.@map$ = strnpcinfo(4);
	//Biali stupid announces
	// .@guild_id = getcastledata(.@map$,CD_GUILD_ID);
	
	// if (.@guild_id)
	// 	announce "The [" + getcastlename(.@map$) + "] castle is occupied by the [" + getguildname(.@guild_id) + "] guild.",bc_all,"0xFF0000",FW_NORMAL,10;
	// else
	// 	announce "The [" + getcastlename(.@map$) + "] castle is currently unoccupied.", bc_all,"0xFF0000",FW_NORMAL,10;
	if (compare( .@map$,"te_alde" ))
		.@string$ = "alde0"+ charat( .@map$,getstrlen(.@map$)-1 );
	else
		.@string$ = "prt0"+ charat( .@map$,getstrlen(.@map$)-1 );
	//Biali we dont have the quests shit
	//donpcevent "#popswitch_"+ .@string$ +"::"+ getarg(0);// monsters for mission TE

	// Biali sem godly TE shit tambem
	// if (.@map$ == "te_aldecas1") {
	// 	donpcevent "Blacksmith Cano#tegod01::OnInit";// god item TE
	// 	$2012_tegod_kafra = 0;
	// 	$@2012_tegirls_alde01 = 0;
	// }
	// else if (.@map$ == "te_prtcas01") {
    // 	$2012_tegod_gloria = 0;
    // 	$@2012_tegirls_prt01 = 0;
    // 	donpcevent "Blacksmith Kai#tegod01::OnInit";
	// }
	return;

OnMyMobDead:
	end;
}

// Guild Kafras
//============================================================
-	script	Kafra_Staff_TE	-1,{
	.@guild_id = getcastledata( strnpcinfo(4),CD_GUILD_ID );
	.@guildname$ = getguildname(.@guild_id);

	cutin "kafra_01",2;
	mes "[Kafra Employee]";
	if (.@guild_id == getcharid(2)) {
		mes "Welcome. ^ff0000" + .@guildname$ + "^000000 Member.";
		mes "The Kafra Corporation will stay with you wherever you go.";
		next;
		switch( select( "Use Storage", "Use Teleport Service", "Rent a Pushcart", "Cancel" ) ) {
		case 1:
			if (getskilllv("NV_BASIC") > 5) {
				mes "[Kafra Employee]";
				mes "Here, let me open";
				mes "your Storage for you.";
				mes "Thank you for using";
				mes "the Kafra Service.";
				close2;
				openstorage;
			} else {
				mes "[Kafra Employee]";
				mes "I'm sorry, but you";
				mes "need the Novice's";
				mes "Basic Skill Level 6 to";
				mes "use the Storage Service.";
				close2;
			}
			break;
		case 2:
			if (compare( strnpcinfo(4),"alde" ) == 1)
				callsub( S_Warp, "Aldebaran", "aldebaran",132,103 );
			else
				callsub( S_Warp, "Prontera", "prontera",278,211 );
		case 3:
			mes "[Kafra Employee]";
			if (BaseClass != Job_Merchant) {
				mes "I'm sorry, but the";
				mes "Pushcart rental service";
				mes "is only available to Merchants,";
				mes "Blacksmiths and Alchemists.";
				close2;
			}
			else if (checkcart()) {
				mes "You already have";
				mes "a Pushcart equipped.";
				mes "Unfortunately, we can't";
				mes "rent more than one to";
				mes "each customer at a time.";
				close2;
			}
			else {
				mes "The Pushcart rental";
				mes "fee is 800 zeny. Would";
				mes "you like to rent a Pushcart?";
				next;
				if (select( "Rent a Pushcart","Cancel" ) == 1) {
					if (Zeny < 800) {
						mes "[Kafra Employee]";
						mes "I'm sorry, but you";
						mes "don't have enough";
						mes "zeny to pay the Pushcart";
						mes "rental fee of 800 zeny.";
						close2;
					}
					else {
						RESRVPTS = RESRVPTS + 80;
						Zeny = Zeny - 800;
						setcart();
					}
				}
			}
			break;
		case 4:
			mes "[Kafra Employee]";
			mes "We, here at Kafra Corporation,";
			mes "are always endeavoring to provide you with the best services. We hope that we meet your adventuring needs and standards of excellence.";
			close2;
			break;
		}
	}
	else {
		mes "I am instructed to only offer my services to the ^ff0000"+ .@guildname$ +"^000000 Guild. Please try another Kafra Employee around here. Sorry for the inconvenience.";
		close2;
	}
	cutin "",255;
	end;

S_Warp:
	mes "[Kafra Employee]";
	mes "Please choose";
	mes "your destination.";
	next;
	switch( select( getarg(0) + " -> 200 z", "Cancel it" ) ) {
	case 1:
		if (Zeny < 200) {
			mes "[Kafra Employee]";
			mes "I'm sorry, but you don't have";
			mes "enough zeny for the Teleport";
			mes "Service. The fee to teleport";
			mes "to "+getarg(0)+" is 200 zeny.";
			close2;
			cutin "",255;
			end;
		}
		Zeny = Zeny - 200;
		RESRVPTS = RESRVPTS + 20;
		warp getarg(1), getarg(2),getarg(3);
		end;
	case 2:
		cutin "",255;
		end;
	}

OnGuardianDied:
	end;
}

// Castle Managers (Invest)
//============================================================
-	script	invest_TE	-1,{
function GuardianData;

	.@map$ = strnpcinfo(4);
	.@npc_name$ = "[ Butler "+ strnpcinfo(1) +"]";
	.@guild_id = getcastledata(.@map$,CD_GUILD_ID);
	.@guildmaster$ = getguildmaster(.@guild_id);

	mes .@npc_name$;
	if (.@guild_id == 0) {
		mes "I have been waiting for a master to fulfill my destiny.";
		mes "Brave soul... fate will guide you towards your future...";
		close;
	}
	if (strcharinfo(0) != .@guildmaster$) {
		mes "No matter how much you pester me, I'll still follow my master ^ff0000"+.@guildmaster$+"^000000. Where are the Guardians?! Send these ruffians away right now!";
		close;
	}
	mes "Welcome. My honorable master, ^ff0000"+strcharinfo(0)+"^000000...";
	mes "Your humble servent, "+strnpcinfo(1)+", is here to serve you.";
	next;
	switch( select( "Castle briefing", "Invest in commercial growth", "Invest in Castle Defenses", "Summon Guardian", "Hire / Fire a Kafra Employee", "Go into Master's room" ) ) {
	case 1:
		.@economy_today = getcastledata(.@map$,CD_INVESTED_ECONOMY);
		.@defense_today = getcastledata(.@map$,CD_INVESTED_DEFENSE);
		mes .@npc_name$;
		mes "I will report the Castle briefing, Master.";
		mes " ";
		mes "^0000ffNow, the commercial growth level is "+GetCastleData(.@map$,CD_CURRENT_ECONOMY)+".";
		if (.@economy_today > 0)
			mes " You invested "+.@economy_today+" times in past 1 day.";
		mes " Now, the Castle Defense level is "+GetCastleData(.@map$,CD_CURRENT_DEFENSE)+".^000000";
		if (.@defense_today > 0)
			mes " ^0000ff- You invested "+.@defense_today+" times in past 1 day.^000000";
		mes " ";
		mes "That's all I have to report, Master.";
		close;

	case 2:
		.@economy = getcastledata(.@map$,CD_CURRENT_ECONOMY);
		setarray .@eco_invest[0], 5,5000, 10,10000, 15,20000, 20,35000, 25,55000, 30,80000, 35,110000, 40,145000, 45,185000, 50,230000,
			55,280000, 60,335000, 65,395000, 70,460000, 75,530000, 80,605000, 85,685000, 90,770000, 95,860000, 100,955000;
		for ( .@i = 0; .@i < getarraysize(.@eco_invest); .@i += 2 )
			if (.@economy <= .@eco_invest[.@i]) break;
		callsub( S_Invest, 4, .@eco_invest[.@i+1], getcastledata(.@map$,CD_INVESTED_ECONOMY), "commercial growth", "quantity of goods made by the guild will increase", "future", "economist", "riches" );

	case 3:
		.@defense = getcastledata(.@map$,CD_CURRENT_DEFENSE);
		setarray .@def_invest[0], 5,10000, 10,20000, 15,40000, 20,70000, 25,110000, 30,160000, 35,220000, 40,290000, 45,370000, 50,460000,
			55,560000, 60,670000, 65,790000, 70,920000, 75,1060000, 80,1210000, 85,1370000, 90,1540000, 95,1720000, 100,1910000;
		for ( .@i = 0; .@i < getarraysize(.@def_invest); .@i += 2 )
			if (.@defense <= .@def_invest[.@i]) break;
		callsub( S_Invest, 5, .@def_invest[.@i+1], getcastledata(.@map$,CD_INVESTED_DEFENSE), "Castle Defenses", "durability of Guardians and the Emperium will increase", "coming battles", "strategist", "Defenses" );

	case 4:
		mes .@npc_name$;
		mes "Will you summon a Guardian? It'll be a protector to defend us loyally.";
		mes "Please select a guardian to defend us.";
		next;
		GuardianData( .@mob_id, .@x, .@y, .@name$ );
		for ( .@i = 0; .@i < MAX_GUARDIANS ; .@i++ ) {
			if (guardianinfo(.@map$,.@i,0))
				.@menu$ = .@menu$ + getmonsterinfo(.@mob_id[.@i],MOB_NAME) + " - Implemented (" + guardianinfo(.@map$,.@i,2) + "/" + guardianinfo(.@map$,.@i,1) + "):";// hp/hpmax
			else
				.@menu$ = .@menu$ + getmonsterinfo(.@mob_id[.@i],MOB_NAME) + " - Not Implemented:";
		}
		.@s = select(.@menu$) -1;
		mes .@npc_name$;
		mes "Will you summon the chosen guardian? 10,000 zeny are required to summon a Guardian.";
		next;
		if (select( "Summon","Cancel" ) == 2) {
			mes .@npc_name$;
			mes "I did as you ordered. But please remember if you the have money to spare, it'll be better to set it up.";
			close;
		}
		mes .@npc_name$;
		if (getgdskilllv(.@guild_id,10002) == 0) {
			mes "Master, we have not the resources to Summon the Guardian. If you want to accumulate them, you have to learn the Guild skill. We failed to summon the Guardian.";
		}
		else if (getcastledata( .@map$,(.@s + CD_ENABLED_GUARDIAN00) ) == 1)
			mes "Master, you already have summoned that Guardian. We cannot summon another.";
		else if (Zeny <  10000)
			mes "Well... I'm sorry but we don't have funds to summon the Guardian. We failed to summon the Guardian.";
		else {
			Zeny = Zeny - 10000;
			setcastledata .@map$,(.@s + CD_ENABLED_GUARDIAN00),1;
			guardian .@map$, .@x[.@s], .@y[.@s], .@name$[.@s], .@mob_id[.@s], "Kafra Employee#"+ replacestr(.@map$, "cas", "") +"::OnGuardianDied", .@s;
			mes "We completed the summoning of the Guardian. Our defenses are now increased with it in place.";
		}
		close;

	case 5:
		mes .@npc_name$;
		if (getcastledata(.@map$,CD_ENABLED_KAFRA) == 1) {
			mes "We are currently hiring a Kafra Employee... Do you want to fire the Kafra Employee?";
			next;
			if (select( "Fire","Cancel" ) == 2) {
				mes .@npc_name$;
				mes "She worked hard in my opinion. It was a good decision to keep her.";
				close;
			}
			cutin "kafra_01",2;
			mes "[ Hired Kafra Employee ]";
			mes "I worked so hard... How can you do that, Master?... Please... Please reconsider... Check it again, Master... Please...";
			next;
			if (select( "Fire","Cancel" ) == 2) {
				mes "[ Hired Kafra Employee ]";
				mes "I'll work hard for you... Thank you!";
				close;
			}
			mes "[ Hired Kafra Employee ]";
			mes "Oh, my goodness! This is nonsense!";
			next;
			cutin "",255;
			disablenpc "Kafra Employee#" + replacestr(.@map$, "cas", "");
			setcastledata .@map$,CD_ENABLED_KAFRA,0;
			mes .@npc_name$;
			mes "....";
			mes "I have discharged the Kafra Employee... But... are you unsatisfied with something?";
			close;
		}
		mes "Will you contact the kafra Main Office and Hire a Employee for our Castle?";
		mes "^ff0000 10,000 zeny is required for their services. ";
		next;
		if (select( "Hire.","Cancel" ) == 2) {
			mes .@npc_name$;
			mes "I did as you ordered, but some of our members will be unhappy. It will be better to hire a Kafra Employee quickly.";
			close;
		}
		mes .@npc_name$;
		if (getgdskilllv(.@guild_id,10001) == 0) {
			mes "Master, we can't hire a Kafra Employee because we don't have a contract with the Kafra Main Office. If you want to obtain a contract with the Kafra Main Office, you will need to learn the Guild skill first.";
			close;
		}
		if (Zeny <  10000) {
			mes "Well... I'm sorry but we don't have enough funds to hire a Kafra Employee.";
			close;
		}
		Zeny = Zeny - 10000;
		enablenpc "Kafra Employee#" + replacestr(.@map$, "cas", "");
		setcastledata .@map$,CD_ENABLED_KAFRA,1;

		mes "We obtained a contract with the kafra Main Office, and hired a Kafra Employee.";
		next;
		cutin "kafra_01",2;
		mes "[ Hired Kafra Employee ]";
		mes "How do you do? I was dispatched from the Main Office.";
		mes "I'll do my best to not tarnish the reputation of the Guild.";
		next;
		cutin "",255;
		mes .@npc_name$;
		mes "The Contract terms of the hired Kafra Employee are for 1 month and after this term, you will need to to pay an additional fee.";
		mes "It will be useful for our members.";
		close;

	case 6:
		mes .@npc_name$;
		mes "Do you want to visit the room where our valuables are stored?";
		mes "That room is restricted to you... you are the only one with access to it.";
		next;
		mes .@npc_name$;
		mes "If you don't open the treasure box within time limits, there is a possibility of losing it when unexpected situation occurs.";
		mes "Please make sure to remember that always, Master.";
		mes "So, for our guild's improvement, you must find time to collect it.";
		next;
		switch( select( "Go into Master's room.","Cancel" ) ) {
		case 1:
			mes .@npc_name$;
			mes "I'll show you the secret path. Follow me...please.";
			mes "When you want to return here, please press the secret switch.";
			close2;
			if (.@map$ == "te_aldecas1") warp "te_aldecas1",113,223;
			else if (.@map$ == "te_aldecas2") warp "te_aldecas2",134,225;
			else if (.@map$ == "te_aldecas3") warp "te_aldecas3",229,267;
			else if (.@map$ == "te_aldecas4") warp "te_aldecas4",83,17;
			else if (.@map$ == "te_aldecas5") warp "te_aldecas5",64,8;
			else if (.@map$ == "te_prtcas01") warp "te_prtcas01",15,209;
			else if (.@map$ == "te_prtcas02") warp "te_prtcas02",207,229;
			else if (.@map$ == "te_prtcas03") warp "te_prtcas03",190,130;
			else if (.@map$ == "te_prtcas04") warp "te_prtcas04",275,160;
			else if (.@map$ == "te_prtcas05") warp "te_prtcas05",281,176;
			end;
		case 2:
			mes .@npc_name$;
			mes "Goods are produced once a day... if you don't remove them in time, they will not be produced anymore.";
			mes "Therefore, it will be better if you check up on them from time to time.";
			close;
		}
	}

S_Invest:
	.@cost_invest = getarg(1);
	.@num_invest_today = getarg(2);
	.@npc_name$ = "[ Butler "+ strnpcinfo(1) +"]";
	if (.@num_invest_today)// Quadruple the cost of investing if you've already invested once.
		.@cost_invest = .@cost_invest * 4;

	mes .@npc_name$;
	mes "If you invest in "+ getarg(3) +", the "+ getarg(4) +". Therfore, if you consider our "+ getarg(5) +", investments will be a necessity.";
	mes " ";
	mes "Initially, you are able to invest just once but if you pay more money, you will be able to invest twice.";
	mes " ";
	if (getcastledata(strnpcinfo(4),CD_CURRENT_ECONOMY) >= 100) {
		mes "^ff0000The "+ getarg(3) +" level of our Castle is at it's highest, 100%. No more investments are needed. Just as I have expected from a great "+ getarg(6) +" like you, Master.^000000";
		close;
	}
	if (.@num_invest_today >= 2) {
		mes "^ff0000You have already invested twice today. You cannot invest any more.^000000 I expect the "+ getarg(7) +" of the guild to grow at a high rate.";
		close;
	}
	if (.@num_invest_today == 0)
		mes "The current investment amount required is ^ff0000"+.@cost_invest+"^000000 zeny. Will you invest?";
	else
		mes "You've invested once today... if you wish to invest once more, ^ff0000"+.@cost_invest+"^000000 more zeny will be needed.";
	next;
	switch( select( "Invest in "+ getarg(3) +".","Cancel" ) ) {
	case 1:
		mes .@npc_name$;
		if (Zeny < .@cost_invest) {
			mes "I'm sorry but there is not enough zeny to invest. You will have to try again when you have the funds, Master.";
			close;
		}
		Zeny = Zeny - .@cost_invest;
		setcastledata strnpcinfo(4), getarg(0), (.@num_invest_today +1);
		mes "We finished the investment safely. I expect that our "+ getarg(3) +" level will be increased by tomorrow.";
		close;
	case 2:
		mes .@npc_name$;
		mes "I'll do as you bid, my master... There is no hurry. We will do our best.";
		close;
	}

function GuardianData {
	.@map$ = strnpcinfo(4);
	if (.@map$ == "te_aldecas1") {
		setarray .@data$[0],
			1287, 17, 218, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1285, 39, 205, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1285, 38, 196, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1286, 21, 194, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 218, 24, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 213, 24, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 73, 70, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1285, 45, 228, "Outer Castle Archer Guardian";// ARCHER_GUARDIAN
	}
	else if (.@map$ == "te_aldecas2") {
		setarray .@data$[0],
			1287, 51, 183, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1286, 27, 184, "Outer Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 88, 43, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1285, 210, 7, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1287, 60, 203, "Outer Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1285, 21, 177, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1286, 117, 46, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1285, 36, 183, "Outer Castle Archer Guardian";// ARCHER_GUARDIAN
	}
	else if (.@map$ == "te_aldecas3") {
		setarray .@data$[0],
			1285, 110, 217, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1286, 90, 112, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1287, 86, 120, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1285, 195, 151, "Inner Castle Archer Guardian",// ARCHER_GUARDIAN
			1286, 116, 112, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1287, 116, 76, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1287, 64, 103, "Outer Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1285, 212, 160, "Inner Castle Archer Guardian";// ARCHER_GUARDIAN
	}
	else if (.@map$ == "te_aldecas4") {
		setarray .@data$[0],
			1285, 187, 100, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1285, 192, 42, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1286, 55, 88, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1287, 145, 209, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1287, 169, 53, "Outer Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1287, 198, 77, "Outer Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1285, 148, 88, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1286, 48, 72, "Inner Castle Knight Guardian";// KNIGHT_GUARDIAN
	}
	else if (.@map$ == "te_aldecas5") {
		setarray .@data$[0],
			1285, 51, 202, "Inner Castle Archer Guardian",// ARCHER_GUARDIAN
			1286, 27, 221, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 145, 78, "Outer Castle Knight Guardian",// KNIGHT_GUARDIAN
			1287, 157, 192, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1287, 157, 74, "Outer Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1285, 188, 79, "Inner Castle Archer Guardian",// ARCHER_GUARDIAN
			1286, 156, 73, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 41, 112, "Inner Castle Knight Guardian";// KNIGHT_GUARDIAN
	}
	else if (.@map$ == "te_prtcas01") {
		setarray .@data$[0],
			1287, 182, 68, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1287, 182, 116, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1287, 153, 86, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1285, 59, 28, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1285, 50, 36, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1286, 184, 183, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 196, 189, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 107, 179, "Inner Castle Knight Guardian";// KNIGHT_GUARDIAN
	}
	else if (.@map$ == "te_prtcas02") {
		setarray .@data$[0],
			1286, 162, 161, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 153, 161, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 178, 44, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1287, 71, 75, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1287, 49, 28, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1285, 64, 186, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1285, 76, 196, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1285, 75, 175, "Outer Castle Archer Guardian";// ARCHER_GUARDIAN
	}
	else if (.@map$ == "te_prtcas03") {
		setarray .@data$[0],
			1286, 191, 190, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 137, 190, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 45, 99, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1287, 50, 87, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1287, 41, 87, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1285, 191, 42, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1285, 179, 43, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1285, 191, 72, "Outer Castle Archer Guardian";// ARCHER_GUARDIAN
	}
	else if (.@map$ == "te_prtcas04") {
		setarray .@data$[0],
			1286, 276, 14, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 274, 35, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 246, 246, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1287, 38, 240, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1287, 29, 240, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1287, 33, 258, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1285, 78, 48, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1285, 36, 61, "Outer Castle Archer Guardian";// ARCHER_GUARDIAN
	}
	else if (.@map$ == "te_prtcas05") {
		setarray .@data$[0],
			1286, 266, 262, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 287, 280, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1286, 245, 250, "Inner Castle Knight Guardian",// KNIGHT_GUARDIAN
			1287, 236, 63, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1287, 251, 63, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1287, 278, 71, "Inner Castle Soldier Guardian",// SOLDIER_GUARDIAN
			1285, 32, 253, "Outer Castle Archer Guardian",// ARCHER_GUARDIAN
			1285, 44, 248, "Outer Castle Archer Guardian";// ARCHER_GUARDIAN
	}
	for ( .@i = 0; .@i < getarraysize(.@data$); .@i += 4 ) {
		set getelementofarray( getarg(0),.@index ), .@data$[.@i];
		set getelementofarray( getarg(1),.@index ), .@data$[.@i+1];
		set getelementofarray( getarg(2),.@index ), .@data$[.@i+2];
		set getelementofarray( getarg(3),.@index ), .@data$[.@i+3];
		.@index++;
	}
}

OnSpawnGuardians:
	GuardianData( .@mob_id, .@x, .@y, .@name$ );
	.@map$ = strnpcinfo(4);
	.@tmp$ = replacestr(.@map$, "cas", "");
	killmonster .@map$, "Kafra Employee#"+ .@tmp$ +"::OnGuardianDied";
	for ( .@i = 0; .@i < MAX_GUARDIANS; .@i++ ) {
		if (getcastledata( .@map$,(.@i + CD_ENABLED_GUARDIAN00) ))
			guardian .@map$, .@x[.@i], .@y[.@i], .@name$[.@i], .@mob_id[.@i], "Kafra Employee#"+ .@tmp$ +"::OnGuardianDied",.@i;
	}
}

// Guild Dungeon Entrances
//============================================================
-	script	lever2_TE	-1,{
	.@guild_id = getcastledata( strnpcinfo(4),CD_GUILD_ID );
	if (.@guild_id == 0) {
		mes "[Ringing Voice]";
		mes "'Those who overcome an ordeal shows a great deal of bravery... and will find their way to another ordeal.'";
		close;
	}
	mes "[Ringing Voice]";
	mes "'Only the truly brave can take the test.'";
	next;
	mes " ";
	mes "There's a small lever. Will you pull it?";
	next;
	if (select( "Pull.","Don't pull." ) == 1) {
		if (.@guild_id == getcharid(2)) {
			.@npc_map$ = strnpcinfo(4);
			if (compare( .@npc_map$,"te_alde" )) {
				.@map$ = "teg_dun02";
				if (.@npc_map$ == "te_aldecas1") setarray .@coord[0],32,122;
				else if (.@npc_map$ == "te_aldecas2") setarray .@coord[0],79,30;
				else if (.@npc_map$ == "te_aldecas3") setarray .@coord[0],165,38;
				else if (.@npc_map$ == "te_aldecas4") setarray .@coord[0],160,148;
				else if (.@npc_map$ == "te_aldecas5") setarray .@coord[0],103,169;
			}
			else {
				.@map$ = "teg_dun01";
				if (.@npc_map$ == "te_prtcas01") setarray .@coord[0],28,251;
				else if (.@npc_map$ == "te_prtcas02") setarray .@coord[0],164,268;
				else if (.@npc_map$ == "te_prtcas03") setarray .@coord[0],164,179;
				else if (.@npc_map$ == "te_prtcas04") setarray .@coord[0],268,203;
				else if (.@npc_map$ == "te_prtcas05") setarray .@coord[0],199,28;
			}
			warp .@map$,.@coord[0],.@coord[1];
		}
		else {
			mes " ";
			mes "Nothing happened.";
			close;
		}
	}
	end;
}

// Treasure Room Exit
//============================================================
-	script	lever1_TE	-1,{
	mes " ";
	mes "There's a small lever. Will you pull it?";
	next;
	if ( select( "Pull.","Do not." ) == 1 ) {
		.@map$ = strnpcinfo(4);
		if (.@map$ == "te_aldecas1") setarray .@coord[0],218,176;
		else if (.@map$ == "te_aldecas2") setarray .@coord[0],51,179;
		else if (.@map$ == "te_aldecas3") setarray .@coord[0],110,119;
		else if (.@map$ == "te_aldecas4") setarray .@coord[0],67,117;
		else if (.@map$ == "te_aldecas5") setarray .@coord[0],51,179;
		else if (.@map$ == "te_prtcas01") setarray .@coord[0],112,183;
		else if (.@map$ == "te_prtcas02") setarray .@coord[0],94,62;
		else if (.@map$ == "te_prtcas03") setarray .@coord[0],51,101;
		else if (.@map$ == "te_prtcas04") setarray .@coord[0],259,265;
		else if (.@map$ == "te_prtcas05") setarray .@coord[0],36,38;
		warp .@map$,.@coord[0],.@coord[1];
	}
	end;
}

// Treasure Room Spawn Template
//============================================================
-	script	treasure_TE	-1,{
OnClock0001:// Spawn Treasure Chests based on castle economy.
	.@map$ = strnpcinfo(4);
	if (.@map$ == "") end;
	.@guild_id = getcastledata(.@map$,CD_GUILD_ID);
	if (.@guild_id == 0) end;

	.@economy = getcastledata(.@map$,CD_CURRENT_ECONOMY);
	.@defense = getcastledata(.@map$,CD_CURRENT_DEFENSE);
	.@economy_today = getcastledata(.@map$,CD_INVESTED_ECONOMY);
	.@defense_today = getcastledata(.@map$,CD_INVESTED_DEFENSE);

	killmonster .@map$, strnpcinfo(0)+"::OnTreasureDied";
	if (.@economy_today) {
		.@economy = .@economy + .@economy_today + (rand(2) && getgdskilllv(.@guild_id,10014));
		.@economy = ( .@economy > 100 ) ? 100 : .@economy;
		setcastledata .@map$,CD_CURRENT_ECONOMY,.@economy;
		setcastledata .@map$,CD_INVESTED_ECONOMY,0;
	}
	if (.@defense_today) {
		.@defense = .@defense + .@defense_today;
		.@defense = ( .@defense > 100 ) ? 100 : .@defense;
		setcastledata .@map$,CD_CURRENT_DEFENSE,.@defense;
		setcastledata .@map$,CD_INVESTED_DEFENSE,0;
	}

	if (.@map$ == "te_aldecas1") {
		setarray .@data[0],// <mob_id>, <x>,<y>
			2203, 115,226,// TREASURE_BOX_TE
			1357, 122,226,// TREASURE_BOX_TE_6
			2203, 115,219,
			1357, 122,219,
			2203, 116,225,
			1357, 117,225,
			2203, 118,225,
			1357, 119,225,
			2203, 120,225,
			1357, 121,225,
			2203, 121,224,
			1357, 121,223,
			2203, 121,222,
			1357, 121,221,
			2203, 121,220,
			1357, 120,220,
			2203, 119,220,
			1357, 118,220,
			2203, 117,220,
			1357, 116,220,
			2203, 116,221,
			1357, 116,222,
			2203, 116,223,
			1357, 116,224;
	}
	else if (.@map$ == "te_aldecas2") {
		setarray .@data[0],
			2203, 134,231,// TREASURE_BOX_TE
			1357, 135,231,// TREASURE_BOX_TE_7
			2203, 135,230,
			1357, 134,230,
			2203, 132,233,
			1357, 133,233,
			2203, 134,233,
			1357, 135,233,
			2203, 136,233,
			1357, 137,233,
			2203, 137,232,
			1357, 137,231,
			2203, 137,230,
			1357, 137,229,
			2203, 137,228,
			1357, 136,228,
			2203, 135,228,
			1357, 134,228,
			2203, 133,228,
			1357, 132,228,
			2203, 132,229,
			1357, 132,230,
			2203, 132,231,
			1357, 132,232;
	}
	else if (.@map$ == "te_aldecas3") {
		setarray .@data[0],
			2203, 224,269,// TREASURE_BOX_TE
			1357, 225,269,// TREASURE_BOX_TE_8
			2203, 225,268,
			1357, 224,268,
			2203, 222,271,
			1357, 223,271,
			2203, 224,271,
			1357, 225,271,
			2203, 226,271,
			1357, 227,271,
			2203, 227,270,
			1357, 227,269,
			2203, 227,268,
			1357, 227,267,
			2203, 227,266,
			1357, 226,266,
			2203, 225,266,
			1357, 224,266,
			2203, 223,266,
			1357, 222,266,
			2203, 222,267,
			1357, 222,268,
			2203, 222,269,
			1357, 222,270;
	}
	else if (.@map$ == "te_aldecas4") {
		setarray .@data[0],
			2203, 84,13,// TREASURE_BOX_TE
			1357, 85,13,// TREASURE_BOX_TE_9
			2203, 85,12,
			1357, 84,12,
			2203, 82,15,
			1357, 83,15,
			2203, 84,15,
			1357, 85,15,
			2203, 86,15,
			1357, 87,15,
			2203, 87,14,
			1357, 87,13,
			2203, 87,12,
			1357, 87,11,
			2203, 87,10,
			1357, 86,10,
			2203, 85,10,
			1357, 84,10,
			2203, 83,10,
			1357, 82,10,
			2203, 82,11,
			1357, 82,12,
			2203, 82,13,
			1357, 82,14;
	}
	else if (.@map$ == "te_aldecas5") {
		setarray .@data[0],
			2203, 62,12,// TREASURE_BOX_TE
			1357, 62,11,// TREASURE_BOX_TE_10
			2203, 61,11,
			1357, 59,14,
			2203, 60,14,
			1357, 61,14,
			2203, 62,14,
			1357, 63,14,
			2203, 64,14,
			1357, 64,13,
			2203, 64,12,
			1357, 64,11,
			2203, 64,10,
			1357, 64,9,
			2203, 63,9,
			1357, 62,9,
			2203, 61,9,
			1357, 60,9,
			2203, 59,9,
			1357, 59,10,
			2203, 59,11,
			1357, 59,12,
			2203, 59,13;
	}
	else if (.@map$ == "te_prtcas01") {
		setarray .@data[0],
			2203, 8,211,// TREASURE_BOX_TE
			1357, 9,211,// TREASURE_BOX_TE_1
			2203, 10,211,
			1357, 11,211,
			2203, 12,211,
			1357, 13,211,
			2203, 13,209,
			1357, 12,209,
			2203, 11,209,
			1357, 10,209,
			2203, 9,209,
			1357, 8,209,
			2203, 8,207,
			1357, 9,207,
			2203, 10,207,
			1357, 11,207,
			2203, 12,207,
			1357, 13,207,
			2203, 13,206,
			1357, 12,206,
			2203, 11,206,
			1357, 10,206,
			2203, 9,206,
			1357, 8,206;
	}
	else if (.@map$ == "te_prtcas02") {
		setarray .@data[0],
			2203, 201,228,// TREASURE_BOX_TE
			1357, 202,228,// TREASURE_BOX_TE_2
			2203, 202,227,
			1357, 201,227,
			2203, 199,230,
			1357, 200,230,
			2203, 201,230,
			1357, 202,230,
			2203, 203,230,
			1357, 204,230,
			2203, 204,229,
			1357, 204,228,
			2203, 204,227,
			1357, 204,226,
			2203, 204,225,
			1357, 203,225,
			2203, 202,225,
			1357, 201,225,
			2203, 200,225,
			1357, 199,225,
			2203, 199,226,
			1357, 199,227,
			2203, 199,228,
			1357, 199,229;
	}
	else if (.@map$ == "te_prtcas03") {
		setarray .@data[0],
			2203, 187,132,// TREASURE_BOX_TE
			1357, 188,132,// TREASURE_BOX_TE_3
			2203, 188,131,
			1357, 187,131,
			2203, 185,134,
			1357, 186,134,
			2203, 187,134,
			1357, 188,134,
			2203, 189,134,
			1357, 190,134,
			2203, 190,133,
			1357, 190,132,
			2203, 190,131,
			1357, 190,130,
			2203, 190,129,
			1357, 189,129,
			2203, 188,129,
			1357, 187,129,
			2203, 186,129,
			1357, 185,129,
			2203, 185,130,
			1357, 185,131,
			2203, 185,132,
			1357, 185,133;
	}
	else if (.@map$ == "te_prtcas04") {
		setarray .@data[0],
			2203, 269,162,// TREASURE_BOX_TE
			1357, 270,162,// TREASURE_BOX_TE_4
			2203, 270,161,
			1357, 269,161,
			2203, 267,164,
			1357, 268,164,
			2203, 269,164,
			1357, 270,164,
			2203, 271,164,
			1357, 272,164,
			2203, 272,163,
			1357, 272,162,
			2203, 272,161,
			1357, 272,160,
			2203, 272,159,
			1357, 271,159,
			2203, 270,159,
			1357, 269,159,
			2203, 268,159,
			1357, 267,159,
			2203, 267,160,
			1357, 267,161,
			2203, 267,162,
			1357, 267,163;
	}
	else if (.@map$ == "te_prtcas05") {
		setarray .@data[0],
			2203, 275,178,// TREASURE_BOX_TE
			1357, 276,178,// TREASURE_BOX_TE_5
			2203, 276,177,
			1357, 275,177,
			2203, 273,180,
			1357, 274,180,
			2203, 275,180,
			1357, 276,180,
			2203, 277,180,
			1357, 278,180,
			2203, 278,179,
			1357, 278,178,
			2203, 278,177,
			1357, 278,176,
			2203, 278,175,
			1357, 277,175,
			2203, 276,175,
			1357, 275,175,
			2203, 274,175,
			1357, 273,175,
			2203, 273,176,
			1357, 273,177,
			2203, 273,178,
			1357, 273,179;
	}
	.@treasure_num = ( 4 + ( .@economy /5 ) ) *3;// x3 <-> data[] size
	for ( .@i = 0; .@i < getarraysize(.@data) && .@treasure_num > .@i; .@i += 3 )// nb. [4;24] chests
		monster .@map$, .@data[.@i+1], .@data[.@i+2],"Treasure Chest", .@data[.@i],1, strnpcinfo(0)+"::OnTreasureDied";

OnTreasureDied:
	end;
}

// Flag warp Template
//============================================================
function	script	F_flag_woe_TE	{
	.@castle$ = getarg(1);
	.@guild_id = getcastledata( .@castle$,CD_GUILD_ID );
	if (.@guild_id == 0) {
		mes "[ Edict of the Divine Rune-Midgarts Kingdom ]";
		mes " ";
		mes "1. Follow the ordinance of The Divine Rune-Midgarts Kingdom, ";
		mes "We declare that";
		mes "there is no formal master of this castle.";
		mes " ";
		mes "2. To the one who can ";
		mes "overcome all trials";
		mes "and destroy the Emperium,";
		mes "the king will endow the one with";
		mes "ownership of this castle.";
		close;
	}
	if (.@guild_id == getcharid(2) && getarg(0)) {
		mes "[ Echoing Voice ]";
		mes "Brave ones...";
		mes "Do you wish to return to your honorable place?";
		next;
		if (select( "Return to the guild castle.","Quit." ) == 1) {
			if (jobcanentermap(.@castle$) == 0) {
				mes "Tertiary job class and users with expanded levels are not allowed to participate in Training Siege Battles.";
				close;
			}
			if (getcastledata( getarg(1),CD_GUILD_ID ) == getcharid(2))
				warp getarg(1),getarg(2),getarg(3);
			end;
		}
	}
	.@guildname$ = getguildname(.@guild_id);
	.@guildmaster$ = getguildmaster(.@guild_id);
	mes "[ Edict of the Divine Rune-Midgarts Kingdom ]";
	mes " ";
	mes "1. Follow the ordinance of The Divine Rune-Midgarts Kingdom, ";
	mes "we approve that this place is in";
	mes "the private prossession of ^ff0000"+.@guildname$+"^000000 Guild.";
	mes " ";
	mes "2. The guild Master of ^ff0000"+.@guildname$+"^000000 Guild is";
	mes "^ff0000"+.@guildmaster$+"^000000";
	mes "If there is anyone who objects to this,";
	mes "prove your strength and honor with a steel blade in your hand.";
	close;
}

-	script	simple_info_TE	-1,{
	callfunc( "F_flag_woe_TE",0,strnpcinfo(4) );
OnInit:
	if (strnpcinfo(4) != "")
		flagemblem getcastledata( strnpcinfo(4),CD_GUILD_ID );
	end;
}

-	script	flag_te	GUILD_FLAG,{
	end;
OnInit:
	if (strnpcinfo(2) != "")
		flagemblem getcastledata( strnpcinfo(2),CD_GUILD_ID );
	end;
}


// GM NPC
//============================================================
prt_gld,1,4,0	script	#Enterance Button prt	CLEAR_NPC,{
	mes "password";
	next;
	if ( callfunc( "F_GM_NPC", 1854,0, 0,9000 ) < 1 ) {
		mes "That's not right";
		close;
	}
	mes "What do you want to do with the Gloria-bound warp?";
	next;
	switch( select( "Open it","Close it","Cancel","Rental item provided" ) ) {
	case 1:
		mes "Opening the warp.";
		enablenpc "to_gloria";
		close;
	case 2:
		mes "Closing the warp.";
		disablenpc "to_gloria";
		close;
	case 3:
		end;
	case 4:
		mes "You have 300 seconds.";
		rentitem 13083,300;// TE_Woe_Knife
		close;
	}
}

alde_gld,1,4,0	script	#Enterance Button ald	CLEAR_NPC,{
	mes "password";
	next;
	if ( callfunc( "F_GM_NPC", 1854,0, 0,9000 ) < 1 ) {
		mes "That's not right";
		close;
	}
	mes "What do you want to do with the Kafragarten-bound warp?";
	next;
	switch( select( "Open it","Close it","Cancel" ) ) {
	case 1:
		mes "Opening the warp.";
		enablenpc "to_kafragarten";
		close;
	case 2:
		mes "Closing the warp.";
		disablenpc "to_kafragarten";
		close;
	case 3:
		end;
	}
}

// God Item Hervor & Jormungand
sec_in02,20,20,0	script	Test Guide	CLEAR_NPC,{
	mes "Password?";
	next;
	if (callfunc( "F_GM_NPC", 18543792,0, 0,99999999 ) < 1) {
		mes "Aww...";
		close;
	}
	mes "We provide material items needed for testing TE.";
	next;
	switch( select( "Materials for Hervor","Materials for Jormungand" ) ) {
	case 1:
		getitem 6595,2;// Hammer_Of_Velund
		getitem 6596,1;// Anvil_Of_Velund
		getitem 6594,4;// Magic_Bronze_Bullion
		getitem 6597,3;// Bracelet_Of_Velund
		getitem 6602,1;// Secret_Of_Rune
		getitem 6605,1;// Muspellium
		getitem 6604,1;// Essence_Of_Rune
		getitem 2115,1;// Valkyrja's_Shield
		end;
	case 2:
		getitem 6603,4;// Skin_Of_Hraesvelg
		getitem 6599,1;// Spirit_Of_Hugin
		getitem 6598,1;// Rib_Of_Jormungand
		getitem 6601,4;// Chisel_Of_Giant
		getitem 6600,1;// Spirit_Of_Munin
		getitem 6605,1;// Muspellium
		getitem 6604,1;// Essence_Of_Rune
		getitem 1473,1;// Wizardy_Staff
		end;
	}
}
