//===== rAthena Script =======================================
//= War of Emperium (Prontera) - Kriemhild
//===== By: ==================================================
//= L0ne_W0lf
//===== Current Version: =====================================
//= 1.4
//===== Compatible With: =====================================
//= rAthena Project
//===== Description: =========================================
//= NPCs that relate to Prontera Guild Castle 1
//===== Additional Comments: =================================
//= 1.0 First Version. No longer uses functions. [L0ne_W0lf]
//= 1.1 Corrected flag-in spawn point. [L0ne_W0lf]
//= 1.2 Corrected treasure room switch coordinates. [L0ne_W0lf]
//= 1.3 Removed dialog from interior flags. [L0ne_W0lf]
//= 1.4 Partially rewrote Script. [Masao]
//============================================================

// Guild Flags (Outside Castle)
//============================================================
-	script	Kriemhild#1::OutsideFlagsPR1	722,{

	set .@GID, GetCastleData("prtg_cas01",1);

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
			if (getcharid(2) == GetCastleData("prtg_cas01",1)) {
				warp "prtg_cas01",96,173;
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

OnRecvCastlePt01:
	FlagEmblem GetCastleData("prtg_cas01",1);
	end;
}

prt_gld,131,60,6	duplicate(OutsideFlagsPR1)	Kriemhild#1-2	722
prt_gld,138,68,6	duplicate(OutsideFlagsPR1)	Kriemhild#2	722
prt_gld,138,60,6	duplicate(OutsideFlagsPR1)	Kriemhild#3	722
prt_gld,135,60,6	duplicate(OutsideFlagsPR1)	Kriemhild#4	722

// Guild Flags (Inside Castle)
//============================================================
-	script	Kriemhild#5::InsideFlagsPR1	722,{
	end;

OnRecvCastlePt01:
	FlagEmblem GetCastleData("prtg_cas01",1);
	end;
}

prtg_cas01,58,56,4	duplicate(InsideFlagsPR1)	Kriemhild#5-2	722
prtg_cas01,64,56,4	duplicate(InsideFlagsPR1)	Kriemhild#6	722
prtg_cas01,76,32,4	duplicate(InsideFlagsPR1)	Kriemhild#7	722
prtg_cas01,84,32,4	duplicate(InsideFlagsPR1)	Kriemhild#8	722
prtg_cas01,94,39,4	duplicate(InsideFlagsPR1)	Kriemhild#9	722
prtg_cas01,94,24,4	duplicate(InsideFlagsPR1)	Kriemhild#10	722
prtg_cas01,73,14,4	duplicate(InsideFlagsPR1)	Kriemhild#11	722
prtg_cas01,73,6,4	duplicate(InsideFlagsPR1)	Kriemhild#12	722
prtg_cas01,55,46,4	duplicate(InsideFlagsPR1)	Kriemhild#13	722
prtg_cas01,45,46,4	duplicate(InsideFlagsPR1)	Kriemhild#14	722

// Guild Flag (Town)
//============================================================
prontera,159,214,0	duplicate(InsideFlagsPR1)	Kriemhild#15	722

// Kafra Employee
//============================================================
prtg_cas01,96,173,0	duplicate(guildkafra)	Kafra Staff#prtg_cas01	117

// Steward
//============================================================
prtg_cas01,112,181,0	duplicate(cm)	Ahvray#prtg_cas01	55

// Treasure Room Exit
//============================================================
prtg_cas01,15,208,0	script	#Lever_PR01	111,{
	mes " ";
	mes "There's a small lever. Will you pull it?";
	next;
	if(select("Pull.:Do not.") == 1) {
		close2;
		warp "prtg_cas01",112,183;
		end;
	}
	close;
}

// Guild Dungeon Switch
//============================================================
prtg_cas01,94,200,0	duplicate(gdlever)	#prtg_cas01	111

// Guild Treasure Spawns
//============================================================
prtg_cas01,11,208,0	duplicate(Gld_Trea_Spawn)	Treasure#prtg_cas01	-1

// AGIT Manager
//============================================================
prtg_cas01,197,197,0	duplicate(Gld_Agit_Manager)	Agit#prtg_cas01	-1

// Guardians
//============================================================
prtg_cas01,112,181,0	duplicate(Gld_Guard_Template)	Guardian#prtg_cas01	-1
