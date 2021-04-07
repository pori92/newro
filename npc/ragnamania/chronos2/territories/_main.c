//===== rAthena Script =======================================
//= War of Emperium Guild Template File
//===== By: ==================================================
//= L0ne_W0lf
//===== Current Version: =====================================
//= 2.0
//===== Compatible With: =====================================
//= rAthena Project
//===== Description: =========================================
//= [Official Conversion]
//= ----------------------------------------------------------
//= - THIS FILE IS REQUIRED FOR GUILD CASTLES TO FUNCTION.
//= ----------------------------------------------------------
//= - Enables AGIT Manager inside Guild Strongholds.
//=   Visible Name required: Agit
//=   Manages the various functions used in and out of WoE.
//=
//= - Enables Stewards inside Guild Strongholds which let's
//=   the guild master invest in Defense and Economy, and
//=   to summon guardians, a Kafra, and enter master's room.
//=
//= - Guardian Spawning Template
//=   Visible Name required: Guardian
//=   Spawn guardians when guild castle data is recieved.
//=
//= - Enables Kafra Services inside Guild Strongholds.
//=   Visible Name required: Kafra Employee
//=   Storage, Guild Storage, Teleport Service, Cart rental.
//=
//= - Treasure Chest spawning.
//=   Chests will NOT be saved anymore in the event of crashes.
//=   Treasures will NOT spawn on a location that already has
//=   treasure chest spawned.
//===== Additional Comments: =================================
//= 2.0 Fixed an issue where Castle Manager couldn't be fired. [Joseph]
//============================================================

