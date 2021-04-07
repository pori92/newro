//===== rAthena Script ======================================= 
//= Gemstone Trader
//===== By: ================================================== 
//= L0ne_W0lf
//===== Current Version: ===================================== 
//= 1.3
//===== Compatible With: ===================================== 
//= rAthena Project
//===== Description: ========================================= 
//= [Official Conversion]
//= Trade various colors of gemstones for other color gemstones.
//===== Additional Comments: ================================= 
//= 1.0 Rescripted to Aegis 10.3 standards. [L0ne_W0lf]
//=     Any notes pertaining to the prior trader may be found
//=     in the cities/payon.c
//= 1.1 Corrected NPC names to fall within proper restrictions. [L0ne_W0lf]
//= 1.2 Updated input with min/max values. [L0ne_W0lf]
//=     Added a checkweight. 
//= 1.3 Fixed checks. [Euphy]
//============================================================ 

rent_ma,179,119,6	script	Jade#ma	754,{
	if (checkweight(1201,1) == 0) {
		mes "^3355FFWait a second! Right now, you're carrying too many items with you. Please come back after putting some of your things into Kafra Storage.^000000";
		close;
	}
	mes "[Jade]";
	mes "Bring me two";
	mes "Gemstones of the";
	mes "same color, and I will";
	mes "change them to Gemstones";
	mes "of a different color.";
	next;
	switch(select("Blue Gemstones into Red ones!:Red Gemstones into Yellow ones!:Yellow Gemstones into Blue ones!")) {
	case 1: callsub S_TradeGems,717,716;
	case 2: callsub S_TradeGems,716,715;
	case 3: callsub S_TradeGems,715,717;
	}

S_TradeGems:
	if (countitem(getarg(0)) < 2) {
		mes "[Jade]";
		mes "Hah...!";
		mes "You're kidding me, right?";
		mes "I can't provide you with this";
		mes "service if you don't";
		mes "give me at least";
		mes "2 "+getitemname(getarg(0))+"s!";
		close;
	}
	else {
		set .@gems,countitem(getarg(0))/2;
		mes "[Jade]";
		mes "I believe I can create";
		mes "a total of " + .@gems + " " + getitemname(getarg(1)) + "s";
		mes "using the "+getitemname(getarg(0))+"s";
		mes "that you currently have.";
		mes "What do you want to do?";
		next;
		switch(select("Give me as many as you can.:I want to set the amount.:I quit.")) {
		case 1:
			delitem getarg(0),.@gems * 2;
			getitem getarg(1),.@gems;
			break;
		case 2:
			mes "[Jade]";
			mes "So how many";
			mes "do you want?";
			mes "The maximum number";
			mes "that you can enter is 100.";
			next;
			while(1) {
				input .@input,0,101;
				if (.@input == 0) {
					mes "[Jade]";
					mes "None at all?";
					mes "I guess you";
					mes "changed your mind...";
					close;
				}
				else if (.@input > 100) {
					mes "[Jade]";
					mes "Errm...";
					mes "I asked you to enter";
					mes "an amount no greater";
					mes "than 100, remember...?";
					next;
				}
				else if (.@gems < .@input) {
					// Custom dialogue
					mes "[Jade]";
					mes "Errm...";
					mes "You don't have that";
					mes "many gems to trade...";
					next;
				}
				else break;
			}
			delitem getarg(0),.@input * 2;
			getitem getarg(1),.@input;
			break;
		case 3:
			mes "[Jade]";
			mes "Sure, no problem.";
			mes "Come back any time.";
			close;
		}
		mes "[Jade]";
		mes "There you go.";
		mes "Feel free to come";
		mes "back any time.";
		mes "Hm, what's that look for?";
		mes "Is there something on my face?";
		close;
	}
}

rent_mb,179,119,6	duplicate(Jade#ma)	Jade#mb	754
