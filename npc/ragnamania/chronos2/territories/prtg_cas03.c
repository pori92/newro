//===== rAthena Script =======================================
//= War of Emperium (Prontera) - Fadhgridh
//===== By: ==================================================
//= L0ne_W0lf
//===== Current Version: =====================================
//= 1.4
//===== Compatible With: =====================================
//= rAthena Project
//===== Description: =========================================
//= NPCs that relate to Prontera Guild Castle 3
//===== Additional Comments: =================================
//= 1.0 First Version. No longer uses functions. [L0ne_W0lf]
//= 1.1 Corrected flag-in spawn point. [L0ne_W0lf]
//= 1.2 Corrected treasure room switch coordinates. [L0ne_W0lf]
//= 1.3 Removed dialog from interior flags. [L0ne_W0lf]
//= 1.4 Partially rewrote Script. [Masao]
//============================================================

// Guild Flags (Outside Castle)
//============================================================
-	script	Fadhgridh#1::OutsideFlagsPR3	722,{

	set .@GID, GetCastleData("prtg_cas03",1);

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
			if (getcharid(2) == GetCastleData("prtg_cas03",1)) {
				warp "prtg_cas03",181,215;
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

OnRecvCastlePt03:
	FlagEmblem GetCastleData("prtg_cas03",1);
	end;
}

prt_gld,147,140,4	duplicate(OutsideFlagsPR3)	Fadhgridh#1-2	722
prt_gld,147,136,4	duplicate(OutsideFlagsPR3)	Fadhgridh#2	722
prt_gld,158,140,4	duplicate(OutsideFlagsPR3)	Fadhgridh#3	722
prt_gld,158,136,4	duplicate(OutsideFlagsPR3)	Fadhgridh#4	722

// Guild Flags (Inside Castle)
//============================================================
-	script	Fadhgridh#5::InsideFlagsPR3	722,{
	end;

OnRecvCastlePt03:
	FlagEmblem GetCastleData("prtg_cas03",1);
	end;
}

prtg_cas03,168,28,4	duplicate(InsideFlagsPR3)	Fadhgridh#5-2	722
prtg_cas03,182,28,4	duplicate(InsideFlagsPR3)	Fadhgridh#6	722
prtg_cas03,43,50,4	duplicate(InsideFlagsPR3)	Fadhgridh#7	722
prtg_cas03,48,50,4	duplicate(InsideFlagsPR3)	Fadhgridh#8	722
prtg_cas03,43,58,4	duplicate(InsideFlagsPR3)	Fadhgridh#9	722
prtg_cas03,48,58,4	duplicate(InsideFlagsPR3)	Fadhgridh#10	722
prtg_cas03,158,210,4	duplicate(InsideFlagsPR3)	Fadhgridh#11	722
prtg_cas03,169,210,4	duplicate(InsideFlagsPR3)	Fadhgridh#12	722
prtg_cas03,162,201,4	duplicate(InsideFlagsPR3)	Fadhgridh#13	722
prtg_cas03,165,201,4	duplicate(InsideFlagsPR3)	Fadhgridh#14	722

// Guild Flag (Town)
//============================================================
prontera,152,214,0	duplicate(InsideFlagsPR3)	Fadhgridh#15	722

// Kafra Employee
//============================================================
prtg_cas03,181,215,4	duplicate(guildkafra)	Kafra Staff#prtg_cas03	117

// Steward
//============================================================
prtg_cas03,51,100,4	duplicate(cm)	Sttick#prtg_cas03	55

// Treasure Room Exit
//============================================================
prtg_cas03,193,130,0	script	#Lever_PR03	111,{
	mes " ";
	mes "There's a small lever. Will you pull it?";
	next;
	if(select("Pull.:Do not.") == 1) {
		close2;
		warp "prtg_cas03",51,101;
		end;
	}
	close;
}

// Guild Dungeon Switch
//============================================================
prtg_cas03,5,70,0	duplicate(gdlever)	#prtg_cas03	111

// Guild Treasure Spawns
//============================================================
prtg_cas03,189,132,0	duplicate(Gld_Trea_Spawn)	Treasure#prtg_cas03	-1

// AGIT Manager
//============================================================
prtg_cas03,17,221,0	duplicate(Gld_Agit_Manager)	Agit#prtg_cas03	-1

// Guardians
//============================================================
prtg_cas03,51,100,4	duplicate(Gld_Guard_Template)	Guardian#prtg_cas03	-1