// WoE : Main Functions
//============================================================
-	script	Gld_Agit_Manager::Gld_Agit_Manager	-1,{
	end;

// War of Emperium has started.
OnAgitStart:
	if (strnpcinfo(0) == "Gld_Agit_Manager") end;
	MapRespawnGuildID strnpcinfo(2),GetCastleData(strnpcinfo(2),CD_GUILD_ID),6;
	GvgOn strnpcinfo(2);

// Spawn (fall through), or respawn the Emperium once it has been broken.
OnStartArena:
	// OnAgitStart will fall through and spawn the Emperium.
	if (strnpcinfo(2) == "aldeg_cas01") { setarray .@emproom[0],216,23; }
	else if (strnpcinfo(2) == "aldeg_cas02") { setarray .@emproom[0],213,23; }
	else if (strnpcinfo(2) == "aldeg_cas03") { setarray .@emproom[0],205,31; }
	else if (strnpcinfo(2) == "aldeg_cas04") { setarray .@emproom[0],36,217; }
	else if (strnpcinfo(2) == "aldeg_cas05") { setarray .@emproom[0],27,101; }
	else if (strnpcinfo(2) == "gefg_cas01") { setarray .@emproom[0],197,181; }
	else if (strnpcinfo(2) == "gefg_cas02") { setarray .@emproom[0],176,178; }
	else if (strnpcinfo(2) == "gefg_cas03") { setarray .@emproom[0],244,166; }
	else if (strnpcinfo(2) == "gefg_cas04") { setarray .@emproom[0],174,177; }
	else if (strnpcinfo(2) == "gefg_cas05") { setarray .@emproom[0],194,184; }
	else if (strnpcinfo(2) == "payg_cas01") { setarray .@emproom[0],139,139; }
	else if (strnpcinfo(2) == "payg_cas02") { setarray .@emproom[0],38,25; }
	else if (strnpcinfo(2) == "payg_cas03") { setarray .@emproom[0],269,265; }
	else if (strnpcinfo(2) == "payg_cas04") { setarray .@emproom[0],270,28; }
	else if (strnpcinfo(2) == "payg_cas05") { setarray .@emproom[0],30,30; }
	else if (strnpcinfo(2) == "prtg_cas01") { setarray .@emproom[0],197,197; }
	else if (strnpcinfo(2) == "prtg_cas02") { setarray .@emproom[0],157,174; }
	else if (strnpcinfo(2) == "prtg_cas03") { setarray .@emproom[0],16,220; }
	else if (strnpcinfo(2) == "prtg_cas04") { setarray .@emproom[0],291,14; }
	else if (strnpcinfo(2) == "prtg_cas05") { setarray .@emproom[0],266,266; }
	// Add custom Guild Castles here.
	else {
		end;
	}
	if (!mobcount(strnpcinfo(2),"Agit#"+strnpcinfo(2)+"::OnAgitBreak")) {
		monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Emperium",1288,1,"Agit#"+strnpcinfo(2)+"::OnAgitBreak";
	}
	end;

// The Emperium has been broken.
OnAgitBreak:
	set .@GID,getcharid(2);
	// Show and log error if an unguilded player breaks the Emperium. (Should NEVER happen)
	if (.@GID <= 0) {
		set .@notice$,"Character "+strcharinfo(0)+" ("+getcharid(0)+") broke the Emperium in Castle: "+strnpcinfo(2)+" while guildless. No data will be saved and Emperium respawned.";
 		logmes .@notice$; debugmes .@notice$;
		donpcevent "Agit#"+strnpcinfo(2)+"::OnStartArena";
		end;
	}
	// Adjust Economy Invest Level for Castle
	set .@Economy,GetCastleData(strnpcinfo(2),CD_CURRENT_ECONOMY) - 5;
	if (.@Economy < 0) set .@Economy, 0;
	SetCastleData strnpcinfo(2), CD_CURRENT_ECONOMY, .@Economy;
	// Adjust Defense Invest Level for Castle
	set .@Defence,GetCastleData(strnpcinfo(2),CD_CURRENT_DEFENSE) - 5;
	if (.@Defence < 0) set .@Defence, 0;
	SetCastleData strnpcinfo(2), CD_CURRENT_DEFENSE, .@Defence;

	// Set new Castle Occupant
	SetCastleData strnpcinfo(2),CD_GUILD_ID, .@GID;

	// Announce that the Emperium is destroyed, and respawn all but new castle-occupants.
	//mapannounce strnpcinfo(2),"The emperium has been destroyed.",bc_map|bc_woe,"0x00CCFF",FW_NORMAL,12;
	mapannounce strnpcinfo(2),"Territory conquered by " + strcharinfo(0) + " for " + getguildname(getcharid(2)),bc_map|bc_woe,"0x00CCFF",FW_NORMAL,14;
	MapRespawnGuildID strnpcinfo(2),.@GID,6;

	// Refresh castle data, disable Kafra and reset Invest information.
	donpcevent strnpcinfo(0)+"::OnRecvCastle";
	//donpcevent "CityFlag::OnRecvCastle"; //Biali
	disablenpc "Kafra Staff#"+strnpcinfo(2);
	for( set .@i, CD_INVESTED_ECONOMY; .@i <= CD_ENABLED_KAFRA; set .@i, .@i+1 ) {
		SetCastleData strnpcinfo(2), .@i, 0;
	}
	// Erase Guardian Database information if the new owners do not have Guardian Research.
	if( getgdskilllv(.@GID,10002) == 0 ) {
		for( set .@i, CD_ENABLED_GUARDIAN00; .@i < CD_MAX; set .@i, .@i+1 ) {
			SetCastleData strnpcinfo(2), .@i, 0;
		}
	}
	// Respawn the Emperium, and display new owners.
	sleep 500; // Slow down script execution slightly.
	if( agitcheck() )
		donpcevent "Agit#"+strnpcinfo(2)+"::OnStartArena";
	sleep 7000;
	announce "The [" + getcastlename(strnpcinfo(2)) + "] territory has been conquered by [" + getguildName(.@GID) + "].",bc_all|bc_woe,"0x00CCFF",FW_NORMAL,14;
	end;

// War of Emperium has ended.
announce "The [" + getcastlename(strnpcinfo(2)) + "] territory has been conquered by [ "+.@breaker$+" ] of [" + getguildName(.@GID) + "].",bc_all,"0x00CCFF",FW_NORMAL,14;
OnAgitEnd:
	if (strnpcinfo(0) == "Gld_Agit_Manager") end;
	GvgOff strnpcinfo(2);
	// If the castle has no owner at the end of WoE, do not kill Emperium.
	if (GetCastleData(strnpcinfo(2),CD_GUILD_ID)) {
		KillMonster strnpcinfo(2),"Agit#"+strnpcinfo(2)+"::OnAgitBreak";
	}
	end;

// Occupying Guild has been disbanded.
OnGuildBreak:
	if (strnpcinfo(0) == "Gld_Agit_Manager") end;
	// Kill guardians, disable the Kafra, and set owner to 0.
	killmonster strnpcinfo(2),"Guardian#"+strnpcinfo(2)+"::OnGuardianDied";
	disablenpc "Kafra Staff#"+strnpcinfo(2);
	SetCastleData strnpcinfo(2),CD_GUILD_ID,0;
	// Wait before refreshing guild information.
	sleep 7000;
	Announce "Territory [" + GetCastleName(strnpcinfo(2)) + "] has been abandoned.",0;
	donpcevent strnpcinfo(0)+"::OnRecvCastle";
	end;

OnAgitInit:
OnRecvCastle:
	if (strnpcinfo(0) == "Gld_Agit_Manager") end;
	// Spawn Monsters if the castle is empty.
	set .@GID, GetCastleData(strnpcinfo(2),CD_GUILD_ID);
	if (.@GID == 0) {
		killmonsterall strnpcinfo(2);
		if (compare(strnpcinfo(2),"aldeg")) {
			// Normal Spawns
			monster strnpcinfo(2),0,0,"Evil Druid",1117,10;
			monster strnpcinfo(2),0,0,"Khalitzburg",1132,4;
			monster strnpcinfo(2),0,0,"Abysmal Knight",1219,2;
			monster strnpcinfo(2),0,0,"Executioner",1205,1;
			monster strnpcinfo(2),0,0,"Penomena",1216,10;
			monster strnpcinfo(2),0,0,"Alarm",1193,18;
			monster strnpcinfo(2),0,0,"Clock",1269,9;
			monster strnpcinfo(2),0,0,"Raydric Archer",1276,7;
			monster strnpcinfo(2),0,0,"Wanderer",1208,3;
			monster strnpcinfo(2),0,0,"Alice",1275,1;
			monster strnpcinfo(2),0,0,"Bloody Knight",1268,1;
			monster strnpcinfo(2),0,0,"Dark Lord",1272,1;
			// Set Emperium room spawn coordinates and spawn monsters.
			if (strnpcinfo(2) == "aldeg_cas01") { setarray .@emproom[0],216,23; }
			else if (strnpcinfo(2) == "aldeg_cas02") { setarray .@emproom[0],213,23; }
			else if (strnpcinfo(2) == "aldeg_cas03") { setarray .@emproom[0],205,31; }
			else if (strnpcinfo(2) == "aldeg_cas04") { setarray .@emproom[0],36,217; }
			else if (strnpcinfo(2) == "aldeg_cas05") { setarray .@emproom[0],27,101; }
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Dark Lord",1272,1;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Tower Keeper",1270,4;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Bloody Knight",1268,1;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Abysmal Knight",1219,1;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Raydric Archer",1276,5;
		}
		else if (compare(strnpcinfo(2),"gefg")) {
			// Normal Spawns
			monster strnpcinfo(2),0,0,"Evil Druid",1117,10;
			monster strnpcinfo(2),0,0,"Wind Ghost",1263,11;
			monster strnpcinfo(2),0,0,"Bathory",1102,10;
			monster strnpcinfo(2),0,0,"Jakk",1130,10;
			monster strnpcinfo(2),0,0,"Marduk",1140,20;
			monster strnpcinfo(2),0,0,"Raydric",1163,9;
			monster strnpcinfo(2),0,0,"Alice",1275,1;
			monster strnpcinfo(2),0,0,"Abysmal Knight",1219,1;
			monster strnpcinfo(2),0,0,"Moonlight Flower",1150,1;
			monster strnpcinfo(2),0,0,"Phreeoni",1159,1;
			// Set Emperium room spawn coordinates and spawn monsters.
			if (strnpcinfo(2) == "gefg_cas01") { setarray .@emproom[0],197,181; }
			else if (strnpcinfo(2) == "gefg_cas02") { setarray .@emproom[0],176,178; }
			else if (strnpcinfo(2) == "gefg_cas03") { setarray .@emproom[0],244,166; }
			else if (strnpcinfo(2) == "gefg_cas04") { setarray .@emproom[0],174,177; }
			else if (strnpcinfo(2) == "gefg_cas05") { setarray .@emproom[0],194,184; }
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Mysteltainn",1203,1;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Orc Hero",1087,1;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"High Orc",1213,10;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Orc Archer",1189,10;
		}
		else if (compare(strnpcinfo(2),"payg")) {
			// Normal Spawns
			monster strnpcinfo(2),0,0,"Greatest General",1277,9;
			monster strnpcinfo(2),0,0,"Wanderer",1208,10;
			monster strnpcinfo(2),0,0,"Mutant Dragonoid",1262,5;
			monster strnpcinfo(2),0,0,"Bathory",1102,5;
			monster strnpcinfo(2),0,0,"Moonlight Flower",1150,1;
			monster strnpcinfo(2),0,0,"Eddga",1115,1;
			monster strnpcinfo(2),0,0,"Horong",1129,11;
			monster strnpcinfo(2),0,0,"Raydric Archer",1276,5;
			monster strnpcinfo(2),0,0,"Kobold Archer",1282,4;
			monster strnpcinfo(2),0,0,"Gargoyle",1253,5;
			// Set Emperium room spawn coordinates and spawn monsters.
			if (strnpcinfo(2) == "payg_cas01") { setarray .@emproom[0],139,139; }
			else if (strnpcinfo(2) == "payg_cas02") { setarray .@emproom[0],38,25; }
			else if (strnpcinfo(2) == "payg_cas03") { setarray .@emproom[0],269,265; }
			else if (strnpcinfo(2) == "payg_cas04") { setarray .@emproom[0],270,28; }
			else if (strnpcinfo(2) == "payg_cas05") { setarray .@emproom[0],30,30; }
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Moonlight Flower",1150,1;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Eddga",1115,1;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Wanderer",1208,6;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Raydric Archer",1276,5;
		}
		else if (compare(strnpcinfo(2),"prtg")) {
			// Normal Spawns
			monster strnpcinfo(2),0,0,"Raydric",1163,1;
			monster strnpcinfo(2),0,0,"Khalitzburg",1132,10;
			monster strnpcinfo(2),0,0,"Abysmal Knight",1219,5;
			monster strnpcinfo(2),0,0,"Bloody Knight",1268,5;
			monster strnpcinfo(2),0,0,"Stormy Knight",1251,1;
			monster strnpcinfo(2),0,0,"Hatii",1252,1;
			monster strnpcinfo(2),0,0,"Raydric Archer",1276,5;
			monster strnpcinfo(2),0,0,"Gryphon",1259,2;
			monster strnpcinfo(2),0,0,"Chimera",1283,3;
			monster strnpcinfo(2),0,0,"Alice",1275,1;
			monster strnpcinfo(2),0,0,"Zealotus",1200,1;
			// Set Emperium room spawn coordinates and spawn monsters.
			if (strnpcinfo(2) == "prtg_cas01") { setarray .@emproom[0],197,197; }
			else if (strnpcinfo(2) == "prtg_cas02") { setarray .@emproom[0],157,174; }
			else if (strnpcinfo(2) == "prtg_cas03") { setarray .@emproom[0],16,220; }
			else if (strnpcinfo(2) == "prtg_cas04") { setarray .@emproom[0],291,14; }
			else if (strnpcinfo(2) == "prtg_cas05") { setarray .@emproom[0],266,266; }
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Guardian Knight",1268,1;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Guardian Master",1251,1;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Hatii",1252,1;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Guardian Knight",1219,1;
			monster strnpcinfo(2),.@emproom[0],.@emproom[1],"Raydric Archer",1276,5;
		}
		// Add custom Guild Castles here.
		else {
			end;
		}
		donpcevent "Agit#"+strnpcinfo(2)+"::OnStartArena";
		// Disable Kafra Staff...
		disablenpc "Kafra Staff#"+strnpcinfo(2);
		end;
	}
	else {
		// Otherwise place the guild emblem on flags.
		if (strnpcinfo(2) == "aldeg_cas01") { donpcevent "::OnRecvCastleA01"; }
		else if (strnpcinfo(2) == "aldeg_cas02") { donpcevent "::OnRecvCastleA02"; }
		else if (strnpcinfo(2) == "aldeg_cas03") { donpcevent "::OnRecvCastleA03"; }
		else if (strnpcinfo(2) == "aldeg_cas04") { donpcevent "::OnRecvCastleA04"; }
		else if (strnpcinfo(2) == "aldeg_cas05") { donpcevent "::OnRecvCastleA05"; }
		else if (strnpcinfo(2) == "gefg_cas01") { donpcevent "::OnRecvCastleG01"; }
		else if (strnpcinfo(2) == "gefg_cas02") { donpcevent "::OnRecvCastleG02"; }
		else if (strnpcinfo(2) == "gefg_cas03") { donpcevent "::OnRecvCastleG03"; }
		else if (strnpcinfo(2) == "gefg_cas04") { donpcevent "::OnRecvCastleG04"; }
		else if (strnpcinfo(2) == "gefg_cas05") { donpcevent "::OnRecvCastleG05"; }
		else if (strnpcinfo(2) == "payg_cas01") { donpcevent "::OnRecvCastlePy01"; }
		else if (strnpcinfo(2) == "payg_cas02") { donpcevent "::OnRecvCastlePy02"; }
		else if (strnpcinfo(2) == "payg_cas03") { donpcevent "::OnRecvCastlePy03"; }
		else if (strnpcinfo(2) == "payg_cas04") { donpcevent "::OnRecvCastlePy04"; }
		else if (strnpcinfo(2) == "payg_cas05") { donpcevent "::OnRecvCastlePy05"; }
		else if (strnpcinfo(2) == "prtg_cas01") { donpcevent "::OnRecvCastlePt01"; }
		else if (strnpcinfo(2) == "prtg_cas02") { donpcevent "::OnRecvCastlePt02"; }
		else if (strnpcinfo(2) == "prtg_cas03") { donpcevent "::OnRecvCastlePt03"; }
		else if (strnpcinfo(2) == "prtg_cas04") { donpcevent "::OnRecvCastlePt04"; }
		else if (strnpcinfo(2) == "prtg_cas05") { donpcevent "::OnRecvCastlePt05"; }
		// Add custom Guild Castles here.
		else {
			end;
		}
		// And load purchased Guardian in castles.
		donpcevent "Guardian#"+strnpcinfo(2)+"::OnSpawnGuardians";
		// And display Kafra if purchased.
		if (GetCastleData(strnpcinfo(2),CD_ENABLED_KAFRA) < 1) disablenpc "Kafra Staff#"+strnpcinfo(2);
	}
	end;
}

