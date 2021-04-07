//===== rAthena Script =======================================
//= War of Emperium (Prontera) - Swanhild
//===== By: ==================================================
//= L0ne_W0lf
//===== Current Version: =====================================
//= 1.4
//===== Compatible With: =====================================
//= rAthena Project
//===== Description: =========================================
//= NPCs that relate to Prontera Guild Castle 2
//===== Additional Comments: =================================
//= 1.0 First Version. No longer uses functions. [L0ne_W0lf]
//= 1.1 Corrected flag-in spawn point. [L0ne_W0lf]
//= 1.2 Corrected treasure room switch coordinates. [L0ne_W0lf]
//= 1.3 Removed dialog from interior flags. [L0ne_W0lf]
//= 1.4 Partially rewrote Script. [Masao]
//============================================================

// Guild Flags (Outside Castle)
//============================================================
-	script	Swanhild#1::OutsideFlagsPR2	722,{

	set .@GID, GetCastleData("prtg_cas02",1);

	if (.@GID == 0) {
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
	if (getcharid(2) == .@GID) {
		mes "[ Echoing Voice ]";
		mes "Brave ones...";
		mes "Do you wish to return to your honorable place?";
		next;
		if(select("Return to the guild castle.:Quit.") == 1) {
			close2;
			if (getcharid(2) == GetCastleData("prtg_cas02",1)) {
				warp "prtg_cas02",169,55;
				end;
			}
			end;
		}
		close;
	}
	mes "[ Edict of the Divine Rune-Midgarts Kingdom ]";
	mes " ";
	mes "1. Follow the ordinance of The Divine Rune-Midgarts Kingdom, ";
	mes "we approve that this place is in";
	mes "the private prossession of ^ff0000"+GetGuildName(.@GID)+"^000000 Guild.";
	mes " ";
	mes "2. The guild Master of ^ff0000"+GetGuildName(.@GID)+"^000000 Guild is";
	mes "^ff0000"+GetGuildMaster(.@GID)+"^000000";
	mes "If there is anyone who objects to this,";
	mes "prove your strength and honor with a steel blade in your hand.";
	close;

OnRecvCastlePt02:
	FlagEmblem GetCastleData("prtg_cas02",1);
	end;
}

prt_gld,244,126,8	duplicate(OutsideFlagsPR2)	Swanhild#1-2	722
prt_gld,244,128,8	duplicate(OutsideFlagsPR2)	Swanhild#2	722
prt_gld,236,126,8	duplicate(OutsideFlagsPR2)	Swanhild#3	722
prt_gld,236,128,8	duplicate(OutsideFlagsPR2)	Swanhild#4	722

// Guild Flags (Inside Castle)
//============================================================
-	script	Swanhild#5::InsideFlagsPR2	722,{
	end;

OnRecvCastlePt02:
	FlagEmblem GetCastleData("prtg_cas02",1);
	end;
}

prtg_cas02,40,227,4	duplicate(InsideFlagsPR2)	Swanhild#5-2	722
prtg_cas02,46,227,4	duplicate(InsideFlagsPR2)	Swanhild#6	722
prtg_cas02,11,219,4	duplicate(InsideFlagsPR2)	Swanhild#7	722
prtg_cas02,11,214,4	duplicate(InsideFlagsPR2)	Swanhild#8	722
prtg_cas02,20,219,4	duplicate(InsideFlagsPR2)	Swanhild#9	722
prtg_cas02,20,214,4	duplicate(InsideFlagsPR2)	Swanhild#10	722
prtg_cas02,79,227,8	duplicate(InsideFlagsPR2)	Swanhild#11	722
prtg_cas02,70,227,8	duplicate(InsideFlagsPR2)	Swanhild#12	722
prtg_cas02,38,189,8	duplicate(InsideFlagsPR2)	Swanhild#13	722
prtg_cas02,34,189,8	duplicate(InsideFlagsPR2)	Swanhild#14	722
prtg_cas02,153,161,4	duplicate(InsideFlagsPR2)	Swanhild#15	722
prtg_cas02,162,161,4	duplicate(InsideFlagsPR2)	Swanhild#16	722

// Guild Flag (Town)
//============================================================
prontera,147,211,1	duplicate(InsideFlagsPR2)	Swanhild#17	722

// Kafra Employee
//============================================================
prtg_cas02,71,36,4	duplicate(guildkafra)	Kafra Staff#prtg_cas02	117

// Steward
//============================================================
prtg_cas02,94,61,4	duplicate(cm)	Roy#prtg_cas02	55

// Treasure Room Exit
//============================================================
prtg_cas02,207,228,0	script	#Lever_PR02	111,{
	mes " ";
	mes "There's a small lever. Will you pull it?";
	next;
	if(select("Pull.:Do not.") == 1) {
		close2;
		warp "prtg_cas02",94,62;
		end;
	}
	close;
}

// Guild Dungeon Switch
//============================================================
prtg_cas02,84,72,0	duplicate(gdlever)	#prtg_cas02	111

// Guild Treasure Spawns
//============================================================
prtg_cas02,202,228,0	duplicate(Gld_Trea_Spawn)	Treasure#prtg_cas02	-1

// AGIT Manager
//============================================================
prtg_cas02,158,174,0	duplicate(Gld_Agit_Manager)	Agit#prtg_cas02	-1

// Guardians
//============================================================
prtg_cas02,94,61,4	duplicate(Gld_Guard_Template)	Guardian#prtg_cas02	-1
