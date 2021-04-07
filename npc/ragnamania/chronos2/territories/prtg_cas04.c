//===== rAthena Script =======================================
//= War of Emperium (Prontera) - Skoegul
//===== By: ==================================================
//= L0ne_W0lf
//===== Current Version: =====================================
//= 1.4
//===== Compatible With: =====================================
//= rAthena Project
//===== Description: =========================================
//= NPCs that relate to Prontera Guild Castle 4
//===== Additional Comments: =================================
//= 1.0 First Version. No longer uses functions. [L0ne_W0lf]
//= 1.1 Corrected flag-in spawn point. [L0ne_W0lf]
//= 1.2 Corrected treasure room switch coordinates. [L0ne_W0lf]
//= 1.3 Removed dialog from interior flags. [L0ne_W0lf]
//= 1.4 Partially rewrote Script. [Masao]
//============================================================

// Guild Flags (Outside Castle)
//============================================================
-	script	Skoegul#1::OutsideFlagsPR4	722,{

	set .@GID, GetCastleData("prtg_cas04",1);

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
			if (getcharid(2) == GetCastleData("prtg_cas04",1)) {
					warp "prtg_cas04",258,247;
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

OnRecvCastlePt04:
	FlagEmblem GetCastleData("prtg_cas04",1);
	end;
}

prt_gld,120,243,6	duplicate(OutsideFlagsPR4)	Skoegul#1-2	722
prt_gld,120,236,6	duplicate(OutsideFlagsPR4)	Skoegul#2	722
prt_gld,122,243,6	duplicate(OutsideFlagsPR4)	Skoegul#3	722
prt_gld,122,236,6	duplicate(OutsideFlagsPR4)	Skoegul#4	722

// Guild Flags (Inside Castle)
//============================================================
-	script	Skoegul#5::InsideFlagsPR4	722,{
	end;

OnRecvCastlePt04:
	FlagEmblem GetCastleData("prtg_cas04",1);
	end;
}

prtg_cas04,82,29,4	duplicate(InsideFlagsPR4)	Skoegul#5-2	722
prtg_cas04,75,29,4	duplicate(InsideFlagsPR4)	Skoegul#6	722
prtg_cas04,75,27,4	duplicate(InsideFlagsPR4)	Skoegul#7	722
prtg_cas04,82,27,4	duplicate(InsideFlagsPR4)	Skoegul#8	722
prtg_cas04,59,29,4	duplicate(InsideFlagsPR4)	Skoegul#9	722
prtg_cas04,67,29,4	duplicate(InsideFlagsPR4)	Skoegul#10	722
prtg_cas04,258,25,4	duplicate(InsideFlagsPR4)	Skoegul#11	722
prtg_cas04,258,20,4	duplicate(InsideFlagsPR4)	Skoegul#12	722
prtg_cas04,263,20,4	duplicate(InsideFlagsPR4)	Skoegul#13	722
prtg_cas04,263,27,4	duplicate(InsideFlagsPR4)	Skoegul#14	722

// Guild Flag (Town)
//============================================================
prontera,164,211,7	duplicate(InsideFlagsPR4)	Skoegul#15	722

// Kafra Employee
//============================================================
prtg_cas04,258,247,4	duplicate(guildkafra)	Kafra Staff#prtg_cas04	117

// Steward
//============================================================
prtg_cas04,259,265,4	duplicate(cm)	Van Dreth#prtg_cas04	55

// Treasure Room Exit
//============================================================
prtg_cas04,275,160,0	script	#Lever_PR04	111,{
	mes " ";
	mes "There's a small lever. Will you pull it?";
	next;
	if(select("Pull.:Do not.") == 1) {
		close2;
		warp "prtg_cas04",259,265;
		end;
	}
	close;
}

// Guild Dungeon Switch
//============================================================
prtg_cas04,56,283,0	duplicate(gdlever)	#prtg_cas04	111

// Guild Treasure Spawns
//============================================================
prtg_cas04,271,162,0	duplicate(Gld_Trea_Spawn)	Treasure#prtg_cas04	-1

// AGIT Manager
//============================================================
prtg_cas04,292,14,0	duplicate(Gld_Agit_Manager)	Agit#prtg_cas04	-1

// Guardians
//============================================================
prtg_cas04,259,265,4	duplicate(Gld_Guard_Template)	Guardian#prtg_cas04	-1