// WoE : Guild Kafras
//============================================================
-	script	Kafra Staff#woe::guildkafra	-1,{

	set .@GID,GetCastleData(strnpcinfo(2),CD_GUILD_ID);

	if (compare(strnpcinfo(2),"aldeg")) {
		setarray .@destination$[0],"Al De Baran","aldebaran";
		setarray .@coordinates[0],132,103;
	}
	else if (compare(strnpcinfo(2),"gefg")) {
		setarray .@destination$[0],"Geffen","geffen";
		setarray .@coordinates[0],120,39;
	}
	else if (compare(strnpcinfo(2),"payg")) {
		setarray .@destination$[0],"Payon","payon";
		setarray .@coordinates[0],70,100;
	}
	else if (compare(strnpcinfo(2),"prtg")) {
		setarray .@destination$[0],"Prontera","prontera";
		setarray .@coordinates[0],278,211;
	}
	// Add custom Guild Castles here.
	else {
		end;
	}

	cutin "kafra_01",2;
	if (getcharid(2) == .@GID) {
		mes "[Kafra Employee]";
		mes "Welcome. ^ff0000" + GetGuildName(.@GID) + "^000000 Member.";
		mes "The Kafra Corporation will stay with you wherever you go.";
		next;
		switch (select("Use Storage:Use Teleport Service:Rent a Pushcart:Cancel")) {
		case 1:
			if(!callfunc("F_CanOpenStorage")){
				mes "[Kafra Employee]";
				mes "I'm sorry, but you";
				mes "need the Novice's";
				mes "Basic Skill Level 6 to";
				mes "use the Storage Service.";
				close2;
				cutin "",255;
				end;
			}
			mes "[Kafra Employee]";
			mes "Here, let me open";
			mes "your Storage for you.";
			mes "Thank you for using";
			mes "the Kafra Service.";
			close2;
			cutin "",255;
			openstorage;
			end;
		case 2:
			mes "[Kafra Employee]";
			mes "Please choose";
			mes "your destination.";
			next;
			switch (select(.@destination$+" -> 200z:Cancel")) {
			case 1:
				if (Zeny < 200) {
					mes "[Kafra Employee]";
					mes "I'm sorry, but you don't have";
					mes "enough zeny for the Teleport";
					mes "Service. The fee to teleport";
					mes "to "+.@destination$+" is 200 zeny.";
					close2;
					cutin "",255;
					end;
				}
				set Zeny, Zeny - 200;
				set RESRVPTS,RESRVPTS+20;
				close2;
				warp .@destination$[1],.@coordinates[0],.@coordinates[1];
				end;
			case 2:
				close2;
				cutin "",255;
				end;
			}
		case 3:
			if (BaseClass != Job_Merchant) {
				mes "[Kafra Employee]";
				mes "I'm sorry, but the";
				mes "Pushcart rental service";
				mes "is only available to Merchants,";
				mes "Blacksmiths, Master Smiths,";
				mes "Alchemists, Biochemists,";
				mes "Mechanics and Geneticists.";
				close2;
				cutin "",255;
				end;
			}
			if (checkcart()) {
				mes "[Kafra Employee]";
				mes "You already have";
				mes "a Pushcart equipped.";
				mes "Unfortunately, we can't";
				mes "rent more than one to";
				mes "each customer at a time.";
				close2;
				cutin "",255;
				end;
			}
			mes "[Kafra Employee]";
			mes "The Pushcart rental";
			mes "fee is 800 zeny. Would";
			mes "you like to rent a Pushcart?";
			next;
			switch (select("Rent a Pushcart.:Cancel")) {
			case 1:
				if (Zeny < 800) {
					mes "[Kafra Employee]";
					mes "I'm sorry, but you";
					mes "don't have enough";
					mes "zeny to pay the Pushcart";
					mes "rental fee of 800 zeny.";
					close2;
					cutin "",255;
					end;
				}
				set RESRVPTS,RESRVPTS+80;
				set Zeny, Zeny - 800;
				setcart;
				close2;
				cutin "",255;
				end;
			case 2:
				close2;
				cutin "",255;
				end;
			}
		case 4:
			mes "[Kafra Employee]";
			mes "We, here at Kafra Corporation,";
			mes "are always endeavoring to provide you with the best services. We hope that we meet your adventuring needs and standards of excellence.";
			close2;
			cutin "",255;
			end;
		}
	}
	mes "[Kafra Employee]";
	mes "I am instructed to only offer my services to the ^ff0000"+GetGuildName(.@GID)+"^000000 Guild. Please try another Kafra Employee around here. Sorry for the inconvenience.";
	close2;
	cutin "",255;
	end;
}

// WoE : Castle Managers
//============================================================
-	script	Castle Manager#cm::cm	-1,{

	set .@GID,GetCastleData(strnpcinfo(2),CD_GUILD_ID);

	// .@guardiantype = Defines the types of guardians per castle basis.
	// 1 - Soldier Guardian, 2 - Archer Guardian, 3 - Knight Guardian
	// .@guardianposx = Define the x spawn point for each uardian.
	// [0] = 1st guardian's x spawn point.
	// .@guardianposy = Define the y spawn point for each guardian.
	// [0] = 1st guardian's y spawn point.
	// .@masterroom = Defines the coordinates of the Treasure Room.
	if (strnpcinfo(2) == "aldeg_cas01") { 
		setarray .@guardiantype[0],1,2,2,2,2,3,3,3;
		setarray .@guardianposx[0],17,39,38,45,21,218,213,73;
		setarray .@guardianposy[0],218,208,196,228,194,24,24,70;
		setarray .@masterroom[0],113,223;
	}
	else if (strnpcinfo(2) == "aldeg_cas02") {
		setarray .@guardiantype[0],3,3,3,1,1,2,2,2;
		setarray .@guardianposx[0],27,88,117,60,51,21,36,210;
		setarray .@guardianposy[0],184,43,46,202,183,177,183,7;
		setarray .@masterroom[0],134,225;
	}
	else if (strnpcinfo(2) == "aldeg_cas03") {
		setarray .@guardiantype[0],3,3,1,1,1,2,2,2;
		setarray .@guardianposx[0],90,116,86,116,64,212,195,110;
		setarray .@guardianposy[0],112,112,120,76,103,160,151,217;
		setarray .@masterroom[0],229,267;
	}
	else if (strnpcinfo(2) == "aldeg_cas04") {
		setarray .@guardiantype[0],2,2,2,1,1,1,3,3;
		setarray .@guardianposx[0],187,192,148,145,169,198,48,55;
		setarray .@guardianposy[0],100,42,88,209,53,77,72,88;
		setarray .@masterroom[0],83,17;
	}
	else if (strnpcinfo(2) == "aldeg_cas05") {
		setarray .@guardiantype[0],2,2,1,1,3,3,3,3;
		setarray .@guardianposx[0],51,188,157,157,27,145,156,41;
		setarray .@guardianposy[0],202,79,192,74,221,78,73,112;
		setarray .@masterroom[0],64,8;
	}
	// Geffen (Britoniah) Castles
	else if (strnpcinfo(2) == "gefg_cas01") {
		setarray .@guardiantype[0],1,1,1,2,2,3,3,3;
		setarray .@guardianposx[0],67,184,62,36,50,50,189,200;
		setarray .@guardianposy[0],179,20,41,186,186,67,41,167;
		setarray .@masterroom[0],152,117;
	}
	else if (strnpcinfo(2) == "gefg_cas02") {
		setarray .@guardiantype[0],1,1,1,2,2,3,3,3;
		setarray .@guardianposx[0],64,56,166,35,20,19,166,159;
		setarray .@guardianposy[0],168,41,25,148,150,41,42,188;
		setarray .@masterroom[0],145,115;
	}
	else if (strnpcinfo(2) == "gefg_cas03") {
		setarray .@guardiantype[0],2,2,1,1,1,3,3,3;
		setarray .@guardianposx[0],48,113,48,157,243,157,234,238;
		setarray .@guardianposy[0],176,214,207,62,41,45,25,160;
		setarray .@masterroom[0],275,289;
	}
	else if (strnpcinfo(2) == "gefg_cas04") {
		setarray .@guardiantype[0],2,2,1,1,1,3,3,3;
		setarray .@guardianposx[0],53,31,49,29,147,57,160,148;
		setarray .@guardianposy[0],191,178,220,46,65,46,50,189;
		setarray .@masterroom[0],116,123;
	}
	else if (strnpcinfo(2) == "gefg_cas05") {
		setarray .@guardiantype[0],2,2,1,1,1,3,3,3;
		setarray .@guardianposx[0],45,71,72,66,177,66,177,193;
		setarray .@guardianposy[0],149,163,142,47,50,17,35,166;
		setarray .@masterroom[0],149,106;
	}
	// Payon (Baulder) Castles
	else if (strnpcinfo(2) == "payg_cas01") {
		setarray .@guardiantype[0],2,2,2,2,2,2,2,3;
		setarray .@guardianposx[0],229,225,222,99,65,36,51,138;
		setarray .@guardianposy[0],92,80,111,45,31,127,144,133;
		setarray .@masterroom[0],295,8;
	}
	else if (strnpcinfo(2) == "payg_cas02") {
		setarray .@guardiantype[0],2,2,2,2,2,2,2,3;
		setarray .@guardianposx[0],237,228,210,57,42,287,264,27;
		setarray .@guardianposy[0],54,72,41,241,241,257,272,20;
		setarray .@masterroom[0],141,149;
	}
	else if (strnpcinfo(2) == "payg_cas03") {
		setarray .@guardiantype[0],2,2,2,2,2,2,2,3;
		setarray .@guardianposx[0],245,269,36,41,39,19,37,268;
		setarray .@guardianposy[0],37,51,39,39,65,276,277,244;
		setarray .@masterroom[0],163,167;
	}
	else if (strnpcinfo(2) == "payg_cas04") {
		setarray .@guardiantype[0],2,2,2,2,2,2,2,3;
		setarray .@guardianposx[0],251,232,231,32,32,35,36,270;
		setarray .@guardianposy[0],212,212,175,287,232,45,17,41;
		setarray .@masterroom[0],151,47;
	}
	else if (strnpcinfo(2) == "payg_cas05") {
		setarray .@guardiantype[0],2,2,2,2,2,2,2,3;
		setarray .@guardianposx[0],19,33,266,266,263,263,250,36;
		setarray .@guardianposy[0],279,260,234,279,37,21,22,36;
		setarray .@masterroom[0],153,137;
	}
	// Prontera (Valkyrie Realms) Castles
	else if (strnpcinfo(2) == "prtg_cas01") {
		setarray .@guardiantype[0],1,1,1,2,2,3,3,3;
		setarray .@guardianposx[0],182,182,153,59,50,184,196,107;
		setarray .@guardianposy[0],62,116,86,28,36,183,189,179;
		setarray .@masterroom[0],15,209;
	}
	else if (strnpcinfo(2) == "prtg_cas02") {
		setarray .@guardiantype[0],3,3,3,1,1,2,2,2;
		setarray .@guardianposx[0],161,153,178,71,49,64,7,75;
		setarray .@guardianposy[0],161,161,44,75,28,186,196,175;
		setarray .@masterroom[0],207,229;
	}
	else if (strnpcinfo(2) == "prtg_cas03") {
		setarray .@guardiantype[0],3,3,3,1,1,2,2,2;
		setarray .@guardianposx[0],191,137,45,50,41,191,179,191;
		setarray .@guardianposy[0],190,190,99,87,87,42,43,72;
		setarray .@masterroom[0],190,130;
	}
	else if (strnpcinfo(2) == "prtg_cas04") {
		setarray .@guardiantype[0],3,3,3,1,1,1,2,2;
		setarray .@guardianposx[0],276,274,246,38,29,33,78,36;
		setarray .@guardianposy[0],14,35,246,240,240,258,48,61;
		setarray .@masterroom[0],275,160;
	}
	else if (strnpcinfo(2) == "prtg_cas05") {
		setarray .@guardiantype[0],3,3,3,1,1,1,2,2;
		setarray .@guardianposx[0],266,287,245,236,251,278,32,44;
		setarray .@guardianposy[0],262,280,250,63,63,253,253,248;
		setarray .@masterroom[0],281,176;
	}
	// Add custom Guild Castles here.
	else {
		end;
	}

	if (.@GID == 0) {
		mes "["+strnpcinfo(1)+"]";
		mes "I have been waiting for a master to fulfill my destiny.";
		mes "Brave soul... fate will guide you towards your future...";
		close;
	}
	if (is_guild_leader(.@GID) == false) {
		mes "["+strnpcinfo(1)+"]";
		mes "No matter how much you pester me, I'll still follow my master ^ff0000"+GetGuildMaster(.@GID)+"^000000. Where are the Guardians?! Send these ruffians away right now!";
		close;
	}
	mes "["+strnpcinfo(1)+"]";
	mes "Welcome. My honorable master, ^ff0000"+strcharinfo(0)+"^000000...";
	mes "Your humble servent, "+strnpcinfo(1)+", is here to serve you.";
	next;
	switch (select("Castle briefing:Invest in commercial growth:Invest in Castle Defenses:Summon Guardian:Hire / Fire a Kafra Employee:Go into Master's room")) {
	case 1:
		mes "["+strnpcinfo(1)+"]";
		mes "I will report the Castle briefing, Master.";
		mes " ";
		mes "^0000ffNow, the commercial growth level is "+GetCastleData(strnpcinfo(2),CD_CURRENT_ECONOMY)+".";
		if (GetCastleData(strnpcinfo(2),CD_INVESTED_ECONOMY)) {
			mes " You invested "+GetCastleData(strnpcinfo(2),CD_INVESTED_ECONOMY)+" times in past 1 day.";
		}
		mes " Now, the Castle Defense level is "+GetCastleData(strnpcinfo(2),CD_CURRENT_DEFENSE)+".^000000";
		if (GetCastleData(strnpcinfo(2),CD_INVESTED_DEFENSE)) {
			mes " ^0000ff- You invested "+GetCastleData(strnpcinfo(2),CD_INVESTED_DEFENSE)+" times in past 1 day.^000000";
		}
		mes " ";
		mes "That's all I have to report, Master.";
		close;
	case 2:
		set .@Economy,GetCastleData(strnpcinfo(2),CD_CURRENT_ECONOMY);
		if (.@Economy < 6) { set .@eco_invest,5000; }
		else if ((.@Economy >= 6) && (.@Economy <= 10)) { set .@eco_invest,10000; }
		else if ((.@Economy >= 11) && (.@Economy <= 15)) { set .@eco_invest,20000; }
		else if ((.@Economy >= 16) && (.@Economy <= 20)) { set .@eco_invest,35000; }
		else if ((.@Economy >= 21) && (.@Economy <= 25)) { set .@eco_invest,55000; }
		else if ((.@Economy >= 26) && (.@Economy <= 30)) { set .@eco_invest,80000; }
		else if ((.@Economy >= 31) && (.@Economy <= 35)) { set .@eco_invest,110000; }
		else if ((.@Economy >= 36) && (.@Economy <= 40)) { set .@eco_invest,145000; }
		else if ((.@Economy >= 41) && (.@Economy <= 45)) { set .@eco_invest,185000; }
		else if ((.@Economy >= 46) && (.@Economy <= 50)) { set .@eco_invest,230000; }
		else if ((.@Economy >= 51) && (.@Economy <= 55)) { set .@eco_invest,280000; }
		else if ((.@Economy >= 56) && (.@Economy <= 60)) { set .@eco_invest,335000; }
		else if ((.@Economy >= 61) && (.@Economy <= 65)) { set .@eco_invest,395000; }
		else if ((.@Economy >= 66) && (.@Economy <= 70)) { set .@eco_invest,460000; }
		else if ((.@Economy >= 71) && (.@Economy <= 75)) { set .@eco_invest,530000; }
		else if ((.@Economy >= 76) && (.@Economy <= 80)) { set .@eco_invest,605000; }
		else if ((.@Economy >= 81) && (.@Economy <= 85)) { set .@eco_invest,685000; }
		else if ((.@Economy >= 86) && (.@Economy <= 90)) { set .@eco_invest,770000; }
		else if ((.@Economy >= 91) && (.@Economy <= 95)) { set .@eco_invest,860000; }
		else if ((.@Economy >= 96) && (.@Economy <= 100)) { set .@eco_invest,955000; }
		//Quadruple the cost of investing if you've already invested once.
		if (GetCastleData(strnpcinfo(2),CD_INVESTED_ECONOMY)) {
			set .@eco_invest,.@eco_invest*4;
		}
		mes "["+strnpcinfo(1)+"]";
		mes "If you invest in commercial growth, the quantity of goods made by the guild will increase. Therfore, if you consider our future, investments will be a necessity.";
		mes " ";
		mes "Initially, you are able to invest just once but if you pay more money, you will be able to invest twice.";
		if (.@Economy >= 100) {
			mes " ";
			mes "^ff0000The commercial growth level of our Castle is at it's highest, 100%. No more investments are needed. Just as I have expected from a great economist like you, Master.^000000";
			close;
		}
		if (GetCastleData(strnpcinfo(2),CD_INVESTED_ECONOMY) >= 2) {
			mes " ";
			mes "^ff0000You have already invested twice today. You cannot invest any more.^000000 I expect riches of the guild to grow at a high rate.";
			close;
		}
		if (GetCastleData(strnpcinfo(2),CD_INVESTED_ECONOMY) == 0) {
			mes " ";
			mes "The current investment amount required is ^ff0000"+.@eco_invest+"^000000 zeny. Will you invest?";
		}
		else {
			mes " ";
			mes "You've invested once today... if you wish to invest once more, ^ff0000"+.@eco_invest+"^000000 more zeny will be needed.";
		}
		next;
		switch (select("Invest in commercial growth:Cancel")) {
		case 1:
			if (Zeny < .@eco_invest) {
				mes "["+strnpcinfo(1)+"]";
				mes "I'm sorry but there is not enough zeny to invest. You will have to try again when you have the funds, Master.";
				close;
			}
			set Zeny, Zeny - .@eco_invest;
			SetCastleData strnpcinfo(2),CD_INVESTED_ECONOMY,GetCastleData(strnpcinfo(2),CD_INVESTED_ECONOMY)+1;
			mes "[ "+strnpcinfo(1)+"]";
			mes "We finished the investment safely. I expect that our growth level will be increased by tomorrow.";
			close;
		case 2:
			mes "["+strnpcinfo(1)+"]";
			mes "I'll do as you bid, my master... There is no hurry. We will do our best.";
			close;
		}
	case 3:
		set .@Defence,GetCastleData(strnpcinfo(2),CD_CURRENT_DEFENSE);
		if (.@Defence < 6) { set .@def_invest,10000; }
		else if ((.@Defence >= 6) && (.@Defence <= 10)) { set .@def_invest,20000; }
		else if ((.@Defence >= 11) && (.@Defence <= 15)) { set .@def_invest,40000; }
		else if ((.@Defence >= 16) && (.@Defence <= 20)) { set .@def_invest,70000; }
		else if ((.@Defence >= 21) && (.@Defence <= 25)) { set .@def_invest,110000; }
		else if ((.@Defence >= 26) && (.@Defence <= 30)) { set .@def_invest,160000; }
		else if ((.@Defence >= 31) && (.@Defence <= 35)) { set .@def_invest,220000; }
		else if ((.@Defence >= 36) && (.@Defence <= 40)) { set .@def_invest,290000; }
		else if ((.@Defence >= 41) && (.@Defence <= 45)) { set .@def_invest,370000; }
		else if ((.@Defence >= 46) && (.@Defence <= 50)) { set .@def_invest,460000; }
		else if ((.@Defence >= 51) && (.@Defence <= 55)) { set .@def_invest,560000; }
		else if ((.@Defence >= 56) && (.@Defence <= 60)) { set .@def_invest,670000; }
		else if ((.@Defence >= 61) && (.@Defence <= 65)) { set .@def_invest,790000; }
		else if ((.@Defence >= 66) && (.@Defence <= 70)) { set .@def_invest,920000; }
		else if ((.@Defence >= 71) && (.@Defence <= 75)) { set .@def_invest,1060000; }
		else if ((.@Defence >= 76) && (.@Defence <= 80)) { set .@def_invest,1210000; }
		else if ((.@Defence >= 81) && (.@Defence <= 85)) { set .@def_invest,1370000; }
		else if ((.@Defence >= 86) && (.@Defence <= 90)) { set .@def_invest,1540000; }
		else if ((.@Defence >= 91) && (.@Defence <= 95)) { set .@def_invest,1720000; }
		else if ((.@Defence >= 96) && (.@Defence <= 100)) { set .@def_invest,1910000; }
		//Quadruple the cost of investing if you've already invested once.
		if (GetCastleData(strnpcinfo(2),CD_INVESTED_DEFENSE)) {
			set .@def_invest,.@def_invest*4;
		}
		mes "["+strnpcinfo(1)+"]";
		mes "If you raise Castle Defenses, the durability of Guardians and the Emperium will increase. Therefore, if you consider our coming battles, some investment in this area will be required.";
		mes " ";
		mes "Originally you can invest just once but if you pay more money, you can invest twice.";
		if (.@Defence >= 100) {
			mes " ";
			mes "^ff0000But the Castle Defense level of our Castle is at it's highest, 100%. No more investments are needed. Just as I have expected from a great strategist like you, Master.^000000";
			close;
		}
		if (GetCastleData(strnpcinfo(2),CD_INVESTED_DEFENSE) >= 2) {
			mes " ";
			mes "^ff0000You have already invested twice today. You cannot invest any more.^000000 I expect the Defenses of the guild to grow at a high rate.";
			close;
		}
		if (GetCastleData(strnpcinfo(2),CD_INVESTED_DEFENSE) == 0) {
			mes " ";
			mes "The current investment amount required is ^ff0000"+.@def_invest+"^000000 zeny. Will you invest?";
		}
		else {
			mes " ";
			mes "You've invested once today... if you wish to invest once more, ^ff0000"+.@def_invest+"^000000 more zeny will be needed.";
		}
		next;
		switch (select("Invest in Castle Defenses.:Cancel")) {
		case 1:
			if (Zeny < .@def_invest) {
				mes "["+strnpcinfo(1)+"]";
				mes "I'm sorry but there is not enough zeny to invest. You will have to try again when you have the funds, Master.";
				close;
			}
			set Zeny, Zeny - .@def_invest;
			SetCastleData strnpcinfo(2),CD_INVESTED_DEFENSE,GetCastleData(strnpcinfo(2),CD_INVESTED_DEFENSE)+1;
			mes "[ "+strnpcinfo(1)+"]";
			mes "We finished the investment safely. I expect that our Castle Defense level will be increased by tomorrow.";
			close;
		case 2:
			mes "["+strnpcinfo(1)+"]";
			mes "I'll do as you bid, my master... There is no hurry. We will do our best.";
			close;
		}
	case 4:
		mes "["+strnpcinfo(1)+"]";
		mes "Will you summon a Guardian? It'll be a protector to defend us loyally.";
		mes "Please select a guardian to defend us.";
		next;
		for( set .@i, 0; .@i <= 7 ; set .@i, .@i+1 ) {
			if (.@guardiantype[.@i] == 1) { set .@type$,"Guardian Soldier"; }
			else if (.@guardiantype[.@i] == 2) { set .@type$,"Guardian Archer"; }
			else { set .@type$,"Guardian Knight"; }
			if (guardianinfo(strnpcinfo(2),.@i,0)) {
				setarray .@gname$[.@i], .@type$ + " - Implemented (" + guardianinfo(strnpcinfo(2),.@i,2) + "/" + guardianinfo(strnpcinfo(2),.@i,1) + ")";
			}
			else {
				setarray .@gname$[.@i], .@type$ + " - Not Implemented";
			}
		}
		set .@menu$,.@gname$[0]+":"+.@gname$[1]+":"+.@gname$[2]+":"+.@gname$[3]+":"+.@gname$[4]+":"+.@gname$[5]+":"+.@gname$[6]+":"+.@gname$[7];
		set .@GDnum,select(.@menu$)+9;
		mes "["+strnpcinfo(1)+"]";
		mes "Will you summon the chosen guardian? 10,000 zeny are required to summon a Guardian.";
		next;
		switch (select("Summon:Cancel")) {
		case 1:
			if (getgdskilllv(.@GID,10002) == 0) {
				mes "["+strnpcinfo(1)+"]";
				mes "Master, we have not the resources to Summon the Guardian. If you want to accumulate them, you have to learn the Guild skill. We failed to summon the Guardian.";
				close;
			}
			if (GetCastleData(strnpcinfo(2),.@GDnum) == 1) {
				mes "["+strnpcinfo(1)+"]";
				mes "Master, you already have summoned that Guardian. We cannot summon another.";
				close;
			}
			if (Zeny < 10000) {
				mes "["+strnpcinfo(1)+"]";
				mes "Well... I'm sorry but we don't have funds to summon the Guardian. We failed to summon the Guardian.";
				close;
			}
			set Zeny, Zeny - 10000;
			SetCastleData strnpcinfo(2),.@GDnum,1; // mark as 'installed'
			set .@UseGID,.@GDnum - 10;
			if (.@guardiantype[.@UseGID] == 1) { set .@type,1287; }
			else if (.@guardiantype[.@UseGID] == 2) { set .@type,1285; }
			else { set .@type,1286; }
			guardian strnpcinfo(2),.@guardianposx[.@UseGID],.@guardianposy[.@UseGID],strmobinfo(2,.@type),.@type,"Guardian#"+strnpcinfo(2)+"::OnGuardianDied",.@UseGID;
			mes "["+strnpcinfo(1)+"]";
			mes "We completed the summoning of the Guardian. Our defenses are now increased with it in place.";
			close;
		case 2:
			mes "["+strnpcinfo(1)+"]";
			mes "I did as you ordered. But please remember if you the have money to spare, it'll be better to set it up.";
			close;
		}
	case 5:
		if (GetCastleData(strnpcinfo(2),CD_ENABLED_KAFRA) == 1) {
			mes "["+strnpcinfo(1)+"]";
			mes "We are currently hiring a Kafra Employee... Do you want to fire the Kafra Employee?";
			next;
			switch (select("Fire:Cancel")) {
			case 1:
				cutin "kafra_01",2;
				mes "[ Hired Kafra Employee ]";
				mes "I worked so hard... How can you do that, Master?... Please... Please reconsider... Check it again, Master... Please...";
				next;
				switch (select("Fire:Cancel")) {
				case 1:
					mes "[ Hired Kafra Employee ]";
					mes "Oh, my goodness! This is nonsense!";
					next;
					cutin "",255;
					break;
				case 2:
					mes "[ Hired Kafra Employee ]";
					mes "I'll work hard for you... Thank you!";
					close;
				}
				break;
			case 2:
				mes "["+strnpcinfo(1)+"]";
				mes "She worked hard in my opinion. It was a good decision to keep her.";
				close;
			}
			disablenpc "Kafra Staff#"+strnpcinfo(2);
			SetCastleData strnpcinfo(2),CD_ENABLED_KAFRA,0;
			mes "["+strnpcinfo(1)+"]";
			mes "....";
			mes "I have discharged the Kafra Employee... But... are you unsatisfied with something?";
			close;
		}
		mes "["+strnpcinfo(1)+"]";
		mes "Will you contact the kafra Main Office and Hire a Employee for our Castle?";
		mes "^ff0000 10,000 zeny is required for their services. ";
		next;
		switch (select("Hire.:Cancel")) {
		case 1:
			if (getgdskilllv(.@GID,10001) == 0) {
				mes "["+strnpcinfo(1)+"]";
				mes "Master, we can't hire a Kafra Employee because we don't have a contract with the Kafra Main Office. If you want to obtain a contract with the Kafra Main Office, you will need to learn the Guild skill first.";
				close;
			}
			if (Zeny < 10000) {
				mes "["+strnpcinfo(1)+"]";
				mes "Well... I'm sorry but we don't have enough funds to hire a Kafra Employee.";
				close;
			}
			set Zeny, Zeny - 10000;
			enablenpc "Kafra Staff#"+strnpcinfo(2);
			SetCastleData strnpcinfo(2),CD_ENABLED_KAFRA,1;
			mes "["+strnpcinfo(1)+"]";
			mes "We obtained a contract with the kafra Main Office, and hired a Kafra Employee.";
			next;
			cutin "kafra_01",2;
			mes "[ Hired Kafra Employee ]";
			mes "How do you do? I was dispatched from the Main Office.";
			mes "I'll do my best to not tarnish the reputation of the Guild.";
			next;
			cutin "",255;
			mes "["+strnpcinfo(1)+"]";
			mes "The Contract terms of the hired Kafra Employee are for 1 month and after this term, you will need to to pay an additional fee.";
			mes "It will be useful for our members.";
			close;
		case 2:
			mes "["+strnpcinfo(1)+"]";
			mes "I did as you ordered, but some of our members will be unhappy. It will be better to hire a Kafra Employee quickly.";
			close;
		}
	case 6:
		mes "["+strnpcinfo(1)+"]";
		mes "Do you want to visit the room where our valuables are stored?";
		mes "That room is restricted to you... you are the only one with access to it.";
		next;
		switch (select("Go into Master's room.:Cancel")) {
		case 1:
			mes "["+strnpcinfo(1)+"]";
			mes "I'll show you the secret path. Follow me...please.";
			mes "When you want to return here, please press the secret switch.";
			close2;
			warp strnpcinfo(2),.@masterroom[0],.@masterroom[1];
			end;
		case 2:
			mes "["+strnpcinfo(1)+"]";
			mes "Goods are produced once a day... if you don't remove them in time, they will not be produced anymore.";
			mes "Therefore, it will be better if you check up on them from time to time.";
			close;
		}
	}
}

// WoE : Guild Dungeon Entrances
//============================================================
-	script	Lever#gd::gdlever	-1,{

	set .@GID,GetCastleData(strnpcinfo(2),CD_GUILD_ID);

	if (.@GID == 0) {
		mes "[Ringing Voice]";
		mes "'Those who overcome an ordeal shows a great deal of bravery... and will find their way to another ordeal.'";
		close;
	}

	if (compare(strnpcinfo(2),"aldeg")) {
		set .@destination$,"gld_dun02";
		if (compare(strnpcinfo(2),"cas01")) setarray .@coordinates[0],32,122;
		else if (compare(strnpcinfo(2),"cas02")) setarray .@coordinates[0],79,30;
		else if (compare(strnpcinfo(2),"cas03")) setarray .@coordinates[0],165,38;
		else if (compare(strnpcinfo(2),"cas04")) setarray .@coordinates[0],160,148;
		else if (compare(strnpcinfo(2),"cas05")) setarray .@coordinates[0],103,169;
	}
	else if (compare(strnpcinfo(2),"gefg")) {
		set .@destination$,"gld_dun04";
		if (compare(strnpcinfo(2),"cas01")) setarray .@coordinates[0],39,258;
		else if (compare(strnpcinfo(2),"cas02")) setarray .@coordinates[0],125,270;
		else if (compare(strnpcinfo(2),"cas03")) setarray .@coordinates[0],268,251;
		else if (compare(strnpcinfo(2),"cas04")) setarray .@coordinates[0],268,108;
		else if (compare(strnpcinfo(2),"cas05")) setarray .@coordinates[0],230,35;
	}
	else if (compare(strnpcinfo(2),"payg")) {
		set .@destination$,"gld_dun01";
		if (compare(strnpcinfo(2),"cas01")) setarray .@coordinates[0],186,165;
		else if (compare(strnpcinfo(2),"cas02")) setarray .@coordinates[0],54,165;
		else if (compare(strnpcinfo(2),"cas03")) setarray .@coordinates[0],54,39;
		else if (compare(strnpcinfo(2),"cas04")) setarray .@coordinates[0],186,39;
		else if (compare(strnpcinfo(2),"cas05")) setarray .@coordinates[0],223,202;
	}
	else if (compare(strnpcinfo(2),"prtg")) {
		set .@destination$,"gld_dun03";
		if (compare(strnpcinfo(2),"cas01")) setarray .@coordinates[0],28,251;
		else if (compare(strnpcinfo(2),"cas02")) setarray .@coordinates[0],164,268;
		else if (compare(strnpcinfo(2),"cas03")) setarray .@coordinates[0],164,179;
		else if (compare(strnpcinfo(2),"cas04")) setarray .@coordinates[0],268,203;
		else if (compare(strnpcinfo(2),"cas05")) setarray .@coordinates[0],199,28;
	}
	// Add custom Guild Castles here.
	else {
		end;
	}

	mes "[Ringing Voice]";
	mes "'Only the truly brave can take the test.'";
	next;
	mes " ";
	mes "There's a small lever. Will you pull it?";
	next;
	if(select("Pull.:Don't pull.") == 1) {
		if (getcharid(2) == .@GID) {
			close2;
			warp .@destination$,.@coordinates[0],.@coordinates[1];
			end;
		}
		mes " ";
		mes "Nothing happened.";
		close;
	}
	close;
}

// Guardian Spawner Template
//============================================================
-	script	Gld_Guard_Template::Gld_Guard_Template	-1,{
// Spawn Guardians in castles
// When adding new castles, ensure that the coordinates coincide
// with the coordinates defined in the Guild Steward template.
OnSpawnGuardians:
	// Define the types of guardians on a per castle basis.
	// 1 - Soldier Guardian; 2 - Archer Guardian; 3 - Knight Guardian
	// Define the x spawn point for each uardian.
	// [0] = 1st guardian's x spawn point.
	// Define the y spawn point for each uardian.
	// [0] = 1st guardian's y spawn point.
	// Aldebaran (Luina) Castles
	if (strnpcinfo(2) == "aldeg_cas01") { 
		setarray .@guardiantype[0],1,2,2,2,2,3,3,3;
		setarray .@guardianposx[0],17,39,38,45,21,218,213,73;
		setarray .@guardianposy[0],218,208,196,228,194,24,24,70;
	}
	else if (strnpcinfo(2) == "aldeg_cas02") {
		setarray .@guardiantype[0],3,3,3,1,1,2,2,2;
		setarray .@guardianposx[0],27,88,117,60,51,21,36,210;
		setarray .@guardianposy[0],184,43,46,202,183,177,183,7;
	}
	else if (strnpcinfo(2) == "aldeg_cas03") {
		setarray .@guardiantype[0],3,3,1,1,1,2,2,2;
		setarray .@guardianposx[0],90,116,86,116,64,212,195,110;
		setarray .@guardianposy[0],112,112,120,76,103,160,151,217;
	}
	else if (strnpcinfo(2) == "aldeg_cas04") {
		setarray .@guardiantype[0],2,2,2,1,1,1,3,3;
		setarray .@guardianposx[0],187,192,148,145,169,198,48,55;
		setarray .@guardianposy[0],100,42,88,209,53,77,72,88;
	}
	else if (strnpcinfo(2) == "aldeg_cas05") {
		setarray .@guardiantype[0],2,2,1,1,3,3,3,3;
		setarray .@guardianposx[0],51,188,157,157,27,145,156,41;
		setarray .@guardianposy[0],202,79,192,74,221,78,73,112;
	}
	// Geffen (Britoniah) Castles
	else if (strnpcinfo(2) == "gefg_cas01") {
		setarray .@guardiantype[0],1,1,1,2,2,3,3,3;
		setarray .@guardianposx[0],67,184,62,36,50,50,189,200;
		setarray .@guardianposy[0],179,20,41,186,186,67,41,167;
	}
	else if (strnpcinfo(2) == "gefg_cas02") {
		setarray .@guardiantype[0],1,1,1,2,2,3,3,3;
		setarray .@guardianposx[0],64,56,166,35,20,19,166,159;
		setarray .@guardianposy[0],168,41,25,148,150,41,42,188;
	}
	else if (strnpcinfo(2) == "gefg_cas03") {
		setarray .@guardiantype[0],2,2,1,1,1,3,3,3;
		setarray .@guardianposx[0],48,113,48,157,243,157,234,238;
		setarray .@guardianposy[0],176,214,207,62,41,45,25,160;
	}
	else if (strnpcinfo(2) == "gefg_cas04") {
		setarray .@guardiantype[0],2,2,1,1,1,3,3,3;
		setarray .@guardianposx[0],53,31,49,29,147,57,160,148;
		setarray .@guardianposy[0],191,178,220,46,65,46,50,189;
	}
	else if (strnpcinfo(2) == "gefg_cas05") {
		setarray .@guardiantype[0],2,2,1,1,1,3,3,3;
		setarray .@guardianposx[0],45,71,72,66,177,66,177,193;
		setarray .@guardianposy[0],149,163,142,47,50,17,35,166;
	}
	// Payon (Baulder) Castles
	else if (strnpcinfo(2) == "payg_cas01") {
		setarray .@guardiantype[0],2,2,2,2,2,2,2,3;
		setarray .@guardianposx[0],229,225,222,99,65,36,51,138;
		setarray .@guardianposy[0],92,80,111,45,31,127,144,133;
	}
	else if (strnpcinfo(2) == "payg_cas02") {
		setarray .@guardiantype[0],2,2,2,2,2,2,2,3;
		setarray .@guardianposx[0],237,228,210,57,42,287,264,27;
		setarray .@guardianposy[0],54,72,41,241,241,257,272,20;
	}
	else if (strnpcinfo(2) == "payg_cas03") {
		setarray .@guardiantype[0],2,2,2,2,2,2,2,3;
		setarray .@guardianposx[0],245,269,36,41,39,19,37,268;
		setarray .@guardianposy[0],37,51,39,39,65,276,277,244;
	}
	else if (strnpcinfo(2) == "payg_cas04") {
		setarray .@guardiantype[0],2,2,2,2,2,2,2,3;
		setarray .@guardianposx[0],251,232,231,32,32,35,36,270;
		setarray .@guardianposy[0],212,212,175,287,232,45,17,41;
	}
	else if (strnpcinfo(2) == "payg_cas05") {
		setarray .@guardiantype[0],2,2,2,2,2,2,2,3;
		setarray .@guardianposx[0],19,33,266,266,263,263,250,36;
		setarray .@guardianposy[0],279,260,234,279,37,21,22,36;
	}
	// Prontera (Valkyrie Realms) Castles
	else if (strnpcinfo(2) == "prtg_cas01") {
		setarray .@guardiantype[0],1,1,1,2,2,3,3,3;
		setarray .@guardianposx[0],182,182,153,59,50,184,196,107;
		setarray .@guardianposy[0],62,116,86,28,36,183,189,179;
	}
	else if (strnpcinfo(2) == "prtg_cas02") {
		setarray .@guardiantype[0],3,3,3,1,1,2,2,2;
		setarray .@guardianposx[0],161,153,178,71,49,64,7,75;
		setarray .@guardianposy[0],161,161,44,75,28,186,196,175;
	}
	else if (strnpcinfo(2) == "prtg_cas03") {
		setarray .@guardiantype[0],3,3,3,1,1,2,2,2;
		setarray .@guardianposx[0],191,137,45,50,41,191,179,191;
		setarray .@guardianposy[0],190,190,99,87,87,42,43,72;
	}
	else if (strnpcinfo(2) == "prtg_cas04") {
		setarray .@guardiantype[0],3,3,3,1,1,1,2,2;
		setarray .@guardianposx[0],276,274,246,38,29,33,78,36;
		setarray .@guardianposy[0],14,35,246,240,240,258,48,61;
	}
	else if (strnpcinfo(2) == "prtg_cas05") {
		setarray .@guardiantype[0],3,3,3,1,1,1,2,2;
		setarray .@guardianposx[0],266,287,245,236,251,278,32,44;
		setarray .@guardianposy[0],262,280,250,63,63,253,253,248;
	}
	// Add custom Guild Castles here.
	else {
		end;
	}

	// Kill all existing guardians before spawning new ones.
	// This should prevent duplicating Guardians when char Server disconnects.
	killmonster strnpcinfo(2),strnpcinfo(0)+"::OnGuardianDied";

	for( set .@i, 0; .@i <= 7 ; set .@i, .@i+1 ) {
		set .@UseGID,.@i + 10;
		if (.@guardiantype[.@i] == 1) { set .@type,1287; }
		else if (.@guardiantype[.@i] == 2) { set .@type,1285; }
		else { set .@type,1286; }
		if (GetCastleData(strnpcinfo(2),.@UseGID)) {
			guardian strnpcinfo(2),.@guardianposx[.@i],.@guardianposy[.@i],strmobinfo(2,.@type),.@type,"Guardian#"+strnpcinfo(2)+"::OnGuardianDied",.@i;
		}
	}
	end;

OnGuardianDied:
	end;
}

// Treasure Room Spawn Template
//============================================================
-	script	Gld_Trea_Spawn::Gld_Trea_Spawn	-1,{
	end;

OnClock0001:
	// Do nothing if this script is the template.
	if (strnpcinfo(1) == "Gld_Trea_Spawn") end;
	
	set .@GID, GetCastleData(strnpcinfo(2),CD_GUILD_ID);
	
	// If there is no owner, do nothing.
	if (!.@GID) end;

	// Is there Economy in this castle?
	set .@Treasure,GetCastleData(strnpcinfo(2),CD_CURRENT_ECONOMY)/5+4;

	// Set information
	if (strnpcinfo(2) == "aldeg_cas01") { 
		set .@treasurebox,1324;
		setarray .@treasurex[0],115,122,115,122,116,117,118,119,120,121,121,121,121,121,121,120,119,118,117,116,116,116,116,116;
		setarray .@treasurey[0],226,226,219,219,225,225,225,225,225,225,224,223,222,221,220,220,220,220,220,220,221,222,223,224;
	}
	else if (strnpcinfo(2) == "aldeg_cas02") { 
		set .@treasurebox,1326;
		setarray .@treasurex[0],134,135,135,134,132,133,134,135,136,137,137,137,137,137,137,136,135,134,133,132,132,132,132,132;
		setarray .@treasurey[0],231,231,230,230,233,233,233,233,233,233,232,231,230,229,228,228,228,228,228,228,229,230,231,232;
	}
	else if (strnpcinfo(2) == "aldeg_cas03") { 
		set .@treasurebox,1328;
		setarray .@treasurex[0],224,225,225,224,222,223,224,225,226,227,227,227,227,227,227,226,225,224,223,222,222,222,222,222;
		setarray .@treasurey[0],269,269,268,268,271,271,271,271,271,271,270,269,268,267,266,266,266,266,266,266,267,268,269,270;
	}
	else if (strnpcinfo(2) == "aldeg_cas04") { 
		set .@treasurebox,1330;
		setarray .@treasurex[0],84,85,85,84,82,83,84,85,86,87,87,87,87,87,87,86,85,84,83,82,82,82,82,82;
		setarray .@treasurey[0],13,13,12,12,15,15,15,15,15,15,14,13,12,11,10,10,10,10,10,10,11,12,13,14;
	}
	else if (strnpcinfo(2) == "aldeg_cas05") { 
		set .@treasurebox,1332;
		setarray .@treasurex[0],61,62,62,61,59,60,61,62,63,64,64,64,64,64,64,63,62,61,60,59,59,59,59,59;
		setarray .@treasurey[0],12,12,11,11,14,14,14,14,14,14,13,12,11,10,9,9,9,9,9,9,10,11,12,13;
	}
	else if (strnpcinfo(2) == "gefg_cas01") { 
		set .@treasurebox,1334;
		setarray .@treasurex[0],153,154,154,153,151,152,153,154,155,156,156,156,156,156,156,155,154,153,152,151,151,151,151,151;
		setarray .@treasurey[0],113,113,112,112,115,115,115,115,115,115,114,113,112,111,110,110,110,110,110,110,111,112,113,114;
	}
	else if (strnpcinfo(2) == "gefg_cas02") { 
		set .@treasurebox,1336;
		setarray .@treasurex[0],139,140,140,139,137,138,139,140,141,142,142,142,142,142,142,141,140,139,138,137,137,137,137,137;
		setarray .@treasurey[0],115,115,114,114,117,117,117,117,117,117,116,115,114,113,112,112,112,112,112,112,113,114,115,116;
	}
	else if (strnpcinfo(2) == "gefg_cas03") { 
		set .@treasurebox,1338;
		setarray .@treasurex[0],269,270,270,269,267,268,269,270,271,272,272,272,272,272,272,271,270,269,268,267,267,267,267,267;
		setarray .@treasurey[0],291,291,290,290,293,293,293,293,293,293,292,291,290,289,288,288,288,288,288,288,289,290,291,292;
	}
	else if (strnpcinfo(2) == "gefg_cas04") { 
		set .@treasurebox,1340;
		setarray .@treasurex[0],115,116,116,115,113,114,115,116,117,118,118,118,118,118,118,117,116,115,114,113,113,113,113,113;
		setarray .@treasurey[0],119,119,118,118,121,121,121,121,121,121,120,119,118,117,116,116,116,116,116,116,117,118,119,120;
	}
	else if (strnpcinfo(2) == "gefg_cas05") { 
		set .@treasurebox,1342;
		setarray .@treasurex[0],143,144,144,143,141,142,143,144,145,146,146,146,146,146,146,145,144,143,142,141,141,141,141,141;
		setarray .@treasurey[0],110,110,109,109,112,112,112,112,112,112,111,110,109,108,107,107,107,107,107,107,108,109,110,111;
	}
	else if (strnpcinfo(2) == "payg_cas01") { 
		set .@treasurebox,1344;
		setarray .@treasurex[0],289,292,292,289,288,289,290,291,292,293,293,293,293,293,293,292,291,290,289,288,288,288,288,288;
		setarray .@treasurey[0],10,10,7,7,11,11,11,11,11,11,10,9,8,7,6,6,6,6,6,6,7,8,9,10;
	}
	else if (strnpcinfo(2) == "payg_cas02") { 
		set .@treasurebox,1346;
		setarray .@treasurex[0],143,146,146,143,142,143,144,145,146,147,147,147,147,147,147,146,145,144,143,142,142,142,142,142;
		setarray .@treasurey[0],146,146,143,143,147,147,147,147,147,147,146,145,144,143,142,142,142,142,142,142,143,144,145,146;
	}
	else if (strnpcinfo(2) == "payg_cas03") { 
		set .@treasurebox,1348;
		setarray .@treasurex[0],158,159,159,158,156,157,158,159,160,161,161,161,161,161,161,160,159,158,157,156,156,156,156,156;
		setarray .@treasurey[0],169,169,168,168,171,171,171,171,171,171,170,169,168,167,166,166,166,166,166,166,167,168,169,170;
	}
	else if (strnpcinfo(2) == "payg_cas04") { 
		set .@treasurebox,1350;
		setarray .@treasurex[0],146,147,147,146,144,145,146,147,148,149,149,149,149,149,149,148,147,146,145,144,144,144,144,144;
		setarray .@treasurey[0],48,48,47,47,50,50,50,50,50,50,49,48,47,46,45,45,45,45,45,45,46,47,48,49;
	}
	else if (strnpcinfo(2) == "payg_cas05") { 
		set .@treasurebox,1352;
		setarray .@treasurex[0],155,158,158,155,154,155,156,157,158,159,159,159,159,159,159,158,157,156,155,154,154,154,154,154;
		setarray .@treasurey[0],134,134,131,131,135,135,135,135,135,135,134,133,132,131,130,130,130,130,130,130,131,132,133,134;
	}
	else if (strnpcinfo(2) == "prtg_cas01") { 
		set .@treasurebox,1354;
		setarray .@treasurex[0],10,11,11,10,8,9,10,11,12,13,13,13,13,13,13,12,11,10,9,8,8,8,8,8;
		setarray .@treasurey[0],209,209,208,208,211,211,211,211,211,211,210,209,208,207,206,206,206,206,206,206,207,208,209,210;
	}
	else if (strnpcinfo(2) == "prtg_cas02") { 
		set .@treasurebox,1356;
		setarray .@treasurex[0],201,202,202,201,199,200,201,202,203,204,204,204,204,204,204,203,202,201,200,199,199,199,199,199;
		setarray .@treasurey[0],228,228,227,227,230,230,230,230,230,230,229,228,227,226,225,225,225,225,225,225,226,227,228,229;
	}
	else if (strnpcinfo(2) == "prtg_cas03") { 
		set .@treasurebox,1358;
		setarray .@treasurex[0],187,188,188,187,185,186,187,188,189,190,190,190,190,190,190,189,188,187,186,185,185,185,185,185;
		setarray .@treasurey[0],132,132,131,131,134,134,134,134,134,134,133,132,131,130,129,129,129,129,129,129,130,131,132,133;
	}
	else if (strnpcinfo(2) == "prtg_cas04") { 
		set .@treasurebox,1360;
		setarray .@treasurex[0],269,270,270,269,267,268,269,270,271,272,272,272,272,272,272,271,270,269,268,267,267,267,267,267;
		setarray .@treasurey[0],162,162,161,161,164,164,164,164,164,164,163,162,161,160,159,159,159,159,159,159,160,161,162,163;
	}
	else if (strnpcinfo(2) == "prtg_cas05") { 
		set .@treasurebox,1362;
		setarray .@treasurex[0],275,276,276,275,273,274,275,276,277,278,278,278,278,278,278,277,276,275,274,273,273,273,273,273;
		setarray .@treasurey[0],178,178,177,177,180,180,180,180,180,180,179,178,177,176,175,175,175,175,175,175,176,177,178,179;
	}
	// Add custom Guild Castles here.
	else {
		end;
	}

	// Apply investment to Eco. and Def. Only happens if there were investments made.
	// Permanent Development can only happen once per day.
	if (GetCastleData(strnpcinfo(2),CD_INVESTED_ECONOMY)) {
		set .@Economy,GetCastleData(strnpcinfo(2),CD_CURRENT_ECONOMY);
		SetCastleData strnpcinfo(2),CD_CURRENT_ECONOMY,.@Economy + GetCastleData(strnpcinfo(2),CD_INVESTED_ECONOMY) + (rand(2) && getgdskilllv(.@GID,10014));
		if (GetCastleData(strnpcinfo(2),CD_CURRENT_ECONOMY) > 100) SetCastleData strnpcinfo(2),CD_CURRENT_ECONOMY,100;
	}
	if (GetCastleData(strnpcinfo(2),CD_INVESTED_DEFENSE)) {
		set .@Defence,GetCastleData(strnpcinfo(2),CD_CURRENT_DEFENSE);
		SetCastleData strnpcinfo(2),CD_CURRENT_DEFENSE,.@Defence + GetCastleData(strnpcinfo(2),CD_INVESTED_DEFENSE);
		if (GetCastleData(strnpcinfo(2),CD_CURRENT_DEFENSE) > 100) SetCastleData strnpcinfo(2),CD_CURRENT_DEFENSE,100;
	}
	// Reset daily investment limits.
	setcastledata strnpcinfo(2),CD_INVESTED_ECONOMY,0;
	setcastledata strnpcinfo(2),CD_INVESTED_DEFENSE,0;

	// Spawn boxes in proper order.
	for (set .@i,0; .@i < .@Treasure ; set .@i,.@i+1) {
		// set treasure box ID
		set .@boxid, .@treasurebox + (.@i+2) % 2;
		set .@box,1 << .@i;
		// Spawn or do not spawn chests if one already exists.
		if ((getd("$@"+strnpcinfo(2)+"_treasure") & .@box) == 0) {
			//monster strnpcinfo(2),.@treasurex[.@i],.@treasurey[.@i],"Treasure Chest",.@boxid,1,"Treasure#"+strnpcinfo(2)+"::OnTreasureDied"+.@i;
			monster strnpcinfo(2),.@treasurex[.@i],.@treasurey[.@i],"Treasure Chest",F_Rand(2200,2202,2203),1,"Treasure#"+strnpcinfo(2)+"::OnTreasureDied"+.@i;
			setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") | .@box;
		}
	}
	end;

// Individual "You killed a chest" events to ensure proper spawning at the change of day.
OnTreasureDied0:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~1;
	end;
OnTreasureDied1:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~2;
	end;
OnTreasureDied2:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~4;
	end;
OnTreasureDied3:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~8;
	end;
OnTreasureDied4:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~16;
	end;
OnTreasureDied5:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~32;
	end;
OnTreasureDied6:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~64;
	end;
OnTreasureDied7:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~128;
	end;
OnTreasureDied8:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~256;
	end;
OnTreasureDied9:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~512;
	end;
OnTreasureDied10:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~1024;
	end;
OnTreasureDied11:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~2048;
	end;
OnTreasureDied12:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~4096;
	end;
OnTreasureDied13:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~8192;
	end;
OnTreasureDied14:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~16384;
	end;
OnTreasureDied15:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~32768;
	end;
OnTreasureDied16:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~65536;
	end;
OnTreasureDied17:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~131072;
	end;
OnTreasureDied18:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~262144;
	end;
OnTreasureDied19:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~524288;
	end;
OnTreasureDied20:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~1048576;
	end;
OnTreasureDied21:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~2097152;
	end;
OnTreasureDied22:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~4194304;
	end;
OnTreasureDied23:
	setd "$@"+strnpcinfo(2)+"_treasure",getd("$@"+strnpcinfo(2)+"_treasure") & ~8388608;
	end;
}
