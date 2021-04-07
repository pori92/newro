// The Sign (Part 1)
//============================================================
-	script	Sign::TheSign	111,{
	callfunc "F_UpdateSignVars";
	cutin "sign_01",4;
	mes "^3355FFNext^000000";
	next;
	cutin "sign_01",255;
	cutin "sign_02",4;
	mes "^3355FFNext^000000";
	next;
	cutin "sign_02",255;
	cutin "sign_03",4;
	mes "^3355FFNext^000000";
	next;
	cutin "sign_03",255;
	cutin "sign_04",4;
	if (!sign_q) set sign_q,1;
	mes "^3355FFClose^000000";
	close2;
	cutin "sign_04",255;
	end;

OnInit:
	// Remove old depreciated settings.
	set $signbmps,0;
	set $signmazemonster,0;
	
	// Set the time zone of the server.
	// - Not official but seemed like a nice way to handle it.
	set $timezonestring$,"^FF0000GMT^000000";
	end;
}

prontera,147,305,0	duplicate(TheSign)	Sign#prontera	111
geffen,168,175,0	duplicate(TheSign)	Sign#geffen	111
morocc,168,265,0	duplicate(TheSign)	Sign#morocc	111
payon,160,183,0	duplicate(TheSign)	Sign#payon	111
aldebaran,54,223,0	duplicate(TheSign)	Sign#aldebaran	111
alberta,35,241,0	duplicate(TheSign)	Sign#alberta	111

prt_in,227,45,0	script	Archeologist#sign	804,{
	callfunc "F_UpdateSignVars";
	cutin "mets_alpha",2;
	mes "[Metz]";
	if (sign_q < 1) {
		mes "Although you need everlasting patience in an archaeological excavation, the feeling you get when you find something makes";
		mes "all those long hours of study and research worth it.";
	}
	else if (sign_q < 4) {
		switch(sign_q) {
		case 1:
			mes "Hm...?";
			mes "Can I help you?";
			next;
			switch(select("I've been following these signs and...:I was just passing by...")) {
			case 1:
				mes "[Metz]";
				mes "Great...!";
				mes "Welcome to my";
				mes "humble lodgings.";
				mes "Hmm, let me see...";
				next;
				if (BaseLevel < 50) {
					mes "[Metz]";
					mes "Uh, it pains me to say this, but I don't think you qualified to help me out. Once you gain enough experience though, I'll be happy to have you on board~";
					break;
				}
				else {
					mes "[Metz]";
					mes "Hey, I think you might";
					mes "be well suited for the job!";
					mes "But do you think you could come back later? I've got my hands full with some other business.";
					next;
					mes "[Metz]";
					mes "Oh right, would you tell";
					mes "me your name? "+ strcharinfo(0) +"?";
					mes "Okay then, I'll remember that.";
					mes "Talk to you later, alright?";
					set sign_q,2;
					break;
				}
			case 2:
				mes "[Metz]";
				mes "Oh really?";
				mes "I see, I thought you";
				mes "were an applicant for";
				mes "the position I'm offering";
				mes "to brave adventurers.";
				break;
			}
			break;
		case 2:
			mes "I'm sorry I made you wait,";
			mes "but I had some research to finish and it took longer than I expected. Now, before I tell you more about the job, I want to test your competency.";
			next;
			mes "[Metz]";
			mes "The job I'm offering is";
			mes "pretty risky and not just";
			mes "anybody can handle it.";
			mes "You'll actually go through";
			mes "a series of tests conducted";
			mes "by my trusted friends.";
			next;
			mes "[Metz]";
			mes "Now, the first person";
			mes "you must visit is ^FF0000Arian^000000";
			mes "in Morocc. Please speak";
			mes "to him and he'll give you";
			mes "all the details about his";
			mes "examination... I hope.";
			next;
			mes "[Metz]";
			mes "Once you're finished with";
			mes "the test, Arian will tell you";
			mes "what to do next. Afterwards,";
			mes "come back to me so that we";
			mes "can finally talk business.";
			next;
			mes "[Metz]";
			mes "Ah, almost forgot.";
			mes "Arian won't talk to anybody";
			mes "unless he knows them or";
			mes "receives a message from me.";
			mes "So if he's snubbed you in the past, just understand that's his way.";
			set sign_q,3;
			break;
		case 3:
			mes "Hm...?";
			mes "Shouldn't you leave";
			mes "for Morocc to see Arian?";
			mes "You better hurry in case";
			mes "somebody else applies";
			mes "for this little job.";
			break;
		}
	}
	else if (sign_q < 13) {
		mes "I don't know if you realize";
		mes "it, but I'm offering a golden";
		mes "opportunity for the adventurer";
		mes "who works for me. So don't";
		mes "hesitate to see Arian.";
		next;
		mes "[Metz]";
		mes "And just so you know,";
		mes "it's not a good idea to";
		mes "judge Arian by his looks.";
		mes "He's more than meets";
		mes "the eye, you know.";
	}
	else if (sign_q < 15) {
		mes "I'm impressed that";
		mes "you managed to get";
		mes "Arian's approval! Oh,";
		mes "and how's Daewoon?";
		mes "He's a character, isn't he?";
	}
	else if (sign_q < 20) {
		mes "I'm not surprised";
		mes "that Daewoon likes";
		mes "you. Ah, but Jore is";
		mes "always busy. Still, if you";
		mes "know his schedule, you";
		mes "should be alright.";
	}
	else if (sign_q < 25) {
		mes "Jesqurienne is";
		mes "a brilliant woman.";
		mes "Although I worry a";
		mes "little bit about her";
		mes "overconfidence, she's";
		mes "a good friend of mine.";
	}
	else if (sign_q < 35) {
		mes "Dearles...?";
		mes "Ah yes, he's one";
		mes "of my shadier friends.";
		mes "He's difficult to find";
		mes "and he's only truly kind";
		mes "to a select few, so...";
		next;
		mes "[Metz]";
		mes "It certainly doesn't";
		mes "help that he's hopelessly";
		mes "addicted to gambling...";
	}
	else if (sign_q < 53) {
		mes "Ah, Bakerlan~";
		mes "I've heard that he's";
		mes "been quite busy lately.";
		mes "But that's how all big";
		mes "businessmen are, I suppose.";
	}
	else if (sign_q == 53) {
		mes "Congratulations~";
		mes "You managed to pass";
		mes "all of the tests! You seem";
		mes "to be the perfect person";
		mes "to carry out this special";
		mes "assignment!";
		next;
		mes "[Metz]";
		mes "By now, you must have";
		mes "six Sobbing Starlight pieces.";
		mes "I'm sure that you want to know";
		mes "more about these fragments.";
		next;
		mes "[Metz]";
		mes "I remember last summer,";
		mes "I found the wholly formed";
		mes "Sobbing Starlight north";
		mes "of Mount Mjolnir during";
		mes "one of my expeditions...";
		next;
		mes "[Metz]";
		mes "Although it was in perfect";
		mes "shape, once it was exposed";
		mes "to the air, it began to crack";
		mes "and shattered into the pieces";
		mes "you now hold in your hand.";
		next;
		mes "[Metz]";
		mes "Now, an ordinary artisan";
		mes "can't put the Sobbing Starlight";
		mes "back together. This mysterious stone has some strange properties. But it's imperative for me to get this stone reassembled.";
		next;
		mes "[Metz]";
		mes "Once restored, a strange";
		mes "pattern can be seen within";
		mes "the Sobbing Starlight. I guess";
		mes "that the pattern is a message";
		mes "written in an ancient language.";
		next;
		mes "[Metz]";
		mes "Would you let me borrow";
		mes "the pieces for a second?";
		mes "I'll show you something";
		mes "quite interesting...";
		next;
		mes "^3355FFOnce you hand the pieces";
		mes "of the Sobbing Starlight to";
		mes "Metz, he pulls out a seventh";
		mes "piece. Once gathered, they";
		mes "begin to emit a strange light.^000000";
		specialeffect EF_TELEPORTATION2;
		next;
		mes "[Metz]";
		mes "Since the pieces still";
		mes "respond to each other,";
		mes "I believe that it's possible";
		mes "for the Sobbing Starlight";
		mes "to be restored to its";
		mes "original form.";
		next;
		mes "[Metz]";
		mes "We're still seeking";
		mes "an artisan of great";
		mes "skill for this task. Once";
		mes "know right away. For now,";
		mes "please hold on to these pieces.";
		set sign_q,54;
		getitem 7177,1; //Part_Of_Star's_Sob
	}
	else if (sign_q == 54) {
		if (rand(1,5) == 4) {
			mes "Ah, you've come";
			mes "just in the nick of time!";
			mes "I just found someone who";
			mes "may be capable of restoring";
			mes "the Sobbing Starlight.";
			next;
			mes "[Metz]";
			mes "His name is";
			mes "^FF0000Engel Howard^000000,";
			mes "a legendary Blacksmith";
			mes "in Midgard. I don't";
			mes "know where he is, but maybe";
			mes "his family in Geffen may know.";
			next;
			mes "[Metz]";
			mes "Unfortunately, that's all";
			mes "the information that I have";
			mes "to give you for now. You'll";
			mes "have to investigate this lead";
			mes "on your own, "+ strcharinfo(0) +".";
		}
		else {
			mes "Although I've made";
			mes "some progress, I still";
			mes "haven't found an artisan";
			mes "capable of restoring the";
			mes "Sobbing Starlight. Please";
			mes "give me a little more time.";
		}
	}
	else if (sign_q < 71) {
		mes "Keep up the good work.";
		mes "I'm sorry that I don't have";
		mes "have much information for";
		mes "you to follow, but someone";
		mes "with your abilities should";
		mes "be able to find a way.";
		next;
		mes "[Metz]";
		mes "While you work things";
		mes "out with Engel Howard";
		mes "and his family in Geffen,";
		mes "I'll continue my research";
		mes "on the Sobbing Starlight.";
	}
	else if (sign_q == 71) {
		mes "Amazing...! You've";
		mes "managed to restore";
		mes "the Sobbing Starlight!";
		mes "Now, I recently learned that";
		mes "this stone can lead you to";
		mes "an ancient place...";
		next;
		mes "[Metz]";
		mes "That's why we need to";
		mes "know what the message in";
		mes "the Sobbing Starlight means.";
		mes "First, we need a Wizard that";
		mes "is skilled in unlocking the";
		mes "messages stored in gems...";
		next;
		mes "[Metz]";
		mes "Hmm. It would probably";
		mes "be best to visit the Wizards";
		mes "on the top floor of the Geffen";
		mes "Tower. There's someone I know";
		mes "there who might just be up for";
		mes "this task...";
		set sign_q,72;
	}
	else if (sign_q == 72) {
		mes "Now that the";
		mes "Sobbing Starlight";
		mes "is restored, we need";
		mes "to find someone who can";
		mes "break the seal on the";
		mes "gem's message...";
		next;
		mes "[Metz]";
		mes "For now, please visit";
		mes "the Wizards at the top";
		mes "floor of the Geffen Tower.";
		mes "I know that one of them is";
		mes "capable of getting the gem's";
		mes "text on to paper...";
	}
	else if (sign_q < 76) {
		mes "The Wizard we're looking";
		mes "for isn't in Geffen? Hm, at least we know he's near Comodo. Now,";
		mes "while you investigate that lead, I'll continue to gather more";
		mes "information on this gem...";
	}
	else if (sign_q == 76) {
		mes "Great...!";
		mes "You were able to get the";
		mes "text in the gem printed on a";
		mes "Record of Ancient Language?";
		next;
		mes "[Metz]";
		mes "Just as I thought.";
		mes "This language isn't";
		mes "one I recognize. It's";
		mes "probably ^333333too^000000 ancient.";
		next;
		mes "[Metz]";
		mes "Fortunately, I know";
		mes "one person who may";
		mes "be able to translate this.";
		mes "If he's not able to do it...";
		mes "We'll have to give up.";
		next;
		mes "[Metz]";
		mes "Bring this Record";
		mes "of Ancient Language";
		mes "to a man named Frank.";
		mes "I hope he'll be able to";
		mes "understand what it says...";
		next;
		while(1) {
			switch(select("Who is Frank?:Where is he?:I see.")) {
			case 1:
				mes "[Metz]";
				mes "Frank Franklin has lived";
				mes "in seclusion and only a few";
				mes "people are aware of his skill.";
				mes "But I can assure you that his";
				mes "knowledge of ancient languages";
				mes "is unrivaled by any mortal.";
				next;
				mes "[Metz]";
				mes "I suppose his interest";
				mes "in history is what drives";
				mes "him in work. Still, I've";
				mes "heard that he doesn't like";
				mes "meeting people. I hope you";
				mes "can convince him to help us...";
				next;
				break;
			case 2:
				mes "[Metz]";
				mes "It's said that";
				mes "Frank Franklin lives";
				mes "on the Alberta Sunken Ship";
				mes "where he devotes his time";
				mes "to his research. He may not";
				mes "always be home though...";
				set sign_q,77;
				next;
				break;
			case 3:
				mes "[Metz]";
				mes "Good luck, then.";
				mes "I hope that you can";
				mes "find a way to get Frank";
				mes "Franklin to help us...";
				close2;
				cutin "mets_alpha",255;
				end;
			}
		}
	}
	else if (sign_q < 80) {
		mes "Frank Franklin has lived";
		mes "in seclusion and only a few";
		mes "people are aware of his skill.";
		mes "But I can assure you that his";
		mes "knowledge of ancient languages";
		mes "is unrivaled by any mortal.";
		next;
		mes "[Metz]";
		mes "I suppose his interest";
		mes "in history is what drives";
		mes "him in work. Still, I've";
		mes "heard that he doesn't like";
		mes "meeting people. I hope you";
		mes "can convince him to help us...";
	}
	else if (sign_q < 82) {
		mes "So far, I've learned";
		mes "from my research that";
		mes "the gem's message has";
		mes "details about a certain";
		mes "location and an item that";
		mes "serves as some kind of key...";
		next;
		mes "[Metz]";
		mes "While I investigate,";
		mes "please try to have Frank";
		mes "Franklin translate the";
		mes "message in the Record of";
		mes "Ancient Language. Keep up";
		mes "the good work, "+ strcharinfo(0) +".";
	}
	else if (sign_q == 82) {
		mes "I get it now!";
		mes "The 'skyscraper'";
		mes "in this text refers to";
		mes "the Geffen Tower!";
		mes "Alright, let's see...";
		next;
		mes "[Metz]";
		mes "Hmm...";
		mes "''The town where the";
		mes "rejected are left behind.''";
		mes "What does that mean";
		mes "and where could it be...?";
	}
	else if (sign_q < 98) {
		mes "I'm sure the town";
		mes "where the rejected";
		mes "live means something,";
		mes "but I'm unable to figure";
		mes "out the answer to this";
		mes "little riddle...";
	}
	else if ((sign_q > 100) && (sign_q < 105)) {
		mes "Angrboda...?!";
		mes "According to legend,";
		mes "her soul was split into";
		mes "pieces and placed behind";
		mes "seals created by the gods!";
		next;
		mes "[Metz]";
		mes "You'll need a stout,";
		mes "heavy or really sharp";
		mes "weapon. Of course, I'm";
		mes "told that such weapons";
		mes "are truly rare...";
		next;
		mes "[Metz]";
		mes "Supposedly, normal";
		mes "Blacksmiths can't even";
		mes "forge those kinds of rare";
		mes "weapons. But if you manage";
		mes "to get one, you might have a";
		mes "chance of breaking the seals.";
		next;
		mes "[Metz]";
		mes "Of course, I'm worried";
		mes "that may be violating the";
		mes "will of the gods by releasing";
		mes "Angrboda, but we've already";
		mes "gone this far...";
	}
	else if (sign_q < 137) {
		mes "I think you're";
		mes "almost there. All";
		mes "of our efforts will";
		mes "soon come to fruition!";
	}
	else if (sign_q == 137) {
		mes "This is it...!";
		mes "You've brought me,";
		mes "'The Sign!' I've finally";
		mes "proven its existence!";
		mes "Please let me handle";
		mes "this and come back later~";
		delitem 7314,1; //The_Sign
		set sign_q,138;
		set .@stime_s,gettime(DT_HOUR);
		if (.@stime_s < 1) set sign_sq,1;
		else if (.@stime_s < 3) set sign_sq,2;
		else if (.@stime_s < 5) set sign_sq,3;
		else if (.@stime_s < 7) set sign_sq,4;
		else if (.@stime_s < 9) set sign_sq,5;
		else if (.@stime_s < 11) set sign_sq,6;
		else if (.@stime_s < 13) set sign_sq,7;
		else if (.@stime_s < 15) set sign_sq,8;
		else if (.@stime_s < 17) set sign_sq,9;
		else if (.@stime_s < 19) set sign_sq,10;
		else if (.@stime_s < 21) set sign_sq,11;
		else set sign_sq,12;
	}
	else if (sign_q == 138) {
		set .@stime_s1,gettime(DT_HOUR);
		if (.@stime_s1 < 1) {
			if (sign_sq == 11) {
				set .@pass_s,1;
			}
		}
		else if (.@stime_s1 < 3) {
			if (sign_sq == 12) {
				set .@pass_s,1;
			}
		}
		else if (.@stime_s1 < 5) {
			if (sign_sq == 1) {
				set .@pass_s,1;
			}
		}
		else if (.@stime_s1 < 7) {
			if (sign_sq == 2) {
				set .@pass_s,1;
			}
		}
		else if (.@stime_s1 < 9) {
			if (sign_sq == 3) {
				set .@pass_s,1;
			}
		}
		else if (.@stime_s1 < 11) {
			if (sign_sq == 4) {
				set .@pass_s,1;
			}
		}
		else if (.@stime_s1 < 13) {
			if (sign_sq == 5) {
				set .@pass_s,1;
			}
		}
		else if (.@stime_s1 < 15) {
			if (sign_sq == 6) {
				set .@pass_s,1;
			}
		}
		else if (.@stime_s1 < 17) {
			if (sign_sq == 7) {
				set .@pass_s,1;
			}
		}
		else if (.@stime_s1 < 19) {
			if (sign_sq == 8) {
				set .@pass_s,1;
			}
		}
		else if (.@stime_s1 < 21) {
			if (sign_sq == 9) {
				set .@pass_s,1;
			}
		}
		else {
			if (sign_sq == 10) {
				set .@pass_s,1;
			}
		}
		if (.@pass_s == 1) {
			mes "Fascinating...";
			mes "This was made with";
			mes "a material outside of";
			mes "Midgard! See this";
			mes "blue lens? That must be";
			mes "its incredible power source!";
			next;
			mes "[Metz]";
			mes "I've found that the runes";
			mes "around the lens control some";
			mes "kind of seals placed at the Geffen Tower and Geffen Fountain. But with this in your hands, the seals should be broken...";
			next;
			mes "[Metz]";
			mes "I... I think";
			mes "you can even use this";
			mes "to enter Valhalla. There";
			mes "may be even other applications";
			mes "using the power of this item...";
			next;
			mes "[Metz]";
			mes "I can only think of";
			mes "one person who can";
			mes "handle working with";
			mes "this: Engel Howard,";
			mes "Midgard's best";
			mes "Blacksmith.";
			set sign_q,139;
			set sign_sq,0;
			getitem 7314,1; //The_Sign
		}
		else {
			mes "I'm sorry, but I'm";
			mes "still examining the";
			mes "artifact you've lent to";
			mes "me. Would you please";
			mes "give me some more time?";
		}
	}
	else if (sign_q < 141) {
		mes "Have you visited";
		mes "Engel Howard yet?";
		mes "He's the only one";
		mes "who can unlock the";
		mes "Sign's power for you...";
	}
	else if (sign_q == 141) {
		if (countitem(2644) == 1) {
			mes "Ah, you're finally";
			mes "here. I've been waiting";
			mes "to speak with you. First,";
			mes "let me thank you again";
			mes "for all of your help.";
			next;
			mes "[Metz]";
			mes "Thanks to you, my wish";
			mes "of proving the existence";
			mes "of the Sign has finally been";
			mes "fulfilled. Its power is now";
			mes "yours to do as you wish.";
			next;
			mes "[Metz]";
			mes "You may have had your doubts,";
			mes "but I'm happy enough to confirm that the Sign really exists. Thanks again, and I hope you stop by and chat from time to time.";
			set sign_q,142;
			getexp (checkre(3))?200000:2000000,0;
		}
		else {
			mes "Have you visited";
			mes "Engel Howard yet?";
			mes "He's the only one";
			mes "who can unlock the";
			mes "the Sign's power for you...";
		}
	}
	else if (sign_q == 201) {
		mes "You failed?";
		mes "It's disappointing,";
		mes "but I know that you";
		mes "did your best. Let";
		mes "me thank you for";
		mes "all your work.";
		next;
		mes "[Metz]";
		mes "Although I need to";
		mes "take back the Sobbing";
		mes "Starlight, I hope you";
		mes "accept this as a token";
		mes "of my gratitude. Good luck";
		mes "on your travels, adventurer.";
		if (checkweight(7178,1) == 0) {
				next;
				mes "^3355FFWait a second! Right now,";
				mes "you have too many items in your inventory. Please come back after you've freed up more inventory space.^000000";
				close;
		}
		delitem 7178,1; //Star's_Sob
		set sign_q,202;
		getexp (checkre(3))?10000:100000,0;
		getitem 617,1; //Old_Violet_Box
	}
	else if (sign_q > 201) {
		if (countitem(7178) == 1) {
			mes "I'm sorry...";
			mes "But I'm taking";
			mes "back the Sobbing";
			mes "Starlight from you.";
			mes "Apparently, you weren't";
			mes "worthy of the task...";
			next;
			mes "[Metz]";
			mes "......";
			mes "Farewell.";
			delitem 7178,1; //Star's_Sob
		}
		else {
			mes "I guess I can't";
			mes "really blame you";
			mes "since I didn't provide";
			mes "you with that much help...";
		}
	}
	else {
		mes "Thank you so much";
		mes "for helping me make";
		mes "my dream come true.";
		mes "can work on another";
		mes "project together.";
		next;
		mes "[Metz]";
		mes "Well then...";
		mes "Good luck on";
		mes "your journeys,";
		mes "brave "+ strcharinfo(0) +".";
	}
	close2;
	cutin "mets_alpha",255;
	end;
}

prt_in,228,26,5	script	Steward#sign	55,{
	callfunc "F_UpdateSignVars";
	mes "[Vandez]";
	if (sign_q < 3) {
		mes "Welcome to the";
		mes "Brayde Estate. How";
		mes "may I be of service?";
		next;
		switch(select("Nothing.:I'm here to see Metz.:Gimmie your cash!")) {
		case 1:
			mes "[Vandez]";
			mes "If you do not have";
			mes "any business to conduct";
			mes "with Master Metz, please";
			mes "leave immediately.";
			close;
		case 2:
			mes "[Vandez]";
			mes "Very good, "+((Sex == SEX_MALE)?"sir.":"madam.");
			mes "Please wait a moment";
			mes "while I consult with";
			mes "the master in his study.";
			close;
		case 3:
			mes "[Vandez]";
			mes "My apologies,";
			mes "but I insist that";
			mes "you leave the premises";
			mes "^FF0000immediately^000000.";
			close2;
			percentheal -30,0;
			warp "prontera",150,150;
			end;
		}
	}
	else if (sign_q < 14) {
		mes "Ah, Master "+ strcharinfo(0) +".";
		mes "Welcome. How may I be";
		mes "of service today?";
		next;
		switch(select("Who is Arian?:What is Metz doing?:How is Elle?")) {
		case 1:
			mes "[Vandez]";
			mes "Ah yes, Arian.";
			mes "I consider him to be";
			mes "a man of few words. The";
			mes "words he does choose to";
			mes "use are rather harsh and";
			mes "brutish, you might say.";
			close;
		case 2:
			mes "[Vandez]";
			mes "Although I've served";
			mes "the Brayde family for years,";
			mes "I'm unfamiliar with Master";
			mes "Metz's work. My apologies, but";
			mes "I simply cannot even begin to fathom his research...";
			close;
		case 3:
			mes "[Vandez]";
			mes "Ah, Mistress Elle";
			mes "has been working here";
			mes "since she was a very young";
			mes "girl. She is almost like";
			mes "a granddaughter to me.";
			mes "Ha ha-^333333*Ahem*^000000";
			close;
		}
	}
	else if (sign_q < 13) {
		mes "I recall that";
		mes "Master Arian visited";
		mes "the master a while ago.";
		mes "They spent all night";
		mes "discussing something";
		mes "related to the master's work.";
		next;
		mes "[Vandez]";
		mes "Goodness, it sounded";
		mes "dreadfully serious. The";
		mes "term, 'ancient power' is";
		mes "usually not mentioned";
		mes "quite often in conversation.";
		close;
	}
	else if (sign_q < 15) {
		mes "Sometimes I worry";
		mes "about Mistress Elle.";
		mes "She's one of the most";
		mes "beautiful girls in Prontera,";
		mes "but does not have a boyfriend.";
		next;
		mes "[Vandez]";
		mes "Many men have given her";
		mes "a great deal of attention, but";
		mes "she always manages to reject";
		mes "every single suitor...";
		close;
	}
	else if (sign_q < 20) {
		mes "Many travellers have";
		mes "begun to visit the master";
		mes "lastly. Apparently, they've";
		mes "been led here by the sign";
		mes "boards we've posted.";
		next;
		mes "[Vandez]";
		mes "Take heed and";
		mes "do not let anyone";
		mes "else take the opportunity";
		mes "the master has presented";
		mes "away from you.";
		close;
	}
	else if (sign_q < 25) {
		mes "It's most curious,";
		mes "but Elle seems to";
		mes "consider that unrefined";
		mes "Jesqurienne as her rival.";
		mes "Women are truly difficult";
		mes "for me to understand...";
		close;
	}
	else if (sign_q < 35) {
		mes "Avarice knows no bounds.";
		mes "The pastime of gambling";
		mes "seems to best represent";
		mes "mankind's greed.";
		next;
		mes "[Vandez]";
		mes "Winning or losing, some";
		mes "gamblers always seem to find";
		mes "some reason to continue when";
		mes "it's smarter to stop. Then again, the mind usually doesn't take precedence over the heart...";
		close;
	}
	else if (sign_q < 54) {
		mes "Bakerlan is a young,";
		mes "brilliant man. Although";
		mes "he inherited his company,";
		mes "it takes talent to continue";
		mes "his father's successes.";
		next;
		mes "[Vandez]";
		mes "It's amazing that Bakerlan";
		mes "is also managing to expand";
		mes "his business even further.";
		mes "Of course, Master Metz has";
		mes "had a role in Bakerlan's";
		mes "success...";
		close;
	}
	else if (sign_q == 54) {
		mes "Oh, congratulations~";
		mes "You finally passed all";
		mes "of the tests. I know they";
		mes "must have been incredibly";
		mes "taxing and challenging.";
		next;
		mes "[Vandez]";
		mes "Master Metz has informed";
		mes "me that he wishes for you";
		mes "to restore find someone";
		mes "to restore the Sobbing";
		mes "Starlight. I wish you luck";
		mes "in that endeavor.";
		close;
	}
	else if (sign_q == 97 || sign_q == 98) {
		mes "Although humans make";
		mes "mistakes, there are those";
		mes "times when failing cannot";
		mes "be an option.";
		next;
		mes "[Vandez]";
		mes "There will always";
		mes "be situations where";
		mes "you won't be getting";
		mes "any second chances.";
		mes "Anyways remember that.";
		close;
	}
	else {
		mes "There will always";
		mes "be situations where";
		mes "you won't be getting";
		mes "any second chances.";
		mes "Anyways remember that.";
		close;
	}
}

prt_in,248,23,3	script	Maid#sign	1275,{
	end;
}
prt_in,248,23,0	script	Maid#sign2	111,{
	callfunc "F_UpdateSignVars";
	mes "[Elle]";
	if (sign_q < 3) {
		mes "Wh-what are you";
		mes "doing in Master Metz's";
		mes "room? Please leave";
		mes "immediately!";
		close;
	}
	else if (sign_q < 14) {
		mes "Oh...?";
		mes ""+ strcharinfo(0) +"?";
		mes "Is there anything that";
		mes "I can help you with?";
		next;
		if (Sex == SEX_MALE) {
			switch(select("You wanna have coffee sometime?:Tell me about Metz.")) {
			case 1:
				mes "[Elle]";
				mes "...?";
				mes "*Blush~*";
				mes "Oh~ A-are you";
				mes "asking me out";
				mes "on a date?";
				next;
				mes "[Elle]";
				mes "Weeeell~";
				mes "Do I have the time";
				mes "to go out with you or";
				mes "not? Hm, maybe if";
				mes "you're really nice";
				mes "to me, , "+ strcharinfo(0) +".";
				close;
			case 2:
				mes "[Elle]";
				mes "Umm....";
				mes "I don't know";
				mes "what to say?";
				next;
				mes "[Elle]";
				mes "He's my employer and";
				mes "I have an opinion of him,";
				mes "but if I told you, it might";
				mes "look unprofessional. But";
				mes "if you have time later, I just";
				mes "might tell you. Ho ho~";
				close;
			}
		}
		else {
			switch(select("You have nice skin, Miss Elle.:Tell me about Metz.")) {
			case 1:
				mes "[Elle]";
				mes "Eh...?";
				mes "Why, thank you!";
				mes "Maybe it's because";
				mes "I don't go out too";
				mes "often. You have nice";
				mes "I don't go out too, "+ strcharinfo(0) +"~";
				close;
			case 2:
				mes "[Elle]";
				mes "Umm....";
				mes "I don't know";
				mes "what to say?";
				next;
				mes "[Elle]";
				mes "He's my employer and";
				mes "I have an opinion of him,";
				mes "but if I told you, it might";
				mes "look unprofessional. But";
				mes "if you have time later, I just";
				mes "might tell you.";
				close;
			}
		}
	}
	else if (sign_q < 13) {
		mes "I'm not so busy";
		mes "nowadays, but I was";
		mes "working hard for a while";
		mes "so my body aches. Oh, what";
		mes "am I saying? Please ignore";
		mes "that--! Ho ho ho~";
		emotion ET_PROFUSELY_SWEAT;
		close;
	}
	else if (sign_q < 15) {
		mes "Guys never understand";
		mes "what a girl really wants!";
		mes "They're always too afraid";
		mes "of showing their interest~";
		next;
		mes "[Elle]";
		mes "Well, even when they";
		mes "do ask me on dates, I never";
		mes "accept their proposals that";
		mes "easily. Hmph, there's not";
		mes "too many boys I like out";
		mes "there, anyway.";
		emotion ET_HNG;
		close;
	}
	else if (sign_q < 20) {
		mes "^333333*Phew....*^000000";
		mes "I'm so tired, even";
		mes "though I didn't work";
		mes "that much today. Some";
		mes "days I feel exhausted";
		mes "for no reason at all...";
		next;
		mes "[Elle]";
		mes "I should take";
		mes "the day off and";
		mes "rest. If I had some";
		mes "refreshment, that";
		mes "would be perfect...";
		close2;
		if (countitem(504) > 0) {
			select("Why don't you take this?");
			mes "[Elle]";
			mes "Oh, you didn't";
			mes "need to do this,";
			mes "but that you soooo";
			mes "much! Ahhhhhhh~";
			delitem 504,1; //White_Potion
			close2;
			emotion ET_CHUPCHUP;
			end;
		}
		end;
	}
	else if (sign_q < 25) {
		mes "Jesqurienne?";
		mes "Well, she's beautiful";
		mes "and talented. She's actually";
		mes "really great. That's why...";
		next;
		mes "[Elle]";
		mes "I consider her";
		mes "my rival! She might";
		mes "be smarter than me,";
		mes "but maybe I can become";
		mes "more beautiful than her...";
		emotion ET_THINK;
		close;
	}
	else if (sign_q < 35) {
		mes "Have you been";
		mes "in Comodo before?";
		mes "It's such a beautiful";
		mes "place with so many";
		mes "things to do!";
		next;
		mes "[Elle]";
		mes "I like gambling in";
		mes "Comodo, but I think";
		mes "it's a little addictive.";
		mes "I've even seen people";
		mes "who seem to live for it...";
		close;
	}
	else if (sign_q < 54) {
		mes "I remember that";
		mes "there was a lady";
		mes "working for Master";
		mes "Bakerlan named Seylin.";
		mes "I hear she's from some";
		mes "distant country...";
		next;
		mes "[Elle]";
		mes "I've seen her";
		mes "once and I think";
		mes "she has a unique";
		mes "style of beauty. Well,";
		mes "different than mine or";
		mes "Jesquienne's anyway...";
		close;
	}
	else if (sign_q == 54) {
		emotion ET_DELIGHT;
		mes "La la la~~";
		mes "Oh, hello.";
		mes "Long time no see.";
		mes "La la la~~";
		next;
		switch(select("What's up?:What happened?")) {
		case 1:
			mes "[Elle]";
			mes "Oh...?";
			mes "Oops...!";
			mes "Do I really";
			mes "look that excited?";
			next;
			mes "[Elle]";
			mes "I just started";
			mes "going out with someone!";
			mes "He's a tall handsome boy";
			mes "and I'm so in love with";
			mes "him and he's so....";
			next;
			mes "^3355FFElle continued";
			mes "talking about how";
			mes "much she loves her";
			mes "new boyfriend, even";
			mes "after you leave the room.^000000";
			close;
		case 2:
			mes "[Elle]";
			mes "Umm....";
			mes "Yes, something";
			mes "very good happened";
			mes "to me. Ho ho ho ho!";
			mes "But it's a secret~";
			close;
		}
	}
	else if (sign_q == 97) {
		mes "Ah~ Hello!";
		mes "Nice to see";
		mes "you again~";
		next;
		mes "[Elle]";
		mes "Er, I'm sorry, but I heard that something bad happened to you. But don't worry, maybe you'll have better luck next time~";
		close;
	}
	else {
		mes "^333333*Sigh...*^000000";
		mes "Lately, there've";
		mes "been too many guests";
		mes "visiting Master Metz.";
		mes "Why can't they leave their";
		mes "dirt outside of the manor?";
		emotion ET_HNG;
		close;
	}
}

morocc_in,115,154,5	script	Rogue#sign	810,{
	callfunc "F_UpdateSignVars";
	if (checkweight(1201,1) == 0) {
		mes "^3355FFWait a second! Right now,";
		mes "you have too many items in your inventory. Please come back after you've freed up more inventory space.^000000";
		close;
	}
	if (sign_q < 3) {
		emotion ET_THINK;
		end;
	}
	else if (sign_q == 3) {
		mes "[Arian]";
		mes "...";
		mes "Who the hell";
		mes "are you, jerkface?";
		next;
		switch(select("Metz sent me here.:^0000FF"+ strcharinfo(0) +"^000000.:Who are you then?")) {
		case 1:
			mes "[Arian]";
			mes "Oh yeah...?";
			mes "Well, I'm sending you";
			mes "back! No way I'm fallin'";
			mes "for that trick, chump!";
			close2;
			warp "morocc",279,173;
			end;
		case 2:
			mes "[Arian]";
			mes "Wha...?";
			mes "^0000FF"+ strcharinfo(0) +"^000000?";
			mes "Yeah, okay. Metz did";
			mes "mention something about";
			mes "about you. You're here";
			mes "for the test, right?";
			next;
			mes "[Arian]";
			mes "Alright, this";
			mes "test is simple.";
			mes "I tell you to bring me";
			mes "a bunch of items and";
			mes "you go get them.";
			next;
			mes "[Arian]";
			mes "I know you jerkward adventurers";
			mes "are always talking and you share the answers for any test some dude is givin' out. 'Course, it doesn't help that I use the same test";
			mes "every frickin' time...";
			next;
			mes "[Arian]";
			mes "Now, you gotta bring and only";
			mes "have the item I ask you for when you come to me. If you know that I'll be asking for something later and you happen to have it, I'll straight up ^FF0000jack it^000000.";
			next;
			mes "[Arian]";
			mes "The first item?";
			mes "Gimme ^FF0000100 Fluff^000000.";
			mes "Bring that and I'll";
			mes "tell you what to";
			mes "bring next.";
			set sign_q,4;
			close;
		case 3:
			mes "[Arian]";
			mes "...";
			mes "......";
			next;
			mes "[Arian]";
			mes "...";
			mes "......";
			mes "Your mom.";
			mes "Now get the";
			mes "hell outta here!";
			specialeffect EF_FIREHIT;
			percentheal -50,0;
			close;
		}
	}
	else if (sign_q < 15) {
		switch(sign_q) {
		case 4:
			mes "[Arian]";
			mes "...";
			if (countitem(914) > 99) {
				delitem 914,100; //Fluff
				if (countitem(7033) > 49) {
					delitem 7033,50; //Poison_Spore
					if (countitem(904) > 29) {
						delitem 904,30; //Scorpion's_Tail
						if (countitem(930) > 19) {
							delitem 930,20; //Rotten_Bandage
							if (countitem(1038) > 14) {
								delitem 1038,15; //Petite_DiablOfs_Horn
								if (countitem(7013) > 9) {
									delitem 7013,10; //Coral_Reef
								}
							}
						}
					}
				}
			}
			else {
				mes "Hey. What the hell's wrong";
				mes "with you? Hurry and get me";
				mes "^FF0000100 Fluff^000000, ya slacker.";
				close;
			}
			mes "Alright, that looks like";
			mes "enough Fluff. Now, go and";
			mes "get me ^FF000050 Poison Spores^000000.";
			set sign_q,5;
			close;
		case 5:
			mes "[Arian]";
			mes "...";
			if (countitem(7033) > 49) {
				delitem 7033,50; //Poison_Spore
				if (countitem(904) > 29) {
					delitem 904,30; //Scorpion's_Tail
					if (countitem(930) > 19) {
						delitem 930,20; //Rotten_Bandage
						if (countitem(1038) > 14) {
							delitem 1038,15; //Petite_DiablOfs_Horn
							if (countitem(7013) > 9) {
								delitem 7013,10; //Coral_Reef
							}
						}
					}
				}
			}
			else {
				mes "Hey. What part of 'Get me";
				mes "^FF000050 Poison Spores^000000 or I'll";
				mes "kick your ass,' don't";
				mes "you understand?";
				close;
			}
			mes "It's about time you";
			mes "got here with those";
			mes "Poison Spores. Now, go";
			mes "and get ^FF000030 Scorpion Tails^000000.";
			set sign_q,6;
			close;
		case 6:
			mes "[Arian]";
			mes "...";
			if (countitem(904) > 29) {
				delitem 904,30; //Scorpion's_Tail
				if (countitem(930) > 19) {
					delitem 930,20; //Rotten_Bandage
					if (countitem(1038) > 14) {
						delitem 1038,15; //Petite_DiablOfs_Horn
						if (countitem(7013) > 9) {
							delitem 7013,10; //Coral_Reef
						}
					}
				}
			}
			else {
				mes "What, your mom drop you on the";
				mes "head right after you were born?";
				mes "Stop bein' stupid and get me";
				mes "^FF000030 Scorpion Tails^000000, nimrod.";
				close;
			}
			mes "Damn, you sure took your";
			mes "sweet time bringing over this";
			mes "over this crap. Okay, now bring";
			mes "^FF000020 Rotten Bandages^000000.";
			set sign_q,7;
			close;
		case 7:
			mes "[Arian]";
			mes "...";
			if (countitem(930) > 19) {
				delitem 930,20; //Rotten_Bandage
				if (countitem(1038) > 14) {
					delitem 1038,15; //Petite_DiablOfs_Horn
					if (countitem(7013) > 9) {
						delitem 7013,10; //Coral_Reef
					}
				}
			}
			else {
				mes "Is it really that hard to get";
				mes "^FF000020 Rotten Bandages^000000? Cuz if it";
				mes "is, then you must really blow.";
				mes "Now hustle it up, punk!";
				close;
			}
			mes "You brought the bandages.";
			mes "Okay short stuff, go and get";
			mes "me ^FF000015 Little Evil Horn^000000. What";
			mes "are you waiting for, a memo?";
			mes "Get outta here~!";
			set sign_q,8;
			close;
		case 8:
			mes "[Arian]";
			mes "...";
			if (countitem(1038) > 14) {
				delitem 1038,15; //Petite_DiablOfs_Horn
				if (countitem(7013) > 9) {
					delitem 7013,10; //Coral_Reef
				}
			}
			else {
				mes "I don't get it.";
				mes "You don't have the";
				mes "^FF000015 Little Evil Horn^000000";
				mes "I told you to get.";
				next;
				mes "[Arian]";
				mes "I see, so it's my";
				mes "fault for not telling you";
				mes "not to bring your crap face";
				mes "back without 'em. ^333333*A-hem*^000000";
				mes "Don't bring your crap face here without 15 Little Evil Horns!!";
				close;
			}
			mes "My grandma coulda grown";
			mes "out her beard in the time";
			mes "it tookyou to come back.";
			mes "Now hurry it up and get";
			mes "me ^FF000010 Coral Reefs^000000!";
			set sign_q,9;
			close;
		case 9:
			mes "[Arian]";
			if (countitem(7013) > 9) {
				delitem 7013,10; //Coral_Reef
			}
			else {
				mes "I don't care how pretty";
				mes "they are or if you're ruining";
				mes "the ecosystem! When I say";
				mes "''bring ^FF000010 Coral Reefs^000000,'' you";
				mes "better have them! All the";
				mes "fish can die for all I care.";
				close;
			}
			mes "Finally you're back.";
			mes "Gimme a sec to count";
			mes "all this stuff so I can make";
			mes "sure you're not trying to";
			mes "cheat. God help you if you";
			mes "try to pull a fast one on me...!";
			set sign_q,10;
			close;
		case 10:
			mes "[Arian]";
			mes "...";
			mes "Alright. Go talk";
			mes "to the guy to my left.";
			mes "The dude at the counter.";
			mes "What's-his-face, Ganaan.";
			set sign_q,11;
			close;
		case 11:
			mes "[Arian]";
			mes "...";
			mes "Alright. Go talk";
			mes "to the guy to my left.";
			mes "The dude at the counter.";
			mes "What's-his-face, Ganaan.";
			next;
			mes "[Arian]";
			mes "You wanna leave me";
			mes "alone now and gimme";
			mes "a little personal space?!";
			mes "I need a break from looking";
			mes "at your ugly mug, you know?";
			close;
		case 12:
			mes "[Arian]";
			mes "Let's see...";
			mes "I'm looking at your";
			mes "answers and they totally";
			mes "suck. Take the test again";
			mes "and do it right this time!";
			next;
			mes "[Arian]";
			mes "Geez...";
			mes "You're givin' Ganaan";
			mes "a hard time. You hear";
			mes "me? That's my job!";
			set sign_q,11;
			close;
		case 13:
			mes "[Arian]";
			mes "Alright. The answers";
			mes "you gave Ganaan tell me";
			mes "you're not a total dumbass.";
			mes "Now you're supposed to go see Daewoon in Payon. And don't forget to show him this Star thingee.";
			if (checkre(3)) {
				if (BaseLevel < 60) getexp 300,0;
				else if (BaseLevel < 70) getexp 750,0;
				else if (BaseLevel < 80) getexp 1000,0;
				else if (BaseLevel < 90) getexp 1300,0;
				else getexp 1800,0;
			} else {
				if (BaseLevel < 60) getexp 3000,0;
				else if (BaseLevel < 70) getexp 7500,0;
				else if (BaseLevel < 80) getexp 10000,0;
				else if (BaseLevel < 90) getexp 13000,0;
				else getexp 18000,0;
			}
			set sign_q,14;
			getitem 7177,1; //Part_Of_Star's_Sob
			close;
		case 14:
			mes "[Arian]";
			mes "...........";
			mes "Payon...?";
			mes "Daewoon?";
			mes "Any of it ring a bell?";
			mes "Cuz it really oughtta!";
			close;
		}
	}
	else {
		mes "[Arian]";
		mes "...";
		mes "Shaddup and";
		mes "lemme alone!";
		mes "I'm thinking about";
		mes "solving world hunger";
		mes "here! Or somethin' like that.";
		emotion ET_THINK;
		close;
	}
}

morocc_in,114,162,4	script	Young Man#sign	118,{
	callfunc "F_UpdateSignVars";
	mes "[Gaanan]";
	if (sign_q < 11) {
		mes "The weather here in";
		mes "Morocc is too hot for me.";
		mes "I'm having a hard time just";
		mes "trying to live here. Do you";
		mes "know a nice and cool place";
		mes "where I can work?";
		emotion ET_PROFUSELY_SWEAT;
		close;
	}
	else if (sign_q == 11) {
		mes "Oh, Arian sent you to me,";
		mes "right? I'm sorry, but he takes";
		mes "a little getting used to. Even";
		mes "though I still have to get used";
		mes "to his... mannerisms.";
		next;
		mes "[Gaanan]";
		mes "Anyway, since he thinks it's";
		mes "boring, Arian put me in charge";
		mes "of the quiz portion of your test. Please carefully choose an";
		mes "answer when I ask you a";
		mes "question. Are you ready?";
		next;
		mes "[Gaanan]";
		mes "Now, the first question.";
		mes "Let's say that you just";
		mes "found yourself on a deserted";
		mes "island. What is the very first";
		mes "thing that you should do?";
		next;
		switch(select("Look for fresh water.:Just wait for rescue.:Forage for food.:Explore the island.")) {
		case 1:
			set .@point_s,.@point_s+7;
			break;
		case 2:
			set .@point_s,.@point_s+1;
			break;
		case 3:
			set .@point_s,.@point_s+4;
			break;
		case 4:
			set .@point_s,.@point_s+10;
			break;
		}
		mes "[Gaanan]";
		mes "The second question is...";
		mes "You happen to be stuck in";
		mes "a narrow place inside some";
		mes "collapsed building. What";
		mes "do you plan to do first?";
		next;
		switch(select("Scream for help.:Stay quiet.:Wait for death to come.:Find a way out.")) {
		case 1:
			set .@point_s,.@point_s+3;
			break;
		case 2:
			set .@point_s,.@point_s+7;
			break;
		case 3:
			set .@point_s,.@point_s+1;
			break;
		case 4:
			set .@point_s,.@point_s+7;
			break;
		}
		mes "[Gaanan]";
		mes "Now, the third question.";
		mes "You're on some dungeon";
		mes "expedition with your friends,";
		mes "but you got lost somehow.";
		mes "How do you handle it?";
		next;
		switch(select("Try to find my friends.:Find a way out.:Stay put.:Continue exploring the dungeon.")) {
		case 1:
			break;
		case 2:
			set .@point_s,.@point_s+5;
			break;
		case 3:
			set .@point_s,.@point_s+10;
			break;
		case 4:
			set .@point_s,.@point_s+1;
			break;
		}
		mes "[Ganaan]";
		mes "Here's the fourth question.";
		mes "You're with your friends inside";
		mes "a mansion with no exit. What do";
		mes "you do first when a murder happens inside the mansion?";
		next;
		switch(select("Wait for the case to get solved.:Try to find my friends first.:Find a way out.:Solve the murder case on my own.:Kill the others before they kill me.")) {
		case 1:
			set .@point_s,.@point_s+5;
			break;
		case 2:
			set .@point_s,.@point_s+7;
			break;
		case 3:
			set .@point_s,.@point_s+3;
			break;
		case 4:
			set .@point_s,.@point_s+1;
			break;
		case 5:
			set .@point_s,.@point_s+1;
			break;
		}
		mes "[Gaanan]";
		mes "The fifth question is...";
		mes "You hear that the end of";
		mes "the world is in one week.";
		mes "So what do you do during";
		mes "this final week?";
		next;
		switch(select("Wait to see the end.:Plant an apple tree.:Look to move to a different world.:What else? Save the world.:What else? Go on a crime spree.")) {
		case 1:
			set .@point_s,.@point_s+5;
			break;
		case 2:
			set .@point_s,.@point_s+3;
			break;
		case 3:
			set .@point_s,.@point_s+7;
			break;
		case 4:
			set .@point_s,.@point_s+10;
			break;
		case 5:
			set .@point_s,.@point_s+1;
			break;
		}
		mes "[Gaanan]";
		mes "Oh! We're done!";
		mes "Okay, let me give";
		mes "these answers to Arian.";
		mes "Sooo... Talk to him and";
		mes "he'll let you know how";
		mes "you did.";
		if (.@point_s > 33) set sign_q,13;
		else set sign_q,12;
		close;
	}
	else if (sign_q < 14) {
		mes "Hm...?";
		mes "Arian is the one";
		mes "who's grading your";
		mes "test. But I understand.";
		mes "If you failed, I'd want";
		mes "to avoid him too...";
		close;
	}
	else {
		mes "^333333*Sigh...*^000000";
		mes "I wish the weather'd";
		mes "cool down, even just a little.";
		mes "While I'm asking for miracles,";
		mes "I may as well wish for a billion kajillion zeny. And maybe a yacht.";
		close;
	}
}

payon,154,170,3	script	Hagin#sign	78,{
	mes "[Hagin]";
	mes "Have you heard?";
	mes "Payon's most eligible";
	mes "bachelor is back home!";
	next;
	mes "[Hagin]";
	mes "He was a little brat";
	mes "back when he was a kid,";
	mes "but now he's grown up to";
	mes "be the manliest of men!";
	mes "No wonder all the ladies";
	mes "just can't resist him!";
	next;
	mes "[Hagin]";
	mes "Heh heh...";
	mes "With this beautiful";
	mes "face and charming figure...";
	mes "I'm gonna seduce him.";
	next;
	switch(select("Who are you talking about?:You're freaking me out!")) {
	case 1:
		mes "[Hagin]";
		mes "You don't know";
		mes "Daewoon, the most";
		mes "beautiful man in all";
		mes "of Payon and maybe";
		mes "even the world?";
		next;
		mes "[Hagin]";
		mes "He left home to become stronger";
		mes "when he was just a boy. I had no idea he would come back as such ";
		mes "a fine specimen of a man...";
		next;
		select("I'd like to meet this Daewoon.");
		mes "[Hagin]";
		mes "Oh, I see~";
		if (Sex == SEX_MALE) {
			mes "You plan to ask him";
			mes "to show you some fighting";
			mes "pointers, do you? You men";
			mes "are all the same: not as";
			mes "cool or tough as Daewoon!";
		}
		else {
			mes "Interested, are you?";
			mes "Well, you'll have to get";
			mes "in line. So many women";
			mes "and only one Daewoon...";
			mes "^333333*Sigh*^000000";
		}
		next;
		mes "[Hagin]";
		mes "Anyway, Daewoon";
		mes "is staying in the annex";
		mes "to the Payon Castle. If you";
		mes "want to see him for yourself,";
		mes "why don't you go there?";
		close;
	case 2:
		mes "[Hagin]";
		mes "Freaking you out?";
		mes "Excuuuuse me~!";
		mes "I'll have you know that";
		mes "a flower's life is brief.";
		mes "I better snag Daewoon";
		mes "while I still can~";
		emotion ET_FRET;
		close;
	}
}

payon_in03,81,22,4	script	Maid#a1	1170,{
	end;
}

payon_in03,81,22,4	script	Maid#a2	111,{
	mes "[Maid]";
	mes "Welcome to the";
	mes "Payon Castle annex";
	mes "where Master Daewoon";
	mes "is staying.";
	close;
}

payon_in03,79,22,4	script	Maid#b1	1404,{
	end;
}

payon_in03,79,22,4	script	Maid#b2	111,{
	mes "[Maid]";
	mes "Welcome.";
	mes "Are you another";
	mes "visitor for Master";
	mes "Daewoon?";
	close;
}

payon_in03,81,15,1	script	Maid#c1	1170,{
	end;
}

payon_in03,81,15,1	script	Maid#c2	111,{
	mes "[Maid]";
	mes "Greetings.";
	mes "Welcome to the";
	mes "Annex to Payon Castle.";
	mes "Have you come here to";
	mes "see Master Daewoon?";
	close;
}

payon_in03,79,15,1	script	Maid#d1	1404,{
	end;
}

payon_in03,79,15,1	script	Maid#d2	111,{
	mes "[Maid]";
	mes "Welcome to the";
	mes "Payon Castle Annex.";
	mes "Master Daewoon is";
	mes "currently lodging here.";
	mes "Have you come to see him?";
	close;
}

payon_in03,8,31,4	script	Maid#e1	1416,{
	end;
}

payon_in03,8,31,4	script	Maid#e2	111,{
	mes "[Chamberlain]";
	mes "Please refrain";
	mes "from attacking";
	mes "the servants.";
	next;
	mes "[Chamberlain]";
	mes "Although you may recognize";
	mes "us as monsters, we have";
	mes "all been properly hired and";
	mes "faithfully serve our master,";
	mes "Daewoon. So there's no";
	mes "need to feel uneasy.";
	close;
}

payon_in03,13,31,4	script	Maid#f1	1416,{
	end;
}

payon_in03,13,31,4	script	Maid#f2	111,{
	mes "[Chamberlain]";
	mes "Master Daewoon~!";
	mes "Please try this too!";
	mes "It's Tiger Foot Skin soup,";
	mes "boiled with nine kinds of";
	mes "exotic, potent herbs.";
	next;
	mes "[Chamberlain]";
	mes "It's famous for easing";
	mes "sores and fatigure, preventing";
	mes "cold and ^333333*Ahem*^000000 enhancing male vigor. Now, open wide, master~";
	close;
}

payon_in03,11,31,4	script	Daewoon#sign	808,{
	callfunc "F_UpdateSignVars";
	mes "[Daewoon]";
	mes "Mwah ah hah!";
	mes "Feasting and merriment,";
	mes "wine, women and song!";
	mes "I could ask for nothing more!";
	next;
	mes "[Daewoon]";
	mes "The most scrumptious";
	mes "delicacies are all mine to";
	mes "taste! And I'm not just talking about the food. Mwah ah hah!";
	mes "I'm the king of the world!";
	next;
	if (sign_q == 14) {
		mes "[Daewoon]";
		mes "Oh, a visitor?";
		mes "I'm sorry, but I believe";
		mes "you're an uninvited guest~";
		if (Sex == SEX_MALE) {
			mes "You'll have to forgive me";
			mes "if I wish to spend my time with maidens as opposed to men.";
		}
		else {
			mes "No matter, a beauty is a beauty, whether or not I know her name.";
			mes "Come and drink with me~";
		}
		next;
		if (countitem(7177) > 0) {
			set .@pay_point,1;
			mes "["+ strcharinfo(0) +"]";
			mes "Sure...";
			mes "But first, would you";
			mes "take a look at this?";
			next;
			mes "^3355FFYou carefully take";
			mes "out the small, lucid";
			mes "jewel that Arian gave";
			mes "you and reveal it to";
			mes "Daewoon's roving eyes.^000000";
			next;
			emotion ET_SURPRISE;
			mes "[Daewoon]";
			mes "Eh? Why that's...";
			mes "I see now, Arian must";
			mes "have sent you! Oh you";
			mes "should have said so";
			mes "at the very beginning~";
			next;
			mes "[Daewoon]";
			mes "My apologies~";
			mes "Lately I've been attracting";
			mes "all sorts of strange attention like some kind of teen celebrity. I've gotten used to being too careful in screening out the dangerous sort.";
			next;
			mes "[Daewoon]";
			mes "Now then.";
			mes "Do you have any";
			mes "idea what that jewel";
			mes "you're holding actually is?";
			next;
			switch(select("Kind of?:How the hell would I know?:No, but would you tell me?")) {
			case 1:
				mes "[Daewoon]";
				mes "Oh...!";
				mes "You must be much";
				mes "smarter than I expected.";
				mes "So tell me, what do you";
				mes "understand about this jewel?";
				next;
				switch(select("It's handy.:I actually don't know...")) {
				case 1:
					set .@pay_point,.@pay_point+2;
					mes "[Daewoon]";
					emotion ET_THINK;
					mes "Mmm...?";
					mes "Handy? If you truly";
					mes "understood, I don't";
					mes "think you'd describe this";
					mes "jewel as merely 'handy.'";
					next;
					break;
				case 2:
					set .@pay_point,.@pay_point+4;
					emotion ET_HNG;
					mes "[Daewoon]";
					mes "Really?";
					mes "Mm. At least you";
					mes "admit it. *Sigh*";
					next;
					break;
				}
				break;
			case 2:
				mes "[Daewoon]";
				emotion ET_THINK;
				mes "...";
				mes "A rather crass way";
				mes "of speaking, but perhaps";
				mes "you picked it up from Arian.";
				mes "In any case, let me explain.";
				next;
				break;
			case 3:
				set .@pay_point,.@pay_point+5;
				mes "[Daewoon]";
				mes "Didn't Arian tell you";
				mes "anything? I appreciate";
				mes "your honesty. And I don't";
				mes "mind chatting a while, I much";
				mes "prefer speaking to honest people rather than foolish know-it-alls.";
				next;
				break;
			}
			mes "[Daewoon]";
			mes "That ^31009CSobbing Starlight^000000";
			mes "is no mere jewel. It is a key";
			mes "item for unlocking some incredible power. I believe Metz happened to obtain a piece, though I am";
			mes "unsure how...";
			next;
			mes "[Daewoon]";
			mes "Metz has asked me and";
			mes "some other friends who";
			mes "hold the fragments of the";
			mes "Sobbing Starlight to entrust";
			mes "them to someone worthy of";
			mes "finding the power it leads to.";
			next;
			mes "[Daewoon]";
			mes "Of course, we all agreed";
			mes "and now you're here for me";
			mes "to judge whether or not you're";
			mes "qualified for this task. Now,";
			mes "are you ready for my test?";
			next;
			switch(select("I'M READY! YEEAH!:I'll do my best!:To hell with this!:Fine. Let's get it over with.")) {
			case 1:
				set .@pay_point,.@pay_point+5;
				mes "[Daewoon]";
				mes "Ooh~";
				mes "Such unbridled";
				mes "enthusiasm usually";
				mes "does more good than harm.";
				next;
				break;
			case 2:
				set .@pay_point,.@pay_point+7;
				emotion ET_OK;
				mes "[Daewoon]";
				mes "Mwah ah hah!";
				mes "That's exactly what";
				mes "I wanted to hear! That";
				mes "kind of quiet and careful";
				mes "confidence will help you";
				mes "in the future, you'll see~";
				next;
				break;
			case 3:
				emotion ET_FRET;
				set .@pay_point,.@pay_point+2;
				mes "[Daewoon]";
				mes "E...";
				mes "Excuse me?";
				next;
				emotion ET_ANGER;
				mes "[Daewoon]";
				mes "How can you be";
				mes "so ridiculous at";
				mes "at time like this?";
				mes "Either mind your manners";
				mes "or don't take this test at";
				mes "all! ^333333*SLAP--!!*^000000";
				percentheal -10,0;
				next;
				break;
			case 4:
				set .@pay_point,.@pay_point+4;
				emotion ET_THINK;
				mes "[Daewoon]";
				mes "Hmm. That kind of half-hearted";
				mes "attitude won't get you very far on your adventures. Still, so long as you don't get overly negative, you should have a decent chance of surviving your challenges.";
				next;
				break;
			}
			mes "[Daewoon]";
			mes "Now, Metz expects me to ask";
			mes "some rather serious questions,";
			mes "but that really isn't my style. For this test, why don't we just talk?";
			mes "Just answer me honestly and";
			mes "light heartedly, alright?";
			emotion ET_SCRATCH;
			next;
			mes "[Daewoon]";
			mes "So...";
			mes "Do you have a lot";
			mes "of friends that you can";
			mes "constantly party with?";
			next;
			switch(select("Yes, I do.:I prefer soloing.:I am lonely.")) {
			case 1:
				set .@pay_point,.@pay_point+5;
				emotion ET_HUK;
				mes "[Daewoon]";
				mes "Oh, that's great~!";
				mes "To have many friends";
				mes "is a priceless blessing.";
				mes "Friends bring us joy and";
				mes "aid when we find ourselves";
				mes "suffering from difficulties.";
				next;
				mes "[Daewoon]";
				mes "Wouldn't you";
				mes "agree that being";
				mes "really close friends";
				mes "with someone can be";
				mes "a life long benefit?";
				next;
				break;
			case 2:
				set .@pay_point,.@pay_point+4;
				mes "[Daewoon]";
				mes "Well, everybody";
				mes "needs to be alone once";
				mes "in a while. And there are";
				mes "some battles you must";
				mes "fight all on your own.";
				next;
				mes "[Daewoon]";
				mes "Also, if you never";
				mes "deal with other people,";
				mes "you may grow selfish or";
				mes "needy. It's better to go";
				mes "out and meet people,";
				mes "don't you think?";
				next;
				break;
			case 3:
				set .@pay_point,.@pay_point+3;
				mes "[Daewoon]";
				mes "You don't have any";
				mes "friends at all? Well,";
				mes "you better learn how";
				mes "to get along with others";
				mes "as soon as you can...!";
				next;
				break;
			}
			mes "[Daewoon]";
			mes "Now, what's your opinion";
			mes "on purposely getting lots";
			mes "of monsters to follow you";
			mes "around. I believe this is";
			mes "called ''Mob Training...''";
			next;
			switch(select("Awesome~!:I hate people who do that.:I do it sometimes...")) {
			case 1:
				emotion ET_FRET;
				mes "[Daewoon]";
				mes "But...";
				mes "Wouldn't that be really";
				mes "rude to anyone else hunting";
				mes "on that same map? I think";
				mes "it would even interfere with";
				mes "someone else's gameplay...";
				next;
				emotion ET_FRET;
				mes "[Daewoon]";
				mes "Perhaps you should try";
				mes "to consider other people's";
				mes "feelings. Mob Training seems";
				mes "to only be good at getting other";
				mes "people angry with you...";
				next;
				break;
			case 2:
				set .@pay_point,.@pay_point+5;
				mes "[Daewoon]";
				mes "Really?";
				mes "I do too!";
				next;
				mes "[Daewoon]";
				mes "Just the other day, I've";
				mes "heard some ruffians boasting";
				mes "of their mob training activities. But personally, I feel they were compensating for their own shortcomings. ";
				next;
				emotion ET_FRET;
				mes "[Daewoon]";
				mes "Such behavior truly";
				mes "bothers me. Although I have";
				mes "spent years in developing an";
				mes "unflappable personality, I find";
				mes "myself irked when encountering";
				mes "such troublemakers.";
				next;
				emotion ET_BEST;
				mes "[Daewoon]";
				mes "When you face obstacles";
				mes "in your own training, never give in to weakness. Assert yourself and find the determination to overcome your tribulations with honor!";
				next;
				break;
			case 3:
				set .@pay_point,.@pay_point+3;
				mes "[Daewoon]";
				mes "At least you're honest.";
				mes "But let me say that I cannot";
				mes "condone that sort of weak willed behavior. True strength can only";
				mes "be found through honor.";
				mes "Remember that.";
				next;
				mes "[Daewoon]";
				mes "In the face of overwhelming";
				mes "odds, do not despair. After all, what is achievement if it is not earned without difficulty? The greater the challenge, the";
				mes "greater the glory.";
				next;
				mes "[Daewoon]";
				mes "Even if you are having hard time,";
				mes "try to take a firm stand.";
				mes "One day, you will realise how strong you have become.";
				next;
				mes "[Daewoon]";
				mes "And...";
				mes "Don't ever partake in";
				mes "mob training again, okay?";
				next;
				break;
			}
			mes "[Daewoon]";
			mes "Anyway, I'm sure you're";
			mes "aware of the War of Emperium";
			mes "in which mighty guilds all across Midgard battle for guild castle dominion. It's actually quite popular, really.";
			next;
			mes "[Daewoon]";
			mes "Now imagine that both of us";
			mes "are in the midst of a heated guild war. The sounds of explosions and earth shaking magic spells are all we can hear. At any time, we can";
			mes "be lost in that mindless chaos.";
			next;
			mes "[Daewoon]";
			mes "Finally, through incredible";
			mes "good fortune, we manage to";
			mes "infiltrate the enemy guild castle and reach their Emperium. If we destroy that Emperium, that castle will belong to our guild.";
			next;
			mes "[Daewoon]";
			mes "However...! This is";
			mes "no ordinary Emperium!";
			mes "It is a masterful sculpture";
			mes "of a gorgeous Priestess!";
			mes "Answer me, adventurer!";
			mes "Would you still destroy it?!";
			next;
			switch(select("Destroy it!:I can't destroy such beauty...:I'd close my eyes, then destroy it.")) {
			case 1:
				set .@pay_point,.@pay_point+3;
				mes "[Daewoon]";
				mes "Hmm. You have a truly";
				mes "strong will. Then again,";
				if (Sex == SEX_MALE) {
					mes "perhaps you lack a true";
					mes "appreciation for beauty.";
					mes "Even in Emperium form, how";
					mes "could you harm a Priestess?";
				}
				else {
					mes "perhaps you cannot appreciate";
					mes "a Priestess's beauty in the";
					mes "way that a man would.";
				}
				break;
			case 2:
				set .@pay_point,.@pay_point+5;
				mes "[Daewoon]";
				mes "Ah yes! I felt you would answer that way! We must cherish and protect what is beautiful in this world. I would never be able to harm a Priestess, even in";
				mes "statue form...";
				break;
			case 3:
				set .@pay_point,.@pay_point+6;
				mes "[Daewoon]";
				mes "Interesting...!";
				mes "Although you cherish";
				mes "the beauty of the Priestess,";
				mes "your loyalty to your guild";
				mes "proves stronger. A most";
				mes "admirable attitude!";
				break;
			}
			next;
			mes "[Daewoon]";
			mes "But yes, if it were";
			mes "me, I would protect that";
			mes "Priestess shaped Emperium";
			mes "until the end of the guild war.";
			mes "Mwah ah hah~!";
			next;
			mes "[Daewoon]";
			mes "While we're on the topic";
			mes "of guilds, let me present";
			mes "another guild related scenario. Let's say that you joined a very popular guild with many allies,";
			mes "as well as formidable enemies.";
			next;
			mes "[Daewoon]";
			mes "Now, during one of your.";
			mes "hunts, you happen to meet";
			mes "a member of one of your enemy guilds. The two of you are the only people on that map. Suddenly, he finds himself in mortal danger!";
			next;
			mes "[Daewoon]";
			mes "This enemy guild member";
			mes "begins to yell for help. Now,";
			mes "would you give your enemy";
			mes "the help that he needs?";
			next;
			switch(select("Yes, of course!:I'd pretend not to hear anything.:I'd make fun of him, then run off.")) {
			case 1:
				set .@pay_point,.@pay_point+6;
				mes "[Daewoon]";
				mes "Ah, you would help him!";
				mes "Good, good. I'm glad to see";
				mes "that you understand that such pettiness should not get in the way of doing what is good and right.";
				break;
			case 2:
				set .@pay_point,.@pay_point+5;
				mes "[Daewoon]";
				mes "True, you're not really";
				mes "obligated to help your";
				mes "enemy. Besides, you may";
				mes "hurt his feelings once he";
				mes "realizes that he's had to";
				mes "depend on his rival for help.";
				break;
			case 3:
				set .@pay_point,.@pay_point+4;
				mes "[Daewoon]";
				mes "Even though he is";
				mes "your enemy, I still";
				mes "believe it's important";
				mes "that you treat him with";
				mes "respect. Where is your honor?";
				break;
			}
			next;
			mes "[Daewoon]";
			mes "Well, there's one";
			mes "last thing I want to";
			mes "know about you. It's the";
			mes "most important question";
			mes "in the world once you";
			mes "think about it.";
			next;
			mes "[Daewoon]";
			mes "...";
			mes "......";
			mes "Do you enjoy life?";
			next;
			switch(select("Yes:No")) {
			case 1:
				mes "[Daewoon]";
				emotion ET_SMILE;
				mes "I'm glad.";
				mes "When you don't live";
				mes "with zeal, it's easy to";
				mes "forget your goals and your";
				mes "purpose for living. Don't have";
				mes "any? Then make some up.";
				next;
				mes "[Daewoon]";
				mes "I hope you always enjoy";
				mes "life as much as you can.";
				mes "As for me, I'm always happy";
				mes "with my wine, women and song~";
				mes "Mwah ah hah~!";
				next;
				break;
			case 2:
				mes "[Daewoon]";
				mes "I understand.";
				mes "People cannot be happy";
				mes "all the time. Sometimes";
				mes "it's easy to forget your";
				mes "goals and purpose in life.";
				next;
				mes "[Daewoon]";
				mes "But you know what? If you";
				mes "have just one dream, one goal";
				mes "to strive towards, things shall get better. If you think you don't have dreams, look back to your past. What you remember may surprise you.";
				next;
				mes "[Daewoon]";
				mes "It's important to look forward,";
				mes "but first you must find what is truly precious to you before you can define your happiness. That's why I think it's good to experience new things as well as reflect.";
				next;
				emotion ET_BEST;
				mes "[Daewoon]";
				mes "Now, what's precious to me?";
				mes "Three things, actually...";
				mes "Wine. Women. And song!";
				mes "Though, if I had to rank them,";
				mes "women would top that list.";
				mes "Mwah ah hah~!";
				next;
				break;
			}
			if (.@pay_point > 29) {
				set sign_q,15;
				getitem 7177,1; //Part_Of_Star's_Sob
				if (checkre(3)) {
					if (BaseLevel < 60) getexp 300,0;
					else if (BaseLevel < 70) getexp 750,0;
					else if (BaseLevel < 80) getexp 1000,0;
					else if (BaseLevel < 90) getexp 1300,0;
					else getexp 1800,0;
				} else {
					if (BaseLevel < 60) getexp 3000,0;
					else if (BaseLevel < 70) getexp 7500,0;
					else if (BaseLevel < 80) getexp 10000,0;
					else if (BaseLevel < 90) getexp 13000,0;
					else getexp 18000,0;
				}
				emotion ET_SMILE;
				mes "[Daewoon]";
				mes "Well, I must say that I've";
				mes "grown quite fond of you. Of";
				mes "course, it helps that we have so much in common. Mwah ah hah~!";
				mes "It was an honor to meet you~";
				next;
				mes "[Daewoon]";
				mes "Oh yes! Your next test";
				mes "examiner is ^CE0000Sir Jore^000000, also";
				mes "known as the Ghost of Al de Baran. Although he's always sick, he has great passion for his research.";
				next;
				mes "[Daewoon]";
				mes "Alright, then.";
				mes "Good luck in";
				mes "Al de Baran~!";
				close;
			}
			else if (.@pay_point < 20) {
				mes "[Daewoon]";
				mes "It pains me to say this,";
				mes "but I do not think you're";
				mes "worthy of holding my fragment";
				mes "of the Sobbing Starlight. But";
				mes "I am willing to give you";
				mes "another chance~";
				close;
			}
			else if ((.@pay_point > 26) && (.@pay_point < 30)) {
				set sign_q,15;
				getitem 7177,1; //Part_Of_Star's_Sob
				if (checkre(3)) {
					if (BaseLevel < 60) getexp 300,0;
					else if (BaseLevel < 70) getexp 750,0;
					else if (BaseLevel < 80) getexp 1000,0;
					else if (BaseLevel < 90) getexp 1300,0;
					else getexp 1800,0;
				} else {
					if (BaseLevel < 60) getexp 3000,0;
					else if (BaseLevel < 70) getexp 7500,0;
					else if (BaseLevel < 80) getexp 10000,0;
					else if (BaseLevel < 90) getexp 13000,0;
					else getexp 18000,0;
				}
				mes "[Daewoon]";
				mes "You know, after talking with";
				mes "you for a while, I now feel fairly comfortable with leaving you this piece of the Sobbing Starlight. Somehow, I think you're strong enough to get all the pieces.";
				next;
				mes "[Daewoon]";
				mes "I hope you will pass the rest of the test";
				mes "and acquire the power.";
				next;
				mes "[Daewoon]";
				mes "Oh yes! Your next test";
				mes "examiner is ^CE0000Sir Jore^000000, also";
				mes "known as the Ghost of Al de Baran. Although he's always sick, he has great passion for his research.";
				next;
				mes "[Daewoon]";
				mes "Alright, then.";
				mes "Good luck in";
				mes "Al de Baran~!";
				close;
			}
			else {
				mes "[Daewoon]";
				mes "It pains me to say this,";
				mes "but I do not think you're";
				mes "worthy of holding my fragment";
				mes "of the Sobbing Starlight. But";
				mes "I am willing to give you";
				mes "another chance~";
				close;
			}
			close;
		}
		else {
			mes "[Daewoon]";
			mes "I wonder...";
			mes "Someone should have";
			mes "passed Arian's test by now.";
			mes "I can't wait to see who was";
			mes "actually able to impress him...";
			close;
		}
	}
	else if (sign_q < 14) {
		mes "[Daewoon]";
		mes "Mwah ah hah~!";
		mes "I couldn't be happier!";
		mes "What more do I need?";
		mes "Gourmet food, fine wine,";
		mes "nubile women...!";
		close;
	}
	else if (sign_q == 98) {
		mes "[Daewoon]";
		mes "I'm sorry, but ";
		mes "no price can make";
		mes "me change my mind.";
		mes "You... You've failed.";
		mes "I'm sorry, friend.";
		close;
	}
	else if (sign_q == 99) {
		emotion ET_SURPRISE;
		mes "[Daewoon]";
		mes "Oh~! It's you!";
		mes "It has been a while since";
		mes "we last conversed. Now that";
		mes "you've accessed the power";
		mes "behind the Sobbing Starlight,";
		mes "do you like it?";
		next;
		switch(select("Yes:No")) {
		case 1:
			mes "[Daewoon]";
			mes "Ah, how great~!";
			mes "Just remember that";
			mes "power can be addictive.";
			mes "Even if you don't agree,";
			mes "it's still wise to avoid";
			mes "greedy tendencies, yes?";
			next;
			mes "[Daewoon]";
			mes "Please make good use of";
			mes "the power you have obtained.";
			mes "I am counting on you to be";
			mes "responsbile and to never lose";
			mes "that smile on your face, okay?";
			mes "Mwah ah hah~!";
			close;
		case 2:
			emotion ET_SCRATCH;
			mes "[Daewoon]";
			mes "Eh...?";
			mes "That's quite a surprise.";
			mes "Perhaps Metz didn't know";
			mes "enough about it? Still, I'm";
			mes "sorry to hear you don't like it.";
			next;
			mes "[Daewoon]";
			mes "But in the end, keep in mind";
			mes "that you must have learned some great lesson from this experience. Anyway, please do your best to use the power responsibly, okay?";
			mes "Mwah ah hah~!";
			close;
		}
	}
	else if (sign_q == 15) {
		mes "[Daewoon]";
		mes "Hm...?";
		mes "Weren't you on";
		mes "your way to find";
		mes "^CE0000Sir Jore^000000 in Al de Baran?";
		next;
		mes "[Daewoon]";
		mes "Oh, having trouble";
		mes "finding him, are you?";
		mes "Well, he's fairly shy, but";
		mes "I'm sure he's hiding some";
		mes "place in that town.";
		close;
	}
	else {
		mes "[Daewoon]";
		mes "Ah, I feel so...";
		mes "Satiated. The food was ";
		mes "stupendous and the women";
		mes "have been even more so.";
		mes "Servants! Fan me please~";
		next;
		mes "[Daewoon]";
		mes "^333333*Yawn...*";
		mes "...z...z...Z....ZZzZZ^000000";
		close;
	}
	close;
}

aldeba_in,139,103,5	script	Monograph#sign	111,{
	mes "[Sir Jore]";
	mes "Uwah~!";
	mes "Stop reading my";
	mes "research monograph!";
	mes "Put that back now!";
	close;
}

aldeba_in,155,101,3	script	Sir Jore#sign	805,7,7,{
	callfunc "F_UpdateSignVars";
	// if ((gettime(DT_HOUR) > 16) && (gettime(DT_HOUR) < 22)) {
	if (sign_q == 15) {
		mes "["+ strcharinfo(0) +"]";
		mes "Excuse me...";
		next;
		emotion ET_HUK;
		mes "^313FFF*Clink*^000000";
		next;
		mes "[Sir Jore]";
		mes "...";
		mes "......";
		next;
		emotion ET_PROFUSELY_SWEAT;
		mes "[Sir Jore]";
		mes "...";
		mes "......";
		mes "...No!";
		mes "Look what";
		mes "you made me do!";
		next;
		emotion ET_CRY;
		mes "[Sir Jore]";
		mes "I've been fiddling";
		mes "with this sample for";
		mes "five hours. And now";
		mes "it's ruined! ^333333*Sob*^000000";
		next;
		emotion ET_CRY;
		mes "[Sir Jore]";
		mes "^333333*Sob*^000000";
		mes "I came to this town";
		mes "so I could focus on";
		mes "my research without";
		mes "any interruptions. So";
		mes "why are you here?";
		next;
		switch(select("Daewoon sent me.:Oops, sorry. Later~")) {
		case 1:
			emotion ET_SWEAT;
			mes "[Sir Jore]";
			mes "O-oh!";
			mes "That's right.";
			mes "You're here to be";
			mes "tested for the piece";
			mes "of the Sobbing Starlight.";
			next;
			emotion ET_PROFUSELY_SWEAT;
			mes "[Sir Jore]";
			mes "So...";
			mes "Er. Then, what...";
			mes "W-what's your name?";
			next;
			select(strcharinfo(0) +", thanks.");
			mes "[Sir Jore]";
			mes "N-nice to meet you.";
			mes "My name is Jore. Just";
			mes "a normal person who loves";
			mes "research. S-sorry if I seem";
			mes "a little nervous! I'm actually";
			mes "quite... shy around people.";
			next;
			mes "[Sir Jore]";
			mes "Oh no...!";
			mes "If you were able to";
			mes "find me, there will be";
			mes "others! When would I get";
			mes "the time to do my research?!";
			mes "N-no! I h-h-hate people!!";
			next;
			mes "[Sir Jore]";
			mes "Still, I did promise";
			mes "M-M-Metz and he is my";
			mes "friend. So I must accept";
			mes "some guests. Even if hundreds";
			mes "of them knock on my door...";
			next;
			mes "[Sir Jore]";
			mes "But first of all,";
			mes "I'm going to need";
			mes "a new research sample.";
			mes "I think it's only fair that";
			mes "you get it for me since you";
			mes "made me ruin the last one.";
			next;
			mes "[Sir Jore]";
			mes "N-now, d-don't worry.";
			mes "The items are actually";
			mes "quite easy to get. It's";
			mes "five hours part that's";
			mes "hard. Now, let's see...";
			next;
			set sign_q,16;
			mes "[Sir Jore]";
			mes "Just bring me";
			mes "10 Empty Test Tubes,";
			mes "10 Green Herbs and";
			mes "2 Yggdrasil Leafs.";
			next;
			mes "[Sir Jore]";
			mes "You see, l-lately I've";
			mes "been studying Biology. ";
			mes "I think the secret to life";
			mes "can be found in the Leaf of";
			mes "Yggdrasil. They can be used";
			mes "to revive the dead, after all.";
			next;
			emotion ET_SWEAT;
			mes "[Sir Jore]";
			mes "Oh, and make sure to";
			mes "bring those things to me";
			mes "me before I go to bed at";
			mes "precisely 10:00 PM PST.";
			mes "I do have a regular sleeping";
			mes "schedule, you know.";
			close;
		case 2:
			emotion ET_CRY;
			mes "[Sir Jore]";
			mes "I spent five hours";
			mes "observing the changes";
			mes "in that research sample.";
			mes "All of that hard work lost!";
			mes "^333333*Wah~!*^000000";
			close;
		}
	}
	else if (sign_q == 16) {
		if ((countitem(1092) > 9) && (countitem(610) > 1) && (countitem(511) > 9)) {
			delitem 1092,10; //Empty_Cylinder
			delitem 610,2; //Leaf_Of_Yggdrasil
			delitem 511,10; //Green_Herb
			set sign_q,17;
			emotion ET_THANKS;
			mes "[Sir Jore]";
			mes "Ah! Th-thank you for";
			mes "bringing what I need.";
			mes "Now I can continue my";
			mes "research. Oh, and see if";
			mes "you're worthy of obtaining";
			mes "the Sobbing Starlight.";
			next;
			mes "[Sir Jore]";
			mes "Now, for your assignment.";
			mes "Have you ever heard about";
			mes "the ^CE3131Stone of Sage^000000? Rumors about";
			mes "it have been spreading around, but no one has confirmed the truth about it, "+ strcharinfo(0) +".";
			next;
			mes "[Sir Jore]";
			mes "Although I have no clue";
			mes "what the Stone of S-S-age";
			mes "may actually be, I have a gut";
			mes "feeling that I need it to bring";
			mes "my Biology research to the next step. This is how you'll help me.";
			next;
			set sign_q,17;
			mes "[Sir Jore]";
			mes "I need you to investigate";
			mes "this Stone of Sage by finding";
			mes "a father and daughter who were";
			mes "famous for being great Alchemists. They vanished deep into a forest, but I believe they know something.";
			close;
		}
		else {
			mes "[Sir Jore]";
			mes "Please bring m-me";
			mes "10 Empty Test Tube,";
			mes "10 Green Herb and";
			mes "2 Leaf of Yggdrasil";
			mes "so that I can make a";
			mes "new research sample.";
			close;
		}
	}
	else if (sign_q == 17) {
		mes "[Sir Jore]";
		mes "I want you to find two";
		mes "Alchemists, a father and";
		mes "daughter, who have gone into";
		mes "seclusion deep in some forest";
		mes "so that I can learn more about";
		mes "the Stone of Sage.";
		next;
		mes "[Sir Jore]";
		mes "Of course, this will";
		mes "possibly further my";
		mes "research, but it's also";
		mes "how I'll judge whether or";
		mes "not you're qualified for my";
		mes "piece of the Sobbing Starlight.";
		close;
	}
	else if (sign_q < 15) {
		mes "[Sir Jore]";
		mes "The mystery of life.";
		mes "The desire to discover its";
		mes "secrets drives me through";
		mes "all the research and sacrifice.";
		next;
		mes "[Sir Jore]";
		mes "I-I'm not that confident in";
		mes "my abilities, but I do believe that everything in this world is created by certain rules. Still, would I be punished by God for trying to create life he did not intend?";
		next;
		mes "[Sir Jore]";
		mes "But I can't stop now.";
		mes "One of these days, someone";
		mes "will reveal the secret of life.";
		mes "Why not me? That knowledge";
		mes "would make humans greater";
		mes "than any other race...";
		close;
	}
	else if (sign_q == 19) {
		mes "[Sir Jore]";
		mes "Ah, you've returned.";
		mes "So, did you learn what";
		mes "exactly is the Stone of Sage?";
		next;
		mes "["+ strcharinfo(0) +"]";
		mes "Well, I'm not sure,";
		mes "but I was told that it's";
		mes "red and can cure people.";
		mes "But it might be something";
		mes "we're already familiar with.";
		next;
		mes "[Sir Jore]";
		mes "That's all...?";
		mes "Maybe it was nothing";
		mes "but a rumor after all.";
		mes "A-anyway, please tell me";
		mes "what you think it might be.";
		next;
		input .@input$;
		if (compare(.@input$,"red gemstone")) {
			mes "[Sir Jore]";
			mes "What...! Huh.";
			mes "Perhaps I should just";
			mes "forget about the Stone of";
			mes "Sage and just research.";
			mes "Still, I'm so ashamed of";
			mes "relying on a rumor...";
			next;
			set sign_q,20;
			getitem 7177,1; //Part_Of_Star's_Sob
			mes "[Sir Jore]";
			mes "Thank you very much";
			mes "for helping me. Now I can";
			mes "go back to my studies and";
			mes "hope that nobody bothers me.";
			mes "But that'll never happen.";
			mes "^333333*Sigh...*^000000";
			next;
			mes "[Sir Jore]";
			mes "W-well, you've earned this";
			mes "piece of the Sobbing Starlight.";
			mes "For the next piece, you must visit ^0063FFLady Jesqurienne^000000 in Geffen, the city of magic. Since she travels often, she's probably in the Inn.";
			next;
			mes "[Sir Jore]";
			mes "O-o-okay then.";
			mes "Good luck getting";
			mes "all the pieces of ";
			mes "Sobbing Starlight,";
			mes ""+ strcharinfo(0) +". Farewell~";
			close;
		}
		else {
			mes "[Sir Jore]";
			mes "Err...?";
			mes "I don't think";
			mes "I quite understood";
			mes "you. What did you say?";
			close;
		}
	}
	else if (sign_q == 20) {
		mes "[Sir Jore]";
		mes "Now you must visit";
		mes "^0063FFLady Jesqurienne^000000 in";
		mes "Geffen. Good luck";
		mes "passing her test.";
		close;
	}
	else {
		mes "[Sir Jore]";
		mes "H-how is this supposed";
		mes "to work? Like this? No!";
		mes "No, that's not right!";
		mes "Think, Jore, think...";
		mes "What's the answer?!";
		close;
	}
// }
	// else if ((gettime(DT_HOUR) > 6) && (gettime(DT_HOUR) < 17)) {
	// 	mes "^3355FFYou find a tense man";
	// 	mes "holding test tubes between";
	// 	mes "his fingers, standing in a pile";
	// 	mes "of books. He seems to be in";
	// 	mes "agony for some reason.";
	// 	next;
	// 	switch(select("Speak to him.:Ignore him.")) {
	// 	case 1:
	// 		mes "["+ strcharinfo(0) +"]";
	// 		mes "Excuse me...";
	// 		next;
	// 		mes "[Sir Jore]";
	// 		mes "...";
	// 		mes "......";
	// 		next;
	// 		mes "^3355FFToo preoccupied with";
	// 		mes "his thoughts, this strange";
	// 		mes "man is unable to hear you.^000000";
	// 		next;
	// 		switch(select("Try again.:Ignore him.")) {
	// 		case 1:
	// 			mes "["+ strcharinfo(0) +"]";
	// 			mes "EXCUSE ME!";
	// 			next;
	// 			mes "[Sir Jore]";
	// 			mes "...!";
	// 			mes "Oh, h-h-hello.";
	// 			mes "Sorry, but I'm kind of";
	// 			mes "busy right now. Yes, yes,";
	// 			mes "would you come back at";
	// 			mes "precisely 5:00 PM PST?";
	// 			next;
	// 			mes "[Sir Jore]";
	// 			mes "Let's see...";
	// 			mes "Now if I recalibrated";
	// 			mes "the faust exhaust, then";
	// 			mes "the bioneutron analyzer";
	// 			mes "would need to be adjusted";
	// 			mes "for cytoplasmic balance...";
	// 			close;
	// 		case 2:
	// 			mes "^3355FFYou decide to leave";
	// 			mes "him alone and let him";
	// 			mes "continue mumbling to";
	// 			mes "himself and playing";
	// 			mes "with his test tubes.^000000";
	// 			close;
	// 		}
	// 	case 2:
	// 		mes "^3355FFYou decide to leave";
	// 		mes "him alone and let him";
	// 		mes "continue mumbling to";
	// 		mes "himself and playing";
	// 		mes "with his test tubes.^000000";
	// 		close;
	// 	}
	// }
	// else {
	// 	mes "[Sir Jore]";
	// 	mes "...z...z...Z";
	// 	close;
	// }
	// close;

OnTouch_:
	if (rand(2)) {
		emotion ET_AHA;
		specialeffect EF_PHARMACY_OK;
	}
	else {
		emotion ET_HUK;
		specialeffect EF_PHARMACY_FAIL;
	}
	end;
}

aldeba_in,156,118,4	script	Piru Piru#sign	102,{
	callfunc "F_UpdateSignVars";
	mes "[Piru Piru]";
	if ((gettime(DT_HOUR) >= 12) && (gettime(DT_HOUR) <= 24)) { //235959
		if (sign_q == 17) {
			emotion ET_CRY;
			mes "Oh, I'm sooo tired~";
			mes "But we can't sleep yet.";
			mes "*Sob* Master, can't we";
			mes "just call it a day already?";
			next;
			switch(select("What do you do in here?:About vanished Alchemists:What is the Stone of Sage?")) {
			case 1:
				mes "[Piru Piru]";
				mes "My master, Sir Jore,";
				mes "is researching a way to";
				mes "create artificial life! Still,";
				mes "it's not easy and we haven't";
				mes "accomplished anything yet...";
				next;
				mes "[Piru Piru]";
				mes "It doesn't help that my";
				mes "master spends all of his";
				mes "time on research. He hasn't";
				mes "been taking care of himself";
				mes "and is losing a lot of weight.";
				mes "I'm really worried about him.";
				close;
			case 2:
				mes "[Piru Piru]";
				mes "Oh, the father and daughter";
				mes "who were both Alchemists, right? Did you know they vanished because they invented the monster potion summoning skill?";
				next;
				mes "[Piru Piru]";
				mes "Their discovery caused";
				mes "such great hysteria in the";
				mes "scientific community. In the";
				mes "end they had no choice but";
				mes "to live in seclusion deep";
				mes "in the ^CE3131forest to the south^000000.";
				next;
				mes "[Piru Piru]";
				mes "They devoted their lives";
				mes "to their research, just like";
				mes "my master. If he makes a major";
				mes "breakthrough, we'll have to";
				mes "disappear like they did...";
				close;
			case 3:
				mes "[Piru Piru]";
				mes "Hmm? Well, I wouldn't";
				mes "know anything about that.";
				mes "In fact, I'm always staying";
				mes "in this lab, so I never hear";
				mes "any rumors or news outside.";
				close;
			}
		}
		else {
			emotion ET_CRY;
			mes "Oh, I'm sooo tired~";
			mes "But we can't sleep yet.";
			mes "*Sob* Master, can't we";
			mes "just call it a day already?";
			next;
			select("What do you do in here?");
			mes "[Piru Piru]";
			mes "My master, Sir Jore,";
			mes "is researching a way to";
			mes "create artificial life! Still,";
			mes "it's not easy and we haven't";
			mes "accomplished anything yet...";
			next;
			mes "[Piru Piru]";
			mes "It doesn't help that my";
			mes "master spends all of his";
			mes "time on research. He hasn't";
			mes "been taking care of himself";
			mes "and is losing a lot of weight.";
			mes "I'm really worried about him.";
			close;
		}
	}
	else if ((gettime(DT_HOUR) >= 6) && (gettime(DT_HOUR) < 12)) {
		mes "Everyday we study and";
		mes "take notes and test and";
		mes "experiment and record";
		mes "results and... Horrible!";
		next;
		mes "[Piru Piru]";
		mes "Although my master and I are the only ones who use this lab, we do have a set working schedule. We work from 10 AM to 5 PM and have our free time from 5 PM to 10 PM, which is when Master goes to bed.";
		next;
		mes "[Piru Piru]";
		mes "Of course, Master";
		mes "is happy if he can";
		mes "just do more research.";
		mes "In any case, please visit";
		mes "us after 5 PM if you have";
		mes "any business with us.";
		close;
	}
	else {
		mes "....Zzz...Zzz...";
		mes "Zzz....Zzz......";
		next;
		switch(select("Wake her up:Leave her sleep")) {
		case 1:
			mes "[Piru Piru]";
			mes "Wh-wha...?";
			mes "Why do you gotta";
			mes "wake me up? Come back";
			mes "after 10:00 AM tomorrow, kay?";
			close;
		case 2:
			mes "[Piru Piru]";
			mes "Zzzz.....Zzzzz...";
			close;
		}
	}
}

prt_maze02,57,151,1	script	Pleur#warp	91,{
	mes "^3355FFYou catch a glimpse";
	mes "of a girl heading directly";
	mes "into a deep forest. You decide";
	mes "to follow her and see if you can";
	mes "learn more.^000000";
	close2;
	set .@warp_s,rand(1,10);
	if (.@warp_s < 5) warp "prt_maze02",11,146;
	if (.@warp_s > 7) warp "prt_maze03",55,8;
	if ((.@warp_s > 4) && (.@warp_s < 8)) warp "prt_maze01",62,129;
	end;
}

prt_maze02,58,150,0	script	#movesign	-1,5,5,{
OnTouch_:
	mes "^3355FFYou catch a glimpse";
	mes "of a girl heading directly";
	mes "into a deep forest. You decide";
	mes "to follow her and see if you can";
	mes "learn more.^000000";
	close2;
	set .@warp_s,rand(1,10);
	if (.@warp_s < 5) warp "prt_maze02",11,146;
	if (.@warp_s > 7) warp "prt_maze03",55,8;
	if ((.@warp_s > 4) && (.@warp_s < 8)) warp "prt_maze01",62,129;
	end;
}

prt_maze02,18,126,0	script	#mazewarp	-1,3,3,{
OnTouch_:
	warp "prt_maze02",90,170;
	end;
}

/* Currently broken.
prt_maze02,25,161,0	script	#music	-1,7,7,{
OnTouch_:
	soundeffect "effect\\¼®¾çÀÇ ¾î½Ø½Å.wav",1;
	end;
}
*/

prt_maze02,132,132,0	script	#skill	-1,{
OnEnable:
	monster "prt_maze02",14,177,"Flora",1118,1,"#skill::OnMyMobDead";
	monster "prt_maze02",17,171,"Flora",1118,1,"#skill::OnMyMobDead";
	monster "prt_maze02",24,173,"Flora",1118,1,"#skill::OnMyMobDead";
	monster "prt_maze02",17,175,"Marine Sphere",1142,1,"#skill::OnMyMobDead";
	monster "prt_maze02",17,168,"Marine Sphere",1142,1,"#skill::OnMyMobDead";
	end;

OnDisable:
	killmonster "prt_maze02","#skill::OnMyMobDead";
	end;

OnMyMobDead:
	end;
}

prt_maze02,16,183,3	script	Pleur#sign	91,{
	callfunc "F_UpdateSignVars";
	mes "[Pleur]";
	if (sign_q < 19) {
		mes "La la la~";
		mes "La la la~";
	}
	else {
		mes "Hmmm...?";
		mes "The Stone of Sage...";
	}
	close;

OnHo:
	emotion ET_DELIGHT;
	end;
OnKis2:
	emotion ET_CHUPCHUP;
	end;
OnGasp:
	emotion ET_SURPRISE;
	end;
OnOmg:
	emotion ET_HUK;
	end;
}

prt_maze02,14,183,4	script	Gordon#sign	51,{
	callfunc "F_UpdateSignVars";
	mes "[Gordon]";
	if (sign_q < 18) {
		emotion ET_DELIGHT;
		mes "Hello darling.";
		mes "What did you do today?";
		next;
		donpcevent "Pleur#sign::OnHo";
		mes "[Pleur]";
		mes "I played Hide-and-Seek";
		mes "with a white bear and a";
		mes "blue bear, father.";
		next;
		emotion ET_DELIGHT;
		mes "[Gordon]";
		mes "Darling...";
		mes "Aren't you tired";
		mes "of playing with the";
		mes "animals? We've lived";
		mes "in this forest for so long...";
		next;
		donpcevent "Pleur#sign::OnKis2";
		mes "[Pleur]";
		mes "Don't worry father, I understand. For now, this is the only place where we can relax and live inpeace. I think we deserve to rest after accomplishing our goals...";
		next;
		emotion ET_CRY;
		mes "[Gordon]";
		mes "Thank you, Pluer.";
		mes "I have no regrets about";
		mes "our work, but sometimes";
		mes "I do wish for a more";
		mes "carefree life for you...";
		if (sign_q < 17) close;
		else if (sign_q == 17) {
			next;
			switch(select("Roar~!:Excuse me.")) {
			case 1:
				set sign_q,18;
				donpcevent "#skill::OnEnable";
				emotion ET_HUK;
				donpcevent "Pleur#sign::OnOMG";
				mes "[Pleur]";
				mes "No no no!";
				mes "Summon Flora!";
				next;
				mes "[Gordon]";
				mes "Great Schott!";
				mes "Summon... Marine Sphere!";
				close;
			case 2:
				emotion ET_SURPRISE;
				donpcevent "Pleur#sign::OnGasp";
				mes "[Gordon]";
				mes "Eh?! Don't you know";
				mes "how dangerous this place";
				mes "is? What are you doing";
				mes "here in the middle of";
				mes "this forest?";
				next;
				mes "["+ strcharinfo(0) +"]";
				mes "Actually, I think";
				mes "I've been looking for";
				mes "you. I've been sent on";
				mes "an errand to find these";
				mes "two famous Alchemists.";
				next;
				mes "[Gordon]";
				mes "Mm...?";
				mes "Well, we're retired";
				mes "now, but I suppose it'd";
				mes "do no harm if you had";
				mes "something to ask us...";
				next;
				switch(select("Ask about Stone of Sage:Ask about Alchemy:Quit")) {
				case 1:
					set sign_q,19;
					mes "[Gordon]";
					mes "Stone of Sage?";
					mes "Huh. To be honest,";
					mes "I don't know anything";
					mes "about it at all. I guess";
					mes "its existence is pretty";
					mes "much just a rumor, really.";
					next;
					mes "[Gordon]";
					mes "All I've heard is that";
					mes "the Stone of Sage might";
					mes "be a catylst to transmute";
					mes "materials into gold. If it";
					mes "really existed, it would be";
					mes "the ultimate alchemic item.";
					next;
					mes "[Pleur]";
					mes "However, I've also heard";
					mes "it's red, can make humans";
					mes "immortal and can cure any";
					mes "sort of disease or ailment.";
					mes "Just where do these rumors";
					mes "come from? It's crazy...";
					next;
					mes "[Gordon]";
					mes "Now, I even hear that some";
					mes "people are working on trying";
					mes "to create the stone themselves.";
					mes "If they succeed, it'll have a huge effect on the entire world!";
					next;
					mes "[Gordon]";
					mes "I'm sorry that you've gone";
					mes "through the trouble of finding";
					mes "us for this kind of information. We're retired after all, so we";
					mes "may be out of the loop.";
					next;
					mes "[Pleur]";
					mes "Although we're retired, we";
					mes "would be much interested in";
					mes "knowing if someone does manage";
					mes "to create such a stone. If that";
					mes "happens, would you tell us?";
					next;
					mes "[Gordon]";
					mes "Now let me guide you";
					mes "on a safe path back out";
					mes "of this maze. I've lived here";
					mes "quite a while, so I can find";
					mes "the exit with my eyes closed.";
					mes "Farewell, adventurer~";
					close2;
					warp "mjolnir_12",44,23;
					end;
				case 2:
					mes "[Pleur]";
					mes "I hope you understand that";
					mes "my father and I devoted and sacrificed so much for our work. Finally, we discovered a way to summon monsters using potions.";
					next;
					mes "[Pleur]";
					mes "However, too many Alchemists";
					mes "hounded us for our information";
					mes "once we announced the results";
					mes "of our research. It was more";
					mes "than we could handle...";
					next;
					mes "[Gordon]";
					mes "I'm sorry, but if you have any";
					mes "questions about Alchemy, there";
					mes "are many qualified researchers and practitioners out there. We came to this forest to find peace...";
					close;
				case 3:
					mes "[Gordon]";
					mes "Hah hah hah~";
					mes "Did you forget";
					mes "what you were";
					mes "going to ask me?";
					close;
				}
			}
		}
	}
	else if (sign_q == 18) {
		emotion ET_HNG;
		mes "Oh...!";
		mes "You scared us!";
		mes "Roaring like some";
		mes "animal! What do you";
		mes "think you were doing?";
		next;
		mes "["+ strcharinfo(0) +"]";
		mes "Actually, I think";
		mes "I've been looking for";
		mes "you. I've been sent on";
		mes "an errand to find these";
		mes "two famous Alchemists.";
		next;
		mes "[Gordon]";
		mes "Mm...?";
		mes "Well, we're retired";
		mes "now, but I suppose it'd";
		mes "do no harm if you had";
		mes "something to ask us...";
		next;
		switch(select("Ask about Stone of Sage:Ask about Alchemy:Quit")) {
		case 1:
			set sign_q,19;
			mes "[Gordon]";
			mes "Stone of Sage?";
			mes "Huh. To be honest,";
			mes "I don't know anything";
			mes "about it at all. I guess";
			mes "its existence is pretty";
			mes "much just a rumor, really.";
			next;
			mes "[Gordon]";
			mes "All I've heard is that";
			mes "the Stone of Sage might";
			mes "be a catylst to transmute";
			mes "materials into gold. If it";
			mes "really existed, it would be";
			mes "the ultimate alchemic item.";
			next;
			mes "[Pleur]";
			mes "However, I've also heard";
			mes "it's red, can make humans";
			mes "immortal and can cure any";
			mes "sort of disease or ailment.";
			mes "Just where do these rumors";
			mes "come from? It's crazy...";
			next;
			mes "[Gordon]";
			mes "Now, I even hear that some";
			mes "people are working on trying";
			mes "to create the stone themselves.";
			mes "If they succeed, it'll have a huge effect on the entire world!";
			next;
			mes "[Gordon]";
			mes "I'm sorry that you've gone";
			mes "through the trouble of finding";
			mes "us for this kind of information. We're retired after all, so we";
			mes "may be out of the loop.";
			next;
			mes "[Pleur]";
			mes "Although we're retired, we";
			mes "would be much interested in";
			mes "knowing if someone does manage";
			mes "to create such a stone. If that";
			mes "happens, would you tell us?";
			next;
			mes "[Gordon]";
			mes "Now let me guide you";
			mes "on a safe path back out";
			mes "of this maze. I've lived here";
			mes "quite a while, so I can find";
			mes "the exit with my eyes closed.";
			mes "Farewell, adventurer~";
			close2;
			warp "mjolnir_12",44,23;
			end;
		case 2:
			mes "[Pleur]";
			mes "I hope you understand that";
			mes "my father and I devoted and sacrificed so much for our work. Finally, we discovered a way to summon monsters using potions.";
			next;
			mes "[Pleur]";
			mes "However, too many Alchemists";
			mes "hounded us for our information";
			mes "once we announced the results";
			mes "of our research. It was more";
			mes "than we could handle...";
			next;
			mes "[Gordon]";
			mes "I'm sorry, but if you have any";
			mes "questions about Alchemy, there";
			mes "are many qualified researchers and practitioners out there. We came to this forest to find peace...";
			close;
		case 3:
			mes "[Gordon]";
			mes "Hah hah hah~";
			mes "Did you forget";
			mes "what you were";
			mes "going to ask me?";
			close;
		}
	}
	else if (sign_q > 18) {
		mes "Sometimes I miss";
		mes "being an alchemist.";
		mes "But then again, a man";
		mes "of my brilliance and genius";
		mes "would put all those newbie";
		mes "scientists to shame~";
		next;
		emotion ET_SWEAT;
		mes "[Pleur]";
		mes "D...";
		mes "D...Daddy!!";
		next;
		emotion ET_SMILE;
		mes "[Gordon]";
		mes "Heh heh~";
		mes "Am I being";
		mes "too arrogant?";
		close;
	}
}

geffen_in,59,74,4	script	Jesqurienne#sign	803,{
	callfunc "F_UpdateSignVars";
	mes "[Jesqurienne]";
	if (sign_q < 21) {
		mes "Bartender~?";
		mes "Give me another drink.";
		if (sign_q < 20) close;
		else if (sign_q == 20) {
			next;
			mes "[Jesqurienne]";
			mes "Ahhhhhh~";
			mes "Hm? Why hello there,";
			if (Sex == SEX_MALE) mes "you fine speciman of a man~";
			else mes "you precious, adorable girl~";
			mes "I'm Jesqurienne. You've heard";
			mes "of me, haven't you? Aren't you surprised to see me?";
			next;
			switch(select("I've never heard of you.:Oh gosh, it's Jesqurienne!")) {
			case 1:
				mes "[Jesqurienne]";
				emotion ET_SWEAT;
				mes "Ho ho ho~!";
				mes "Surely you";
				mes "must be joking~";
				next;
				switch(select("You got me, you got me.:Nope. Doesn't ring a bell.")) {
				case 1:
					emotion ET_HNG;
					mes "[Jesqurienne]";
					mes "Ohohohohoho~!";
					mes "I knew it! I knew it!";
					mes "Then again, there's little";
					mes "that a famous genius like";
					mes "myself does ^333333not^000000 know!";
					next;
					mes "[Jesqurienne]";
					mes "Gah--!";
					mes "My glass is";
					mes "already empty?";
					mes "Bartender, another";
					mes "drink please~";
					next;
					break;
				case 2:
					emotion ET_THINK;
					mes "[Jesqurienne]";
					mes "...";
					mes "......";
					mes "Now I understand.";
					mes "You've been living";
					mes "under a rock for all";
					mes "this time, haven't you?";
					next;
					mes "[Jesqurienne]";
					mes "But I guess someone";
					mes "as simple minded as you";
					mes "wouldn't recognize a famous,";
					mes "brilliant genius once you";
					mes "saw her, wouldn't you?";
					next;
					break;
				}
				break;
			case 2:
				mes "[Jesqurienne]";
				mes "Ohohohohoho~!";
				mes "I knew it! I knew it!";
				mes "Then again, there's little";
				mes "that a famous genius like";
				mes "myself does ^333333not^000000 know!";
				next;
				mes "[Jesqurienne]";
				mes "Gah--!";
				mes "My glass is";
				mes "already empty?";
				mes "Bartender, another";
				mes "drink please~";
				next;
				break;
			}
			mes "[Jesqurienne]";
			mes "Anyway, I'm so proud";
			mes "of my supreme intelligence!";
			mes "I may be somewhat obsessive";
			mes "about studying, but that's just another reason to admire me~";
			next;
			mes "[Jesqurienne]";
			mes "The Wizard and Sage";
			mes "exams? No problem~";
			mes "Even the Alchemist test";
			mes "was fairly simple. So far";
			mes "I haven't met anyone";
			mes "smarter than me~";
			next;
			switch(select("^333333Stuck-up chick.^000000:Take it easy on the drinks...")) {
			case 1:
				emotion ET_FRET;
				mes "[Jesqurienne]";
				mes "What...?";
				mes "What did you say?";
				mes "No one has ever";
				mes "said anything like";
				mes "that to me before!";
				mes "H-how dare you...";
				next;
				emotion ET_ANGER;
				mes "[Jesqurienne]";
				mes "Prove that you can";
				mes "hold a candle to my";
				mes "superior intellect and";
				mes "I'll be willing to accept";
				mes "your little insult! It's time";
				mes "for a Quiz Challenge!";
				next;
				mes "["+ strcharinfo(0) +"]";
				mes "Quiz... Challenge?";
				mes "Like a trivia game?";
				mes "But who's going to";
				mes "ask us the questions?";
				next;
				donpcevent "Aaron#sign::onSmile";
				emotion ET_SURPRISE;
				emotion ET_SURPRISE, playerattached();
				mes "[Aaron]";
				mes "Did someone say";
				mes "''Quiz Challenge?''";
				mes "I believe I can be";
				mes "of assistance.";
				next;
				set sign_q,21;
				emotion ET_KIK;
				mes "[Jesqurienne]";
				mes "Professor Aaron?";
				mes "Ho ho~ If he's asking";
				mes "the questions, it looks";
				mes "like your chances of";
				mes "beating me are zero!";
				close;
			case 2:
				mes "[Jesqurienne]";
				mes "Ho ho ho~";
				mes "Plenty of people have";
				mes "told me not to drink so";
				mes "much. But once I start";
				mes "I can't stop. I love to";
				mes "drink that much!";
				next;
				mes "[Jesqurienne]";
				mes "And...";
				mes "Sometimes I'd rather";
				mes "look at the world through";
				mes "these hazy eyes. See things";
				mes "the way I want to see them...";
				close;
			}
		}
	}
	else if ((sign_q == 21) || (sign_q == 22)) {
		mes "It amuses me that";
		mes "you think that you'd";
		mes "stand a chance against";
		mes "me in a Quiz Challenge.";
		mes "Ho ho ho ho ho~!";
		next;
		mes "[Jesqurienne]";
		mes "Professor Aaron";
		mes "is waiting for you";
		mes "to ask him to begin.";
		mes "And I'm waiting for the";
		mes "moment when you realize";
		mes "you have no hope of winning!";
		close;
	}
	else if (sign_q == 23) {
		mes "Bwahahahaha!";
		mes "You should have known";
		mes "from the beginning that you";
		mes "never had a chance! Of course,";
		mes "I did, but you know, I guess you had to learn for yourself.";
		next;
		emotion ET_FRET;
		mes "[Jesqurienne]";
		mes "I'd insult you if it weren't for the fact that you embarassed yourself enough during the Quiz Challenge. As a matter of fact, I'll even forgive you for wounding my pride earlier.";
		next;
		emotion ET_KIK;
		mes "[Jesqurienne]";
		mes "Can you believe it?";
		mes "Even drunk I can beat";
		mes "you in a test of intelligence!";
		mes "Bwahaha! I can't believe how";
		mes "simple minded you are...!";
		next;
		switch(select("I can't let you win!:Darn it...")) {
		case 1:
			set sign_q,22;
			mes "[Jesqurienne]";
			mes "You're a slow learner,";
			mes "aren't you? Well, I welcome";
			mes "your ''challenge'' anytime!";
			mes "Bwah hah hah hah hah~!";
			close;
		case 2:
			mes "[Jesqurienne]";
			mes "Just now you realize";
			mes "how pitiful your intellect";
			mes "is compared to mine? Ho ho ho!";
			mes "There's hope for every fool!";
			close;
		}
	}
	else if (sign_q == 24) {
		mes "What...?";
		mes "I... I...";
		mes "I don't b-believe it.";
		next;
		mes "[Jesqurienne]";
		mes "I lost...";
		mes "M-maybe you were right.";
		mes "I am arrogant after all...";
		mes "I should stop drinking so";
		mes "much. Travel around and";
		mes "broaden my knowledge...";
		next;
		mes "[Jesqurienne]";
		mes "You're the only";
		mes "one who has been";
		mes "able to beat me in";
		mes "a battle of minds.";
		mes "W-who are you...?";
		next;
		input .@input$;
		mes "[Jesqurienne]";
		mes ""+.@input$+"...";
		mes "I will remember that.";
		next;
		mes "[Jesqurienne]";
		set sign_q,25;
		getitem 7177,1; //Part_Of_Star's_Sob
		mes "Here...";
		mes "My old friend, Metz, told";
		mes "me to give this to someone";
		mes "who is worthy. I was going";
		mes "to keep it, but I suppose";
		mes "you're its true owner...";
		next;
		mes "[Jesqurienne]";
		mes "If you want to know more about the Sobbing Starlight, find a man named ^3131CEDearles^000000. It may be hard to find him since he wanders from place to place, but it might help to know that he loves gambling...";
		next;
		mes "[Jesqurienne]";
		mes "Good luck finding";
		mes "Dearles. I'm taking";
		mes "this loss pretty badly,";
		mes "so I think I'll stay here";
		mes "and have another drink.";
		mes "Farewell, "+.@input$+".";
		close;
	}
	else if (sign_q == 25) {
		mes "Ooooh...";
		mes "My head...";
		mes "Oh...! It's you...!";
		mes "So did you find Dearles?";
		next;
		mes "[Jesqurienne]";
		mes "Hmm...";
		mes "He's addicted to";
		mes "gambling, so maybe you";
		mes "can find him some place";
		mes "where you can do that...";
		close;
	}
	else {
		mes "OoOooOhh~";
		mes "Sooooo dizzy.";
		mes "Maybe I drank";
		mes "too much again~";
		close;
	}

OnOmg:
	emotion ET_HUK;
	end;

OnHo:
	emotion ET_DELIGHT;
	end;
}

geffen_in,61,72,7	script	Aaron#sign	754,{
	callfunc "F_UpdateSignVars";
	mes "[Aaron]";
	if (sign_q == 21) {
		mes "Alright, before";
		mes "we begin, let me";
		mes "tell you the rules...";
		next;
		emotion ET_PROFUSELY_SWEAT;
		mes "[Aaron]";
		mes "I'm going to give you";
		mes "ten multiple choice questions.";
		mes "Since this is an impromptu";
		mes "exhibition bout, I'm going to";
		mes "use questions that I use";
		mes "in teaching my class.";
		next;
		set sign_q,22;
		mes "[Aaron]";
		mes "Alright...";
		mes "I'm almost finished";
		mes "compiling the questions.";
		mes "We're ready to go when";
		mes "you're ready to begin!";
		close;
	}
	else if (sign_q == 22) {
		switch(rand(1,3)) {
		case 1:
			mes "1. Which NPC is";
			mes "not relevant to the";
			mes "Blacksmith Job Quest?";
			next;
			if (select("Baisulist:Wickebine:Barcardi:Krongast") == 3) set .@user_p,.@user_p+1;
			break;
		case 2:
			mes "1. Which item is not";
			mes "relevant to the creation";
			mes "of a Counteragent?";
			next;
			if (select("Karvodailnirol:Detrimindexta:Alcohol") != 1) set .@user_p,.@user_p+1;
			break;
		case 3:
			mes "1. Choose the";
			mes "monster that is";
			mes "a different size";
			mes "than the others.";
			next;
			if (select("Giant Whisper:Marine:Cornutus:Kobold Archer") == 2) set .@user_p,.@user_p+1;
			break;
		}
		if (rand(1,10) < 9 ) {
			donpcevent "Jesqurienne#sign::OnHo";
			mes "[Jesqurienne]";
			mes "Heh heh...";
			mes "The first question";
			mes "is always too easy!";
			set .@npc_p,.@npc_p+1;
		}
		else {
			donpcevent "Jesqurienne#sign::OnOmg";
			mes "[Jesqurienne]";
			mes "Huh...?";
			mes "How can I not know";
			mes "the answer to this?!";
		}
		next;
		switch(rand(1,3)) {
		case 1:
			mes "[Aaron]";
			mes "2. Choose the skill";
			mes "related to the Priest's";
			mes "B.S. Sacramenti from the";
			mes "ones displayed in the list.";
			next;
			if (select("Lex Divina:Gloria:Recovery:Sanctuary") == 2) set .@user_p,.@user_p+1;
			break;
		case 2:
			mes "[Aaron]";
			mes "2. Choose the material that";
			mes "is not related to the creation";
			mes "of a Condensed White Potion.";
			next;
			if (select("Medicine Bowl:Witch Starsand:Empty Bottle:Empty Potion Bottle") == 3) set .@user_p,.@user_p+1;
			break;
		case 3:
			mes "[Aaron]";
			mes "2. Choose the item that is";
			mes "necessary for a Blacksmith";
			mes "to create a Gladius.";
			next;
			if (select("Sapphire:Zircon:Topaz:Cursed Ruby") == 1) set .@user_p,.@user_p+1;
			break;
		}
		if (rand(1,10) < 8 ) {
			donpcevent "Jesqurienne#sign::OnHo";
			mes "[Jesqurienne]";
			mes "Ho ho ho ho~!";
			mes "I know the answer.";
			mes "Any fool should know";
			mes "this. But do you?";
			set .@npc_p,.@npc_p+1;
		}
		else {
			donpcevent "Jesqurienne#sign::OnOmg";
			mes "[Jesqurienne]";
			mes "Oh...";
			mes "I knew the answer";
			mes "to this just yesterday!";
			mes "Why can't I think of it now?!";
		}
		next;
		switch(rand(1,3)) {
		case 1:
			mes "[Aaron]";
			mes "3. Choose the";
			mes "property that is";
			mes "unrelated to the";
			mes "Mage's Bolt type skills.";
			next;
			if (select("Water:Earth:Fire:Wind") == 2) set .@user_p,.@user_p+1;
			break;
		case 2:
			mes "[Aaron]";
			mes "3. What is the";
			mes "Bunny Band's DEF";
			mes "and its added ability?";
			next;
			if (select("1 / LUK +2:1 / LUK +5:2 / LUK +2:2 / LUK +5") == 3) set .@user_p,.@user_p+1;
			break;
		case 3:
			mes "[Aaron]";
			mes "3. Choose the prefix or";
			mes "suffix that is incorrectly";
			mes "matched with its Monster";
			mes "Card name.";
			next;
			if (select("Hornet Card - Martyr:Requiem - Chaos:Wormtail - Clever:Golem - Immortal") == 4) set .@user_p,.@user_p+1;
			break;
		}
		if (rand(1,10) < 8 ) {
			donpcevent "Jesqurienne#sign::OnHo";
			mes "[Jesqurienne]";
			mes "Ah...";
			mes "That's another";
			mes "point for me!";
			set .@npc_p,.@npc_p+1;
		}
		else {
			donpcevent "Jesqurienne#sign::OnOmg";
			mes "[Jesqurienne]";
			mes "z...z...Z";
			mes "W-what? Oh!";
			mes "Well, I won't need";
			mes "that point anyway...";
		}
		next;
		mes "[Jesqurienne]";
		mes "Let's check our";
		mes "scores, shall we?";
		mes ".................";
		next;
		if (.@npc_p > .@user_p) {
			mes "[Jesqurienne]";
			mes "Heh heh...";
			mes "It looks like";
			mes "I'm beating you!";
			mes "But you shouldn't";
			mes "be surprised...";
		}
		else if (.@npc_p == .@user_p) {
			mes "[Jesqurienne]";
			mes "Still, you're";
			mes "smarter than";
			mes "I thought you'd be...";
		}
		else {
			mes "[Jesqurienne]";
			mes "W-wait a minute!";
			mes "H-how could you";
			mes "have more points";
			mes "than me?! I better";
			mes "get serious!";
		}
		next;
		mes "[Aaron]";
		mes "^333333*Ahem!*^000000";
		mes "Question";
		mes "number four!";
		next;
		switch(rand(1,2)) {
		case 1:
			mes "[Aaron]";
			mes "4. Choose the correct";
			mes "name of the ruler of the";
			mes "Rune-Midgarts Kingdom.";
			next;
			if (select("Tristan lll:Tristram lll:Tristar lll:Trust lll") == 2) set .@user_p,.@user_p+1;
			break;
		case 2:
			mes "[Aaron]";
			mes "4. Choose the monster";
			mes "that is a different type";
			mes "than the others.";
			next;
			if (select("Penomena:Hatii:Pest:Explosion") == 1) set .@user_p,.@user_p+1;
			break;
		}
		if (rand(1,10) < 8 ) {
			donpcevent "Jesqurienne#sign::OnHo";
			mes "[Jesqurienne]";
			mes "That counts as";
			mes "a question? You're";
			mes "being too easy!";
			set .@npc_p,.@npc_p+1;
		}
		else {
			donpcevent "Jesqurienne#sign::OnOmg";
			mes "[Jesqurienne]";
			mes "I know the";
			mes "answer! W-why";
			mes "can't I think of";
			mes "it right now?!";
		}
		next;
		if (.@npc_p > .@user_p) {
			mes "[Jesqurienne]";
			mes "Heh heh~ It looks";
			mes "like I have the lead.";
			mes "But that's only natural for";
			mes "someone as brilliant as me~";
		}
		else if (.@npc_p == .@user_p) {
			mes "[Jesqurienne]";
			mes "Up till now";
			mes "you've managed";
			mes "to keep up with";
			mes "me. Huh. So you're";
			mes "not a total idiot...";
		}
		else {
			mes "[Jesqurienne]";
			mes "Heh heh~ It looks";
			mes "like I have the lead.";
			mes "But that's only natural for";
			mes "someone as brilliant a--";
			mes "Wait. How do you have";
			mes "more points than me?!";
		}
		next;
		switch(rand(1,3)) {
		case 1:
			mes "[Aaron]";
			mes "5. Choose the monster";
			mes "which does not drop the";
			mes "'Yggdrasil Leaf' item.";
			next;
			if (select("Marduk:Baphomet Jr.:Angeling:Wanderer") == 1) set .@user_p,.@user_p+1;
			break;
		case 2:
			mes "[Aaron]";
			mes "5. Choose the job class";
			mes "that cannot equip Silk Robe.";
			next;
			if (select("Swordman:Merchant:Hunter:Mage") == 3) set .@user_p,.@user_p+1;
			break;
		case 3:
			mes "[Aaron]";
			mes "5. Choose the level";
			mes "requirement for entering";
			mes "the PvP Room.";
			next;
			if (select("30:31:32:33") == 2) set .@user_p,.@user_p+1;
			break;
		}
		set zis_5,rand(1,10);
		if (rand(1,10) < 9 ) {
			donpcevent "Jesqurienne#sign::OnHo";
			mes "[Jesqurienne]";
			mes "I didn't have";
			mes "to think very hard";
			mes "to know the answer.";
			mes "Are you still thinking?";
			mes "I wouldn't think you'd know!";
			set .@npc_p,.@npc_p+1;
		}
		else {
			donpcevent "Jesqurienne#sign::OnOmg";
			mes "[Jesqurienne]";
			mes "I...";
			mes "Hold on,";
			mes "I know this one...";
			mes "(Oh craaaaaap!)";
		}
		next;
		if (.@npc_p > .@user_p) {
			mes "[Jesqurienne]";
			mes "Oh? What a surprise.";
			mes "I'm in the lead. I know";
			mes "the suspense must be";
			mes "killing you, but I'm pretty";
			mes "sure who the winner will";
			mes "be. Me me me meee~";
		}
		else if (.@npc_p == .@user_p) {
			mes "[Jesqurienne]";
			mes "Are you copying";
			mes "my answers? Because";
			mes "there's no way we can";
			mes "be tied right now...";
		}
		else {
			mes "[Jesqurienne]";
			mes "I...";
			mes "I must be more";
			mes "drunk than I thought";
			mes "if I'm losing right now...";
		}
		next;
		switch(rand(1,3)) {
		case 1:
			mes "[Aaron]";
			mes "6. What is the";
			mes "correct weight";
			mes "for 1 Empty Bottle?";
			next;
			if (select("1:2:3") == 2) set .@user_p,.@user_p+1;
			break;
		case 2:
			mes "[Aaron]";
			mes "6. Choose the";
			mes "correct DEF for";
			mes "the Indian Filet item.";
			next;
			if (select("0:1:2:3") == 4) set .@user_p,.@user_p+1;
			break;
		case 3:
			mes "[Aaron]";
			mes "6. What is the";
			mes "city closest to";
			mes "Turtle Island?";
			next;
			if (select("Al De Baran:Alberta:Comodo:Izlude") == 2) set .@user_p,.@user_p+1;
			break;
		}
		if (rand(1,10) < 9 ) {
			donpcevent "Jesqurienne#sign::OnHo";
			mes "[Jesqurienne]";
			mes "^333333*Sigh...*^000000";
			mes "Simple questions,";
			mes "simple answers.";
			mes "Did you get it?";
			set .@npc_p,.@npc_p+1;
		}
		else {
			donpcevent "Jesqurienne#sign::OnOmg";
			mes "[Jesqurienne]";
			mes "W-wait...!";
			mes "I know the";
			mes "answer to this";
			mes "one! Just let me";
			mes "th-think...!";
		}
		next;
		if (.@npc_p > .@user_p) {
			mes "[Jesqurienne]";
			mes "Oh, look at that.";
			mes "I have more points";
			mes "than you. I know, it";
			mes "must be frustrating";
			mes "trying to keep up.";
		}
		else if (.@npc_p == .@user_p) {
			mes "[Jesqurienne]";
			mes "Mmm...?";
			mes "How are you cheating?!";
			mes "You having the same score";
			mes "as me must be impossible!";
		}
		else {
			mes "[Jesqurienne]";
			mes "I don't understand.";
			mes "You have a higher sco--";
			mes "I don't-- How can yo--";
			mes "Why is this happening?";
		}
		next;
		switch(rand(1,3)) {
		case 1:
			mes "[Aaron]";
			mes "7. Fifty-one multiplied";
			mes "by fifteen, divided by three,";
			mes "plus five is equal to...?";
			next;
			if (select("250:255:260:265") == 3) set .@user_p,.@user_p+1;
			break;
		case 2:
			mes "[Aaron]";
			mes "7. Four thousand five hundred sixty divided by four, divided by two, plus three is equal to...?";
			next;
			if (select("573:574:575:576") == 1) set .@user_p,.@user_p+1;
			break;
		case 3:
			mes "[Aaron]";
			mes "7. Three thousand one hundred";
			mes "two added to five hundred, plus four, divided by six equals...";
			next;
			if (select("600:601:602") == 2) set .@user_p,.@user_p+1;
			break;
		}
		if (rand(1,10) < 9 ) {
			donpcevent "Jesqurienne#sign::OnHo";
			mes "[Jesqurienne]";
			mes "Math?";
			mes "My mind is";
			mes "a veritable";
			mes "calculator!";
			mes "Ho ho ho~!";
			set .@npc_p,.@npc_p+1;
		}
		else {
			donpcevent "Jesqurienne#sign::OnOmg";
			mes "[Jesqurienne]";
			mes "What the--?!";
			mes "Why is all the math";
			mes "written out in words";
			mes "instead of the traditional";
			mes "numerics and symbols?!";
			mes "A-answer me--!!";
		}
		next;
		if (.@npc_p > .@user_p) {
			mes "[Jesqurienne]";
			mes "Ah. Did I tell you";
			mes "I was in the lead";
			mes "right now? Well, let";
			mes "me remind you, in case";
			mes "I forget. Ho ho ho ho~!";
		}
		else if (.@npc_p == .@user_p) {
			mes "[Jesqurienne]";
			mes "That's it.";
			mes "I don't understand";
			mes "how your score is";
			mes "equal to mine. Are";
			mes "you getting bonus";
			mes "points somehow?!";
		}
		else {
			mes "[Jesqurienne]";
			mes "There's no other";
			mes "explanation! You've";
			mes "got to be using some";
			mes "sort of crib sheet! But";
			mes "where are you hiding it?";
		}
		next;
		switch(rand(1,2)) {
		case 1:
			mes "[Aaron]";
			mes "8. Choose the building";
			mes "that is the closest to the";
			mes "Item Upgrade Place in Juno.";
			next;
			if (select("Tavern:Monster Library:Tool Shop:Weapon Shop") == 4) set .@user_p,.@user_p+1;
			break;
		case 2:
			mes "[Aaron]";
			mes "8. Choose the Hunter's";
			mes "Trap skill which does not";
			mes "inflict Property Damage.";
			next;
			if (select("Claymore Trap:Freezing Trap:Shockwave Trap:Land Mine") == 3) set .@user_p,.@user_p+1;
			break;
		}
		if ( rand(1,10) < 9 ) {
			donpcevent "Jesqurienne#sign::OnHo";
			mes "[Jesqurienne]";
			mes "Hah hah~!";
			mes "That was a";
			mes "piece of cake!";
			set .@npc_p,.@npc_p+1;
		}
		else {
			donpcevent "Jesqurienne#sign::OnOmg";
			mes "[Jesqurienne]";
			mes "Grrr...";
			mes "Why don't";
			mes "I know this one?!";
		}
		next;
		if (.@npc_p > .@user_p) {
			mes "[Jesqurienne]";
			mes "I know, you're wondering";
			mes "how such an intelligent";
			mes "person can exist. Well,";
			mes "I guess my intellect sort";
			mes "of balances the stupidity";
			mes "of the rest of the world...";
		}
		else if (.@npc_p == .@user_p) {
			mes "[Jesqurienne]";
			mes "How can our scores";
			mes "be equal? No... No...";
			mes "Think, Jesqurienne...";
			mes "Time travel isn't possible.";
			mes "But why would you time travel";
			mes "for the answers to a quiz?";
		}
		else {
			mes "[Jesqurienne]";
			mes "I... I don't";
			mes "get it. H-how are";
			mes "you w-winning? M-my";
			mes "whole perception of";
			mes "reality is starting t-to...";
		}
		next;
		switch(rand(1,2)) {
		case 1:
			mes "[Aaron]";
			mes "9. Which monster would";
			mes "receive the most damage";
			mes "from a Fire Property Dagger?";
			next;
			if (select("Dagger Goblin:Mace Goblin:Morning Star Goblin:Hammer Goblin") == 4) set .@user_p,.@user_p+1;
			break;
		case 2:
			mes "[Aaron]";
			mes "9. Choose the monster";
			mes "on which the Mage skill,";
			mes "''Stone Curse,'' is ineffective. ^FFFFFFaaaaaa aaaaaaa aaaaaa aaaaaaa aaaaaaaaa^000000";
			next;
			if (select("Elder Willow:Evil Druid:Magnolia:Marc") == 2) set .@user_p,.@user_p+1;
			break;
		}
		if ( rand(1,10) < 9 ) {
			donpcevent "Jesqurienne#sign::OnHo";
			mes "[Jesqurienne]";
			mes "Ahhh...";
			mes "I'm just breezing";
			mes "through this Quiz Challenge!";
			mes "Aren't you having a hard time?";
			set .@npc_p,.@npc_p+1;
		}
		else {
			donpcevent "Jesqurienne#sign::OnOmg";
			mes "[Jesqurienne]";
			mes "Huh...?";
			mes "I don't understand";
			mes "why I don't know this...";
		}
		next;
		if (.@npc_p > .@user_p) {
			mes "[Jesqurienne]";
			mes "Bwahahaha!";
			mes "Only one question";
			mes "left! You have to get";
			mes "this one right or I'll";
			mes "call you stupid forever!";
		}
		else if (.@npc_p == .@user_p) {
			mes "[Jesqurienne]";
			mes "We're tied?!";
			mes "Oh no... I better";
			mes "get this last question";
			mes "right. (And I hope that";
			mes "you get it wrong!)";
		}
		else {
			mes "[Jesqurienne]";
			mes "I'm losing?!";
			mes "And we're at the";
			mes "last question already?!";
		}
		next;
		switch(rand(1,2)) {
		case 1:
			mes "[Aaron]";
			mes "10. Choose the NPC";
			mes "that looks different";
			mes "than all the others.";
			next;
			if (select("Prontera Hollgrehenn:Prontera Doll Merchant:Izlude Meat Merchant:Morocc Meat Merchant") == 3) set .@user_p,.@user_p+1;
			break;
		case 2:
			mes "[Aaron]";
			mes "10. Choose the item";
			mes "that cannot be equipped";
			mes "by Novice class characters.";
			next;
			if (select("Funeral Hat:Shackles:Wooden Mail:Pantie") == 3) set .@user_p,.@user_p+1;
			break;
		}
		if ( rand(1,10) < 9 ) {
			donpcevent "Jesqurienne#sign::OnHo";
			mes "[Jesqurienne]";
			mes "As usual, I got";
			mes "the last question";
			mes "absolutely right~";
			set .@npc_p,.@npc_p+1;
		}
		else {
			donpcevent "Jesqurienne#sign::OnOmg";
			mes "[Jesqurienne]";
			mes "Huh...";
			mes "Wh-what was";
			mes "the question again?";
			mes "Nooo, I missed it!";
		}
		next;
		mes "[Aaron]";
		mes "Okay, the quiz";
		mes "is over! Now, I'll";
		mes "reveal the results";
		mes "of the competitors...";
		next;
		mes "[Aaron]";
		mes "Umm...";
		mes ""+ strcharinfo(0) +":";
		mes ""+.@user_p+" points!";
		next;
		mes "[Aaron]";
		mes "Jesqurienne...";
		mes ""+.@npc_p+" points!";
		next;
		if (.@npc_p > .@user_p) {
			set sign_q,23;
			emotion ET_KIK;
			mes "[Jesqurienne]";
			mes "Bwahahaha!";
			mes "I win! I knew it!";
			mes "Ho ho ho ho ho ho~";
		}
		else if (.@npc_p == .@user_p) {
			set sign_q,24;
			mes "[Jesqurienne]";
			mes "Tied?! ";
			mes "Alright, I'm impressed.";
			mes "I'll admit, you're much";
			mes "smarter than I thought...";
		}
		else {
			set sign_q,24;
			mes "[Jesqurienne]";
			mes "No...!";
			mes "I can't...";
			mes "Believe this...";
		}
		next;
		mes "[Aaron]";
		mes "Thank you";
		mes "for playing!";
		mes ".......................";
		mes "...........................";
		mes "Alright, back to drinking!";
		close;
	}
	else {
		emotion ET_HUK;
		mes "Goodness...!";
		mes "Either these beer";
		mes "goggles are on too tight,";
		mes "or you're the most gorgeous";
		mes "woman I've seen in my life!";
		next;
		if (Sex == SEX_MALE) {
			select("Um, I'm a dude...");
			emotion ET_CRY;
			mes "[Aaron]";
			mes "N-no...!";
			mes "M-maybe I should";
			mes "take it easy on the";
			mes "alcohol. I do have classes";
			mes "to teach tomorrow anyway...";
		}
		else {
			select("Why, thank you~");
			emotion ET_BEST;
			mes "[Aaron]";
			mes "Ah, yes. Your";
			mes "sense of style, your";
			mes "magnificent body. Everything";
			mes "about you is beautiful! Not just that, but you're also intelligent!";
			next;
			emotion ET_BIGTHROB;
			mes "[Aaron]";
			mes "I should know!";
			mes "Not only do I teach";
			mes "classes, but I'm also";
			mes "a Quiz Challenge moderater";
			mes "master in my spare time~";
			mes "You're truly a jewel...";
		}
		close;
	}
OnSmile:
	emotion ET_SMILE;
	end;
}

cmd_in02,88,51,4	script	Strange Guy#sign	806,{
	callfunc "F_UpdateSignVars";
	mes "[Dearles]";
	if (sign_q < 25) {
		mes "No...! Damn it,";
		mes "not again! When's";
		mes "my lucky streak";
		mes "gonna start?";
		next;
		mes "[Dearles]";
		mes "Hey, you've got that look";
		mes "like you want something from";
		if (Zeny < 10000) {
			mes "me. Hah! You are poor!";
			emotion ET_HNG;
			mes "It also looks like you're low on cash~! Well, this is what guys like me to do to shameless";
			mes "moochers like you!";
			percentheal -10,0;
			close;
		}
		else {
			mes "me. It also looks like you got zeny to spare! I think I'll help myself and borrow some of your cash!";
			mes "^FF0000Yoink!^000000";
			set Zeny, Zeny-10000;
			specialeffect EF_COIN;
			close;
		}
	}
	else if (sign_q == 25) {
		mes "No...! Damn it,";
		mes "not again! When's";
		mes "my lucky streak";
		mes "gonna start?";
		next;
		switch(select("Excuse me...:Just pass by.")) {
		case 1:
			mes "[Dearles]";
			mes "What is it?!";
			mes "I'm not in the mood";
			mes "for chatting with complete";
			mes "and total strangers, so";
			mes "get to the point~!";
			next;
			switch(select("Oh, nothing.:I'm here for Metz...?")) {
			case 1:
				mes "[Dearles]";
				mes "Wha...? You bother";
				mes "me and make lose this";
				mes "game for nothing? For that,";
				mes "I'll freakin' beat you to near";
				mes "freakin' death! Bam bam bam!";
				close2;
				percentheal -100,0;
				soundeffect "effect\\sign_noise.wav",1;
				percentheal -99,0;
				warp "comodo",122,100;
				end;
			case 2:
				mes "[Dearles]";
				mes "Oh. You're here for";
				mes "the Sobbing Starlight, huh? If you wanna take my test, there's *ahem* a fee of 30,000 zeny. So take it or leave it, capish?";
				next;
				mes "[Dearles]";
				mes "I'll have nothing";
				mes "to do with you if you";
				mes "can't pay up. Just think";
				mes "of the fee as a preliminary";
				mes "for my test. You know, to";
				mes "weed out the riffraff.";
				set sign_q,26;
				close;
			}
		case 2:
			mes "[Dearles]";
			mes "Crap...!";
			mes "I'm almost broke!";
			mes "But I gotta win all";
			mes "my cash back! How can";
			mes "I raise more money fast";
			mes "without actually working...";
			close;
		}
	}
	else if (sign_q == 26) {
		mes "Eh heh heh~";
		mes "Soooooo, did you";
		mes "bring the money?";
		next;
		switch(select("Here you are...:Not yet...")) {
		case 1:
			mes "[Dearles]";
			mes "Ummm.......";
			if (Zeny < 30000) {
				mes "When I say 30,000 zeny,";
				mes "I mean 30,000 zeny! I'll let";
				mes "you off on account of you looking like you're not smart enough to know how to count. But pull this";
				mes "on me again and I'll...!";
			}
			else {
				mes "Heh heh~";
				mes "That's thirty grand,";
				mes "alright! Okay, come back";
				mes "to me tomorrow night and";
				mes "we'll start your test...";
				set sign_q,27;
				set Zeny, Zeny-30000;
			}
			close;
		case 2:
			mes "[Dearles]";
			mes "Huh...?";
			mes "Alright, but you";
			mes "better hurry. I can";
			mes "change my mind at";
			mes "any time, you know!";
			close;
		}
	}
	else if (sign_q == 27) {
		// if ((gettime(DT_HOUR) > 18) && (gettime(DT_HOUR) < 23)) {
			mes "Nice, you're here";
			mes "just in time. Well,";
			mes "all that matters is that";
			mes "you come during the night.";
			next;
			mes "[Dearles]";
			mes "You're wondering how";
			mes "a guy like me is pals with";
			mes "Metz, but that's none of your";
			mes "business. I guess I gotta keep";
			mes "this promise to him, so when";
			mes "you're ready, say the word.";
			set sign_q,28;
			close;
		// }
		// else {
		// 	mes "Hey... When I say";
		// 	mes "''tomorrow night,'' I mean,";
		// 	mes "come and talk to me at nighttime! Don't you know anything about shady dealings?! Pfft! Adventurers...";
		// 	close;
		// }
	}
	else if (sign_q== 28) {
		mes "Alright! I want you to";
		mes "bring me a bunch of items!";
		mes "Yeah, I know, you're a real";
		mes "pro at this, but let me set";
		mes "you straight before you blow";
		mes "this off as a piece of cake...";
		next;
		mes "[Dearles]";
		mes "I'm not gonna give you an";
		mes "exact list of items I want. Oh";
		mes "no, what you gotta do is bring";
		mes "me artsy crafts. This test is";
		mes "gonna judge your appreciation";
		mes "for... Craftsmanship~";
		next;
		mes "[Dearles]";
		mes "Since I'm seeing whether";
		mes "or not you got good taste,";
		mes "variety is the important thing";
		mes "here. So don't bring freakin'";
		mes "a hundred of the same object.";
		mes "Just one of each kind'll do.";
		next;
		mes "[Dearles]";
		mes "What are you";
		mes "standin' around";
		mes "waiting for? Bring";
		mes "those collection items!";
		set sign_q,29;
		close;
	}
	else if (sign_q < 35) {
		switch(sign_q) {
		case 29:
			mes "Ah, so is this";
			mes "the stuff you brought?";
			mes "Lemme take a look-see...";
			if (countitem(734)) set .@diaris_t,.@diaris_t+1;
			if (countitem(735)) set .@diaris_t,.@diaris_t+1;
			if (countitem(736)) set .@diaris_t,.@diaris_t+1;
			if (countitem(7149)) set .@diaris_t,.@diaris_t+1;
			if (countitem(747)) set .@diaris_t,.@diaris_t+2;
			if (countitem(749)) set .@diaris_t,.@diaris_t+4;
			if (countitem(740)) set .@diaris_t,.@diaris_t+1;
			if (countitem(741)) set .@diaris_t,.@diaris_t+1;
			if (countitem(742)) set .@diaris_t,.@diaris_t+2;
			if (countitem(743)) set .@diaris_t,.@diaris_t+3;
			if (countitem(752)) set .@diaris_t,.@diaris_t+3;
			if (countitem(753)) set .@diaris_t,.@diaris_t+4;
			if (countitem(754)) set .@diaris_t,.@diaris_t+4;
			if (countitem(750)) set .@diaris_t,.@diaris_t+7;
			if (countitem(751)) set .@diaris_t,.@diaris_t+7;
			next;
			if (.@diaris_t > 10) {
				mes "[Dearles]";
				mes "Nice, nice~";
				mes "These'll sell for--";
				mes "Er, I'm glad to say";
				mes "that you pass for now.";
				next;
				mes "[Dearles]";
				mes "I think you're ready";
				mes "for the next step. Now,";
				mes "I'm gonna send you to";
				mes "Lamadin for Part Two";
				mes "of my test. Yeah, I know...";
				if (countitem(734)) delitem 734,1; //Red_Frame
				if (countitem(735)) delitem 735,1; //Blue_Porcelain
				if (countitem(736)) delitem 736,1; //White_Platter
				if (countitem(7149)) delitem 7149,1; //Yellow_Plate
				if (countitem(747)) delitem 747,1; //Crystal_Mirror
				if (countitem(749)) delitem 749,1; //Frozen_Rose
				if (countitem(740)) delitem 740,1; //Stuffed_Doll
				if (countitem(741)) delitem 741,1; //Poring_Doll
				if (countitem(742)) delitem 742,1; //Chonchon_Doll
				if (countitem(743)) delitem 743,1; //Spore_Doll
				if (countitem(752)) delitem 752,1; //Grasshopper_Doll
				if (countitem(753)) delitem 753,1; //Monkey_Doll
				if (countitem(754)) delitem 754,1; //Raccoondog_Doll
				if (countitem(750)) delitem 750,1; //Baphomet_Doll
				if (countitem(751)) delitem 751,1; //Osiris_Doll
				set sign_q,30;
				if (checkre(3)) {
					if (BaseLevel < 60) getexp 300,0;
					else if (BaseLevel < 70) getexp 500,0;
					else if (BaseLevel < 80) getexp 800,0;
					else if (BaseLevel < 90) getexp 1000,0;
					else getexp 1300,0;
				} else {
					if (BaseLevel < 60) getexp 3000,0;
					else if (BaseLevel < 70) getexp 5000,0;
					else if (BaseLevel < 80) getexp 8000,0;
					else if (BaseLevel < 90) getexp 10000,0;
					else getexp 13000,0;
				}
				next;
				warp "cmd_in01",33,29;
				end;
			}
			else if ((.@diaris_t > 0) && (.@diaris_t < 11)) {
				mes "[Dearles]";
				mes "Hmm... Some of this";
				mes "stuff looks good, but";
				mes "there isn't enough variety";
				mes "here that proves your eye for";
				mes "craftsmanship. Come back";
				mes "with more stuff, alright?";
				close;
			}
			else {
				mes "[Dearles]";
				mes "Hmm...";
				mes "All the stuff you're";
				mes "carrying? Worthless junk!";
				mes "Go and find stuff that was";
				mes "skillfully crafted, okay?";
				next;
				mes "[Dearles]";
				mes "And by crafts I don't mean";
				mes "potions, weapons, equipment,";
				mes "none of that. Just think of, well, stuff you'd show off in your rooom and you'll be on the right track. Remember, variety!";
				close;
			}
		case 30:
		case 31:
			mes "Hey, you gotta";
			mes "finish Part Two of";
			mes "my test. I'm gonna send";
			mes "you to Lamadin now...";
			close2;
			warp "cmd_in01",33,29;
			end;
		case 32:
			mes "You failed Part Two,";
			mes "the rhythm portion of";
			mes "my freakin' test?! If you";
			mes "wanna try again, you're";
			mes "welcome to another chance...";
			next;
			switch(select("Yes.:Maybe later.")) {
			case 1:
				mes "[Dearles]";
				mes "Okay...";
				mes "Just keep in mind";
				mes "that Part Two was ";
				mes "supposed to be";
				mes "the easy part...";
				close2;
				warp "cmd_in01",33,29;
				end;
			case 2:
				mes "[Dearles]";
				mes "What...?";
				mes "Alright, but you";
				mes "really shouldn't give";
				mes "up. I mean, Part Two is";
				mes "supposed to be ridiculously";
				mes "easy. I made it that way...";
				close;
			}
		case 33:
			mes "Alright, Lamadin";
			mes "tells me you passed.";
			mes "Not the best performance,";
			mes "but it's good enough.";
			next;
			mes "[Dearles]";
			mes "Alright, take this chunk";
			mes "of Sobbing Starlight and";
			mes "go find someone named,";
			mes "um, ''Bakerlan'' in Alberta.";
			set sign_q,35;
			getitem 7177,1; //Part_Of_Star's_Sob
			if (checkre(3)) {
				if (BaseLevel < 60) getexp 300,0;
				else if (BaseLevel < 70) getexp 700,0;
				else if (BaseLevel < 80) getexp 1900,0;
				else if (BaseLevel < 90) getexp 1200,0;
				else getexp 1700,0;
			} else {
				if (BaseLevel < 60) getexp 3000,0;
				else if (BaseLevel < 70) getexp 7000,0;
				else if (BaseLevel < 80) getexp 19000,0;
				else if (BaseLevel < 90) getexp 12000,0;
				else getexp 17000,0;
			}
			next;
			mes "[Dearles]";
			mes "Well, that's it.";
			mes "There's no reason";
			mes "for you to ever see";
			mes "me again. But yeah,";
			mes "good luck with that";
			mes "Sobbing Starlight business.";
			close;
		case 34:
			mes "Lamadin tells me";
			mes "you passed. Since you";
			mes "did so good, I'm gonna";
			mes "give you ^333333some^000000 of your money";
			mes "back. Not all, but most of it.";
			mes "Isn't that reward enough?";
			next;
			mes "[Dearles]";
			mes "Alright, take this chunk";
			mes "of Sobbing Starlight and";
			mes "go find someone named,";
			mes "um, ''Bakerlan'' in Alberta.";
			set sign_q,35;
			getitem 7177,1; //Part_Of_Star's_Sob
			set Zeny, Zeny+20000;
			if (checkre(3)) {
				if (BaseLevel < 60) getexp 300,0;
				else if (BaseLevel < 70) getexp 700,0;
				else if (BaseLevel < 80) getexp 1000,0;
				else if (BaseLevel < 90) getexp 1400,0;
				else getexp 1900,0;
			} else {
				if (BaseLevel < 60) getexp 3000,0;
				else if (BaseLevel < 70) getexp 7000,0;
				else if (BaseLevel < 80) getexp 10000,0;
				else if (BaseLevel < 90) getexp 14000,0;
				else getexp 19000,0;
			}
			next;
			mes "[Dearles]";
			mes "Well, that's it.";
			mes "There's no reason";
			mes "for you to ever see";
			mes "me again. But yeah,";
			mes "good luck with that";
			mes "Sobbing Starlight business.";
			close;
		}
	}
	else if (sign_q == 97) {
		mes "No...! Damn it,";
		mes "not again! When's";
		mes "my lucky streak";
		mes "gonna start?";
		next;
		mes "[Dearles]";
		mes "Hey, you've got that look";
		mes "like you want something from";
		if (Zeny < 10000) {
			mes "me. It also looks like you're low on cash~! Well, this is what guys like me to do to shameless";
			mes "moochers like you!";
			emotion ET_HNG;
			percentheal -10,0;
			close;
		}
		else {
			mes "me. It also looks like you got zeny to spare! I think I'll help myself and borrow some of your cash!";
			mes "^FF0000Yoink!^000000";
			mes "Giggle giggle..";
			set Zeny, Zeny-10000;
			close;
		}
	}
	else if (sign_q == 98) {
		mes "Whaaaaaaaaaat are";
		mes "you doing back here?";
		if (Zeny > 9999) {
			mes "Fine, since we know each";
			mes "other, I'm borrowing some";
			mes "cash. You know, for old";
			mes "time's sake. ^FF0000Yoink!^000000";
			emotion ET_KIK;
			set Zeny, Zeny-10000;
		}
		else {
			mes "I got nothin' for you and";
			mes "you obviously have nothing";
			mes "for me! Now lemme gamble!";
			emotion ET_HNG;
		}
		close;
	}
	else {
		mes "Hey, why are you";
		mes "still talkin' to me?";
		mes "You finished my test.";
		mes "It's over. Not get outta";
		mes "here before I jack some";
		mes "more of your cash!";
		emotion ET_KIK;
		next;
		switch(select("Okay.:I want to take Part Two again.")) {
		case 1:
			mes "[Dearles]";
			mes "Fine, fine.";
			mes "Geez, why do";
			mes "these guys always";
			mes "come and bother me?";
			emotion ET_HNG;
			close;
		case 2:
			mes "[Dearles]";
			mes "Wha...?";
			mes "Part Two";
			mes "was really";
			mes "that fun? Fine,";
			mes "knock yourself out.";
			next;
			warp "cmd_in01",33,29;
			end;
		}
	}
}

cmd_in01,33,25,5	script	Examiner#sign	724,{
	callfunc "F_UpdateSignVars";
	mes "[Lamadin]";
	if (sign_q == 30) {
		mes "Welcome to";
		mes "Part Two of Dearles'";
		mes "exam where your sense";
		mes "of rhythm will be tested~";
		next;
		mes "[Lamadin]";
		mes "Please click on the";
		mes "Chat Room to enter the";
		mes "Standby Room. When it's";
		mes "your turn, the test will begin!";
		next;
		mes "[Lamadin]";
		mes "The top left pole";
		mes "means 'Up,' and there";
		mes "are a total of four marks";
		mes "designated as Upper, Lower";
		mes "Left and Right. Hitting each";
		mes "mark will produce a sound.";
		next;
		mes "[Lamadin]";
		mes "During the test,";
		mes "you must hit the marks";
		mes "according to the given";
		mes "instructions in order to";
		mes "play music. Nifty, huh?";
		next;
		mes "[Lamadin]";
		mes "I'm in charge of grading";
		mes "your performance and determining your qualification. Please do your best and come back to me when";
		mes "you finish the test. Good luck~";
		mes "Please do your best.";
		close;
	}
	else if (sign_q == 31) {
		set sign_q,30;
		mes "Please click on the";
		mes "Chat Room to enter the";
		mes "Standby Room. When it's";
		mes "your turn, the test will begin!";
		next;
		mes "[Lamadin]";
		mes "The top left pole";
		mes "means 'Up,' and there";
		mes "are a total of four marks";
		mes "designated as Upper, Lower";
		mes "Left and Right. Hitting each";
		mes "mark will produce a sound.";
		next;
		mes "[Lamadin]";
		mes "During the test,";
		mes "you must hit the marks";
		mes "according to the given";
		mes "instructions in order to";
		mes "play music. Nifty, huh?";
		next;
		mes "[Lamadin]";
		mes "I'm in charge of grading";
		mes "your performance and determining your qualification. Please do your best and come back to me when";
		mes "you finish the test. Good luck~";
		mes "Please do your best.";
		close;
	}
	else if (sign_q == 32) {
		mes "Let's see...";
		mes "You're "+ strcharinfo(0) +"?";
		mes "Oh, what a shame!";
		mes "You failed this time.";
		mes "But don't you worry...";
		next;
		mes "[Lamadin]";
		mes "You're welcome to";
		mes "try again whenever";
		mes "you want, alright?";
		mes "Thank you~";
		set sign_q,30;
		close;
	}
	else if (sign_q == 33) {
		mes "Let's see...";
		mes "You're "+ strcharinfo(0) +"?";
		mes "Congratulations!";
		mes "You passed the test!";
		next;
		mes "[Lamadin]";
		mes "I'll send a message to";
		mes "Mister Dearles right away,";
		mes "so please go speak to him";
		mes "again. Once again, great job~ ";
		close;
	}
	else if (sign_q == 34) {
		mes "Let's see...";
		mes "You're "+ strcharinfo(0) +"?";
		mes "Congratulations!";
		mes "You got a perfect";
		mes "score on this test!";
		next;
		mes "[Lamadin]";
		mes "I'll send a message to";
		mes "Mister Dearles right away,";
		mes "so please go speak to him";
		mes "again. He may even give";
		mes "you a reward since you";
		mes "did such a great job~";
		close;
	}
	else {
		mes "H-how did you";
		mes "find your way here?";
		mes "This is private property,";
		mes "owned by Mister Dearles.";
		mes "Please leave immediately!";
		next;
		warp "comodo",187,164;
		end;
	}
}

cmd_in01,16,24,0	script	Emergency Exit	111,{
	mes "[Exit]";
	mes "Would you like to go out?";
	next;
	switch(select("Yes.:No.")) {
	case 1:
		mes "[Exit]";
		mes "Farewell.";
		next;
		warp "comodo",187,163;
		end;
	case 2:
		mes "[Exit]";
		mes "..........";
		close;
	}
}

cmd_in01,33,33,1	script	Standby Room#sign	66,{
	end;

OnInit:
	waitingroom "DANCE~ DANCE~",20,"Standby Room#sign::OnStartArena",1,0,50;
	enablewaitingroomevent;
	end;

OnStartArena:
	donpcevent "s_dance_timer::OnButton_Off";
	donpcevent "Examiner#sd::OnDisable";
	warpwaitingpc "cmd_in01",16,15,1;
	donpcevent "s_dance_timer::OnEnable";
	disablewaitingroomevent;
	end;

OnReset:
	enablewaitingroomevent;
	end;
}

cmd_in01,1,1,0	script	s_dance_timer	-1,{
OnEnable:
	initnpctimer;
	end;

OnDisable:
	stopnpctimer;
	end;

OnButton_Off:
	callsub OnDisableAll;
	end;

OnDisableAll:
	donpcevent "s_dance#up::OnDisable";
	donpcevent "s_dance#down::OnDisable";
	donpcevent "s_dance#left::OnDisable";
	donpcevent "s_dance#right::OnDisable";
	donpcevent "s_dance#cen::OnDisable";
	return;

OnTimer2000:
	mapannounce "cmd_in01","The test will be begin shortly. Please do your best~",bc_map,"0xFFFF00";
	end;

OnTimer4000:
	mapannounce "cmd_in01"," UP LEFT",bc_map,"0xFFFF00";
	donpcevent "s_dance#up::OnUp";
	donpcevent "s_dance#up::OnEnable";
	end;

OnTimer6000:
	callsub OnDisableAll;
	mapannounce "cmd_in01"," DOWN RIGHT",bc_map,"0xFFFF00";
	donpcevent "s_dance#down::OnUp";
	donpcevent "s_dance#down::OnEnable";
	end;

OnTimer8000:
	callsub OnDisableAll;
	mapannounce "cmd_in01"," DOWN LEFT & UP RIGHT",bc_map,"0xFFFF00";
	donpcevent "s_dance#left::OnUp";
	donpcevent "s_dance#left::OnEnable";
	end;

OnTimer11000:
	callsub OnDisableAll;
	mapannounce "cmd_in01"," DOWN RIGHT",bc_map,"0xFFFF00";
	donpcevent "s_dance#down::OnUp";
	donpcevent "s_dance#down::OnEnable";
	end;

OnTimer13000:
	callsub OnDisableAll;
	mapannounce "cmd_in01"," DOWN LEFT & UP RIGHT & UP LEFT & STAY CENTER",bc_map,"0xFFFF00";
	donpcevent "s_dance#left::OnUp";
	donpcevent "s_dance#left::OnEnable";
	end;

OnTimer18000:
	callsub OnDisableAll;
	mapannounce "cmd_in01"," DOWN LEFT & DOWN RIGHT & DOWN LEFT",bc_map,"0xFFFF00";
	donpcevent "s_dance#left::OnUp";
	donpcevent "s_dance#left::OnEnable";
	end;

OnTimer21000:
	callsub OnDisableAll;
	mapannounce "cmd_in01"," DOWN RIGHT & CENTER & DOWN RIGHT",bc_map,"0xFFFF00";
	donpcevent "s_dance#down::OnUp";
	donpcevent "s_dance#down::OnEnable";
	end;

OnTimer24000:
	callsub OnDisableAll;
	mapannounce "cmd_in01"," DOWN LEFT & UP LEFT & UP RIGHT & DOWN RIGHT & CENTER",bc_map,"0xFFFF00";
	donpcevent "s_dance#left::OnUp";
	donpcevent "s_dance#left::OnEnable";
	end;

OnTimer30000:
	callsub OnDisableAll;
	mapannounce "cmd_in01"," DOWN LEFT & UP RIGHT & UP LEFT & DOWN RIGHT",bc_map,"0xFFFF00";
	donpcevent "s_dance#left::OnUp";
	donpcevent "s_dance#left::OnEnable";
	end;

OnTimer34000:
	callsub OnDisableAll;
	mapannounce "cmd_in01"," UP RIGHT & DOWN RIGHT & UP RIGHT & DOWN RIGHT",bc_map,"0xFFFF00";
	donpcevent "s_dance#right::OnUp";
	donpcevent "s_dance#right::OnEnable";
	end;

OnTimer38000:
	callsub OnDisableAll;
	mapannounce "cmd_in01"," UP LEFT & UP RIGHT & CENTER & UP RIGHT & DOWN LEFT & DOWN RIGHT",bc_map,"0xFFFF00";
	donpcevent "s_dance#up::OnUp";
	donpcevent "s_dance#up::OnEnable";
	end;

OnTimer44000:
	stopnpctimer;
	donpcevent "s_dance#up::OnReset";
	donpcevent "s_dance#down::OnReset";
	donpcevent "s_dance#left::OnReset";
	donpcevent "s_dance#right::OnReset";
	donpcevent "s_dance#cen::OnReset";
	mapannounce "cmd_in01","Well done.",bc_map,"0xFFFF00";
	enablenpc "Examiner#sd";
	donpcevent "Standby Room#sign::OnReset";
	end;
}

cmd_in01,16,21,0	script	s_dance#up	139,1,3,{
OnInit:
	disablenpc "s_dance#up";
	end;

OnEnable:
	enablenpc "s_dance#up";
	specialeffect EF_SUMMONSLAVE;
	end;

OnDisable:
	//specialeffect EF_SUMMONSLAVE;
	disablenpc "s_dance#up";
	end;

OnUp:
	set .s_up,.s_up + 1;
	end;

OnReset:
	set .s_up,0;
	end;

OnTouch_:
	soundeffect "effect\\sign_up.wav",1;
	if (.s_up == 1) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#up::OnDisable";
	}
	else if (.s_up == 2) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#cen::OnUp";
		donpcevent "s_dance#cen::OnEnable";
		donpcevent "s_dance#up::OnDisable";
	}
	else if (.s_up == 3) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#right::OnUp";
		donpcevent "s_dance#right::OnEnable";
		donpcevent "s_dance#up::OnDisable";
	}
	else if (.s_up == 4) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnUp";
		donpcevent "s_dance#down::OnEnable";
		donpcevent "s_dance#up::OnDisable";
	}
	else if (.s_up == 5) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#right::OnUp";
		donpcevent "s_dance#right::OnEnable";
		donpcevent "s_dance#up::OnDisable";
	}
	end;
}

cmd_in01,16,11,0	script	s_dance#down	139,1,3,{
OnInit:
	donpcevent "s_dance#down::OnDisable";
	end;

OnEnable:
	enablenpc "s_dance#down";
	specialeffect EF_SUMMONSLAVE;
	end;

OnDisable:
	//specialeffect EF_SUMMONSLAVE;
	disablenpc "s_dance#down";
	end;

OnUp:
	set .s_down,.s_down + 1;
	end;

OnReset:
	set .s_down,0;
	end;

OnTouch_:
	soundeffect "effect\\sign_down.wav",1;
	if (.s_down == 1) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnDisable";
	}
	else if (.s_down == 2) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnDisable";
	}
	else if (.s_down == 3) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#left::OnUp";
		donpcevent "s_dance#left::OnEnable";
		donpcevent "s_dance#down::OnDisable";
	}
	else if (.s_down == 4) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#cen::OnUp";
		donpcevent "s_dance#cen::OnEnable";
		donpcevent "s_dance#down::OnDisable";
	}
	else if (.s_down == 5) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnDisable";
	}
	else if (.s_down == 6) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#cen::OnUp";
		donpcevent "s_dance#cen::OnEnable";
		donpcevent "s_dance#down::OnDisable";
	}
	else if (.s_down == 7) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnDisable";
	}
	else if (.s_down == 8) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#right::OnUp";
		donpcevent "s_dance#right::OnEnable";
		donpcevent "s_dance#down::OnDisable";
	}
	else if (.s_down == 9) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnDisable";
	}
	else if (.s_down == 10) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnDisable";
	}
	end;
}

cmd_in01,11,16,0	script	s_dance#left	139,3,1,{
OnInit:
	donpcevent "s_dance#left::OnDisable";
	end;


OnEnable:
	enablenpc "s_dance#left";
	specialeffect EF_SUMMONSLAVE;
	end;

OnDisable:
	//specialeffect EF_SUMMONSLAVE;
	disablenpc "s_dance#left";
	end;

OnUp:
	set .s_left,.s_left + 1;
	end;

OnReset:
	set .s_left,0;
	end;

OnTouch_:
	soundeffect "effect\\sign_left.wav",1;
	if (.s_left == 1) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#right::OnUp";
		donpcevent "s_dance#right::OnEnable";
		donpcevent "s_dance#left::OnDisable";
	}
	else if (.s_left == 2) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#right::OnUp";
		donpcevent "s_dance#right::OnEnable";
		donpcevent "s_dance#left::OnDisable";
	}
	else if (.s_left == 3) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnUp";
		donpcevent "s_dance#down::OnEnable";
		donpcevent "s_dance#left::OnDisable";
	}
	else if (.s_left == 4) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#left::OnDisable";
	}
	else if (.s_left == 5) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#up::OnUp";
		donpcevent "s_dance#up::OnEnable";
		donpcevent "s_dance#left::OnDisable";
	}
	else if (.s_left == 6) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#right::OnUp";
		donpcevent  "s_dance#right::OnEnable";
		donpcevent "s_dance#left::OnDisable";
	}
	else if (.s_left == 7) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnUp";
		donpcevent "s_dance#down::OnEnable";
		donpcevent "s_dance#left::OnDisable";
	}
	end;
}

cmd_in01,21,16,0	script	s_dance#right	139,3,1,{
OnInit:
	donpcevent "s_dance#right::OnDisable";
	end;

OnEnable:
	enablenpc "s_dance#right";
	specialeffect EF_SUMMONSLAVE;
	end;

OnDisable:
	//specialeffect EF_SUMMONSLAVE;
	disablenpc "s_dance#right";
	end;

OnUp:
	set .s_right,.s_right + 1;
	end;

OnReset:
	set .s_right,0;
	end;

OnTouch_:
	soundeffect "effect\\sign_right.wav",1;
	if (.s_right == 1) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#right::OnDisable";
	}
	else if (.s_right == 2) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#up::OnUp";
		donpcevent "s_dance#up::OnEnable";
		donpcevent "s_dance#right::OnDisable";
	}
	else if (.s_right == 3) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnUp";
		donpcevent "s_dance#down::OnEnable";
		donpcevent "s_dance#right::OnDisable";
	}
	else if (.s_right == 4) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#up::OnUp";
		donpcevent "s_dance#up::OnEnable";
		donpcevent "s_dance#right::OnDisable";
	}
	else if (.s_right == 5) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnUp";
		donpcevent "s_dance#down::OnEnable";
		donpcevent "s_dance#right::OnDisable";
	}
	else if (.s_right == 6) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnUp";
		donpcevent "s_dance#down::OnEnable";
		donpcevent "s_dance#right::OnDisable";
	}
	else if (.s_right == 7) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#cen::OnUp";
		donpcevent "s_dance#cen::OnEnable";
		donpcevent "s_dance#right::OnDisable";
	}
	else if (.s_right == 8) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#left::OnUp";
		donpcevent "s_dance#left::OnEnable";
		donpcevent "s_dance#right::OnDisable";
	}
	end;
}

cmd_in01,16,16,0	script	s_dance#cen	139,1,1,{
OnInit:
	donpcevent "s_dance#cen::OnDisable";
	end;

OnEnable:
	enablenpc "s_dance#cen";
	specialeffect EF_SUMMONSLAVE;
	end;

OnDisable:
	//specialeffect EF_SUMMONSLAVE;
	disablenpc "s_dance#cen";
	end;
	
OnUp:
	set .s_center,.s_center + 1;
	end;

OnReset:
	set .s_center,0;
	end;

OnTouch_:
	soundeffect "effect\\sign_center.wav",1;
	if (.s_center == 1) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#cen::OnDisable";
	}
	else if (.s_center == 2) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#down::OnUp";
		donpcevent "s_dance#down::OnEnable";
		donpcevent "s_dance#cen::OnDisable";
	}
	else if (.s_center == 3) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#cen::OnDisable";
	}
	else if (.s_center == 4) {
		donpcevent "Examiner#sd::OnUp";
		donpcevent "s_dance#right::OnUp";
		donpcevent "s_dance#right::OnEnable";
		donpcevent "s_dance#cen::OnDisable";
	}
	end;
}

cmd_in01,14,14,0	script	Examiner#sd	-1,6,6,{
OnInit:
	disablenpc "Examiner#sd";
	end;

OnTouch_:
	if (.s_check < 30) {
		if (sign_q == 30) {
			set sign_q,32;
		}
	}
	else if (.s_check < 34) {
		if (sign_q == 30) {
			set sign_q,33;
		}
	}
	else if (.s_check == 34) {
		if (sign_q == 30) {
			set sign_q,34;
		}
	}
	warp "cmd_in01",29,33;
	donpcevent "Examiner#sd::OnDisable";
	end;

OnUp:
	set .s_check,.s_check + 1;
	end;

OnDisable:
	set .s_check,0;
	disablenpc "Examiner#sd";
	end;
}

alberta_in,125,101,5	script	Wealthy-looking Merchant	807,{
	callfunc "F_UpdateSignVars";
	mes "[Bakerlan]";
	if (sign_q < 35) {
		mes "Umm...well then...";
		mes "I shall take the action for Prontera...";
		mes "And for Juno...";
		mes "Awww....";
		mes "Gosh, this is such a pain in the ass...";
		mes "Mumble mumble...";
		close;
	}
	else if (sign_q == 35) {
		mes "Gosh.....";
		mes "I do not know what I should do about Juno...";
		mes "?";
		mes "Who are you?";
		next;
		switch(select("Nothing.:Mr. Metz sent me.")) {
		case 1:
			mes "[Bakerlan]";
			mes "Hmm...";
			mes "I am pretty busy at this moment. So please do not interrupt me any further.";
			mes "If you are looking for a job,";
			mes "please inquire of my steward.";
			close;
		case 2:
			mes "[Bakerlan]";
			mes "Ah....";
			mes "He did?....Hmmm..";
			mes "Unfortunately I am kind of busy...";
			mes "will you please come back later?";
			mes "Thank you.";
			set sign_q,36;
			close;
		}
	}
	else if (sign_q == 36) {
		mes "Hmm...? You've";
		mes "finished all of the";
		mes "tests up until Dearle's";
		mes "challenge? Prove it to me";
		mes "with your pieces of the";
		mes "Sobbing Starlight...";
		next;
		switch(select("Give me a minute...:Here...")) {
		case 1:
			mes "[Bakerlan]";
			mes "Well, you better";
			mes "come back soon. I'm";
			mes "a busy businessman, so";
			mes "my time is quite precious.";
			close;
		case 2:
			if (countitem(7177) < 5) {
				mes "[Bakerlan]";
				mes "Hmm, I suppose you";
				mes "still haven't completed";
				mes "all the tests. These aren't";
				mes "enough pieces of the Sobbing";
				mes "Starlight, you know...";
				close;
			}
			else if (countitem(7177) == 5) {
				mes "[Bakerlan]";
				mes "Ah, now I see that";
				mes "you speak the truth.";
				mes "Alright, we can begin my test.";
				next;
				mes "[Bakerlan]";
				mes "First, I wish for you to make";
				mes "a delivery. The object I want you to deliver is expensive and must be handled with care. Don't lose it or you will fail. Now, speak to my steward for more information.";
				set sign_q,37;
				close;
			}
			else {
				mes "[Bakerlan]";
				mes "Hm? It's not possible for";
				mes "you to have this many pieces";
				mes "of the Sobbing Starlight!";
				mes "These must be fakes. How";
				mes "dare you! Leave me!";
				close;
			}
		}
	}
	else if (sign_q < 40) {
		mes "Please speak to my";
		mes "steward for all matters";
		mes "related to the delivery";
		mes "that you must complete";
		mes "for my test.";
		close;
	}
	else if (sign_q == 40) {
		mes "Ah yes, Mahatra tells";
		mes "me that you've completed";
		mes "the delivery. Well, um, he now";
		mes "has another assignment for";
		mes "for you to complete. So";
		mes "please talk to him again.";
		set sign_q,41;
		close;
	}
	else if (sign_q < 52) {
		mes "You have not finished yet.";
		mes "Why don't you go finish them first?";
		mes "I am a busy businessman.";
		close;
	}
	else if (sign_q == 52) {
		mes "Ah, I was informed about you.";
		mes "Well, although you have your goal,";
		mes "that does not necessarily mean to help that kid.";
		mes "Metz must have an eye for a right person, I assume.";
		next;
		mes "[Bakerlan]";
		mes "Well, I wanted to assign you some various tasks";
		mes "on my own plan, but recently I am very busy";
		mes "to take care of tradings with Kunlun and Amatsu.";
		next;
		mes "[Bakerlan]";
		mes "I found Seyling while I was trading with Amatsu few years ago.";
		mes "I introduced her brother to the royal family of Prontera, too.";
		mes "But anyways,";
		next;
		mes "[Bakerlan]";
		mes "I want to test you longer, but";
		mes "I am too busy for that. Also I don't think it is good for you.";
		mes "Let's finish the test now.";
		mes "You are qualified enough already.";
		next;
		mes "[Bakerlan]";
		mes "There you go.";
		mes "I am the last one who tested your qualification.";
		mes "Now bring all of the stone pieces to Metz.";
		mes "He will tell you what you need to do next.";
		set sign_q,53;
		getitem 7177,1; //Part_Of_Star's_Sob
		if (checkre(3)) {
			if (BaseLevel < 60) getexp 500,0;
			else if (BaseLevel < 70) getexp 800,0;
			else if (BaseLevel < 80) getexp 1100,0;
			else if (BaseLevel < 90) getexp 1500,0;
			else getexp 2000,0;
		} else {
			if (BaseLevel < 60) getexp 5000,0;
			else if (BaseLevel < 70) getexp 8000,0;
			else if (BaseLevel < 80) getexp 11000,0;
			else if (BaseLevel < 90) getexp 15000,0;
			else getexp 20000,0;
		}
		close;
	}
	else if (sign_q == 97) {
		mes "Umm....";
		mes "Did I see you wrong? Or did Metz do?";
		mes "...I do not have any more business with you.";
		mes "Take care now.";
		close;
	}
	else if (sign_q == 98) {
		mes "Umm...well then...";
		mes "I shall take the action for Prontera...";
		mes "And for Juno...";
		mes "Awww....";
		mes "Gosh, this is such a pain in the ass...";
		mes "Mumble mumble...";
		close;
	}
	else {
		mes "How is it going?";
		mes "In fact, we want to do it on our own...";
		mes "but we are too preoccupied with our works...";
		mes "I hope you will keep up the good work.";
		mes "I am also curious what that stone is.";
		close;
	}
}

alberta_in,154,171,5	script	Maid#s10	758,{
	callfunc "F_UpdateSignVars";
	mes "[Seylin]";
	if (sign_q < 38) {
		mes "I'm sorry, but I'm";
		mes "busy cleaning the manor";
		mes "right now so I don't have";
		mes "time to talk. Oh, and would";
		mes "you please wipe your shoes";
		mes "on the mat before coming in?";
		close;
	}
	else if (sign_q == 38) {
		mes "Leibech...?";
		mes "I remember that he's";
		mes "a regular customer who";
		mes "orders the strangest things.";
		mes "Last I heard, he was traveling";
		mes "near Mount Mjolnir.";
		next;
		mes "[Seylin]";
		mes "Yes, that was where";
		mes "his last order was sent";
		mes "to. Hm, I wonder. Do you";
		mes "think he could have been";
		mes "heading towards the";
		mes "Schwarzwald Republic?";
		close;
	}
	else if (sign_q < 42) {
		mes "Ooooh...";
		mes "What am I going";
		mes "to do?! Oh-- You";
		mes "startled me!";
		next;
		mes "[Seylin]";
		mes "I'm sorry, but";
		mes "I was just thinking";
		mes "about something. I hope";
		mes "I didn't bother you. ^333333*Sigh*^000000";
		close;
	}
	else if (sign_q == 42) {
		mes "Ooooh...";
		mes "What am I going";
		mes "to do?! Oh-- You";
		mes "startled me!";
		next;
		mes "[Seylin]";
		mes "I'm sorry, but";
		mes "I was just thinking";
		mes "about something. I hope";
		mes "I didn't bother you. ^333333*Sigh*^000000";
		set sign_q,43;
		close;
	}
	else if (sign_q < 51) {
		switch(sign_q) {
		case 43:
			mes "^333333*Sigh...*^000000";
			mes "Oh dear...";
			mes "What can I do";
			mes "about this...?";
			next;
			switch(select("Ignore her.:Excuse me, but Mahatra sent me...")) {
			case 1:
				mes "[Seylin]";
				mes "Oh, it's no use";
				mes "worrying about";
				mes "something I can do";
				mes "nothing about. I better";
				mes "get back to work...";
				close;
			case 2:
				mes "[Seylin]";
				mes "Mister Mahatra";
				mes "sent you to me?";
				mes "Hm? Does he need";
				mes "me for anything?";
				next;
				switch(select("Actually, he wants me to help you.")) {
				case 1:
					mes "[Seylin]";
					mes "Oh, how very kind!";
					mes "Yes, yes, I could use";
					mes "some help right now!";
					mes "You see, it'll be my brother's";
					mes "birthday, but I'm so busy with";
					mes "work that I can't see him.";
					emotion ET_THANKS;
					next;
					mes "[Seylin]";
					mes "The last time I saw him,";
					mes "he looked so tired and weak";
					mes "so it's worrying me. Now, I've";
					mes "heard there's some new medicine";
					mes "called ^FF0000Vigorgra^000000. I don't know much about it, but it should help him!";
					next;
					mes "[Seylin]";
					mes "Do you think you could";
					mes "find that medicine and";
					mes "bring it to me? If you don't";
					mes "want to, I understand. Plus,";
					mes "I don't know if the master";
					mes "would approve of this...";
					next;
					switch(select("I can't do it.:Let me think about it.:Sure, why not?")) {
					case 1:
						mes "[Seylin]";
						mes "Oh, really?";
						mes "Alright, I can";
						mes "understand. I'm";
						mes "very sorry to bother";
						mes "you with my problems.";
						set sign_q,44;
						close;
					case 2:
						mes "[Seylin]";
						mes "Oh okay.";
						mes "Take your time.";
						mes "If you can help";
						mes "me, I'd really";
						mes "appreciate it~";
						set sign_q,45;
						close;
					case 3:
						mes "[Seylin]";
						mes "Oh, thank you so much!";
						mes "Now, I remember hearing";
						mes "that you can find Vigorgra";
						mes "somewhere in Al de Baran.";
						mes "Somebody in the Alchemist";
						mes "Guild makes it, I think.";
						next;
						mes "[Seylin]";
						mes "I'm sorry, but I don't";
						mes "know much about the medicine.";
						mes "Well, aside from the fact that";
						mes "it makes men feel young again.";
						mes "So that must be good, right?";
						mes "Thanks again for your help~";
						set sign_q,46;
						close;
					}
				}
			}
		case 44:
			mes "Hello there~";
			mes "Oh, have you";
			mes "changed your mind";
			mes "about helping me?";
			mes "I'll repay you,";
			mes "of course.";
			next;
			switch(select("No.:Yes.")) {
			case 1:
				mes "[Seylin]";
				mes "Oh really?";
				mes "I'm sorry, I...";
				mes "I just thought";
				mes "that maybe...";
				close2;
				emotion ET_THINK;
				end;
			case 2:
				mes "[Seylin]";
				mes "Oh, thank you so much!";
				mes "Now, I remember hearing";
				mes "that you can find Vigorgra";
				mes "somewhere in Al de Baran.";
				mes "Somebody in the Alchemist";
				mes "Guild makes it, I think.";
				next;
				mes "[Seylin]";
				mes "I'm sorry, but I don't";
				mes "know much about the medicine.";
				mes "Well, aside from the fact that";
				mes "it makes men feel young again.";
				mes "So that must be good, right?";
				mes "Thanks again for your help~";
				set sign_q,46;
				close;
			}
		case 45:
			mes "Hello there~";
			mes "So have you decided";
			mes "yet? If you help me,";
			mes "I'll be sure to pay";
			mes "you back somehow.";
			next;
			switch(select("Um, I'm still thinking.:Yes.")) {
			case 1:
				mes "[Seylin]";
				mes "Oh okay.";
				mes "But please hurry~";
				mes "My brother's birthday";
				mes "is coming up soon!";
				close;
			case 2:
				mes "[Seylin]";
				mes "Oh, thank you so much!";
				mes "Now, I remember hearing";
				mes "that you can find Vigorgra";
				mes "somewhere in Al de Baran.";
				mes "Somebody in the Alchemist";
				mes "Guild makes it, I think.";
				next;
				mes "[Seylin]";
				mes "I'm sorry, but I don't";
				mes "know much about the medicine.";
				mes "Well, aside from the fact that";
				mes "it makes men feel young again.";
				mes "So that must be good, right?";
				mes "Thanks again for your help~";
				set sign_q,46;
				close;
			}
		case 46:
		case 47:
			mes "I know that you might";
			mes "be able to find Vigorgra";
			mes "in the Alchemist's Guild";
			mes "in Al de Baran. Aside from";
			mes "that, I don't know much...";
			next;
			mes "[Seylin]";
			mes "Once you get it,";
			mes "would you bring";
			mes "the Vigorgra to me?";
			close;
		case 48:
			if (countitem(7044) < 1) {
				mes "Oh, you know where";
				mes "you can get Vigorgra?";
				mes "That's great news!";
				mes "Oh, when you have it,";
				mes "bring to me, okay?";
				close;
			}
			else {
				mes "Hurray~!";
				mes "You brought the";
				mes "Vigorgra! I hope";
				mes "my brother will";
				mes "be happy with this!";
				next;
				mes "[Seylin]";
				mes "Oh! Would you please";
				mes "bring this Vigorgra to my";
				mes "brother? His name is Maruin";
				mes "and he's working over at";
				mes "the Prontera Castle.";
				next;
				mes "[Seylin]";
				mes "Ah, I almost forgot!";
				mes "I just finished writing";
				mes "him this letter, so would";
				mes "you also make sure he gets";
				mes "this? Thank you so much!";
				set sign_q,49;
				getitem 7183,1; //Sister_Letter
				close;
			}
		case 49:
			mes "Would you please";
			mes "deliver the Vigorgra";
			mes "and my letter to my brother";
			mes "Maruin in the Prontera Castle?";
			mes "And wish him 'Happy Birthday~'";
			close;
		case 50:
			mes "Thanks so much";
			mes "for your help again!";
			mes "I want you to have this";
			mes "as a token of my gratitude.";
			mes "You really are a kind person~";
			set sign_q,51;
			getitem 525,3; //Panacea
			next;
			emotion ET_CHUPCHUP;
			close;
		}
	}
	else if (sign_q == 97) {
		mes "Oh no~!";
		mes "Please don't";
		mes "drag your muddy";
		mes "feet over the carpet!";
		mes "Would you please leave?";
		close;
	}
	else if (sign_q == 98) {
		mes "I'm sorry, but I'm";
		mes "busy cleaning the manor";
		mes "right now so I don't have";
		mes "time to talk. Oh, and would";
		mes "you please wipe your shoes";
		mes "on the mat before coming in?";
		close;
	}
	else {
		mes "Although the master isn't";
		mes "a messy person, he's pretty";
		mes "unorganized. I wish he'd make";
		mes "it easier for me to tell which";
		mes "papers are documents and ";
		mes "which ones are trash...";
		next;
		mes "[Seylin]";
		mes "So how have you been?";
		mes "Is everything okay with you?";
		mes "I hope you have a lot of good";
		mes "experiences in your adventures~";
		close;
	}
}

-	script	Soldier#s11_	-1,{
	callfunc "F_UpdateSignVars";
	mes "[Maruin]";
	if (sign_q < 49) {
		mes "Welcome to";
		mes "Prontera Castle.";
		mes "Please be careful";
		mes "and avoid getting lost.";
		next;
		mes "[Maruin]";
		mes "Oh man...";
		mes "I'm so tired~!";
		mes "Enervated, even~";
		mes "If I only had some";
		mes "kind of refreshment...";
		close;
	}
	else if (sign_q == 49) {
		if ((countitem(7044) < 1) && (countitem(7183) < 1)) {
			mes "Welcome to";
			mes "Prontera Castle.";
			mes "Please be careful";
			mes "and avoid getting lost.";
			next;
			mes "[Maruin]";
			mes "Oh man...";
			mes "I'm so tired~!";
			mes "Enervated, even~";
			mes "If I only had some";
			mes "kind of refreshment...";
			close;
		}
		else {
			mes "Welcome to";
			mes "Prontera Castle.";
			mes "Please be careful";
			mes "and avoid getting los--";
			next;
			mes "[Maruin]";
			mes "What's that?";
			mes "You're here for";
			mes "my sister? Um, did";
			mes "something happen...?";
			next;
			select("Oh no, she sent you a birthday gift.");
			mes "[Maruin]";
			mes "Birthday...?";
			mes "What are you sm--";
			mes "OH. It is my birthday.";
			mes "Ha! I completely forgot!";
			next;
			mes "[Maruin]";
			mes "Thanks for coming";
			mes "all the way out here";
			mes "to deliver my present!";
			mes "Wow, I wonder what she";
			mes "got for me this year?";
			next;
			emotion ET_SURPRISE;
			mes "[Maruin]";
			mes "Th-this is--!";
			mes "Oh. Snap. That's right.";
			mes "She's been worried about";
			mes "me being tired lately. But";
			mes "does she even know what";
			mes "Vigorgra is supposed to...?";
			next;
			mes "[Maruin]";
			mes "Never mind. It's the";
			mes "thought that counts.";
			mes "But for the record, it's";
			mes "not like I need this stuff.";
			mes "I mean, I have, you know,";
			mes "a girlfr--you know what I mean.";
			next;
			mes "[Maruin]";
			mes "I'd like to pay you";
			mes "back, but since I'm";
			mes "on duty, all I can do";
			mes "is replenish your health.";
			mes "I'm not really supposed to,";
			mes "but no one will say anything.";
			delitem 7044,1; //Vigorgra
			delitem 7183,1; //Sister_Letter
			set sign_q,50;
			percentheal 100,100;
			next;
			mes "[Maruin]";
			mes "Well, thanks for";
			mes "the letter and the";
			mes "male supplement, I guess.";
			mes "I'll send a message to my";
			mes "sister. Good luck on your";
			mes "travels, alright?";
			close;
		}
	}
	else if (sign_q == 97 || sign_q == 98) {
		mes "Welcome to";
		mes "Prontera Castle.";
		mes "Please be careful";
		mes "and avoid getting lost.";
		next;
		mes "[Maruin]";
		mes "Oh man...";
		mes "I'm so tired~!";
		mes "Enervated, even~";
		mes "If I only had some";
		mes "kind of refreshment...";
		close;
	}
	else {
		mes "Oh hey, how's";
		mes "it going? Thanks";
		mes "again for helping";
		mes "out my sister, we";
		mes "really appreciate it.";
		if (Sex == SEX_MALE) {
			if (rand(1,5) == 5) {
				next;
				mes "[Maruin]";
				mes "Oh...";
				mes "And just between you";
				mes "and me, that Vigorgra";
				mes "really came in handy!";
				mes "That stuff's amazing!";
			}
		}
		close;
	}
}

alde_alche,169,162,7	script	Alchemist#sign	749,{
	callfunc "F_UpdateSignVars";
	mes "[Melkaba]";
	if (sign_q < 46) {
		mes "Most Alchemists seek out the";
		mes "Stone of Sage, but in my opinion, their goals are too short sighted. There are more important studies";
		mes "to be conducted in the name of science for the good of mankind...";
		next;
		switch(select("...:So what are you studying?")) {
		case 1:
			mes "[Melkaba]";
			mes "In the end, the ";
			mes "Stone of Sage may";
			mes "just be a simple rumor.";
			mes "After all, thousands of";
			mes "Alchemists have already";
			mes "failed to create it.";
			close;
		case 2:
			mes "[Melkaba]";
			mes "What am I studying?";
			mes "Well, my expertise is...";
			mes "Different. If you must";
			mes "know, it's a secret~";
			mes "If any man found out";
			mes "about my research...";
			close;
		}
	}
	else if (sign_q == 46) {
		mes "Eh...?";
		mes "What do you need?";
		mes "If it's not important,";
		mes "please leave my";
		mes "laboratory!";
		next;
		switch(select("Vigorgra?:Oh, I'm sorry.")) {
		case 1:
			mes "[Melkaba]";
			mes "What?! Who told you";
			mes "that I could make that?!";
			mes "Oh, no matter. I suppose";
			mes "you want me to get some";
			mes "ready for you. Now tell me...";
			mes "Why do you want it?";
			next;
			switch(select("No, I don't want it!:I need Vigorgra for... a friend.")) {
			case 1:
				mes "[Melkaba]";
				mes "You immature--!";
				mes "You come all this";
				mes "way to bother me?";
				mes "Don't bring your";
				mes "shame into my lab!";
				close;
			case 2:
				mes "[Melkaba]";
				mes "Oh right.";
				mes "Your friend.";
				mes "I understand you.";
				mes "Crystal clear.";
				next;
				mes "[Melkaba]";
				mes "Well, since you know";
				mes "about my secret research,";
				mes "I'll do you a favor so long as";
				mes "you don't tell anyone else!";
				mes "Of course, I can't just give";
				mes "you Vigorgra for free...";
				next;
				mes "[Melkaba]";
				mes "Now, write this";
				mes "down. These are the";
				mes "ingredients I need to";
				mes "make a bottle of Vigorgra.";
				next;
				mes "[Melkaba]";
				mes "^ff00001 Ment";
				mes "20 Honey";
				mes "10 Royal Jelly";
				mes "30 Bear's Footskin";
				mes "1 Hinalle Leaflet";
				mes "1 Empty Bottle.^000000";
				next;
				mes "[Melkaba]";
				mes "Alright.";
				mes "Now go and";
				mes "bring all those";
				mes "items to me. I'll";
				mes "be seeing you later.";
				set sign_q,47;
				close;
			}
		case 2:
			mes "[Melkaba]";
			mes "There's no need";
			mes "to apologize. But";
			mes "I'd appreciate it if";
			mes "you'd let me work";
			mes "in peace.";
			close;
		}
	}
	else if (sign_q == 47) {
		mes "Hmmm...";
		mes "So did you";
		mes "bring everything";
		mes "you need for the";
		mes "Vigorgra...?";
		next;
		switch(select("Not yet...:Yes.")) {
		case 1:
			mes "[Melkaba]";
			mes "Well, let me";
			mes "remind you of";
			mes "what you need to";
			mes "bring to me in case";
			mes "you forgot already...";
			next;
			mes "[Melkaba]";
			mes "^ff00001 Ment";
			mes "20 Honey";
			mes "10 Royal Jelly";
			mes "30 Bear's Footskin";
			mes "1 Hinalle Leaflet";
			mes "1 Empty Bottle.^000000";
			next;
			mes "[Melkaba]";
			mes "Take your time...";
			mes "In the end, you're";
			mes "the one who's got";
			mes "the need for it, anyway.";
			close;
		case 2:
			mes "[Melkaba]";
			mes "Great...!";
			mes "Now let me check";
			mes "to see if you have";
			mes "everything ready...";
			next;
			mes "[Melkaba]";
			if ((countitem(526) < 10) || (countitem(518) < 20) || (countitem(948) < 30) || (countitem(520) < 1) || (countitem(708) < 1) || (countitem(713) < 1)) {
				mes "Hmm, you're still";
				mes "missing some of the";
				mes "ingredients. Now, listen";
				mes "carefully. I need you to get...";
				next;
				mes "[Melkaba]";
				mes "^ff00001 Ment";
				mes "20 Honey";
				mes "10 Royal Jelly";
				mes "30 Bear's Footskin";
				mes "1 Hinalle Leaflet";
				mes "1 Empty Bottle.^000000";
				close;
			}
			else {
				mes "Good work.";
				mes "Everything's here.";
				mes "Alright, just this once";
				mes "I'll make you a bottle";
				mes "of Vigorgra.";
				next;
				mes "[Melkaba]";
				mes "If you ask me again,";
				mes "I won't speak to you!";
				mes "And I'll need to charge";
				mes "you 10,000 zeny.";
				next;
				mes "[Melkaba]";
				if (Zeny < 10000) {
					mes "Huh...";
					mes "It doesn't look like";
					mes "you have enough zeny";
					mes "right now. No matter,";
					mes "I can wait until you";
					mes "bring it all to me.";
				}
				else {
					mes "Alright, I'll be";
					mes "taking my fee from";
					mes "you now. It's not that";
					mes "expensive when you";
					mes "consider Vigorgra's";
					mes "numerous benefits.";
					next;
					mes "^3355FFMelkaba placed";
					mes "all the ingredients";
					mes "into a test tube and";
					mes "began processing it";
					mes "through some strange";
					mes "electronic equipment.^000000";
					next;
					mes "...";
					mes "......";
					next;
					mes "...";
					mes "......";
					mes ".........";
					next;
					mes "[Melkaba]";
					if (rand(1,100) < 98) {
						specialeffect EF_PHARMACY_OK;
						mes "Ah! Success!";
						mes "A lifetime's supply";
						mes "of Vigorgra! I know it's";
						mes "just one bottle, but this";
						mes "stuff is extremely potent!";
						next;
						set Zeny, Zeny-10000;
						delitem 526,10; //Royal_Jelly
						delitem 518,20; //Honey
						delitem 948,30; //Bear's_Foot
						delitem 520,1; //Leaflet_Of_Hinal
						delitem 708,1; //Ment
						delitem 713,1; //Empty_Bottle
						set sign_q,48;
						getitem 7044,1; //Vigorgra
						mes "[Melkaba]";
						mes "Um, just remember";
						mes "not to take too much";
						mes "at one time. Can't have";
						mes "you getting crazy high";
						mes "blood pressure~";
						close;
					}
					else {
						specialeffect EF_PHARMACY_FAIL;
						delitem 526,10; //Royal_Jelly
						delitem 518,20; //Honey
						delitem 948,30; //Bear's_Foot
						delitem 520,1; //Leaflet_Of_Hinal
						delitem 708,1; //Ment
						delitem 713,1; //Empty_Bottle
						mes "It failed?!";
						mes "Of course, the mixture";
						mes "was too vigorous, even";
						mes "for the machinery! I'm sorry,";
						mes "but would you bring the things";
						mes "we need to make Vigorgra again?";
						close;
					}
				}
			}
		}
	}
	else if (sign_q == 97) {
		mes "Most Alchemists seek out the";
		mes "Stone of Sage, but in my opinion, their goals are too short sighted. There are more important studies";
		mes "to be conducted in the name of science for the good of mankind...";
		next;
		switch(select("...:So what are you studying?")) {
		case 1:
			mes "[Melkaba]";
			mes "In the end, the";
			mes "Stone of Sage may";
			mes "just be a simple rumor.";
			mes "After all, thousands of";
			mes "Alchemists have already";
			mes "failed to create it.";
			close;
		case 2:
			mes "[Melkaba]";
			mes "What am I studying?";
			mes "Well, my expertise is...";
			mes "Different. If you must";
			mes "know, it's a secret~";
			mes "If any man found out";
			mes "about my research...";
			close;
		}
	}
	else if (sign_q == 98) {
		mes "Most Alchemists seek out the";
		mes "Stone of Sage, but in my opinion, their goals are too short sighted. There are more important studies";
		mes "to be conducted in the name of science for the good of mankind...";
		next;
		switch(select("...:So what are you studying?")) {
		case 1:
			mes "[Melkaba]";
			mes "In the end, the";
			mes "Stone of Sage may";
			mes "just be a simple rumor.";
			mes "After all, thousands of";
			mes "Alchemists have already";
			mes "failed to create it.";
			close;
		case 2:
			mes "[Melkaba]";
			mes "What am I studying?";
			mes "Well, my expertise is...";
			mes "Different. If you must";
			mes "know, it's a secret~";
			mes "If any man found out";
			mes "about my research...";
			close;
		}
	}
	else {
		mes "Vigorgra is";
		mes "a miracle of";
		mes "modern science,";
		mes "but it can do more";
		mes "harm than good if";
		mes "you're not careful!";
		close;
	}
}

alberta_in,114,178,5	script	Refined Steward	109,{
	callfunc "F_UpdateSignVars";
	mes "[Mahatra]";
	if (sign_q < 37) {
		mes "Welcome to the";
		mes "Alchesh Estate.";
		mes "The Alcheshs are the";
		mes "most esteemed family";
		mes "in all of Alberta.";
		next;
		mes "[Mahatra]";
		mes "I am Mahatra Mornen,";
		mes "steward of this family.";
		mes "Feel free to ask me if";
		mes "you need anything and";
		mes "I shall do my best";
		mes "to assist you.";
		close;
	}
	else if (sign_q == 37) {
		mes "Ah yes, the master informed";
		mes "me that you would be taking";
		mes "care of an urgent delivery for";
		mes "him. Please take this to a";
		mes "man named ^3355FFLeibech^000000.";
		next;
		mes "[Mahatra]";
		mes "It may be difficult";
		mes "to find him since he";
		mes "travels around the world.";
		mes "Ah yes, I have heard that";
		mes "he was in some other country...";
		next;
		mes "[Mahatra]";
		mes "Now, the item I am";
		mes "about to give you is";
		mes "one of a kind. Don't lose";
		mes "it or you will fall out of favor with the master...";
		next;
		mes "^3355FFMahatra gives you";
		mes "a unique stone that has";
		mes "your name attached to it.^000000";
		set sign_q,38;
		getnameditem 7049,strcharinfo(0);
		close;
	}
	else if (sign_q == 38 || (sign_q == 39 && countitem(7181) < 1)) {
		mes "You haven't delivered";
		mes "the Stone yet? Please take";
		mes "good care of it since it's very";
		mes "rare. Don't use it or lose it.";
		mes "before it's delivered!";
		mes "Take care, now...";
		close;
	}
	else if (sign_q == 39) {
		mes "Ah, you've returned.";
		mes "And I see you already";
		mes "delivered the Stone. Great,";
		mes "well done. Let me send a";
		mes "message to the master, so";
		mes "please visit him later.";
		delitem 7181,1; //Receipt_01
		set sign_q,40;
		close;
	}
	else if (sign_q == 40) {
		mes "Thank you very";
		mes "much for the trouble";
		mes "you've gone through";
		mes "on our behalf.";
		close;
	}
	else if (sign_q == 41) {
		mes "Greetings. Hm?";
		mes "Did the master ask";
		mes "you to perform another";
		mes "task for him already?";
		next;
		switch(select("No.:You have another assignment for me.")) {
		case 1:
			mes "[Mahatra]";
			mes "Very well.";
			mes "Then we shall";
			mes "converse later~";
			close;
		case 2:
			mes "[Mahatra]";
			mes "I... I do...?";
			mes "The master didn't";
			mes "leave me any instructions.";
			mes "Hmmm. Oh, I know what you can";
			mes "do! Why don't you help ^FF0000Seylin^000000? She seems bothered by something...";
			set sign_q,42;
			close;
		}
	}
	else if (sign_q < 51) {
		mes "Although you may only";
		mes "be doing it for the Sobbing";
		mes "Starlight, I really appreciate";
		mes "all your help. Seylin's a very";
		mes "nice girl and doesn't deserve";
		mes "to feel down...";
		close;
	}
	else if (sign_q == 51) {
		mes "Yes.";
		mes "I heard from Seylin.";
		mes "I did not know she was worried about her brother.";
		mes "Ahem ahem...";
		mes "Thank you for helping her.";
		mes "I will send a message to my master.";
		next;
		mes "Mahatra]";
		mes "If there is anything else, he will let you pass the test.";
		mes "Good luck.";
		set sign_q,52;
		close;
	}
	else if (sign_q == 98) {
		mes "I'm very disappointed";
		mes "in you. We put our trust";
		mes "in you and you really";
		mes "let us down.";
		next;
		mes "[Mahatra]";
		mes "Well, I suppose";
		mes "that's the nature";
		mes "of the testing. They're";
		mes "designed so that only";
		mes "the best of the best";
		mes "can pass them.";
		close;
	}
	else {
		mes "I hope the master listens";
		mes "to me and dresses more like";
		mes "a man in his position. Even if";
		mes "he thinks he's just a merchant,";
		mes "he's the master of this estate!";
		mes "But please don't tell him that~";
		close;
	}
}

alberta,98,202,5	script	Guard#s10	105,{
	mes "[Hurubu]";
	mes "Welcome to the";
	mes "Alchesh Estate.";
	if (sign_q < 35) {
		mes "If you have any business";
		mes "with the master, please";
		mes "let me know.";
		close;
	}
	else if (sign_q < 52) {
		mes "If you have any business";
		mes "with the master, please";
		mes "let me know.";
		next;
		switch(select("I'd like to see Mr. Bakerlan.:Have a nice day.")) {
		case 1:
			mes "[Hurubu]";
			mes "Ah, you've";
			mes "come to speak";
			mes "to the master?";
			mes "He's not out on";
			mes "business, so you";
			mes "can probably see him.";
			close;
		case 2:
			mes "[Hurubu]";
			mes "Ah...";
			mes "Good day.";
			close;
		}
	}
	else if (sign_q == 97 || sign_q == 98) {
		mes "Please leave if";
		mes "you do not have";
		mes "any business here.";
		close;
	}
	else {
		mes "Lately, it seems that";
		mes "the master is in a good";
		mes "mood. I believe that we";
		mes "have you to thank for that.";
		close;
	}
}

alberta,43,49,5	script	Poor-looking Merchant	89,{
	callfunc "F_UpdateSignVars";
	mes "[Machen]";
	if (sign_q < 35) {
		mes "Why...?";
		mes "How did my";
		mes "family's wealth";
		mes "and prestige just";
		mes "go down the drain?";
		next;
		mes "[Machen]";
		mes "Ever since the";
		mes "Alcheshs came to Alberta,";
		mes "they quickly took our place";
		mes "as the biggest business owners";
		mes "here. It's our biggest shame...";
		close;
	}
	else if ((sign_q < 52) || (sign_q ==98)) {
		mes "^333333*Sigh...*^000000";
		mes "How did it happen?";
		mes "How did the Alcheshs";
		mes "become so rich so quickly?";
		next;
		switch(select("Alchesh family?:Do you know where Mr. Bakerlan is?")) {
		case 1:
			mes "[Machen]";
			mes "My family, the Tudas,";
			mes "used to run the biggest";
			mes "trading company in Alberta.";
			mes "But when the Alcheshs came";
			mes "fifty years ago, they started";
			mes "to outdo us in everything...";
			next;
			mes "[Machen]";
			mes "It's like they're financial";
			mes "geniuses or something!";
			mes "Under Bakerlan's guidance,";
			mes "their estate has grown to be";
			mes "one of the richest in Alberta,";
			mes "if not all of Rune-Midgarts...";
			close;
		case 2:
			mes "[Machen]";
			mes "Bakerlan...?";
			mes "Oh, he's probably";
			mes "in his ten story money";
			mes "vault, swimming in his";
			mes "money by now. You";
			mes "know rich people.";
			next;
			select(".........");
			mes "[Machen]";
			mes "It-was-a-joke!";
			mes "You see that big";
			mes "mansion to the north?";
			mes "That's the Alchesh Estate.";
			mes "He should be home now.";
			next;
			mes "[Machen]";
			mes "He usually travels";
			mes "a lot on business,";
			mes "but if you're lucky you";
			mes "should be able to catch him.";
			close;
		}
	}
	else if (sign_q == 97) {
		mes "Why...?";
		mes "How did my";
		mes "family's wealth";
		mes "and prestige just";
		mes "go down the drain?";
		next;
		mes "[Machen]";
		mes "Ever since the";
		mes "Alcheshs came to Alberta,";
		mes "they quickly took our place";
		mes "as the biggest business owners";
		mes "here. It's our biggest shame...";
		close;
	}
	else {
		mes "You know, if the Alcheshs";
		mes "were greedy, they actually";
		mes "wouldn't be as big as they";
		mes "are today. They've contributed";
		mes "to a lot of social causes and";
		mes "that won them a lot of support.";
		next;
		mes "[Machen]";
		mes "I gotta admit...";
		mes "The whole family";
		mes "is a bunch of financial";
		mes "geniuses, alright.";
		close;
	}
}

yuno,330,100,4	script	Knight#ss	734,{
	callfunc "F_UpdateSignVars";
	mes "[Leibech]";
	if (sign_q < 38) {
		mes "I have a great";
		mes "interest in collecting";
		mes "unique and uncommon";
		mes "goods. You know, things";
		mes "that most people see just";
		mes "once in their lifetimes.";
		next;
		mes "[Leibech]";
		mes "I usually use the";
		mes "Alchesh Trading Company";
		mes "to help add to my collection.";
		mes "Their prices aren't the cheapest, but their service is very reliable.";
		close;
	}
	else if (sign_q == 38) {
		if (countitem(7049) < 1) {
			mes "Excuse me...";
			mes "Are you from the Alchesh";
			mes "Trading Company? I've been";
			mes "waiting for my order and they";
			next;
			switch(select("No, I'm not.:They must be busy.:Yes, I have your order.")) {
			case 1:
				mes "[Leibech]";
				mes "Oh, I'm sorry.";
				mes "My mistake. Well";
				mes "then, be safe in";
				mes "your travels.";
				close;
			case 2:
				mes "[Leibech]";
				mes "I suppose you're";
				mes "right. I mean, Juno";
				mes "is pretty far from";
				mes "Alberta. Maybe I'm";
				mes "just overly excited";
				mes "about my delivery...";
				close;
			case 3:
				mes "[Leibech]";
				mes "Really?!";
				mes "That's great!";
				mes "Do you have the";
				mes "item I ordered?";
				mes "Where is it?";
				next;
				switch(select("I put it somewhere.:Sorry, I lost it.")) {
				case 1:
					mes "[Leibech]";
					mes "Oh, alright. ";
					mes "So long as you didn't";
					mes "lose it, that's fine. I'll wait";
					mes "here, so would you bring it";
					mes "to me as soon as you can?";
					close;
				case 2:
					mes "[Leibech]";
					mes "What...?";
					mes "Hey, man.";
					mes "That's not funny!";
					mes "You're joking, right?";
					next;
					switch(select("No. I'm not joking.:Okay, you got me~")) {
					case 1:
						mes "[Leibech]";
						mes "I don't believe it!";
						mes "I think I'm going to";
						mes "write a letter to your";
						mes "boss, Mister Bakerlan.";
						mes "What do you think ";
						mes "about that?";
						close;
					case 2:
						mes "[Leibech]";
						mes "Oh, thank goodness!";
						mes "I thought you might have";
						mes "really lost it! Say, would you";
						mes "bring it to me as soon as";
						mes "can? I'll wait for you here.";
						close;
					}
				}
			}
		}
		else {
			set .@signid,getcharid(0,strcharinfo(0));
			set .@sign3, .@signid & 65535;
			set .@sign4, .@signid >> 16;
			set .@sign1,254;
			set .@sign2,0;
			if (!countitem2(7049,1,0,0,.@sign1,.@sign2,.@sign3,.@sign4)) {
				mes "Hm...?";
				mes "There must be some";
				mes "mistake. This isn't what";
				mes "I ordered. Well, I can wait... ";
				next;
				mes "[Leibech]";
				mes "Just come back and";
				mes "bring me what I actually";
				mes "ordered, alright? And this";
				mes "time, don't make any mistakes.";
				mes "Thanks, I appreciate it~";
				close;
			}
			else {
				mes "Finally, it's here!";
				mes "Yes, this is what I ordered.";
				mes "Thanks for the delivery!";
				next;
				mes "[Leibech]";
				mes "Well, here's your";
				mes "receipt. Please take";
				mes "this to Mister Bakerlan";
				mes "so he knows you did";
				mes "a good job for me.";
				mes "Thanks again!";
				delitem2 7049,1,1,0,0,.@sign1,.@sign2,.@sign3,.@sign4;
				set sign_q,39;
				getitem 7181,1; //Receipt_01
				if (checkre(3)) {
					if (BaseLevel < 60) getexp 100,0;
					else if (BaseLevel < 70) getexp 200,0;
					else if (BaseLevel < 80) getexp 400,0;
					else if (BaseLevel < 90) getexp 700,0;
					else getexp 1100,0;
				} else {
					if (BaseLevel < 60) getexp 1000,0;
					else if (BaseLevel < 70) getexp 2000,0;
					else if (BaseLevel < 80) getexp 4000,0;
					else if (BaseLevel < 90) getexp 7000,0;
					else getexp 11000,0;
				}
				close;
			}
		}
	}
	else if (sign_q == 97) {
		mes "I have a great";
		mes "interest in collecting";
		mes "unique and uncommon";
		mes "goods. You know, things";
		mes "that most people see just";
		mes "once in their lifetimes.";
		next;
		mes "[Leibech]";
		mes "I usually use the";
		mes "Alchesh Trading Company";
		mes "to help add to my collection.";
		mes "Their prices aren't the cheapest, but their service is very reliable.";
		close;
	}
	else if (sign_q == 98) {
		mes "I am interested in collecting uncommon stuffs.";
		mes "For that, I need to find something that I cannot see around here.";
		next;
		mes "[Leibech]";
		mes "Usually, I am using Alchesh Trading Company for that.";
		mes "Although the price is little bit higher than I wish,";
		mes "they are very reliable.";
		close;
	}
	else {
		mes "Hey, thanks for";
		mes "delivering my order";
		mes "for me. It was a great";
		mes "addition to my collection!";
		next;
		mes "[Leibech]";
		mes "It's really tough to";
		mes "find unique and oddball";
		mes "items, but I find great pride";
		mes "in expanding my collection~";
		close;
	}
}

// The Sign (Part 2)
//============================================================
geffen_in,159,48,5	script	Lonely-looking Woman	711,{
	callfunc "F_UpdateSignVars";
	mes "[Brenda Howard]";
	if (sign_q < 54) {
		mes "Hmm...";
		mes "What should I make for";
		mes "dinner today? Pickled cabbage?";
		mes "I learned how to make it a while ago, but I've never gotten the chance to make it yet...";
		close;
	}
	else if (sign_q == 54) {
		mes "Hey, who are you anyhow?";
		mes "Don't you know it's rude to";
		mes "enter someone's house without";
		mes "being invited? Besides, I don't have the time to help strangers while I'm busy making dinner...";
		next;
		mes "["+ strcharinfo(0) +"]";
		mes "W-wait!";
		mes "I'm here to see...";
		next;
		input .@input$;
		if (.@input$ != "Engel Howard") {
			mes "[Brenda Howard]";
			mes "Huh?";
			mes "What are you";
			mes "talking about?";
			next;
			mes "[Brenda Howard]";
			mes "Hmm...";
			mes "I wonder";
			mes "how my pickled";
			mes "cabbage will turn out?";
			emotion ET_DELIGHT;
			close;
		}
		else {
			mes "[Brenda Howard]";
			mes "Ah... I see.";
			mes "You're looking for my husband.";
			mes "My husband, my daughter and";
			mes "I just moved to Geffen from";
			mes "Prontera a while ago.";
			next;
			mes "[Brenda Howard]";
			mes "We moved to Geffen for the sake of my husband's business. Apparently, this town is closest to something he really seems to need. Whatever it is, it must be really important to his smithing work.";
			next;
			mes "[Brenda Howard]";
			mes "Oh, and if you're going to look";
			mes "for my husband, please talk to my daughter before you go. I think she has something that she wants to give to her father...";
			set sign_q,55;
			close;
		}
	}
	else if (sign_q < 57) {
		mes "Ho-ho~!";
		mes "Crisp and delicious pickled";
		mes "cabbage~ My kid loves this stuff and finished it all by herself the last time I made it.";
		close;
	}
	else if (sign_q == 57) {
		mes "Ah...";
		mes "So you've seen my husband.";
		mes "How is he doing? I worry about";
		mes "whether or not he's taking care";
		mes "of himself enough...";
		next;
		mes "[Brenda Howard]";
		mes "Oh, I can't help but worry!";
		mes "Thank you for letting me know";
		mes "how he's doing. Still, he should";
		mes "be doing a better job of keeping";
		mes "in touch with us. ^333333*Sigh*^000000";
		emotion ET_THINK;
		close;
	}
	else if (sign_q < 62) {
		if (countitem(7278) > 0) {
			mes "Thank you so much for bringing";
			mes "this to me. I'm so happy to hear that he's fine and doing well.";
			mes "Although he's not here often enough, it's good to know";
			mes "that he loves his job.";
			next;
			mes "[Brenda Howard]";
			mes "Even so, I should start letting";
			mes "him know that I want him to spend";
			mes "a little more time at home. Oh, and why don't you talk to Liana? She's been waiting to tell you something.";
			delitem 7278,1; //Wellbeing_Letter
			set sign_q,sign_q+4;
			close;
		}
		else {
			mes "Liana's daddy needs to come home more often. ^333333*Sigh*^000000 Even though he's away for long periods of time, I suppose it's for the best...";
			close2;
			emotion ET_THINK;
			end;
		}
	}
	else if (sign_q < 67) {
		mes "So how have you been?";
		mes "So how have you been?";
		mes "As usual, Liana misses";
		mes "her daddy, but I suppose";
		mes "it can't be helped...";
		next;
		mes "I may be no expert, but I'm";
		mes "certain that my husband is";
		mes "the best blacksmith in the world! Did you know Hollgrehenn and Aragham used to be his apprentices? Ho ho ho~";
		close;
	}
	else {
		mes "Try to cherish your";
		mes "family, especially through the";
		mes "hard times. Even when you're angry with them, try to be more understanding. I know it's hard...";
		close;
	}
}

geffen_in,171,42,3	script	Cute Girl	703,{
	callfunc "F_UpdateSignVars";
	if (checkweight(908,200) == 0) {
		mes "^3355FFWait a second! Right now,";
		mes "you have too many items in your inventory. Please come back after you've made more available inventory space.^000000";
		close;
	}
	mes "[Liana]";
	if (sign_q < 54) {
		mes "*Pout*";
		mes "When's my daddy";
		mes "coming home?!";
		mes "I... I miss him so much~";
		mes "*Cries*";
		emotion ET_CRY;
		close;
	}
	else if (sign_q == 54) {
		mes "Oh, my mom said she's gonna cook me something good today.";
		mes "I wonder what she's gonna make?";
		mes "I hope it's pickled cabbage again!";
		emotion ET_SMILE;
		close;
	}
	else if (sign_q == 55) {
		mes "Everyone says that daddy is the best blacksmith in the whole world! But now he lets his apprentices do";
		mes "the work so he can go around the world to find a rare ore~ Isn't that amazing?";
		next;
		switch(select("What are you drawing by the way?:Apprentices?")) {
		case 1:
			mes "[Liana]";
			mes "Oh, this?";
			mes "It's a letter for my daddy.";
			mes "Mom said that some "+((Sex == SEX_MALE)?"guy":"lady")+" is gonna try to find my dad, so I'm making this so "+((Sex == SEX_MALE)?"":"s")+"he can take it him~";
			close;
		case 2:
			mes "[Liana]";
			mes "Yeah, Uncle Hollegrehenn and Aragham come to visit sometimes and we all play. But, it's more fun to see my dad, even though he's not back yet. ^333333*Pout*^000000";
			next;
			switch(select("Don't you miss your dad?:He also misses you a lot.")) {
			case 1:
				mes "[Liana]";
				mes "I miss him sooo much!";
				mes "^333333*Cries*^000000 But Mom always";
				mes "says that he's too busy.";
				mes "^333333*Pouts*^000000";
				close;
			case 2:
				mes "[Liana]";
				mes "I hope so...";
				mes "But I hate it when";
				mes "he doesn't have enough";
				mes "time to come home and";
				mes "see me. Sooooooooo~";
				mes "I wrote this letter!";
				emotion ET_THINK;
				next;
				switch(select("....:I'll bring this to him.")) {
				case 1:
					mes "[Brenda Howard]";
					mes "Liana~";
					mes "This nice "+((Sex == SEX_MALE)?"man":"lady")+" is going to look for your dad. Why don't you ask "+((Sex == SEX_MALE)?"him":"her")+" to take your letter to him for you?";
					next;
					mes "[Liana]";
					mes "You are...?";
					mes "Really, really?";
					mes "H-hooray!";
					next;
					mes "[Liana]";
					mes "Okay then, don't";
					mes "forget to give this to";
					mes "my dad, okay? Promise?";
					emotion ET_DELIGHT;
					set sign_q,56;
					getitem 7276,1; //Picture_Letter
					close;
				case 2:
					mes "[Liana]";
					mes "Mmmm...";
					mes "But I don't know you!";
					mes "Mom says I should never";
					mes "ask for anything from strangers.";
					close;
				}
			}
		}
	}
	else if (sign_q < 62) {
		if (rand(1,10) < 6) {
			mes "My dad never broke anything";
			mes "his customers gave him. And my uncle Hollgrehenn and Aragham wouldn't let anything like that";
			mes "happen, would they?";
			close;
		}
		else {
			mes "Would you please bring my letter over to my dad? Heh heh, he'll be";
			mes "so happy to hear from me!";
			close;
		}
	}
	else if (sign_q < 66) {
		mes "Yay~!";
		mes "Thank you for bringing my letter to my dad. Here, here!";
		mes "You have to share my treasure with me, 'kay?";
		set sign_q,sign_q+4;
		getitem 529,10; //Candy
		close;
	}
	else {
		mes "I never saw my dad fail to upgrade a weapon or armor. Mmm? But maybe if he had something really really old and rare and special...";
		close;
	}
}

mjo_dun02,88,295,4	script	Flaming Spirit Man	85,{
	callfunc "F_UpdateSignVars";
	if (checkweight(908,200) == 0) {
		mes "^3355FFWait a second! Right now,";
		mes "you have too many items in your inventory. Please come back after you've freed up more inventory space.^000000";
		close;
	}
	mes "[Engel]";
	if ((sign_q > 1) && (sign_q < 54)) {
		if(countitem(1002) > 0) {
			mes "Just as I suspected...";
			mes "I didn't bring enough of them.";
			mes "Hmm, this is serious. What";
			mes "am I going to do about this?";
			next;
			mes "[Engel]";
			mes "Oh great! I see that you're";
			mes "carrying some Iron Ores with you. Would you be so kind as to lend me 1 Iron Ore? Please, I beg of you...";
			next;
			switch(select("Sure, why not?:Sorry, I can't.")) {
			case 1:
				mes "[Engel]";
				mes "Thank you so much!";
				mes "If it weren't for your help,";
				mes "I'd be in big trouble. I really appreciate you stepping in and volunteering your materials like this.";
				delitem 1002,1; //Iron_Ore
				getexp 10,0;
				close;
			case 2:
				mes "[Engel]";
				mes "I suppose I understand.";
				mes "However, you're lucky that I don't kick you out of my forge right here and right now~";
				close2;
				emotion ET_HNG;
				end;
			}
		}
		else {
			mes "I hope you understand that";
			mes "this forge isn't really open to the public. I'm doing some intensive training,so I'd appreciate it if you would just leave now.";
			emotion ET_HNG;
			close2;
			warp "mjo_dun02",372,346;
			end;
		}
	}
	else if (sign_q < 56) {
		mes "I hope you understand that";
		mes "this forge isn't really open to the public. I'm doing some intensive training,so I'd appreciate it if you would just leave now.";
		close2;
		emotion ET_HNG;
		end;
	}
	else if (sign_q == 56) {
		if (countitem(7276) > 0) {
			mes "^333333*Sigh*^000000";
			mes "It's been a long";
			mes "time since I've seen";
			mes "my family. I really should let them know how I'm doing sooner or later. Hmmm....";
			next;
			mes "[Engel]";
			mes "...?";
			mes "Were you looking for me?";
			mes "I'm sorry, but I'm busy at the moment. Please don't disturb me while I try to get my work done.";
			next;
			switch(select("I need your help.:Here is a letter for you.:I am leaving, leaving.")) {
			case 1:
				mes "[Engel]";
				mes "Well, I'd like to help you,";
				mes "but now isn't a good for me.";
				mes "plenty of other good smiths out there who can help you with the work that you want done. Farewell.";
				close;
			case 2:
				mes "[Engel]";
				mes "Oh, are you serious?";
				mes "Let me read it first.";
				next;
				mes "[Engel]";
				mes "Yes, yes.";
				mes "...Hahaha!";
				mes "It's so good to hear from";
				mes "my darling daughter.";
				next;
				mes "[Engel]";
				mes "Thanks, I really appreciate that you've delivered this letter for me. Now, is there anything you'd like to ask of me? If it's not a big favor, I can probably help you.";
				next;
				switch(select("Please look at this.")) {
				case 1:
					mes "[Engel]";
					mes "Oh?";
					mes "Isn't this...?";
					mes "I see, I see!";
					next;
					mes "[Engel]";
					mes "Long ago, my old master told me that there are these strange ores that have fallen from the sky. The most beautiful and mysterious is the one shines just like a star.";
					next;
					mes "[Engel]";
					mes "Most people may know it as Sobbing Starlight, but my master used to call it God's Tear Drop.";
					next;
					mes "[Engel]";
					mes "However, this ore has been shattered into pieces. Judging from the smoothness of the edges, its inner power must have caused it to break apart. So you want me to put this back together, don't you?";
					next;
					mes "[Engel]";
					mes "This will be a good challenge";
					mes "for me! However, I'll need some";
					mes "special tools and materials to repair this kind of ore. Now, I want you to bring me the following things...";
					next;
					mes "[Engel]";
					mes "^FF00005 Mini Furnace^000000,";
					mes "^FF00002 Oridecon Hammer^000000,";
					mes "and ^ff00001 good quality Anvil^000000.";
					mes "Now keep in mind that ordinary anvils won't be good enough for";
					mes "this kind of work.";
					next;
					mes "[Engel]";
					mes "Now, an Emperium Anvil would be ideal for this job. I used to have one, but a while back I ended up giving it to someone. Anyway, I'll wait here for you while you gather everything you need.";
					next;
					mes "[Engel]";
					mes "Right. Let me guide you to a shortcut to the exit of these mines, just in case you don't know your way out of here. Good luck~";
					delitem 7276,1; //Picture_Letter
					delitem 7177,7; //Part_Of_Star's_Sob
					set sign_q,57;
					close2;
					warp "mjo_dun02",371,344;
					end;
				}
			case 3:
				mes "[Engel]";
				mes "Alright, then.";
				mes "Take care.";
				close;
			}
		}
		else {
			mes "^333333*Sigh*^000000";
			mes "It's been a long";
			mes "time since I've seen";
			mes "my family. I really should let them know how I'm doing sooner or later. Hmmm....";
			next;
			mes "[Engel]";
			mes "...?";
			mes "Do you have any business";
			mes "me? I'm sorry, but right";
			mes "now I'm very busy. Please leave";
			mes "me alone to my research.";
			close;
		}
	}
	else if (sign_q == 57) {
		mes "As I've told you before, I'm more likely to succeed in my work if I'm able to use a higher quality anvil. Let's me see what you've brought...";
		next;
		if ((countitem(612) > 4) && (countitem(615) > 1) && ((countitem(986) > 0) || (countitem(987) > 0) || (countitem(988) > 0) || (countitem(989) > 0))) {
			mes "[Engel]";
			if (countitem(986) > 0) {
				mes "A...";
				mes "Regular Anvil?";
				mes "Alright, I guess I'll try it.";
				mes "But I can't guarantee success.";
				set .@anvil,0;
			}
			else if (countitem(987) > 0) {
				mes "Ah...";
				mes "An Oridecon Avil.";
				mes "This isn't too bad,";
				mes "but there's a good risk";
				mes "that this might not work.";
				set .@anvil,1;
			}
			else if (countitem(988) > 0) {
				mes "Ah...";
				mes "A Golden Anvil.";
				mes "This just might be able to do the job. This might take a while, so I have something to ask of you.";
				set .@anvil,2;
			}
			else if (countitem(989) > 0) {
				mes "Oh wow, an Emperium Anvil!";
				mes "And this looks like one I might have actually made. Great, I should be able to do this so long as I don't make any critical mistakes~";
				set .@anvil,3;
			}
			next;
			mes "[Engel]";
			mes "While I'm working on this, would you deliver a letter to my family for me? I'm sorry, but please consider that I'm waiving the fee for restoring this Sobbing Starlight.";
			next;
			mes "[Engel]";
			mes "Well then...";
			mes "I wish you safety";
			mes "in your travels.";
			delitem 612,5; //Portable_Furnace
			delitem 615,2; //Oridecon_Hammer
			delitem (986+.@anvil),1; //Anvil-Oridecon_Anvil-Golden_Anvil-Emperium_Anvil
			set sign_q, (58+.@anvil);
			getitem 7278,1; //Wellbeing_Letter
			close;
		}
		else {
			if (rand(1,6) == 3) {
				mes "[Engel]";
				mes "Oh, you don't have everything ready yet? Take your time, so long as you didn't forget what you needed to bring. You do remember, right?";
				next;
				mes "[Engel]";
				mes "^FF00005 Mini Furnace^000000,";
				mes "^FF00002 Oridecon Hammer^000000,";
				mes "and ^ff00001 good quality Anvil^000000.";
				mes "That's all you need!";
				next;
				mes "[Engel]";
				mes "Remember that I have a greater chance of repairing the Sobbing Starlight if I have access to a higher quality Anvil. Otherwise...";
				close;
			}
			else {
				mes "[Engel]";
				mes "Still don't have everything ready? That's fine, just take your time. So long as you haven't forgotten all the things that you need. I mean, how can you forget when you have such an important ore on you?";
				close;
			}
		}
	}
	else if (sign_q < 66) {
		mes "Are you back already?";
		mes "Sorry, but I haven't quite finished yet. I won't be done for a while, so why don't you deliver that letter to my family?";
		close;
	}
	else if (sign_q < 70) {
		if ((sign_q == 66 && rand(1,100) < 38) || (sign_q == 67 && rand(1,100) < 67) || (sign_q == 68 && rand(1,100) < 91) || (sign_q== 69)) {
			mes "Are you back already?";
			mes "While you were gone, I managed to restore this Sobbing Starlight. Why don't you go ahead and take a look?";
			next;
			set sign_q,71;
			getitem 7178,1; //Star's_Sob
			specialeffect2 EF_YUFITELHIT;
			next;
			mes "[Engel]";
			mes "This was one of the most difficult jobs I've ever done. But look! It was beautiful when broken in fragments but now it's absolutely dazzling! This was really worth my effort.";
			next;
			mes "[Engel]";
			mes "In any case, I worked really hard to do a good job on this, so I hope you treasure this Sobbling Starlight, young adventurer.";
			close;
		}
		else switch(sign_q) {
			case 66:
			case 67:
				mes "You've returned?";
				mes "Well, I don't know how to put this, but once you hear it, don't take it the wrong way...";
				emotion ET_PROFUSELY_SWEAT;
				next;
				mes "[Engel]";
				mes "^333333*Ahem*^000000";
				mes "Just as I've warned you, this attempt to restore the Sobbling Starlight failed because the anvil you gave me wasn't up to the job. I'm sorry about that.";
				next;
				mes "[Engel]";
				mes "However, I only";
				mes "broke all of the tools";
				mes "and the ore pieces are still intact. Now, if you bring me the tools one more time, I can try this again.";
				next;
				mes "[Engel]";
				mes "Since I'm a bit more familiar with this material, I won't take so much time. Once again, let me tell you which things you need to bring...";
				next;
				mes "[Engel]";
				mes "^FF00005 Mini Furnace^000000,";
				mes "^FF00002 Oridecon Hammer^000000,";
				mes "and ^ff00001 good quality Anvil^000000.";
				mes "And this time, bring";
				mes "me a better anvil, huh?";
				next;
				mes "[Engel]";
				mes "Although it'd be perfect if I had an Emperium Anvil, I'm pretty sure it'll be alright if we used a Golden Anvil.";
				set sign_q,70;
				close;
			case 68:
				mes "Oh good, you're back.";
				mes "I've got some bad news,";
				mes "so please don't overreact~";
				mes "Um, are you ready?";
				emotion ET_PROFUSELY_SWEAT;
				next;
				mes "[Engel]";
				mes "While I was trying to restore the ";
				mes "Sobbling Starlight, I was attacked ";
				mes "by monsters all of a sudden. If only";
				mes "I paid more attention to my";
				mes "surroundings...";
				next;
				mes "[Engel]";
				mes "Please understand that I get very deeply engrossed in my smithing work. If you don't mind, I'll try this again you'll bring all the tools just like the last time.";
				next;
				mes "[Engel]";
				mes "^FF00005 Mini Furnace^000000 and";
				mes "^FF00002 Oridecon Hammer^000000.";
				mes "Don't forget the ^FF0000Golden Anvil^000000! But if you can get your hands on one, an ^FF0000Emperium Anvil^000000 would be better.";
				set sign_q,70;
				close;
		}
	}
	else if (sign_q == 70) {
		if ((countitem(612) > 4) && (countitem(615) > 1) && ((countitem(986) > 0) || (countitem(987) > 0) || (countitem(988) > 0) || (countitem(989) > 0))) {
			if ((countitem(986) > 0) || (countitem(987) > 0)) {
				mes "Didn't I tell you to bring me a Golden Anvil or an Emperium Anvil? Anything less isn't good enough to do any restoration work on this Sobbing Starlight.";
				next;
				mes "[Engel]";
				mes "Next time you come";
				mes "here, bring a Golden or Emperium Anvil and make sure to leave all of your other anvils in Kafra Storage or something, okay?";
				close;
			}
			else if (countitem(988) > 0) {
				mes "Good, good.";
				mes "I see that you've brought a Golden Anvil. Now I can get started right away! Still, I'm a little about those monsters showing up again, so would you keep a lookout?";
			}
			else if (countitem(989) > 0) {
				mes "Excellent! You've brought an Emperium Anvil! Now, keep a lookout for monsters while I repair these ore fragments. We can't have those beasts ruin my work again, right? Thank you.";
			}
			next;
			mes "^3355FF*Clink*";
			mes "*Clink Clink Clink*";
			mes "*Clink Clink Clink*";
			mes "*Cliiiiiiiiiiiiink*^000000";
			next;
			specialeffect EF_REPAIRWEAPON;
			next;
			mes "^3355FF*Clink*";
			mes "*Clink-Clink*";
			mes "*Clink-Clink-Clink*";
			mes "*Claaaaaaaaaaack*^000000";
			next;
			specialeffect EF_REPAIRWEAPON;
			next;
			mes "[Engel]";
			mes "It's almost done.";
			mes "Just be a bit more patient...";
			next;
			specialeffect EF_REPAIRWEAPON;
			next;
			mes "^3355FF*Tink Tink*^000000";
			mes " ";
			mes "...*Tonk*^000000";
			next;
			specialeffect EF_REPAIRWEAPON;
			next;
			specialeffect EF_FLASHER;
			next;
			mes "[Engel]";
			mes "Finally... Completed.";
			mes "^333333*Phew!*^000000 That was one of the toughest jobs I've ever done, but this was well worth all of our efforts. Just look at the dazzling beauty of this Sobbing Starlight!";
			next;
			mes "[Engel]";
			mes "We've both gone through a lot of trouble to make this, so I hope you treasure your Sobbing Starlight. Good luck on your adventures...";
			if (countitem(988) > 0) delitem 988,1; //Golden_Anvil
			else if (countitem(989) > 0) delitem 989,1; //Emperium_Anvil
			set sign_q,71;
			getitem 7178,1; //Star's_Sob
			specialeffect2 EF_YUFITELHIT;
			close;
		}
		else {
			if (rand(1,6) == 3) {
				mes "Oh, you don't have everything ready yet? Take your time, so long as you didn't forget what you needed to bring. You do remember, right?";
				next;
				mes "[Engel]";
				mes "^FF00005 Mini Furnace^000000,";
				mes "^FF00002 Oridecon Hammer^000000,";
				mes "and ^ff00001 good quality Anvil^000000.";
				mes "That's all you need!";
				next;
				mes "[Engel]";
				mes "Remember that I have a greater chance of repairing the Sobbing Starlight if I have access to a higher quality Anvil. Otherwise...";
				close;
			}
			else {
				mes "Still don't have everything ready? That's fine, just take your time. So long as you haven't forgotten all the things that you need. I mean, how can you forget when you have such an important ore on you?";
				close;
			}
		}
	}
	else if (sign_q < 139) {
		mes "How have you been doing lately? Feel free to ask me if you ever think that you need my expertise, alright?";
		close;
	}
	else if (sign_q == 139) {
		mes "How have you been";
		mes "doing lately? You seem";
		mes "quite well. So is there anything";
		mes "I can help you with today?";
		next;
		select("I need your help again.");
		mes "[Engel]";
		mes "Haha, so what have";
		mes "you brought me this time?";
		mes "It must be fairly important if you've brought it all the way";
		mes "down here.";
		next;
		select("Please look at this.");
		mes "[Engel]";
		mes "Isn't this...?!";
		mes "Amazing, just by looking at it,";
		mes "I can feel its power! You really";
		mes "are something! How do you come across all of this amazing stuff?";
		next;
		mes "[Engel]";
		mes "You know, I consider myself";
		mes "lucky to even see this kind of stuff. Most smiths might be able to see this kind of thing only once in their entire lives. And to be able to work on it...";
		next;
		mes "[Engel]";
		mes "Hmmm...";
		mes "It's going to take quite";
		mes "a while to work on this. Unfortunately, I can't even";
		mes "give you a time estimate...";
		mes "But I'll do my best for you.";
		delitem 7314,1; //The_Sign
		next; //Biali
		// set sign_q,140;
		// set .@stime_e,gettime(DT_HOUR);
		// if (.@stime_e < 2) set sign_sq,1;
		// else if (.@stime_e < 4) set sign_sq,2;
		// else if (.@stime_e < 6) set sign_sq,3;
		// else if (.@stime_e < 8) set sign_sq,4;
		// else if (.@stime_e < 10) set sign_sq,5;
		// else if (.@stime_e < 12) set sign_sq,6;
		// else if (.@stime_e < 14) set sign_sq,7;
		// else if (.@stime_e < 16) set sign_sq,8;
		// else if (.@stime_e < 18) set sign_sq,9;
		// else if (.@stime_e < 20) set sign_sq,10;
		// else if (.@stime_e < 22) set sign_sq,11;
		// else set sign_sq,12;
		// close;
	// }
	// else if (sign_q == 140) {
		// set .@stime_e1,gettime(DT_HOUR);
		// if (.@stime_e1 < 2) {
		// 	if (sign_sq == 11) {
		// 		set .@pass_s1,1;
		// 	}
		// }
		// else if (.@stime_e1 < 4) {
		// 	if (sign_sq == 12) {
		// 		set .@pass_s1,1;
		// 	}
		// }
		// else if (.@stime_e1 < 6) {
		// 	if (sign_sq == 1) {
		// 		set .@pass_s1,1;
		// 	}
		// }
		// else if (.@stime_e1 < 8) {
		// 	if (sign_sq == 2) {
		// 		set .@pass_s1,1;
		// 	}
		// }
		// else if (.@stime_e1 < 10) {
		// 	if (sign_sq == 3) {
		// 		set .@pass_s1,1;
		// 	}
		// }
		// else if (.@stime_e1 < 12) {
		// 	if (sign_sq == 4) {
		// 		set .@pass_s1,1;
		// 	}
		// }
		// else if (.@stime_e1 < 14) {
		// 	if (sign_sq == 5) {
		// 		set .@pass_s1,1;
		// 	}
		// }
		// else if (.@stime_e1 < 16) {
		// 	if (sign_sq == 6) {
		// 		set .@pass_s1,1;
		// 	}
		// }
		// else if (.@stime_e1 < 18) {
		// 	if (sign_sq == 7) {
		// 		set .@pass_s1,1;
		// 	}
		// }
		// else if (.@stime_e1 < 20) {
		// 	if (sign_sq == 8) {
		// 		set .@pass_s1,1;
		// 	}
		// }
		// else if (.@stime_e1 < 22) {
		// 	if (sign_sq == 9) {
		// 		set .@pass_s1,1;
		// 	}
		// }
		// else {
		// 	if (sign_sq == 10) {
		// 		set .@pass_s1,1;
		// 	}
		// }
		// if (.@pass_s1 == 1) {
			mes "[Engel]";
			mes "It's so...";
			mes "Beautiful! I don't know";
			mes "if I'll ever see anything";
			mes "like this again in my life...";
			next;
			mes "[Engel]";
			mes "Oh, you're back just in time.";
			mes "Although it was one of my most difficult jobs, I believe you'll be pleased with my work. Only a few smiths are privileged enough to work with this, even just once.";
			next;
			mes "[Engel]";
			mes "This is now yours to keep.";
			mes "Thank you for giving me the";
			mes "honor of working on a worthy";
			mes "smithing challenge.";
			set sign_q,141;
			getitem 2644,1; //The_Sign_
			close;
		// }
		// else {
		// 	mes "I haven't completed it yet, but please understand that I've got to be really careful when working with something so valuable. But don't worry, its inner power will be revealed when I'm finished.";
		// 	close;
		// }
	}
	else {
		mes "Sometimes, you can only";
		mes "improve yourself by training in solitude. But don't ever forget about the ones who really care about you. It's those people who make everything worth it.";
		close2;
		emotion ET_THINK;
		end;
	}
}

gef_tower,118,36,4	script	Annoyed Man	64,{
	callfunc "F_UpdateSignVars";
	mes "[Dhota]";
	if (sign_q < 72) {
		mes "Hmmm...";
		mes "That can't be right...";
		mes "What could possibly be";
		mes "the answer I'm looking";
		mes "for? ^333333*Sigh...*^000000";
		emotion ET_HNG;
		close;
	}
	else if (sign_q == 72) {
		if (BaseClass == Job_Mage) {
			mes "Wah~";
			mes "Why the hell did he even go there...!";
		}
		else {
			mes "You're not even a Mage,";
			mes "much less a Wizard, Sage, Warlock or a Sorcerer.";
			mes "Why bother climbing this tower?";
		}
		mes "What are you doing here?!";
		emotion ET_HNG;
		next;
		input .@input$;
		if ((.@input$ == "Metz Brayde") || (.@input$ == "Sobbing Starlight")) {
			mes "[Dhota]";
			mes "Eh?";
			if (.@input$ == "Metz Brayde") {
				mes "Did you just say you're";
				mes "here for Metz Brayde?";
			}
			if (.@input$ == "Sobbing Starlight") {
				mes "For that Sobbing Starlight, is that right?";
			}
			next;
			mes "[Dhota]";
			mes "...";
			emotion ET_THINK;
			next;
			mes "[Dhota]";
			mes "...";
			mes "......";
			emotion ET_THINK;
			next;
			mes "[Dhota]";
			mes "...";
			mes "......";
			mes "BWAAAAH~!";
			emotion ET_ANGER;
			next;
			mes "[Dhota]";
			mes "Right, he wants that guy";
			mes "who's good at working with";
			mes "gems and stuff. Eh, he's not";
			mes "here right now. Went somewhere";
			mes "near Comodo to investigate some";
			mes "tribal people or whatever.";
			set sign_q,73;
			emotion ET_HNG;
			close;
		}
		else {
			mes "[Dhota]";
			mes "Say what...?";
			mes "I have no idea what";
			mes "you're talking about!";
			mes "If you've got nothing";
			mes "to say, then leave me alone!";
			close;
		}
	}
	else {
		mes "Hmmm...";
		mes "That can't be right...";
		mes "What could possibly be";
		mes "the answer I'm looking";
		mes "for? ^333333*Sigh...*^000000";
		emotion ET_HNG;
		close;
	}
}

umbala,163,256,3	script	Native#_s	781,{
	callfunc "F_UpdateSignVars";
	if (event_umbala >= 3) {
		mes "[Laotan]";
		if (sign_q < 73) {
			mes "Oh, I wish I had";
			mes "a Mr. Smile mask!";
			mes "But where can I get";
			mes "one of those? Well, I'd";
			mes "be happy if I had some";
			mes "Meat to eat, I guess!";
			emotion ET_DELIGHT;
			close;
		}
		else if (sign_q == 73) {
			mes "Mmm...?";
			mes "A new guy in our village?";
			mes "I think I know him! Yea, I do!";
			next;
			mes "[Laotan]";
			if (countitem(2278) > 0) {
				mes "Oh my gosh!";
				mes "You've got a Mr. Smile mask!";
				mes "Would you give that to me?";
				mes "Pretty please...?";
				next;
				switch(select("Sure~:^FF0000No.^000000")) {
				case 1:
					mes "[Laotan]";
					mes "Hooooray!";
					mes "Thank you thank you";
					mes "thank you thank you";
					mes "soooooooooo much!";
					next;
					mes "[Laotan]";
					mes "Oh right~!";
					mes "The weird man in the funny clothes was in our village for a while, but ever since he went into that big tree, nobody's seen him!";
					delitem 2278,1; //Mr_Smile
					set sign_q,74;
					close;
				case 2:
					mes "[Laotan]";
					mes "I...";
					mes "I was...";
					mes "I just...";
					mes "Waaaaaaahhhh!";
					close;
				}
			}
			else {
				mes "Waaaait.";
				mes "I knooow~!";
				mes "I know if you get";
				mes "me a Mr. Smile, okay?";
				close;
			}
		}
		else {
			mes "I love my Mr. Smile mask";
			mes "soooo much! I'm gonna show";
			mes "it to all my friends! Thank you";
			mes "so much again! You're really";
			mes "really nice, you know that?";
			close;
		}
	}
	else {
		mes "[??????]";
		mes "Chuuuba?";
		mes "Chu-chu-chu-chu-chaba?";
		mes "Oom oom oom daba. Blip blip?";
		mes "Sabaloo koombah Solo. Ho ho~";
		close;
	}
}

um_in,27,23,3	script	Fastidious-Looking Guy	121,{
	callfunc "F_UpdateSignVars";
	if (checkweight(908,200) == 0) {
		mes "^3355FFWait a second! Right now,";
		mes "you have too many items in your inventory. Please come back after you've freed up more inventory space.^000000";
		close;
	}
	if (sign_q < 74) {
		mes "^333333*Giggle*^000000";
		mes "So if I do this,";
		mes "then that and then...";
		mes "Ooh, these calculations";
		mes "are absolutely perfect!";
		emotion ET_KIK;
		next;
		mes "[Cyon]";
		mes "Wh-what?!";
		mes "Who are you?";
		mes "H-how did you get";
		mes "in here? I demand";
		mes "that you leave, right now!";
		emotion ET_FRET;
		close2;
		warp "umbala",111,121;
		end;
	}
	else if (sign_q == 74) {
		mes "[Cyon]";
		mes "^333333*Giggle*^000000";
		mes "So if I do this,";
		mes "then that and then...";
		mes "Ooh, these calculations";
		mes "are absolutely perfect!";
		emotion ET_KIK;
		next;
		mes "[Cyon]";
		mes "Wh-what?!";
		mes "Who are you?";
		mes "H-how did you get";
		mes "in here? I demand";
		mes "that you leave, right now!";
		emotion ET_FRET;
		next;
		switch(select("I'm here for Metz Brayde.:My apologies.:Would you look at this?:...")) {
		case 1:
			mes "[Cyon]";
			mes "Huh? Brayde?";
			mes "Do you expect me";
			mes "to just trust you without";
			mes "a single shred of proof that";
			mes "he sent you? Get out now!";
			close;
		case 2:
			mes "[Cyon]";
			mes "If you're so sorry,";
			mes "then hurry up and get";
			mes "out of here! Not just anyone";
			mes "is allowed here! Leave!";
			emotion ET_HNG;
			close;
		case 3:
			mes "[Cyon]";
			mes "What could be so";
			mes "special about what";
			mes "you've brought here?!";
			mes "Fine, you've piqued my";
			mes "scientific curiosity...";
			next;
			emotion ET_HUK;
			next;
			mes "[Cyon]";
			mes "Sweet lord...";
			mes "This is 'God's Tear Drop!'";
			mes "The Sobbling Starlight!";
			mes "He finally made it....";
			next;
			mes "[Cyon]";
			mes "^333333*Giggle*^000000";
			mes "Well, since he's kept his promise, I suppose that I should keep mine";
			mes "as well. Now, within this Sobbing Starlight are these tiny letters... ^FFFFFFcobo^000000";
			next;
			mes "[Cyon]";
			mes "The text is so small that even Hunters skilled in Vulture's Eye are unable to read them. However, I've read that this Sobbing";
			mes "Starlight will respond";
			mes "to really old papers...";
			next;
			mes "[Cyon]";
			mes "Now, if we want to figure out";
			mes "what's written in the Sobbing";
			mes "Starlight, we'd need at least";
			mes "10 ancient pieces of paper...";
			set sign_q,75;
			close;
		case 4:
			specialeffect EF_VENOMDUST;
			mes "[Cyon]";
			mes "Not listening, eh?";
			mes "Fine, if you don't";
			mes "understand words, then";
			mes "I'll have to use force!";
			mes "Get out here right now!";
			close2;
			percentheal -30,0;
			specialeffect2 EF_MAGNUMBREAK;
			end;
		}
	}
	else if (sign_q == 75) {
		mes "[Cyon]";
		mes "You've come back.";
		mes "I hope you were able";
		mes "to find some ancient";
		mes "or really aged paper...";
		next;
		if (countitem(1097) > 9) {
			mes "[Cyon]";
			mes "How did you find these";
			mes "Worn Out Pages? This is great,";
			mes "I'm sure the Sobbing Starlight";
			mes "will respond to these!";
			next;
			mes "[Cyon]";
			mes "Yes. Yes...";
			mes "This should be enough.";
			mes "Now give them to me";
			mes "and wait here while";
			mes "I try a few things...";
			next;
			specialeffect EF_SPHERE;
			next;
			mes "[Cyon]";
			mes "Just as I thought!";
			mes "The Sobbing Starlight is responding to these Worn Out Pages! Excellent! I've finally fulfilled my promise to Metz! Now he can leave";
			mes "me alone!";
			delitem 1097,10; //Worn_Out_Page
			set sign_q,76;
			getitem 7275,1; //Ancient_Document
			close;
		}
		else if (countitem(1097) > 0) {
			mes "[Cyon]";
			mes "How did you find these";
			mes "^FF0000Worn Out Pages^000000? This is great,";
			mes "I'm sure the Sobbing Starlight";
			mes "will respond to these!";
			next;
			mes "[Cyon]";
			mes "Wait, we don't have enough";
			mes "of them to make the Sobbing";
			mes "Starlight respond. Find more";
			mes "of these papers and bring";
			mes "them all to me!";
			close;
		}
		else {
			mes "[Cyon]";
			mes "You haven't found anything?";
			mes "What kind of scientist are you?";
			mes "Now go out and find some old and ancient papers so that we can learn what's written in the Sobbing Starlight! Go!";
			next;
			mes "[Cyon]";
			mes "...?";
			mes "Why are you still here?";
			mes "Leave and do what I told";
			mes "you to do, alright?! Don't";
			mes "make me get violent...";
			next;
			percentheal -30,0;
			specialeffect2 EF_MAGNUMBREAK;
			next;
			warp "umbala",111,121;
			end;
		}
	}
	else if (sign_q == 76) {
		mes "[Cyon]";
		mes "My business with you is finished, so you go along on your way now. And tell Metz not to bother me anymore! I'm done doing favors!";
		close;
	}
	else {
		mes "[Cyon]";
		mes "How dare you intrude";
		mes "on my property?! Now,";
		mes "get out now before I get";
		mes "violent! Didn't you hear me?";
		mes "GET OUT OF HERE!";
		close;
	}
}

alberta,165,83,4	script	Fastidious Old Man	755,{
	callfunc "F_UpdateSignVars";
	if (checkweight(908,200) == 0) {
		mes "^3355FFWait a second! Right now,";
		mes "you have too many items in your inventory. Please come back after you've freed up more inventory space.^000000";
		close;
	}
	mes "[Frank]";
	if (sign_q < 77) {
		mes "My back~";
		mes "It's so sore!";
		mes "And my eyes are";
		mes "hurting worse and worse.";
		mes "^333333*Sigh*^000000 I'm getting old...";
		close;
	}
	else if (sign_q == 77) {
		mes "My vision's getting";
		mes "blurrier and I get headaches";
		mes "when I read. I guess this old";
		mes "man's got no choice but to get";
		mes "some sort of seeing aid...";
		set sign_q,78;
		close;
	}
	else if (sign_q == 78) {
		if ((countitem(2203) > 0) && (countitem(7275) > 0)) {
			mes "My vision's getting";
			mes "blurrier and I get headaches";
			mes "when I read. I guess this old";
			mes "man's got no choice but to get";
			mes "some sort of seeing aid...";
			next;
			switch(select("Wait, I've got a pair of glasses...:Pass on by.")) {
			case 1:
				mes "[Frank]";
				mes "Oh, you've brought me";
				mes "these Glasses? Thanks";
				mes "so much, youngster. Now that";
				mes "I can see better, what can";
				mes "I do for you in return?";
				next;
				while(1) {
					switch(select("About Geffen's Hidden Power:About Sobbing Starlight:Interpret Ancient Document")) {
					case 1:
						mes "[Frank]";
						mes "Geffen's hidden power?";
						mes "I don't know much about it, but I'm sure that Geffen Tower is more than just a simple building. I'm sure it was created to restrain or contain some powerful force.";
						next;
						mes "[Frank]";
						mes "It's even possible that the fountain in front of Geffen Tower also plays the same role, but I've got no hard evidence. Since I'm not too interested in Geffen, I haven't really investigated...";
						next;
						mes "[Frank]";
						mes "Still...";
						mes "There's a strong possibility that some enormous power is being sealed beneath the Geffen Tower.";
						next;
						break;
					case 2:
						mes "[Frank]";
						mes "The Sobbing Starlight?";
						mes "To the experts, it's known as God's Tear Drop. Now, some believe it was created from the voice of God.";
						next;
						mes "[Frank]";
						mes "Of course, it probably isn't made from God's voice or tear drops, but who knows? In any case, it's said that something's written in the Sobbing Starlight. What ever it is, it must be something important...";
						next;
						break;
					case 3:
						mes "[Frank]";
						mes "I don't believe it!";
						mes "This is... I see. You want me to translate this ancient language. Ah, you're rather fortunate. I'm probably the only person in the world who can translate this.";
						next;
						mes "[Frank]";
						mes "Hmm, as far as I can tell, this is a sophisticated language spoken by the ancient gods. It's complex and confusing, but I'll do my best for you. Come back to me later, and I'll what I've learned.";
						delitem 2203,1; //Glasses
						delitem 7275,1; //Ancient_Document
						set sign_q,79;
						close;
					}
				}
			case 2:
				mes "[Frank]";
				mes "Oooh~";
				mes "How will I ever";
				mes "be able to continue";
				mes "my life's work? I'm";
				mes "helpless if I can't read...";
				close;
			}
		}
		else {
			mes "My vision's getting";
			mes "blurrier and I get headaches";
			mes "when I read. I guess this old";
			mes "man's got no choice but to get";
			mes "some sort of seeing aid...";
			close;
		}
	}
	else if (sign_q == 79) {
		if (rand(1,50) == 9) {
			mes "I've finally completed the translation. It was a challenge deciphering the meaning of some";
			mes "of these words. Even translated in our own language, this contents of this text are fairly ambiguous.";
			next;
			mes "[Frank]";
			mes "Well, I've written down the best translation that I could for you. It's been a long time since I've had this kind of challenge. Thanks, youngster.";
			mes "Ha ha ha~";
			set sign_q,80;
			getitem 7274,1; //Ancient_Translator
			close;
		}
		else {
			mes "I'm sorry, but I haven't finished translating this text. It's taking quite a long time since I don't have any reference material for this particular language. Why";
			mes "don't you come back later?";
			close;
		}
	}
	else {
		mes "There are many things out";
		mes "there that defy our understanding of the world and are beyond our imagination. Many fear the unknown, but the truly brave will always seek out the truth.";
		close;
	}
}

gef_fild07,182,241,0	script	#Valkyrie Warp	111,1,1,{
	callfunc "F_UpdateSignVars";
	if ((sign_q == 80) && (countitem(907) > 3) && (countitem(953) > 11) && (countitem(7013) > 364)) {
		mes "^6B8E23It seems that";
		mes "something in the";
		mes "vicinity is reacting";
		mes "with the Sobbing Starlight";
		mes "in your possession. Perhaps";
		mes "you can find it nearby...^000000";
		close;
	}

OnTouch_:
	if ((sign_q == 80) && (countitem(907) > 3) && (countitem(953) > 11) && (countitem(7013) > 364)) {
		mes "["+strcharinfo(0)+"]";
		mes "What the...?";
		mes "What's happening?!";
		specialeffect2 EF_BEGINSPELL6;
		next;
		mes "^3355FFFor some reason, in";
		mes "this particular spot, the";
		mes "Sobbing Starlight is reacting";
		mes "with the Resin, Stone Hearts";
		mes "and Coral Reefs that you're";
		mes "holding. All the objects are";
		mes "violently resonating...^000000";
		specialeffect2 EF_ENHANCE;
		next;
		mes "^3355FFAll of a sudden these";
		mes "objects emit a bright flash";
		mes "of light that envelops your";
		mes "entire body, then you gently";
		mes "fall into unconsciousness...^000000";
		specialeffect2 EF_FLASHER;
		next;
		delitem 907,4; //Resin
		delitem 953,12; //Stone_Heart
		delitem 7013,365; //Coral_Reef
		set sign_q,81;
		warp "himinn",49,10;
		end;
	}
	else if (sign_q == 203) {
		mes "^3355FFNothing seems to";
		mes "happen when you";
		mes "approach this area now.^000000";
		close;
	}
	else if (sign_q > 80) {
		warp "himinn",49,10;
	}
	end;
}

himinn,48,86,5	script	Valkyrie#sign	811,{
	callfunc "F_UpdateSignVars";
	mes "[Valkyrie Sandra]";
	if (sign_q < 81) {
		mes "Only the chosen";
		mes "can enter this place.";
		mes "I will not ask how you've";
		mes "gained entrance, but I will";
		mes "require you to leave.";
		close2;
		warp "gef_fild07",180,242;
		end;
	}
	else if (sign_q == 81) {
		mes "Welcome, "+strcharinfo(0)+",";
		mes "to this realm of holiness.";
		mes "You have endured great difficulty and tested your courage to obtain the Sobbing Starlight, which will be the certificate for your test.";
		next;
		select("Test...?");
		mes "[Valkyrie Sandra]";
		mes "The gods have decided that";
		mes "you are worthy of undergoing";
		mes "a special test that will judge";
		mes "your merits. If you are a true";
		mes "hero who is pure of heart,";
		mes "you will certainly succeed...";
		next;
		mes "[Valkyrie Sandra]";
		mes "Now, there is a critical";
		mes "situation in the ^FF0000realm where";
		mes "the fallen warriors dwell^000000. The";
		mes "gods wish for you to restore the balance by quelling a specific";
		mes "evil influence in that place.";
		next;
		mes "[Valkyrie Sandra]";
		mes "There will be many obstacles.";
		mes "First, the fallen, who will target their anger and hatred towards";
		mes "you. Where they have failed to";
		mes "enter Valhalla, you have a rare";
		mes "and wondrous opportunity...";
		next;
		mes "[Valkyrie Sandra]";
		mes "Secondly, and more";
		mes "importantly, you must find";
		mes "this evil influence on your";
		mes "own. This will judge your";
		mes "ability to discern good from evil. Do not trust appearances...";
		next;
		mes "[Valkyrie Sandra]";
		mes "This is your task.";
		mes "I cannot tell you more.";
		mes "It is now your duty to";
		mes "travel there and ferret";
		mes "out true darkness from";
		mes "one of the hearts there...";
		set sign_q,82;
		percentheal 100,100;
		if (checkre(3)) {
			if (BaseLevel < 56) getexp 900,0;
			else if ((BaseLevel > 55) && (BaseLevel < 61)) getexp 1200,0;
			else if ((BaseLevel > 60) && (BaseLevel < 66)) getexp 2000,0;
			else if ((BaseLevel > 65) && (BaseLevel < 71)) getexp 3500,0;
			else if ((BaseLevel > 70) && (BaseLevel < 76)) getexp 7000,0;
			else if ((BaseLevel > 75) && (BaseLevel < 81)) getexp 12000,0;
			else if ((BaseLevel > 80) && (BaseLevel < 86)) getexp 16000,0;
			else if ((BaseLevel > 85) && (BaseLevel < 91)) getexp 21000,0;
			else getexp 35000,0;
		} else {
			if (BaseLevel < 56) getexp 9000,0;
			else if ((BaseLevel > 55) && (BaseLevel < 61)) getexp 12000,0;
			else if ((BaseLevel > 60) && (BaseLevel < 66)) getexp 20000,0;
			else if ((BaseLevel > 65) && (BaseLevel < 71)) getexp 35000,0;
			else if ((BaseLevel > 70) && (BaseLevel < 76)) getexp 70000,0;
			else if ((BaseLevel > 75) && (BaseLevel < 81)) getexp 120000,0;
			else if ((BaseLevel > 80) && (BaseLevel < 86)) getexp 160000,0;
			else if ((BaseLevel > 85) && (BaseLevel < 91)) getexp 210000,0;
			else getexp 350000,0;
		}
		close2;
		warp "geffen",120,100;
		end;
	}
	else if (sign_q < 95) {
		mes "I commend your ability";
		mes "to survive in the realm";
		mes "of the dead. I imagine it";
		mes "must be very difficult for";
		mes "a mortal to endure its cruelty.";
		close;
	}
	else if (sign_q == 95) {
		mes "Regrettably, I can't really";
		mes "provide any answers for you.";
		mes "You must overcome the ordeals";
		mes "of the gods on your own. All I can do is offer my guidance and prayer. ^FFFFFFcobo^000000";
		next;
		mes "[Valkyrie Sandra]";
		mes "Remember that the";
		mes "demonstration of your belief,";
		mes "rather than the decision to";
		mes "blindly adhere to faith, is";
		mes "what the gods want to see.";
		next;
		mes "[Valkyrie Sandra]";
		mes "Always step forward";
		mes "with wisdom and courage.";
		mes "That is all I can tell you.";
		set sign_q,96;
		close;
	}
	else if ((sign_q == 129) || (sign_q == 130)) {
		mes "Welcome back.";
		mes "Not only have you passed the trials that the gods have set for you, you have tested your courage in the realm of the dead and protected Midgard from attack.";
		next;
		mes "[Valkyrie Sandra]";
		mes "I'm pleased to announce that the gods have been watching you and decided to invite you to Valhalla. However, Midgard still has great need of you.";
		next;
		mes "[Valkyrie Sandra]";
		mes "As a symbol of this promise to invite you to Valhalla, you shall be rewarded with 'The Sign' which will show all others that you are a great warrior whose courage was tested by the gods themselves.";
		next;
		mes "[Valkyrie Sandra]";
		mes "Congratulations,";
		mes ""+ strcharinfo(0) +". Verily,";
		mes "you are an honorable";
		mes "hero worthy of praise!";
		set sign_q,137;
		getitem 7314,1; //The_Sign
		close;
	}
	else if (sign_q < 150) {
		mes "The gods are watching";
		mes "you. Prove your courage,";
		mes "and at that moment, you";
		mes "will earn the honor of being";
		mes "selected by the gods.";
		close;
	}
	else if ((sign_q > 199) && (sign_q < 202)) {
		mes "You have yet to";
		mes "fully prove your courage.";
		mes "Once you do, you will be";
		mes "summoned by the gods.";
		close;
	}
	else if (sign_q == 202) {
		mes "The gods are disappointed";
		mes "in what you have decided to";
		mes "do. Unfortunately, you have";
		mes "been banished from Valhalla";
		mes "and this place as well.";
		next;
		mes "[Valkyrie Sandra]";
		mes "Although you have failed,";
		mes "I hope that you find your";
		mes "another way to win back";
		mes "the favor of the gods...";
		set sign_q,203;
		close;
	}
	else {
		if (countitem(7314) < 1) {
			mes "Only the chosen";
			mes "can enter this place.";
			mes "I will not ask how you've";
			mes "gained entrance, but I will";
			mes "require you to leave.";
			close2;
			warp "gef_fild07",180,242;
			end;
		}
		else {
			mes "Great warrior,";
			mes "your time has not yet";
			mes "come. Please focus on";
			mes "your training until you";
			mes "are summoned by the gods...";
			close;
		}
	}
}

// The Sign (Part 3)
//============================================================
que_sign01,196,39,4	script	Serin#dummy	90,{
	end;

OnDisable:
OnInit:
	disablenpc "Serin#dummy";
	end;

OnEnable:
	enablenpc "Serin#dummy";
	end;

OnStart:
	initnpctimer;
	end;

OnTimer3000:
	specialeffect EF_GLASSWALL;
	end;

OnTimer6000:
	specialeffect EF_CRASHEARTH;
	end;

OnTimer9000:
	specialeffect EF_LORD;
	end;

OnTimer13000:
	donpcevent "Serin#dummy::OnDisable";
	donpcevent "Dark Lord#serin::OnEnable";
	donpcevent "Serin#serin::OnEnable";
	stopnpctimer;
	end;
}

que_sign01,196,44,4	script	Dark Lord#serin	737,{
	end;

OnDisable:
OnInit:
	disablenpc "Dark Lord#serin";
	end;

OnEnable:
	enablenpc "Dark Lord#serin";
	end;
}

que_sign01,196,39,4	script	Serin#serin	90,{
	callfunc "F_UpdateSignVars";
	if (sign_q < 132) {
		mes "[Serin]";
		mes "....?";
		close;
	}
	else if (sign_q == 132) {
		mes "[Serin]";
		mes "As its magic power grows,";
		mes "the Magic Circle is nearing completion. The symbol which I've asked you for is the last material needed for summoning Dark Lord.";
		next;
		mes "[Serin]";
		mes "However, the power of that";
		mes "symbol can be used to complete";
		mes "the Magic Circle or destroy it.";
		mes "Would you hand it over to me?";
		mes "I choose to destroy this...";
		next;
		mes "[Serin]";
		mes "Please...";
		mes "Let me have the symbol.";
		next;
		select("Give Serin the symbol.");
		mes "[Serin]";
		mes "This could be";
		mes "pretty dangerous";
		mes "so please step back...";
		delitem 7305,1; //Authority_Of_Nine_World
		set sign_q,133;
		donpcevent "Serin#dummy::OnEnable";
		donpcevent "Serin#dummy::OnStart";
		donpcevent "Serin#serin::OnDisable";
		close;
	}
	else if (sign_q == 133) {
		mes "[Serin]";
		mes "I'm sorry.";
		mes "But I have to do this";
		mes "to summon Dark Lord.";
		next;
		select("But why...?");
		mes "[Serin]";
		mes "It was never the witch";
		mes "that wanted Dark Lord summoned,";
		mes "but me. I've always wanted to return to my human form. I'm sick and tired of being bound here in Niflheim!";
		next;
		mes "[Serin]";
		mes "Unfortunately, the symbol";
		mes "which Lady Hell gave you is";
		mes "limited to a one time use. Its";
		mes "power wasn't enough to bring me";
		mes "back, so summoning Dark Lord is";
		mes "my last chance.";
		next;
		select("But if Dark Lord comes to Midgard...");
		mes "[Serin]";
		mes "Oh, I'm pretty sure of";
		mes "what will happen if Dark Lord";
		mes "enters the realm of the living. He'll destroy Midgard and bring death to thousands and thousands of people.";
		next;
		mes "[Serin]";
		mes "So if I came back to life";
		mes "and everyone else were dead,";
		mes "However, by summoning Dark Lord,";
		mes "you might be thinking it'd be pretty pointless for me to come back. But you know what? I don't care.";
		next;
		mes "[Serin]";
		mes "The living don't appreciate";
		mes "what they have, so they ought";
		mes "to be punished. They can all go to Niflheim while I enjoy the warmth of the sun and the fresh outside air.";
		next;
		mes "[Serin]";
		mes "Maybe you might not";
		mes "pity my situation since you've";
		mes "never been bound to Niflheim,";
		mes "but I'm begging you. Don't get";
		mes "in my way.";
		next;
		switch(select("Alright. I'll let you go.:No, you have to be stopped.")) {
		case 1:
			mes "[Serin]";
			mes "Are you really willing";
			mes "to throw so much away for";
			mes "my sake? You do understand";
			mes "that you'll be failing the ordeals set before you by the gods...";
			next;
			switch(select("I changed my mind for Midgard.:I do, and it's alright...")) {
			case 1:
				mes "[Serin]";
				mes "...";
				mes "I really don't want to fight you,";
				mes "but I've come too far to give up now. If you insist on interfering, then you leave me no choice...";
				next;
				donpcevent "Dark Lord#serin::OnEnable";
				mes "[Dark Lord]";
				mes "^330033Insolent mortal!";
				mes "Do you really think";
				mes "you have a chance of";
				mes "stopping me? Hmpf.";
				mes "Every fool must learn.";
				mes "Prepare to die!^000000";
				set sign_q,134;
				donpcevent "Serin#serin::OnDisable";
				donpcevent "Dark Lord#serin::OnDisable";
				donpcevent "CallMonster#serin::Oncall";
				close;
			case 2:
				mes "[Serin]";
				mes "The least I can";
				mes "do is send you back";
				mes "to Midgard and";
				mes "ask the Dark Lord to spare";
				mes "you. Thank you so much...";
				set sign_q,200;
				getexp (checkre(3))?20000:200000,0;
				set $@sign_w2,0;
				donpcevent "Dark Lord#serin::OnDisable";
				close2;
				warp "umbala",132,203;
				end;
			}
		case 2:
			mes "[Serin]";
			mes "...";
			mes "I really don't want to fight you,";
			mes "but I've come too far to give up now. If you insist on interfering, then you leave me no choice...";
			next;
			emotion ET_KIK, getnpcid(0, "Dark Lord#serin");
			mes "[Dark Lord]";
			mes "^330033Insolent mortal!";
			mes "Do you really think";
			mes "you have a chance of";
			mes "stopping me? Hmpf.";
			mes "Every fool must learn.";
			mes "Prepare to die!^000000";
			set sign_q,134;
			donpcevent "Serin#serin::OnDisable";
			donpcevent "Dark Lord#serin::OnDisable";
			donpcevent "CallMonster#serin::Oncall";
			close;
		}
	}
	else if (sign_q == 134) {
		mes "[Serin]";
		mes "I see now.";
		mes "Soon, I'll lose my memories";
		mes "and remain dead in Niflheim.";
		mes "Just like all the others. Still,";
		mes "may I ask you one question?";
		next;
		mes "[Serin]";
		mes "With that symbol, you";
		mes "could order the dead to do";
		mes "whatever you want. Why didn't";
		mes "you use it to command me to quit?";
		next;
		mes "[Serin]";
		mes "...";
		mes "......";
		mes "..........";
		next;
		mes "[Serin]";
		mes "I see it now.";
		mes "The kindness in your eyes";
		mes "tells me everything. You wanted to give me another chance. But in the end, I managed to destroy the";
		mes "chance you had given me.";
		next;
		mes "[Serin]";
		mes "Even though I'm nothing but";
		mes "a spirit now, it was an honor";
		mes "for me to meet somebody like you. Although I'll lose my memories, I'll try not to forget you.";
		next;
		mes "[Serin]";
		mes "My memories of your";
		mes "courage and kindness";
		mes "are more precious to";
		mes "me than life itself.";
		next;
		mes "[Serin]";
		mes "Farewell, now.";
		mes "And good luck on";
		mes "your travels, my friend...";
		set sign_q,135;
		close;
	}
	else if (sign_q == 135) {
		mes "^3355FFYou helped the";
		mes "unconscious Serin";
		mes "and returned to Niflheim.^000000";
		close2;
		set sign_q,136;
		set $@sign_w2,0;
		warp "que_sign01",117,137;
		end;
	}
	else if (sign_q == 199) {
		set .@fail_s1,rand(1,800);
		set .@fail_s2,rand(1,700);
		set .@fail_s3,rand(1,600);
		set .@fail_s4,rand(1,500);
		set .@fail_s5,rand(1,400);
		if (countitem(2643) == 1) {
			if (((sign_sq == 0) && (.@fail_s3 == 356)) || ((sign_sq == 1) && (.@fail_s2 == 356)) || (.@fail_s1 == 356)) {
				set sign_q,200;
				mes "[Serin]";
				mes "Even though you tried";
				mes "to stop me, I still don't wish";
				mes "to take your life. I understand";
				mes "that you've merely trying to";
				mes "protect your Midgard.";
				next;
				mes "[Serin]";
				mes "However...";
				mes "I do not think you";
				mes "have the courage to";
				mes "overcome the ordeals ";
				mes "of the gods. Please don't";
				mes "come here anymore...";
				next;
				mes "[Serin]";
				mes "Farewell...";
				close2;
				set $@sign_w2,0;
				warp "niflheim",30,156;
				end;
			}
			else {
				mes "[Serin]";
				mes "Haven't you";
				mes "given up yet?";
				mes "Please don't";
				mes "try to stop me!";
				close2;
				set sign_q,134;
				donpcevent "Serin#serin::OnDisable";
				donpcevent "Dark Lord#serin::OnDisable";
				donpcevent "CallMonster#serin::Oncall";
				end;
			}
		}
		else {
			if (((sign_sq == 0) && (.@fail_s5 == 356)) || ((sign_sq == 1) && (.@fail_s4 == 356)) || (.@fail_s3 == 356)) {
				set sign_q,200;
				mes "[Serin]";
				mes "Even though you tried";
				mes "to stop me, I still don't wish";
				mes "to take your life. I understand";
				mes "that you've merely trying to";
				mes "protect your Midgard.";
				next;
				mes "[Serin]";
				mes "However...";
				mes "I do not think you";
				mes "have the courage to";
				mes "overcome the ordeals ";
				mes "of the gods. Please don't";
				mes "come here anymore...";
				next;
				mes "[Serin]";
				mes "Farewell...";
				close2;
				set $@sign_w2,0;
				warp "niflheim",30,156;
				end;
			}
			else {
				mes "[Serin]";
				mes "Haven't you";
				mes "given up yet?";
				mes "Please don't";
				mes "try to stop me!";
				close2;
				set sign_q,134;
				donpcevent "Serin#serin::OnDisable";
				donpcevent "Dark Lord#serin::OnDisable";
				donpcevent "CallMonster#serin::Oncall";
				end;
			}
		}
	}
	else if (sign_q == 200) {
		mes "[Serin]";
		mes "Let me guide";
		mes "you to where";
		mes "you belong.";
		close2;
		warp "umbala",132,203;
		end;
	}
	else {
		mes "..........";
		close;
	}
	end;

OnDisable:
	disablenpc "Serin#serin";
	end;

OnEnable:
	enablenpc "Serin#serin";
	end;
}

que_sign01,197,195,4	script	Serin#witch	90,{
	callfunc "F_UpdateSignVars";
	if (sign_q < 124) {
		mes "[Serin]";
		mes "...";
		mes "......";
		emotion ET_THINK;
		close;
	}
	else if (sign_q == 124) {
		mes "[Serin]";
		mes "You're finally here.";
		mes "That witch has been watching";
		mes "my every move, so she probably";
		mes "knows what I'm up to by now...";
		next;
		select("Why are you doing this...");
		mes "[Serin]";
		mes "You don't understand";
		mes "the horrific experience";
		mes "of being bound to Niflheim.";
		mes "I'm sick of breathing death";
		mes "and feeding on despair.";
		mes "I want to live again!";
		next;
		select("Is that why you want Dark Lord...?");
		mes "[Serin]";
		mes "Unfortunately, the symbol";
		mes "which Lady Hell gave you is";
		mes "limited to a one time use. Its";
		mes "power wasn't enough to bring me";
		mes "back, so summoning Dark Lord is";
		mes "my last chance.";
		next;
		select("But if Dark Lord comes to Midgard...");
		mes "[Serin]";
		mes "Oh, I'm pretty sure of";
		mes "what will happen if Dark Lord";
		mes "enters the realm of the living. He'll destroy Midgard and bring death to thousands and thousands of people.";
		next;
		mes "[Serin]";
		mes "So if I came back to life";
		mes "and everyone else were dead,";
		mes "However, by summoning Dark";
		mes "Lord, you might be thinking it'd be pretty pointless for me to come back. But I don't care.";
		next;
		mes "[Serin]";
		mes "The living don't appreciate";
		mes "what they have, so they ought";
		mes "to be punished. They can all go to Niflheim while I enjoy the warmth of the sun and the fresh outside air. Everyone should die...";
		next;
		mes "[Serin]";
		mes "Maybe you might not";
		mes "pity my situation since you've";
		mes "never been bound to Niflheim,";
		mes "but I'm begging you. Don't get";
		mes "in my way, "+strcharinfo(0)+".";
		next;
		switch(select("I can't let you do this!:Okay, have it your way.")) {
		case 1:
			set sign_q,125;
			close;
		case 2:
			mes "[Serin]";
			mes "Are you really willing";
			mes "to throw so much away for";
			mes "my sake? You do understand";
			mes "that you'll be failing the ordeals set before you by the gods...";
			next;
			switch(select("I changed my mind for Midgard.:I do, and it's alright...")) {
			case 1:
				set sign_q,125;
				close;
			case 2:
				mes "[Serin]";
				mes "The least I can";
				mes "do is send you back";
				mes "to Midgard and";
				mes "ask the Dark Lord to spare";
				mes "you. Thank you so much...";
				set sign_q,200;
				getexp (checkre(3))?20000:200000,0;
				set $@sign_w1,0;
				close2;
				warp "umbala",132,203;
				end;
			}
		}
	}
	else if (sign_q == 125) {
		if (countitem(2643) ==1) {
			mes "[Serin]";
			mes "If you think that";
			mes "I can't summon Dark Lord";
			mes "without the symbol, then you're";
			mes "mistaken. I've been collecting";
			mes "the power of despair!";
			next;
			mes "[Serin]";
			mes "Do you remember what";
			mes "happened to the dead that you";
			mes "helped on my behalf? Even if they seemed to have found shelter at first, they cannot escape my";
			mes "deep hollow of despair...";
			next;
			mes "[Serin]";
			mes "And that poor little girl,";
			mes "Alakina Anne? She still";
			mes "hasn't realized that she's dead!";
			next;
			mes "[Serin]";
			mes "You gave her hope,";
			mes "but ultimately, you can't";
			mes "keep your promise to bring her home. Oh, her disappointment";
			mes "must be so crushing...";
			next;
			mes "[Serin]";
			mes "Yes...";
			mes "By trying to help,";
			mes "you gave them nothing";
			mes "but pain, just as I planned.";
			mes "Now I have enough despair";
			mes "to summon Dark Lord!";
			next;
			mes "[Serin]";
			mes "I don't want us to fight,";
			mes "but I can't let you stop me.";
			mes "I've already sold my soul to";
			mes "Dark Lord to become a living";
			mes "human again so I can't give up";
			mes "now! We'll have to battle!";
			close2;
			set sign_q,126;
			donpcevent "CallMonster#witch::Oncall";
			donpcevent "Serin#witch::OnDisable";
			end;
		}
		else {
			mes "[Serin]";
			mes "If you think that";
			mes "I can't summon Dark Lord";
			mes "without the symbol, then you're";
			mes "mistaken. I've been collecting";
			mes "the power of despair!";
			next;
			mes "[Serin]";
			mes "What most adventurers";
			mes "don't know is that many of the";
			mes "souls in Niflheim are simply";
			mes "doomed to suffer. That's the";
			mes "nature of this realm and one";
			mes "of the rules of balance...";
			next;
			mes "[Serin]";
			mes "It was child's play to ask";
			mes "some adventurers to help";
			mes "these souls. But once they learn that these souls can't be helped,";
			mes "it's too late! In failing them, the adventurers add to their despair!";
			next;
			mes "[Serin]";
			mes "And by increasing";
			mes "the despair here, it";
			mes "also adds to the power I'll";
			mes "use to summon Dark Lord!";
			next;
			mes "[Serin]";
			mes "I don't want us to fight,";
			mes "but I can't let you stop me.";
			mes "I've already sold my soul to";
			mes "Dark Lord to become a living";
			mes "human again so I can't give up";
			mes "now! We'll have to battle!";
			close2;
			set sign_q,126;
			donpcevent "CallMonster#witch::Oncall";
			donpcevent "Serin#witch::OnDisable";
			end;
		}
	}
	else if (sign_q == 126) {
		mes "[Serin]";
		mes "I see now.";
		mes "Soon, I'll lose my memories";
		mes "and remain dead in Niflheim.";
		mes "Just like all the others. Still,";
		mes "may I ask you one question?";
		next;
		mes "[Serin]";
		mes "With that symbol, you";
		mes "could order the dead to do";
		mes "whatever you want. Why didn't";
		mes "you use it to command me to quit?";
		next;
		mes "[Serin]";
		mes "...";
		mes "......";
		mes "..........";
		next;
		mes "[Serin]";
		mes "I see it now.";
		mes "The kindness in your eyes";
		mes "tells me everything. You wanted to give me another chance. But in the end, I managed to destroy the";
		mes "chance you had given me.";
		next;
		mes "[Serin]";
		mes "Even though I'm nothing but";
		mes "a spirit now, it was an honor";
		mes "for me to meet somebody like you. Although I'll lose my memories, I'll try not to forget you.";
		next;
		mes "[Serin]";
		mes "My memories of your";
		mes "courage and kindness";
		mes "are more precious to";
		mes "me than life itself.";
		next;
		mes "[Serin]";
		mes "Farewell, now.";
		mes "And good luck on";
		mes "your travels, my friend...";
		delitem 7308,1; //Witch's_Potion
		set sign_q,127;
		close;
	}
	else if (sign_q == 127) {
		mes "^3355FFYou helped the";
		mes "unconscious Serin";
		mes "and returned to Niflheim.^000000";
		close2;
		set sign_q,128;
		set $@sign_w1,0;
		warp "que_sign01",117,137;
		end;
	}
	else if (sign_q == 198) {
		set .@fail_s1,rand(1,1000);
		set .@fail_s2,rand(1,900);
		set .@fail_s3,rand(1,800);
		set .@fail_s4,rand(1,700);
		set .@fail_s5,rand(1,600);
		if (countitem(2643) == 1) {
			if (((sign_sq == 0) && (.@fail_s3 == 356)) || ((sign_sq == 1) && (.@fail_s2 == 356)) || (.@fail_s1 == 356)) {
				delitem 7308,1; //Witch's_Potion
				set sign_q,200;
				mes "[Serin]";
				mes "Even though you tried";
				mes "to stop me, I still don't wish";
				mes "to take your life. I understand";
				mes "that you've merely trying to";
				mes "protect your Midgard.";
				next;
				mes "[Serin]";
				mes "However...";
				mes "I do not think you";
				mes "have the courage to";
				mes "overcome the ordeals ";
				mes "of the gods. Please don't";
				mes "come here anymore...";
				next;
				mes "^3355FFSerin took";
				mes "1 Witch's Tonic";
				mes "from you.^000000";
				next;
				mes "[Serin]";
				mes "I'm sorry...";
				mes "But I'm taking";
				mes "your Witch's Tonic";
				mes "to help me summon";
				mes "Dark Lord. Farewell...";
				close2;
				set $@sign_w1,0;
				warp "niflheim",30,156;
				end;
			}
			else {
				mes "[Serin]";
				mes "Haven't you";
				mes "given up yet?";
				mes "Please don't";
				mes "try to stop me!";
				close2;
				set sign_q,126;
				donpcevent "Serin#witch::OnDisable";
				donpcevent "CallMonster#witch::Oncall";
				end;
			}
		}
		else {
			if (((sign_sq == 0) && (.@fail_s5 == 356)) || ((sign_sq == 1) && (.@fail_s4 == 356)) || (.@fail_s3 == 356)) {
				delitem 7308,1; //Witch's_Potion
				set sign_q,200;
				mes "[Serin]";
				mes "Even though you tried";
				mes "to stop me, I still don't wish";
				mes "to take your life. I understand";
				mes "that you've merely trying to";
				mes "protect your Midgard.";
				next;
				mes "[Serin]";
				mes "However...";
				mes "I do not think you";
				mes "have the courage to";
				mes "overcome the ordeals ";
				mes "of the gods. Please don't";
				mes "come here anymore...";
				next;
				mes "^3355FFSerin took";
				mes "1 Witch's Tonic";
				mes "from you.^000000";
				next;
				mes "[Serin]";
				mes "I'm sorry...";
				mes "But I'm taking";
				mes "your Witch's Tonic";
				mes "to help me summon";
				mes "Dark Lord. Farewell...";
				close2;
				set $@sign_w1,0;
				warp "niflheim",30,156;
				end;
			}
			else {
				mes "[Serin]";
				mes "Haven't you";
				mes "given up yet?";
				mes "Please don't";
				mes "try to stop me!";
				close2;
				set sign_q,126;
				donpcevent "Serin#witch::OnDisable";
				donpcevent "CallMonster#witch::Oncall";
				end;
			}
		}
	}
	else if (sign_q == 200) {
		mes "[Serin]";
		mes "Let me guide";
		mes "you to where";
		mes "you belong.";
		mes ".......";
		close2;
		set $@sign_w1,0;
		warp "umbala",132,203;
		end;
	}
	else {
		mes "[Serin]";
		mes ".........";
		close;
	}
	end;

OnDisable:
	disablenpc "Serin#witch";
	end;

OnEnable:
	enablenpc "Serin#witch";
	end;
}

niflheim,313,70,4	script	Pleasant-Featured Lady#s	90,{
	callfunc "F_UpdateSignVars";
	if (sign_q < 82) {
		mes "[Serin]";
		mes "I'm sorry,";
		mes "but you're not";
		mes "the person I'm";
		mes "looking for. No...";
		close;
	}
	else if (sign_q == 82) {
		mes "[Serin]";
		mes "Kind adventurer...";
		mes "You're the one I'm looking";
		mes "for, the one who's been on";
		mes "a long journey to prove";
		if (Sex == SEX_MALE) {
			mes "his courage.";
		}
		else {
			mes "her courage.";
		}
		next;
		mes "[Serin]";
		mes "Even in the darkness of";
		mes "Niflheim, I can recognize";
		mes "you. You shine out to me like";
		mes "a star! I beg of you, please";
		mes "listen to my story...";
		next;
		switch(select("I'm busy, sorry.:Sure, go ahead.")) {
		case 1:
			mes "[Serin]";
			mes "I know I can't stop";
			mes "you from pursing your";
			mes "path to glory. But if you";
			mes "should change your mind...!";
			close;
		case 2:
			mes "[Serin]";
			mes "Thank you...";
			mes "Now, if you've heard";
			mes "from the others and as";
			mes "you can tell by my appearance,";
			mes "I clearly don't belong here.";
			next;
			mes "[Serin]";
			mes "I might not have";
			mes "the luck to be selected";
			mes "by Valkyrie, but I need";
			mes "your help to get out of";
			mes "here as soon as I can~";
			next;
			switch(select("Er, I'm busy, now that I think about it.:Sure, let's do it.")) {
			case 1:
				mes "[Serin]";
				mes "I know I can't stop";
				mes "you from pursing your";
				mes "path to glory. But if you";
				mes "should change your mind...!";
				close;
			case 2:
				mes "[Serin]";
				mes "I know I'm asking too much";
				mes "of you, but if you'd also help";
				mes "the other unfortunate souls in";
				mes "this place, I'd be truly grateful. Somehow, I think solving their problems will help me get back.";
				next;
				switch(select("Sure, why not?:Why should I help them?")) {
				case 1:
					mes "[Serin]";
					mes "I knew you'd understand!";
					mes "You really are a kind person.";
					mes "Now, in order to help the other";
					mes "misfortunate in Niflheim, you've got to remember to gain their trust first and get close to them, okay?";
					set sign_q,83;
					close;
				case 2:
					mes "[Serin]";
					mes "I... I understand.";
					mes "Although I asked too much in asking you to help the other people here, I was hoping you'd realize that";
					mes "would be the best way to learn clues for a way to escape for now.";
					set sign_q,84;
					close;
				}
			}
		}
	}
	else if (sign_q == 83) {
		if (sign_sq < 8) {
			mes "[Serin]";
			mes "Hmm...?";
			mes "You don't know which";
			mes "people you need to help";
			mes "here in Niflheim? Mmm,";
			mes "let me think about it...";
			next;
			mes "[Serin]";
			mes "In this doomed place,";
			mes "there isn't too much trust";
			mes "amongst some of the people";
			mes "here, but some will share their";
			mes "problems if you ^3355FFapproach them";
			mes "closely^000000, ^3355FFface to face^000000. Okay?";
			next;
			mes "[Serin]";
			mes "In this way, if they talk";
			mes "to you first, they might";
			mes "be more willing to accept";
			mes "help or tell you what you";
			mes "really need to know.";
			mes "I hope this helps...";
			close;
		}
		else if (sign_sq == 8) {
			mes "[Serin]";
			mes "Thank you so much for";
			mes "your help. This is all I have,";
			mes "and it means a lot to me, but";
			mes "I want you to have this ring. It's the only way I can properly express my gratitude for your aid so far.";
			set sign_q,85;
			set sign_sq,0;
			getitem 2642,1; //Serin's_Gold_Ring
			close;
		}
		else {
			mes "[Serin]";
			mes "To the dead,";
			mes "living people";
			mes "are either good";
			mes "prey or good marks.";
			close;
		}
	}
	else if (sign_q == 84) {
		mes "[Serin]";
		mes "Hello, adventurer.";
		mes "How have you been doing?";
		mes "I'm surprised to still see you";
		mes "around this dangerous town.";
		next;
		mes "[Serin]";
		mes "If you wander around";
		mes "Niflheim, you'll find that";
		mes "some of the deceased here are";
		mes "different than most of the others in this town. Please talk to them and see if you can be of any help.";
		set sign_q,87;
		close;
	}
	else if (sign_q == 85) {
		mes "[Serin]";
		mes "There's a Bard in";
		mes "Niflheim with a very";
		mes "sweet, yet melancholy voice.";
		mes "He sings for strangers just";
		mes "like you, adventurer.";
		next;
		mes "[Serin]";
		mes "I think he might know";
		mes "some useful information,";
		mes "so it might be a good";
		mes "idea to speak with him.";
		set sign_q,86;
		close;
	}
	else if (sign_q < 92) {
		mes "[Serin]";
		mes "Hello, "+strcharinfo(0)+",";
		mes "I'm surprised that";
		mes "you've managed to survive";
		mes "here all this time. It's no small feat for a mortal to be able to remain alive in Niflheim...";
		close;
	}
	else if (sign_q == 92) {
		if (countitem(2642) > 0) {
			mes "[Serin]";
			mes "Ah, "+strcharinfo(0)+"~";
			mes "How is everything?";
			mes "Once again, I want to";
			mes "thank you for helping the";
			mes "poor souls in this place.";
			next;
			mes "[Serin]";
			mes "Hmm...?";
			mes "What's with that";
			mes "look on your face?";
			mes "Do you have something";
			mes "you want to ask me?";
			next;
		}
		else {
			mes "[Serin]";
			mes "Ah, "+strcharinfo(0)+"~";
			mes "How is everything?";
			next;
			mes "[Serin]";
			mes "Hmm...?";
			mes "What's with that";
			mes "look on your face?";
			mes "Do you have something";
			mes "you want to ask me?";
			next;
		}
		switch(select("Nothing.:About the Queen of the Dead...")) {
		case 1:
			mes "[Serin]";
			mes "Well, if you ever";
			mes "need my help, please";
			mes "don't hesitate to ask.";
			close;
		case 2:
			mes "[Serin]";
			mes "The Queen of the Dead?";
			mes "Why, she's the ruler of Niflheim.";
			mes "As Loki and Angrboda's last child, she was given complete control of this realm by Odin.";
			next;
			mes "[Serin]";
			mes "She usually rules from her";
			mes "castle, Hell, but sometimes she goes out to tour Niflheim. That's all I really know about her.";
			next;
			select("About the Symbol of Nine Realms");
			mes "[Serin]";
			mes "Oh that...?";
			mes "Sometimes it's called";
			mes "the Voucher of the Dead.";
			mes "Odin gave it to the Queen";
			mes "of the Dead to signify her";
			mes "authority over Niflheim.";
			next;
			mes "[Serin]";
			mes "There are many rumors";
			mes "floating around about that";
			mes "symbol and its abilities, but";
			mes "all we know for sure is that it can be used to command the dead...";
			next;
			select("About Angrboda");
			mes "[Serin]";
			mes "Angrboda...?";
			mes "She's the mother of the";
			mes "Queen of Hell, as well as";
			mes "some of the most powerful";
			mes "monsters in this universe.";
			next;
			mes "[Serin]";
			mes "The gods feared her monstrous";
			mes "children so much that they bound";
			mes "them and sealed Angrboda away.";
			mes "Nothing has been heard";
			mes "of her since...";
			next;
			select("I was told by the Witch that you're...");
			mes "[Serin]";
			mes "Oh, the Witch was";
			mes "talking about me? I'm";
			mes "aware that she doesn't";
			mes "think very highly of me.";
			mes "Then again, it's not like";
			mes "I can trust her either.";
			next;
			mes "[Serin]";
			mes "Well, it can't be helped.";
			mes "At least we both agree that";
			mes "somehow I don't really belong";
			mes "here in Niflheim.";
			emotion ET_THINK;
			set sign_q,93;
			close;
		}
	}
	else if (sign_q == 93) {
		mes "[Serin]";
		mes "I'm sorry that I sort of";
		mes "rambled on and on that last";
		mes "time we spoke. Now that I think";
		mes "about it, I didn't really give you any information that might have been very useful to you.";
		next;
		mes "[Serin]";
		mes "But lately I've heard that the";
		mes "Queen of the Dead is seeking her";
		mes "mother, Angrboda. It's strange that even the queen, with all of her";
		mes "power, is unable to find her.";
		next;
		mes "[Serin]";
		mes "I have no idea how,";
		mes "but it seems like Angrboda";
		mes "has been sealed away in the";
		mes "world of Midgard...";
		emotion ET_THINK;
		set sign_q,94;
		close;
	}
	else if (sign_q == 94) {
		mes "[Serin]";
		mes "I've told you";
		mes "everything I know.";
		mes "But if you want to learn more";
		mes "about Angrboda, you probably need to talk to someone who actually communicates with the gods.";
		next;
		mes "[Serin]";
		mes "Perhaps Valkyrie";
		mes "or someone who actually";
		mes "lived in Asgard may know";
		mes "more about where Angrboda";
		mes "is sealed away.";
		next;
		mes "[Serin]";
		mes "Also, why would you want";
		mes "the Symbol of the Nine Realms?";
		mes "It's a very dangerous object that could cause a lot of trouble if it fell into the wrong hands...";
		next;
		switch(select("What do you mean??:Don't worry, it won't.")) {
		case 1:
			mes "[Serin]";
			mes "There are plenty of dead";
			mes "people in Niflheim that are";
			mes "driven by regret and despair.";
			mes "The rage of being dead may result in some of them performing horrific deeds if they had the symbol.";
			next;
			switch(select("Then what should I do?:Thanks for the concern, but I'm not worried.")) {
			case 1:
				mes "[Serin]";
				mes "I really think that you";
				mes "should bring that symbol";
				mes "to me before you show it to anybody else. Then, I want you to know why I really need its power.";
				next;
				mes "[Serin]";
				mes "I can't explain myself";
				mes "now, but I want to use the";
				mes "power of the symbol to do";
				mes "something really helpful";
				mes "for you. You'll just need";
				mes "to trust me on this.";
				next;
				select("I'll think about it.");
				mes "[Serin]";
				mes "Then I will";
				mes "wait for you here.";
				set sign_q,95;
				close;
			case 2:
				mes "[Serin]";
				mes "Alright...";
				mes "It's your decision.";
				set sign_q,95;
				close;
			}
		case 2:
			mes "[Serin]";
			mes "Ah...";
			mes "Alright, I suppose";
			mes "that if you're worthy";
			mes "of obtaining the symbol,";
			mes "you should also be able";
			mes "to protect it from abuse.";
			set sign_q,95;
			close;
		}
	}
	else if (sign_q < 118) {
		mes "[Serin]";
		mes "If you obtain the";
		mes "Symbol of Nine Realms,";
		mes "please bring it to me";
		mes "right away, "+strcharinfo(0)+".";
		close;
	}
	else if (sign_q == 118) {
		mes "[Serin]";
		mes "Yes...";
		mes "This is the Symbol of the";
		mes "Nine Realms. It only has enough";
		mes "power for one use, but it's still not easy to get this. Now, what were you planning to use this for?";
		next;
		select("Tell her your story.");
		mes "[Serin]";
		mes "Ah, so you're here";
		mes "in Niflheim to overcome";
		mes "the ordeals of the gods and";
		mes "prove your courage to Valkyrie.";
		next;
		mes "[Serin]";
		mes "So wait...";
		mes "You've obtained that symbol";
		mes "just for that witch? This may";
		mes "seem rude, but I want to tell";
		mes "you exactly how I feel about her.";
		next;
		mes "[Serin]";
		mes "Isn't it suspicious that she";
		mes "hasn't explained her intentions to you? The Symbol of Nine Realms";
		mes "is one of the most powerful objects in Niflheim. Whatever she's planning has to be large scale.";
		next;
		mes "[Serin]";
		mes "Then, there's that Metz Brayde.";
		mes "Do you really believe that after he completes his research, he'll just give it back to you? You can't just trust someone to hold an object of enormous power and give it back!";
		next;
		switch(select("W-what should I do?:I can't believe this!")) {
		case 1:
			mes "[Serin]";
			mes "Well, I can't really tell";
			mes "you what to do, but I don't think it's a good idea to let that witch have the Symbol of Nine Realms. There's no telling what she'll";
			mes "use its power for.";
			next;
			mes "[Serin]";
			mes "Actually...";
			mes "There is this rumor";
			mes "going around, but I don't";
			mes "know if you want to hear it...";
			set sign_q,131;
			close;
		case 2:
			mes "[Serin]";
			mes "I'm sorry if you were offended.";
			mes "I know I can't really convince you to believe anything, but please understand that I just don't want anyone to take advantage of you. Forgive my rudeness.";
			close;
		}
	}
	else if (sign_q < 129) {
		mes "^3355FFThis is only";
		mes "a lingering trace";
		mes "of Serin, a manifestation";
		mes "of her definitive memory.^000000";
		close;
	}
	else if (sign_q == 129) {
		mes "[Serin]";
		mes "...";
		mes "......";
		next;
		mes "[Serin]";
		mes "...";
		mes "......";
		mes "..........";
		if (countitem(2643) == 1) {
			next;
			switch(select("Give Serin her ring.:Keep the ring.")) {
			case 1:
				mes "[Serin]";
				mes "...";
				mes "......";
				mes ".............";
				next;
				mes "[Serin]";
				mes "...."+strcharinfo(0)+".....";
				mes "I don't want to forget you.";
				mes "I can forget my obsession with";
				mes "life and all my other memories,";
				mes "But if I can keep just one memory, I want it to be of your kindness.";
				next;
				mes "[Serin]";
				mes "Even now, you're still";
				mes "so very kind to me. Thank";
				mes "you for giving back my ring,";
				mes "my most precious possession.";
				mes "Thank you, thank you...";
				emotion ET_CRY;
				next;
				mes "^3355FFThe sound of Serin's voice";
				mes "softened and when it grew silent, her eyes blankly stared ahead as";
				mes "if she were in a trance. It looks like she has already forgotten";
				mes "everything...^000000";
				next;
				mes "^3355FFBut Serin has also been able";
				mes "to forget her sadness. The tears streaked across her cheeks and";
				mes "the faint smile on her lips tell you that her memories of you";
				mes "will always remain in her heart.^000000";
				delitem 2643,1; //Serin's_Gold_Ring_
				getexp (checkre(3))?50000:500000,0;
				close;
			case 2:
				emotion ET_CRY;
				close;
			}
		}
		else {
			emotion ET_CRY;
			close;
		}
	}
	else if (sign_q == 130) {
		mes "[Serin]";
		mes "...........";
		emotion ET_CRY;
		next;
		mes "[Serin]";
		mes "...........";
		emotion ET_THINK;
		next;
		mes "[Serin]";
		mes "...........";
		emotion ET_THINK;
		next;
		mes "[Serin]";
		mes "...........";
		emotion ET_CRY;
		close;
	}
	else if (sign_q == 131) {
		mes "[Serin]";
		mes "........";
		next;
		select("Tell me the rumors about the witch.");
		next;
		mes "[Serin]";
		mes "Well, I've heard that the witch has been hiding deep in Niflheim and will only speak to those who pass her test. Apparently, she's been preparing some sort of ritual";
		mes "to gain more power...";
		next;
		mes "[Serin]";
		mes "It's almost too horrible";
		mes "to believe, but I think that";
		mes "she's preparing the ritual to";
		mes "summon Dark Lord, ruler of";
		mes "the Realm of Fiends.";
		next;
		select("Dark Lord...?");
		mes "[Serin]";
		mes "Well, most people don't";
		mes "know this, but Dark Lord";
		mes "comes from the Realm of Fiends.";
		mes "In his own domain, he's so powerful that even the gods fear his might.";
		next;
		mes "[Serin]";
		mes "Now, sometimes Dark Lord can";
		mes "enter the world of Midgard, but only in a manifestation that represents just a small portion";
		mes "of his full power.";
		next;
		mes "[Serin]";
		mes "You see, it takes too much energy to travel from the Realm of Fiends to Midgard. And since the life force in Midgard conflicts with his powers, Dark Lord can't reach your world directly.";
		next;
		select("Wouldn't Lady Hell stop him?");
		mes "[Serin]";
		mes "Well, Dark Lord only wants";
		mes "Midgard, so the Queen of the Dead doesn't feel threatened about her control of Niflheim.";
		next;
		mes "[Serin]";
		mes "In fact, I'm sure she's aware";
		mes "that Dark Lord will cause thousands of deaths in Midgard, meaning that there would be thousands more souls for her to rule over. So it's not to her advantage to stop him.";
		next;
		select("Then what should we do...?");
		mes "[Serin]";
		mes "No matter what the cost,";
		mes "we've got to stop her from";
		mes "summoning Dark Lord in order";
		mes "to protect Midgard from";
		mes "total annihiliation.";
		next;
		mes "[Serin]";
		mes "I used to be a pretty";
		mes "skilled Wizard, so I know";
		mes "that she needs to draw a really huge magic circle in Niflheim if she wants to summon Dark Lord.";
		next;
		select("Can you tell me where?");
		mes "[Serin]";
		mes "Well, there are certain rules";
		mes "and conditions to perform the summoning. There aren't any spaces wide enough in the Valley of Gyoll, and Niflheim's entrance is watched by too many people...";
		next;
		mes "[Serin]";
		mes "Now, if I were to summon";
		mes "Dark Lord, I would probably";
		mes "do it somewhere inside town";
		mes "to avoid attention. Hmmm...";
		mes "I'll send you there once I figure out where the circle might be.";
		set sign_q,132;
		close;
	}
	else if (sign_q == 132) {
		if ($@sign_w2 == 1) {
			mes "[Serin]";
			mes "I need to finish";
			mes "my preparations to send";
			mes "you to the magic circle,";
			mes "so I need a little more time...";
			close;
		}
		mes "[Serin]";
		mes "Alright...";
		mes "So are you";
		mes "ready to leave?";
		next;
		switch(select("Yes:Not yet")) {
		case 1:
			mes "[Serin]";
			mes "Okay~";
			mes "Let's go...";
			close2;
			set $@sign_w2,1;
			warp "que_sign01",199,36;
			end;
		case 2:
			close;
		}
	}
	else if ((sign_q < 135) || (sign_q == 199)) {
		if ($@sign_w2 == 1) {
			mes "[Serin]";
			mes "My preparations";
			mes "are taking longer";
			mes "than I thought. Would";
			mes "you wait a little while?";
			close;
		}
		mes "^3355FFThis is just a lingering";
		mes "trace of Serin, an impression";
		mes "of her soul and memories that";
		mes "you can still sense somehow.^000000";
		next;
		switch(select("Follow the trace.:Ignore it.")) {
		case 1:
			close2;
			set sign_q,199;
			set $@sign_w2,1;
			warp "que_sign01",199,36;
			end;
		case 2:
			close;
		}
	}
	else if (sign_q < 137) {
		mes "[Serin]";
		mes "...";
		mes "......";
		mes "W-who...";
		mes "Who are you?";
		emotion ET_THINK;
		close;
	}
	else if (sign_q > 199) {
		mes "^3355FFThis is just a lingering";
		mes "trace of Serin, an impression";
		mes "of her soul and memories that";
		mes "you can still sense somehow.";
		mes "What could have happened to her?^000000";
		if (countitem(2642) > 0) {
			next;
			mes "^33555FFSuddenly, Serin's";
			mes "gold ring sparkled";
			mes "with a soft glow and";
			mes "faded away.^000000";
			delitem 2642,1; //Serin's_Gold_Ring
			close;
		}
		close;
	}
	else {
		if (countitem(2642) > 0) {
			mes "[Serin]";
			mes "Thank you...";
			emotion ET_CRY;
			delitem 2642,1; //Serin's_Gold_Ring
			next;
			mes "^3355FFYou returned";
			mes "Serin's gold ring.^000000";
			close;
		}
		mes "[Serin]";
		mes "...";
		mes "......";
		emotion ET_THINK;
		close;
	}
}

que_sign01,122,141,4	script	Witch#s	792,{
	callfunc "F_UpdateSignVars";
	if (checkweight(1201,1) == 0) {
		mes "- Wait a minute !! -";
		mes "- Currently you're carrying -";
		mes "- too many items with you. -";
		mes "- Please try again -";
		mes "- after you loose some weight. -";
		close;
	}
	mes "[Kirkena]";
	if ((countitem(7313) == 1) && ((sign_q != 124) || (sign_q != 125) || (sign_q != 126))) {
		mes "That Witch's Medal...";
		mes "You must be here to";
		mes "help your friend take";
		mes "care of Serin. Are you";
		mes "ready to go, "+strcharinfo(0)+"?";
		next;
		switch(select("Yes.:Not yet...")) {
		case 1:
			switch(select("Go directly to Serin:Path Towards Serin")) {
			case 1:
				mes "[Kirkena]";
				mes "Thank you";
				mes "for your help.";
				mes "Serin's threat may";
				mes "be too much for just";
				mes "one adventurer alone...";
				close2;
				warp "que_sign01",195,189;
				end;
			case 2:
				mes "[Kirkena]";
				mes "Thank you";
				mes "for your help.";
				mes "Serin's threat may";
				mes "be too much for just";
				mes "one adventurer alone...";
				close2;
				warp "que_sign02",35,313;
				end;
			}
		case 2:
			mes "[Kirkena]";
			mes "Please hurry...";
			mes "Time is of the essence...";
			close;
		}
	}
	if (sign_q == 90) {
		if (countitem(2642) == 1) {
			mes "That bastard stole";
			mes "two spell books from me.";
			mes "You've brought one of them";
			mes "back, but the other book";
			mes "is still missing.";
			next;
			mes "[Kirkena]";
			mes "Would you please";
			mes "retrieve my other";
			mes "spell book for me,";
			mes "adventurer?";
			set sign_sq,0;
			close;
		}
		else {
			mes "Some bastard stole";
			mes "two of my spell books.";
			mes "I'd be grateful if you can";
			mes "find him in Niflheim and";
			mes "bring my books back to me.";
			close;
		}
	}
	else if (sign_q == 91) {
		if (countitem(7304) > 0) {
			mes "Once that fool stole my spell";
			mes "books, he was cursed after he";
			mes "cast those spells without my";
			mes "permission. I'm so relieved to";
			mes "finally hold these in my";
			mes "hands again.";
			next;
			mes "[Kirkena]";
			mes "Now mortal...";
			mes "Why is it that";
			mes "you've come to see me?";
			mes "I'm sure that there must";
			mes "be something you want.";
			next;
			select("He asked me to see you for....");
			mes "[Kirkena]";
			mes "As I expected,";
			mes "there is something behind";
			mes "all of this. Now, you may";
			mes "know where you are, but";
			mes "do you understand why";
			mes "the dead are here?";
			next;
			mes "[Kirkena]";
			mes "This realm is a place";
			mes "for warriors that have failed";
			mes "to prove their courage. Keep in";
			mes "mind that it's not too late for";
			mes "you to join their ranks.";
			next;
			mes "[Kirkena]";
			mes "The realm of Niflheim";
			mes "is ruled by the Queen of the";
			mes "Dead. Sometimes she appears";
			mes "in her shining armor and makes the rounds. Everyone who sees her is stunned by the image of authority.";
			next;
			mes "[Kirkena]";
			mes "Now...";
			mes "What I need you to do is";
			mes "ask the Queen of the Dead";
			mes "for the Symbol of Nine Realms.";
			next;
			select("What is that?");
			mes "[Kirkena]";
			mes "The symbol acts as";
			mes "a voucher of the queen's";
			mes "authority and represents her";
			mes "undeniable right to rule over";
			mes "the dead. But right now, I can't";
			mes "explain why I need it.";
			next;
			mes "[Kirkena]";
			mes "I'll tell you why I need";
			mes "it once you bring me the";
			mes "queen's symbol. Now, please";
			mes "keep this secret and tell no one that I asked you to bring the symbol to me.";
			next;
			select("How am I supposed to get the symbol?");
			mes "[Kirkena]";
			mes "Taking the symbol";
			mes "by force is out of the";
			mes "question. Not even the gods";
			mes "would consider battling the";
			mes "Queen of the Dead.";
			next;
			mes "[Kirkena]";
			mes "You will need to";
			mes "earn the queen's favor";
			mes "in order to even have";
			mes "a chance of obtaining";
			mes "the Symbol of Nine Realms.";
			next;
			mes "[Kirkena]";
			mes "Now, there is a rumor";
			mes "that the Queen of the Dead";
			mes "is searching for her lost mother, Angrboda. Now, if you could find where Angrboda has been";
			mes "sealed away...";
			delitem 7304,1; //Witch's_Spell_Book
			set sign_q,92;
			close;
		}
		else {
			mes "Hmm...?";
			mes "Why haven't you";
			mes "brought my books";
			mes "back to me yet?";
			emotion ET_HNG;
			close;
		}
	}
	else if (sign_q == 92) {
		if (rand(1,10) < 9) {
			mes "If you need to learn more";
			mes "about Angrboda, why don't you";
			mes "just ask around? I'm sure that";
			mes "everyone is aware that the queen";
			mes "is searching for her mother.";
			next;
			mes "[Kirkena]";
			mes "Once again, don't let";
			mes "anyone know that I've asked";
			mes "you to bring me the Symbol of";
			mes "the Nine Realms. I especially";
			mes "don't want Serin to find out.";
			next;
			mes "[Kirkena]";
			mes "If I can help it,";
			mes "I won't tolerate";
			mes "Serin's presense here";
			mes "in Niflheim. If I could";
			mes "banish her, I'd do it!";
			close;
		}
		else {
			mes "I almost hate";
			mes "suggesting it, but";
			mes "I think Serin might";
			mes "have some information";
			mes "on Angrboda's whereabouts.";
			next;
			mes "[Kirkena]";
			mes "But remember to be";
			mes "careful around her.";
			mes "Something about that";
			mes "Serin isn't quite right...";
			close;
		}
	}
	else if (sign_q < 118) {
		mes "It may be almost";
		mes "impossible to obtain";
		mes "the Symbol of Nine Realms.";
		mes "Still, you and I both need it.";
		next;
		mes "[Kirkena]";
		mes "I hope you understand";
		mes "that the symbol is more";
		mes "than just a mere voucher.";
		mes "It actually contains";
		mes "enormous power...";
		close;
	}
	else if (sign_q == 118) {
		mes "The Symbol of Nine Realms?";
		mes "How were you able to get that?!";
		mes "Ah, you must have found the Queen of the Dead's mother, Angrboda, right? Great work~";
		next;
		mes "[Kirkena]";
		mes "Now, if you'll just";
		mes "hand me the symbol, I'll tell";
		mes "you what we need to do next.";
		next;
		switch(select("Give the symbol.:Don't give the symbol.")) {
		case 1:
			mes "[Kirkena]";
			mes "Listen carefully.";
			mes "Since you were actually";
			mes "able to get the symbol, I believe that you're the only person capable of performing this next task.";
			next;
			mes "[Kirkena]";
			mes "We're going to use this";
			mes "symbol to create something,";
			mes "but we need one last item.";
			mes "I need you to find something";
			mes "imbued with Serin's vibes.";
			next;
			mes "[Kirkena]";
			mes "Serin's already hid herself";
			mes "deep within Niflheim, but I'm";
			mes "sure you can find something";
			mes "if you can find any remaining";
			mes "trace of her.";
			delitem 7305,1; //Authority_Of_Nine_World
			set sign_q,119;
			close;
		case 2:
			mes "[Kirkena]";
			mes "Huh...?";
			mes "Don't tell me that";
			mes "you've taken that wench's";
			mes "side! Well, I won't take the";
			mes "symbol against your will, but";
			mes "you better think this over...";
			emotion ET_THINK;
			close;
		}
	}
	else if (sign_q == 119) {
		if (countitem(2642) > 0) {
			mes "This is Serin's gold ring?";
			mes "Excellent, this has been";
			mes "strongly infused with her";
			mes "vibes. It's really tough to find something like this that resonates so strongly with its owner.";
			delitem 2642,1; //Serin's_Gold_Ring
			set sign_q,120;
			close;
		}
		else {
			mes "Hmm, you don't have";
			mes "anything related to Serin.";
			mes "This isn't good. She's hid";
			mes "herself already and it might";
			mes "be too late to find any trace of her. I'll have to do something...";
			set sign_q,121;
			close;
		}
	}
	else if ((sign_q == 120) || (sign_q == 121)) {
		mes "Now that the potion I'm";
		mes "making is being processed,";
		mes "I can finally tell you what";
		mes "I've been trying to do with";
		mes "the objects I've asked you";
		mes "to get for me.";
		next;
		mes "[Kirkena]";
		mes "I didn't explain the";
		mes "reason I wanted the Symbol";
		mes "of Nine Realms to prevent Serin";
		mes "from getting suspicious and forcing you to reveal my plans. You see, Serin isn't fit for Niflheim.";
		next;
		mes "[Kirkena]";
		mes "Although she's in the";
		mes "world of the dead, Serin";
		mes "has never accepted death and";
		mes "has desired to return to life. Of course, that's the natural response for everyone that comes here...";
		next;
		mes "[Kirkena]";
		mes "However, unlike the others";
		mes "who have despaired, lost";
		mes "hope and accepted their fate,";
		mes "Serin has never given up her hope to return to life. With her hope, she retains her beauty and light.";
		next;
		mes "[Kirkena]";
		mes "But she's only denying";
		mes "the fate she deserves.";
		mes "What she's trying to do";
		mes "is wrong and we need to";
		mes "stop her before it's too late.";
		next;
		while(1) {
			switch(select("What does she want?:What is she going to do?:What should I do?")) {
			case 1:
				mes "[Kirkena]";
				mes "Make no mistake:";
				mes "Serin wants the Symbol";
				mes "of the Nine Realms. ";
				next;
				mes "[Kirkena]";
				mes "Now, if she could use it";
				mes "multiple times, she could just";
				mes "command the guards of Niflheim";
				mes "to just let her pass and re-enter the world of the living. But your symbol can be used just once...";
				next;
				set .@kir_talk1,1;
				if ((.@kir_talk1 == 1) && (.@kir_talk2 == 1) && (.@kir_talk3 == 1)) {
					if (sign_q == 120) set sign_q,122;
					else if (sign_q == 121) set sign_q,123;
				}
				break;
			case 2:
				mes "[Kirkena]";
				mes "I believe Serin is going to";
				mes "summon the Dark Lord. Since";
				mes "she used to be a great wizard,";
				mes "it's entirely possible. However, she might need the Symbol of the Nine Realms in order to do it.";
				next;
				mes "[Kirkena]";
				mes "Now, you may believe that";
				mes "Dark Lord can be defeated by";
				mes "humans, but what you might not";
				mes "know is that the manifestation of Dark Lord in your world is limited to a fraction of his true power.";
				next;
				mes "[Kirkena]";
				mes "Sometimes Dark Lord can";
				mes "cross over into Midgard,";
				mes "but traveling from his world into";
				mes "ours takes vast amounts of energy. Also the life force in your world conflicts with his dark powers.";
				next;
				mes "[Kirkena]";
				mes "Now, if Dark Lord were";
				mes "summoned into Niflheim,";
				mes "he would have easy access";
				mes "to Midgard and the use";
				mes "of all of his destructive power.";
				next;
				mes "[Kirkena]";
				mes "Serin plans to strike";
				mes "a deal with Dark Lord:";
				mes "In exchange for summoning";
				mes "him to Niflheim, Serin will";
				mes "be brought back to life.";
				next;
				mes "[Kirkena]";
				mes "Although you've found";
				mes "favor with Lady Hell, she";
				mes "will probably not stop Dark";
				mes "Lord's approach. Dark Lord";
				mes "only wants Midgard.";
				next;
				mes "[Kirkena]";
				mes "Now that I think about";
				mes "it, massive death would";
				mes "actually increase Lady Hell's";
				mes "sphere of influence. I don't think she'll help Dark Lord, but she";
				mes "also won't get in his way.";
				next;
				set .@kir_talk2,1;
				if ((.@kir_talk1 == 1) && (.@kir_talk2 == 1) && (.@kir_talk3 == 1)) {
					if (sign_q == 120) set sign_q,122;
					else if (sign_q == 121) set sign_q,123;
				}
				break;
			case 3:
				mes "[Kirkena]";
				mes "I need you to take";
				mes "this tonic and have";
				mes "Serin drink it. This";
				mes "special potion will erase";
				mes "most of her memories.";
				next;
				mes "[Kirkena]";
				mes "Without her memories,";
				mes "Serin should also lose";
				mes "her twisted ambitions.";
				mes "Now, with the Symbol of Nine Realms, Serin cannot refuse drinking this potion.";
				next;
				mes "[Kirkena]";
				mes "That's why having the";
				mes "symbol is so crucial.";
				mes "Serin is clever enough";
				mes "to avoid drinking this";
				mes "for quite a while now...";
				next;
				set .@kir_talk3,1;
				if ((.@kir_talk1 == 1) && (.@kir_talk2 == 1) && (.@kir_talk3 == 1)) {
					if (sign_q == 120) set sign_q,122;
					else if (sign_q == 121) set sign_q,123;
				}
			}
			if ((sign_q == 122) || (sign_q == 123)) close;
		}
		close;
	}
	else if ((sign_q == 122) || (sign_q == 123)) {
		mes "The potion is finally";
		mes "completed. Now, take this";
		mes "and command Serin to drink it.";
		next;
		mes "[Kirkena]";
		if (sign_q == 122) {
			mes "Luckily, I was able to";
			mes "use Serin's gold ring to";
			mes "trace her location. I'm going";
			mes "to send you there, so please";
			mes "do whatever it takes to stop her.";
			next;
			mes "[Kirkena]";
			mes "Please take these with you";
			mes "as they'll probably be useful";
			mes "when you deal with her. As for";
			mes "these vouchers, give them to your allies. They'll send them straight to where Serin is located.";
			next;
			mes "[Kirkena]";
			mes "When you're finished";
			mes "dealing with Serin, don't";
			mes "forget to bring back all";
			mes "of the vouchers I've";
			mes "given you, alright?";
			set sign_q,124;
			getitem 7308,1; //Witch's_Potion
			getitem 2643,1; //Serin's_Gold_Ring_
			getitem 7313,5; //Seal_Of_Witch
			close;
		}
		else if (sign_q == 123) {
			mes "I'm not exactly sure";
			mes "where Serin is hiding,";
			mes "but I'll send you to her";
			mes "general location. Do";
			mes "everything in your";
			mes "power to stop her.";
			next;
			mes "[Kirkena]";
			mes "Now, I'm lending you";
			mes "these Witch's Medals. You";
			mes "may lend these to your allies";
			mes "to help you deal with Serin.";
			mes "Remember, if they carry more";
			mes "than one, they won't work.";
			next;
			mes "[Kirkena]";
			mes "Let your allies know";
			mes "that they have to take";
			mes "the secret passge through";
			mes "the right side of the portrait";
			mes "on the castle's second floor.";
			mes "Then, I can send them to Serin. ";
			next;
			mes "[Kirkena]";
			mes "When you're finished";
			mes "dealing with Serin, don't";
			mes "forget to bring back all of";
			mes "the Witch's Medals that";
			mes "I've lent to you, alright?";
			set sign_q,124;
			getitem 7308,1; //Witch's_Potion
			getitem 7313,5; //Seal_Of_Witch
			close;
		}
	}
	else if ((sign_q == 124) || (sign_q == 125) || (sign_q == 198)) {
		if ($@sign_w1 == 1) {
			mes "Please wait";
			mes "a bit. I'm still";
			mes "trying to finish";
			mes "these preparations...";
			close;
		}
		if (countitem(2643) == 1) {
			mes "You're finally";
			mes "back. We might not";
			mes "have enough time to";
			mes "stop her, but we have";
			mes "to try. Are you ready?";
			next;
			switch(select("Yes:No")) {
			case 1:
				close2;
				set $@sign_w1,1;
				warp "que_sign01",195,189;
				end;
			case 2:
				mes "[Kirkena]";
				mes "Hurry up, then!";
				mes "There's no time";
				mes "to waste!";
				close;
			}
		}
		else {
			mes "We've got to";
			mes "stop Serin before";
			mes "she does something";
			mes "truly horrible. Are";
			mes "you ready to go?";
			next;
			switch(select("Yes:No")) {
			case 1:
				mes "[Kirkena]";
				mes "Okay then.";
				mes "Good luck,";
				mes ""+strcharinfo(0)+"...";
				close2;
				warp "que_sign02",35,313;
				end;
			case 2:
				mes "[Kirkena]";
				mes "Hurry up, then!";
				mes "There's no time";
				mes "to waste!";
				close;
			}
		}
	}
	else if ((sign_q == 127) || (sign_q == 128)) {
		if (countitem(2643) == 1) {
			if (countitem(7313) < 5) {
				mes "Hmmm...?";
				mes "Where are all the";
				mes "vouchers I've lent to you?";
				mes "Please retrieve them all";
				mes "before coming back to me.";
				close;
			}
			else {
				mes "You've done well.";
				mes "Without her memories of her";
				mes "previous life, Serin can remain";
				mes "here in Niflheim peacefully.";
				next;
				mes "[Kirkena]";
				mes "Although she failed to return to life, I'm sure she is glad to have met you. I think she's also started to learn that life's meaning is not in living alone...";
				next;
				mes "[Kirkena]";
				mes "Once again, thank";
				mes "you so much for your";
				mes "help. Once you finish here,";
				mes "please visit our queen, Lady Hell. I believe she wants to see you for some reason, "+strcharinfo(0)+"...";
				delitem 7313,5; //Seal_Of_Witch
				set sign_q,129;
				getexp (checkre(3))?50000:500000,0;
				close;
			}
		}
		else {
			if (countitem(7313) < 5) {
				mes "Hmmm...?";
				mes "Where are all the";
				mes "vouchers I've lent to you?";
				mes "Please retrieve them all";
				mes "before coming back to me.";
				close;
			}
			else {
				mes "You've done well.";
				mes "Without her memories of her";
				mes "previous life, Serin can remain";
				mes "here in Niflheim peacefully.";
				next;
				mes "[Kirkena]";
				mes "Although she failed to return to life, I'm sure she is glad to have met you. I think she's also started to learn that life's meaning is not in living alone...";
				next;
				mes "[Kirkena]";
				mes "Once again, thank";
				mes "you so much for your";
				mes "help. Once you finish here,";
				mes "please visit our queen, Lady Hell. I believe she wants to see you for some reason...";
				delitem 7313,5; //Seal_Of_Witch
				set sign_q,130;
				getexp (checkre(3))?30000:300000,0;
				close;
			}
		}
	}
	else if ((sign_q == 136) || (sign_q == 135)) {
		mes "I'm so relieved that";
		mes "my expectations about";
		mes "you weren't wrong.";
		next;
		mes "[Kirkena]";
		mes "You've done well.";
		mes "Without her memories of her";
		mes "previous life, Serin can remain";
		mes "here in Niflheim peacefully.";
		next;
		mes "[Kirkena]";
		mes "Although she failed to return to life, I'm sure she is glad to have met you. I think she's also started to learn that life's meaning is not in living alone...";
		next;
		mes "[Kirkena]";
		mes "Once again, thank";
		mes "you so much for your";
		mes "help. Once you finish here,";
		mes "please visit our queen, Lady Hell. I believe she wants to see you for some reason...";
		if (countitem(2643) == 1) set sign_q,129;
		else set sign_q,130;
		getexp (checkre(3))?30000:300000,0;
		close;
	}
	else if (sign_q == 200) {
		mes "How could you fail when";
		mes "the stakes are so high?";
		mes "Serin almost summoned";
		mes "the Dark Lord, but luckily,";
		mes "somebody else stopped";
		mes "her in the nick of time.";
		next;
		mes "[Kirkena]";
		mes "Fortunately, there are many people who are coming to Niflheim as part of the ordeals set before them by the gods. It looks like you just failed that ordeal, and Valkyrie will choose someone else.";
		next;
		mes "[Kirkena]";
		mes "It's over. You failed.";
		mes "Still, consider yourself";
		mes "lucky. Your soul could have";
		mes "been bound to Niflheim if it";
		mes "weren't for Serin's wish for";
		mes "you to remain free.";
		next;
		mes "[Kirkena]";
		mes "You really should thank";
		mes "her for that. Though, it's";
		mes "ironic that you failed your";
		mes "ordeals for her sake...";
		if (countitem(2642) > 0) delitem 2642,1; //Serin's_Gold_Ring
		if (countitem(7308) > 0) delitem 7308,1; //Witch's_Potion
		set sign_q,201;
		getexp (checkre(3))?20000:200000,0;
		close;
	}
	else if (sign_q > 200) {
		mes "Hmpf.";
		mes "I don't really";
		mes "want to talk to";
		mes "you anymore.";
		close;
	}
	else if ((sign_q > 130) && (sign_q < 136)) {
		mes "You've got to hurry";
		mes "and stop Serin!";
		close;
	}
	else {
		mes "Hm? Still exploring";
		mes "Niflheim? Although you're";
		mes "strong enough to survive,";
		mes "I still think you're risking";
		mes "your life by remaining here";
		mes "when you don't have to.";
		close;
	}
}

nif_in,186,168,1	script	#witch	-1,1,1,{
OnTouch_:
	callfunc "F_UpdateSignVars";
	if (sign_q == 83) {
		if (sign_sq == 2) {
			if (countitem(7304) > 0) {
				mes "[Kirkena]";
				mes "W-what's this?";
				mes "Why is it that";
				mes "you have one of";
				mes "my lost spell books?";
				next;
				switch(select("From a cursed soul...")) {
				case 1:
					mes "[Kirkena]";
					mes "Oh. That bastard must have";
					mes "stolen my spell books and got cursed when he cast the spells without my permission. Still, it's a relief to have my spells back.";
					next;
					mes "[Kirkena]";
					mes "So mortal...";
					mes "You must be here for";
					mes "some reason. Speak";
					mes "your mind.";
					next;
					switch(select("Send me back to my world.:There's a lost child here that I want to help...")) {
					case 1:
						mes "[Kirkena]";
						mes "Understood.";
						mes "Let me send";
						mes "you back to the";
						mes "realm of the living";
						mes "where you belong...";
						close2;
						warp "umbala",132,203;
						end;
					case 2:
						mes "[Kirkena]";
						mes "There's a living child?";
						mes "Here in Niflheim? That's";
						mes "most peculiar. Well, let me";
						mes "give you this. It will send";
						mes "a living human back to one";
						mes "of the towns in your realm.";
						delitem 7304,1; //Witch's_Spell_Book
						set sign_sq,3;
						getitem 7309,1; //Wing_Of_Crow
						close;
					}
				}
			}
			else {
				mes "[Kirkena]";
				mes "A mortal? What are you doing";
				mes "here? I'm not sure how more";
				mes "of you are able to get here,";
				mes "or your reasons for coming,";
				mes "but this place is dangerous";
				mes "for the living.";
				next;
				mes "[Kirkena]";
				mes "I'm sending you back";
				mes "to the realm of the living.";
				mes "If you can help it, you should";
				mes "probably avoid coming back";
				mes "to Niflheim...";
				close2;
				warp "umbala",132,203;
				end;
			}
		}
		else if (sign_sq == 3) {
			if (countitem(7309) < 1) {
				mes "[Kirkena]";
				mes "You lost the wing?";
				mes "Here, let me give you";
				mes "my last one. Now, hurry";
				mes "up and save that lost child!";
				set sign_sq,4;
				getitem 7309,1; //Wing_Of_Crow
				close;
			}
			else {
				mes "[Kirkena]";
				mes "I just gave you";
				mes "that wing, right?";
				mes "Hurry and save that";
				mes "poor child stuck in";
				mes "Niflheim!";
				close;
			}
		}
		else if (sign_sq < 6) {
			mes "[Kirkena]";
			mes "Hmm...";
			mes "If you don't have";
			mes "anything important to";
			mes "accomplish in Niflheim,";
			mes "you should probably return";
			mes "to the realm of the living...";
			close;
		}
		else if (sign_sq == 6) {
			mes "[Kirkena]";
			mes "So did you already";
			mes "use the wing to save";
			mes "that poor, lost child?";
			next;
			mes "[Kirkena]";
			mes "What...?!";
			mes "It didn't work?";
			mes "That's impossible!";
			mes "Wait, give me a moment to";
			mes "think. What could be wrong?";
			set sign_sq,7;
			close;
		}
		else if (sign_sq == 7) {
			mes "[Kirkena]";
			mes "Alright.";
			mes "Now I understand";
			mes "why the wing didn't";
			mes "work for that poor girl...";
			next;
			mes "[Kirkena]";
			mes "She's so young that";
			mes "she doesn't even know";
			mes "that she's dead. It's tragic,";
			mes "but there's no way for her";
			mes "to get out of here...";
			set sign_sq,8;
			close;
		}
		else {
			mes "[Kirkena]";
			mes "When people don't fully";
			mes "know the situation that";
			mes "they're in, they become more";
			mes "willing to take their chances.";
			close;
		}
	}
	else if (sign_q < 88) {
		mes "[Kirkena]";
		mes "When people don't fully";
		mes "know the situation that";
		mes "they're in, they become more";
		mes "willing to take their chances.";
		close;
	}
	else if (sign_q == 88) {
		if (countitem(2642) > 0) {
			mes "[Kirkena]";
			mes "As I expected,";
			mes "there is something behind";
			mes "all of this. Now, you may";
			mes "know where you are, but";
			mes "do you understand why";
			mes "the dead are here?";
			next;
			mes "[Kirkena]";
			mes "This realm is a place";
			mes "for warriors that have failed";
			mes "to prove their courage. Keep in";
			mes "mind that it's not too late for";
			mes "you to join their ranks.";
			next;
			mes "[Kirkena]";
			mes "The realm of Niflheim";
			mes "is ruled by the Queen of the";
			mes "Dead. Sometimes she appears";
			mes "in her shining armor and makes the rounds. Everyone who sees her is stunned by the image of authority.";
			next;
			mes "[Kirkena]";
			mes "Now...";
			mes "What I need you to do is";
			mes "ask the Queen of the Dead";
			mes "for the Symbol of Nine Realms.";
			next;
			select("What is that?");
			mes "[Kirkena]";
			mes "The symbol acts as";
			mes "a voucher of the queen's";
			mes "authority and represents her";
			mes "undeniable right to rule over";
			mes "the dead. But right now, I can't";
			mes "explain why I need it.";
			next;
			mes "[Kirkena]";
			mes "I'll tell you why I need";
			mes "it once you bring me the";
			mes "queen's symbol. Now, please";
			mes "keep this secret and tell no one that I asked you to bring the symbol to me.";
			next;
			switch(select("Alright, I understand.:How am I supposed to get the symbol?")) {
			case 1:
				set sign_q,89;
				close;
			case 2:
				mes "[Kirkena]";
				mes "Taking the symbol";
				mes "by force is out of the";
				mes "question. Not even the gods";
				mes "would consider battling the";
				mes "Queen of the Dead.";
				next;
				mes "[Kirkena]";
				mes "You will need to";
				mes "earn the queen's favor";
				mes "in order to even have";
				mes "a chance of obtaining";
				mes "the Symbol of Nine Realms.";
				next;
				mes "[Kirkena]";
				mes "Now, there is a rumor";
				mes "that the Queen of the Dead";
				mes "is searching for her lost mother, Angrboda. Now, if you could find where Angrboda has been";
				mes "sealed away...";
				next;
				mes "[Kirkena]";
				mes "When you need to meet";
				mes "me from now on, go ahead";
				mes "and take the ^FF0000secret passage";
				mes "through the right side of the";
				mes "portrait on the second floor^000000";
				mes "of this castle, "+strcharinfo(0)+".";
				set sign_q,92;
				next;
				mes "[Kirkena]";
				mes "If you use that piano";
				mes "to find me, I'll probably";
				mes "mistake you for one of the";
				mes "humans that need guidance";
				mes "out of Niflheim. So don't";
				mes "forget to use that passage.";
				close;
			}
		}
		else {
			mes "[Kirkena]";
			mes "Did you need my help?";
			mes "I know that I'm one of the few in Niflheim that are sympathetic with mortals, I've got a problem of my own that I need to deal with...";
			next;
			switch(select("Never mind, sorry!:What happened...?")) {
			case 1:
				mes "[Kirkena]";
				mes "...";
				mes "Hrrmmmpf...";
				emotion ET_HNG;
				close;
			case 2:
				mes "[Kirkena]";
				mes "Recently, I've found that";
				mes "two of my spell books are";
				mes "missing. They contain some";
				mes "pretty potent spells that";
				mes "could cause disaster in";
				mes "incompetent hands...";
				next;
				mes "[Kirkena]";
				mes "I'm pretty sure they";
				mes "were stolen, so if you'd";
				mes "retrieve them for me from";
				mes "the thief, I'd be truly grateful. Then, I'd have my hands free";
				mes "to give the help you came for.";
				next;
				mes "[Kirkena]";
				mes "Oh, and next time you come";
				mes "to see me, go ahead and use";
				mes "the passage to the right of the portrait on the second floor";
				mes "of the castle.";
				set sign_q,90;
				close;
			}
		}
	}
	else if (sign_q == 89) {
		mes "[Kirkena]";
		mes "...Hm?";
		mes "Is there";
		mes "something that";
		mes "you need to ask me?";
		next;
		select("How can I get the symbol?");
		mes "[Kirkena]";
		mes "Taking the symbol";
		mes "by force is out of the";
		mes "question. Not even the gods";
		mes "would consider battling the";
		mes "Queen of the Dead.";
		next;
		mes "[Kirkena]";
		mes "You will need to";
		mes "earn the queen's favor";
		mes "in order to even have";
		mes "a chance of obtaining";
		mes "the Symbol of Nine Realms.";
		next;
		mes "[Kirkena]";
		mes "Now, there is a rumor";
		mes "that the Queen of the Dead";
		mes "is searching for her lost mother, Angrboda. Now, if you could find where Angrboda has been";
		mes "sealed away...";
		next;
		mes "[Kirkena]";
		mes "When you need to";
		mes "meet me from now on,";
		mes "go ahead and take passage";
		mes "through the right side of the";
		mes "portrait on the second";
		mes "floor of this castle.";
		set sign_q,92;
		close;
	}
	end;
}

que_sign01,45,227,4	script	Queen of the Dead	856,{
	callfunc "F_UpdateSignVars";
	mes "[Lady Hell]";
	if (sign_q < 117) {
		mes "^8C1717You wish to have";
		mes "an audience with the";
		mes "Queen of the Dead without";
		mes "invitation? Insolent mortal!";
		mes "Go back to where you belong!^000000";
		close2;
		percentheal -100,0;
		end;
	}
	else if (sign_q == 117) {
		mes "^8C1717I have been told";
		mes "by Ganglati that you";
		mes "are the mortal that has";
		mes "guided Mother's soul to me.^000000";
		next;
		mes "[Lady Hell]";
		mes "^8C1717Do not fear me,";
		mes "hero of Midgard.";
		mes "You have won the favor";
		mes "of the Queen of the Dead";
		mes "and may ask me of any";
		mes "reward if I deem it fair.^000000";
		next;
		select("The Symbol of the Nine Realms...");
		mes "[Lady Hell]";
		mes "^8C1717The true Symbol of the";
		mes "Nine Realms cannot be freely";
		mes "given or lent. However, I sense";
		mes "your purpose and will give you";
		mes "a symbol imbued with enough";
		mes "power to be used only once.^000000";
		next;
		mes "[Lady Hell]";
		mes "^8C1717With the symbol I give you,";
		mes "you can command the dead to";
		mes "carry out your will without";
		mes "question. However, keep in";
		mes "mind that after one use,";
		mes "its power will be consumed.^000000";
		next;
		mes "[Lady Hell]";
		mes "^8C1717I have also decided";
		mes "to reward you with one";
		mes "more special permission.";
		mes "You may now freely draw";
		mes "water from the fountain";
		mes "in my mansion, brave hero.^000000";
		next;
		mes "^3355FFYou received the";
		mes "Symbol of the Nine Realms.^000000";
		delitem 7307,1; //Whisper_Of_Soul
		set sign_q,118;
		getitem 7305,1; //Authority_Of_Nine_World
		close;
	}
	else if (sign_q < 142) {
		mes "^8C1717Greetings, mortal.";
		mes "Make sure that you";
		mes "use the power of the";
		mes "symbol wisely. You will";
		mes "be responsible for the";
		mes "consequences...^000000";
		close;
	}
	else if (sign_q == 142) {
		mes "^8C1717Ah.";
		mes "You are the";
		mes "mortal called";
		mes ""+strcharinfo(0)+", are you not?";
		mes "Yes, you are known to me.^000000";
		next;
		mes "[Lady Hell]";
		mes "^8C1717I've wanted to see you";
		mes "as I've sensed that you";
		mes "carry something which feels";
		mes "very familiar to me. Do you";
		mes "have something extraordinarily";
		mes "special in your possession?^000000";
		next;
		switch(select("The Sign:Sobbing Starlight")) {
		case 1:
			mes "[Lady Hell]";
			mes "^8C1717The Sign...?";
			mes "Hmm, no, that's not";
			mes "what I sensed. It's actually";
			mes "something quite different...^000000";
			close;
		case 2:
			mes "[Lady Hell]";
			mes "^8C1717Yes, that's it!";
			mes "I never expected a mortal";
			mes "to have such an interesting";
			mes "artifact in "+((Sex == SEX_MALE)?"his":"her")+" possession.^000000";
			next;
			mes "[Lady Hell]";
			mes "^8C1717As queen of Niflheim,";
			mes "I command you to lend the";
			mes "Sobbing Starlight to me! Fear";
			mes "not, I shall quickly return it. For a mortal, it must have";
			mes "taken great pains to obtain this...^000000";
			next;
			switch(select("Please take it...:N-no! Don't take it!")) {
			case 1:
				mes "[Lady Hell]";
				mes "^8C1717Thank you mortal.";
				mes "Now, I shall show";
				mes "you something truly";
				mes "interesting...^000000";
				delitem 7178,1; //Star's_Sob
				set sign_q,143;
				close;
			case 2:
				mes "[Lady Hell]";
				mes "^8C1717Ha ha ha!";
				mes "You amuse me,";
				mes "mortal! To think,";
				mes "you even have courage";
				mes "to refuse the queen of";
				mes "Niflheim! Ha ha ha!^000000";
				next;
				mes "[Lady Hell]";
				mes "^8C1717Mercy is not a quality";
				mes "that I am known for, but";
				mes "since you are my favored";
				mes "mortal, I shall not kill you.";
				mes "Still, it would be unwise";
				mes "to displease me~^000000";
				close2;
				warp "niflheim",29,154;
				end;
			}
		}
	}
	else if (sign_q == 143) {
		mes "^8C1717As queen of this realm,";
		mes "I am unaccustomed to labor.";
		mes "But give me a moment to finish";
		mes "my work on this priceless";
		mes "artifact, mortal.^000000";
		next;
		specialeffect EF_GLASSWALL;
		next;
		specialeffect EF_NAPALMBEAT;
		next;
		specialeffect EF_FIREPILLARBOMB;
		next;
		specialeffect EF_LORD;
		next;
		mes "[Lady Hell]";
		mes "^8C1717It is done.";
		mes "This is the true";
		mes "form of the object";
		mes "you humans call the";
		mes "Sobbing Starlight.^000000";
		next;
		set sign_q,144;
		getitem 7025,1; //Lucifer's_Lament
		mes "[Lady Hell]";
		mes "^8C1717Although you may also know";
		mes "this object as God's Tear Drop, keep in mind that history, as you humans know it, may actually be different than the truth.^000000";
		next;
		mes "[Lady Hell]";
		mes "^8C1717In other words, there";
		mes "are some older tales about";
		mes "the gods and their enemies that";
		mes "may have been confused and twisted as they were handed down from generation to generation.^000000";
		next;
		mes "[Lady Hell]";
		mes "^8C1717That is all I can tell";
		mes "you for now, mortal. It will";
		mes "be your job to discover the";
		mes "truth of the legends...^000000";
		close;
	}
	else {
		mes "^8C1717Greetings, mortal.";
		mes "Is the realm of the living";
		mes "that boring and tedious?";
		mes "Ha ha ha! Well, there shall";
		mes "always be a place for you";
		mes "here in Niflheim.^000000";
		close;
	}
}

niflheim,146,241,0	script	Depressing Man	735,{
	callfunc "F_UpdateSignVars";
	if (sign_q < 80) {
		mes "[????]";
		mes "Leave me be,";
		mes "ruffian! I'm disinclined";
		mes "towards conversation";
		mes "at the moment.";
		close;
	}
	else if (sign_q < 87) {
		mes "[????]";
		mes "Don't go judging";
		mes "people based on just";
		mes "how they look. Try to look";
		mes "inside and find the truth";
		mes "within their hearts.";
		close;
	}
	else if (sign_q == 87) {
		if (countitem(2642) > 1) {
			mes "[Gen]";
			mes "You lookin' for";
			mes "something? Crayu";
			mes "must have sent you.";
			mes "Alright then, let's get";
			mes "straight to the point.";
			next;
			mes "[Gen]";
			mes "So, why is it that you";
			mes "wanna become one";
			mes "of Valkyrie's chosen?";
			next;
			switch(select("To prove my courage:For honor:To help people")) {
			case 1:
				if (sign_sq > 2) set sign_sq,0;
				else set sign_sq,sign_sq+1;
			case 2:
				break;
			}
			mes "[Gen]";
			mes "Alright...";
			mes "Now, did Crayu";
			mes "tell you why I'm here?";
			next;
			switch(select("Yes:No")) {
			case 1:
				mes "[Gen]";
				mes "Good, then you";
				mes "already know what";
				mes "you need to do. Now go";
				mes "see the witch of Niflheim.";
				next;
				mes "[Gen]";
				mes "And, off the record,";
				mes "I think you should be";
				mes "really careful if you find";
				mes "yourself dealing with Serin...";
				set sign_q,88;
				close;
			case 2:
				mes "[Gen]";
				mes "You know, I was an";
				mes "adventurer myself. In fact,";
				mes "I even came here to Niflheim";
				mes "for the ordeals set by the gods. However, I failed and ended up being bound to this realm...";
				next;
				mes "[Gen]";
				mes "I just wanted to warn you.";
				mes "Be careful and don't justify";
				mes "your greed for any sort of reward using the excuse that you're just gonna prove your courage.";
				mes "That's what I did...";
				next;
				mes "[Gen]";
				mes "Anyway, I've already talked";
				mes "too much. First, go and see";
				mes "the witch and ask her to";
				mes "help you out, okay?";
				next;
				mes "[Gen]";
				mes "One last thing. Off the";
				mes "record, I think you should";
				mes "be really careful if you find";
				mes "yourself dealing with Serin.";
				mes "She seems nice enough, but";
				mes "something's weird about her.";
				next;
				mes "[Gen]";
				mes "She's awfully persuasive,";
				mes "and the fact that she used";
				mes "to be a great wizard when she";
				mes "was alive bothers me. She's a lot different than the rest of the guys stuck in Niflheim...";
				set sign_q,88;
				close;
			}
		}
		else {
			mes "[Gen]";
			mes "Are you here";
			mes "to prove your";
			mes "courage to the gods?";
			next;
			mes "[Gen]";
			mes "You know, I was an";
			mes "adventurer myself. In fact,";
			mes "I even came here to Niflheim";
			mes "for the ordeals set by the gods. However, I failed and ended up being bound to this realm...";
			next;
			mes "[Gen]";
			mes "I just wanted to warn you.";
			mes "Be careful and don't justify";
			mes "your greed for any sort of reward using the excuse that you're just gonna prove your courage.";
			mes "That's what I did...";
			next;
			mes "[Gen]";
			mes "Anyway, I've already talked";
			mes "too much. First, go and see";
			mes "the witch and ask her to";
			mes "help you out, okay?";
			set sign_q,88;
			close;
		}
	}
	else if (sign_q < 117) {
		mes "[Gen]";
		mes "Huh... I hear you're";
		mes "looking for something";
		mes "pretty important. It's going";
		mes "to be a dangerous search.";
		next;
		mes "[Gen]";
		mes "They are plenty of";
		mes "other parties that are";
		mes "interested in the thing";
		mes "which you're seeking...";
		close;
	}
	else if (sign_q == 117) {
		mes "[Gen]";
		mes "You must be a very";
		mes "resourceful mortal.";
		mes "Not even Lady Hell, with";
		mes "all her power, could find";
		mes "the soul of her mother";
		mes "for a long time.";
		next;
		mes "[Gen]";
		mes "There's no need";
		mes "for me to hide my";
		mes "true identity any longer.";
		mes "My real name is Ganglati,";
		mes "servant of Lady Hell, the";
		mes "ruler of Niflheim.";
		next;
		mes "[Gen]";
		mes "Her highness would";
		mes "have words with you.";
		mes "Shall I send you to her";
		mes "mansion, Eljudnir,";
		mes "right now?";
		next;
		switch(select("Yes:No")) {
		case 1:
			mes "[Gen]";
			mes "Remember to be";
			mes "careful and especially";
			mes "polite when you speak to";
			mes "Lady Hell. Otherwise, the";
			mes "consequences will be severe...";
			close2;
			warp "que_sign01",45,20;
			end;
		case 2:
			mes "[Gen]";
			mes "I understand.";
			mes "Meeting with a deity is";
			mes "no small matter. However,";
			mes "I advise you to make haste";
			mes "as her highness is eager";
			mes "to see you soon.";
			close;
		}
	}
	else if (sign_q == 118) {
		mes "[Gen]";
		mes "You must be most favored";
		mes "to receive the Symbol of the";
		mes "Nine Realms. Of course, it";
		mes "can be used only once, but";
		mes "it is still a great honor.";
		next;
		mes "[Gen]";
		mes "Once again, I ask that";
		mes "you be on guard against";
		mes "Serin. She may already be";
		mes "aware of what you plan to";
		mes "do with this symbol...";
		close;
	}
	else if (sign_q < 129) {
		mes "[Gen]";
		mes "You must hurry and";
		mes "stop the summoning";
		mes "before your world in";
		mes "cast into immense peril!";
		next;
		mes "[Gen]";
		mes "Although Lady Hell";
		mes "is being rather blase";
		mes "about this matter, I beseech";
		mes "you to do what you can for";
		mes "the realm of the living!";
		close;
	}
	else if (sign_q > 200) {
		mes "[Gen]";
		mes "I should have";
		mes "known you couldn't";
		mes "stop her. Still, I had";
		mes "a little hope that you'd";
		mes "be able to do it.";
		next;
		mes "[Gen]";
		mes "Perhaps I expected";
		mes "far too much of you.";
		mes "Goodbye for now, mortal.";
		close;
	}
	else {
		mes "[Gen]";
		mes "You've done a great";
		mes "job of stopping Serin.";
		mes "Excellent! Such great";
		mes "service on behalf of";
		mes "the realm of the living!";
		next;
		mes "[Gen]";
		mes "I'm pleased to inform";
		mes "you that you've been";
		mes "invited to Lady Hell's";
		mes "mansion once again.";
		mes "Are you ready to go?";
		next;
		switch(select("No, thanks.:Yes.")) {
		case 1:
			mes "[Gen]";
			mes "I see.";
			mes "Well then, come";
			mes "back to me when you";
			mes "feel fully prepared.";
			close;
		case 2:
			mes "[Gen]";
			mes "Good, good.";
			mes "Don't forget to";
			mes "speak to her highness";
			mes "with the utmost respect!";
			close2;
			warp "que_sign01",45,20;
			end;
		}
		close;
	}
}

nif_in,140,177,0	script	#Switch	111,{
	callfunc "F_UpdateSignVars";
	if (countitem(7313) == 1) {
		warp "que_sign01",115,135;
		end;
	}
	if (sign_q > 89) {
		if (sign_q == 126) set sign_q,198;
		warp "que_sign01",115,135;
		end;
	}
	end;
}

niflheim,102,54,4	script	Mad Man#s	739,{
	callfunc "F_UpdateSignVars";
	mes "[Laichin]";
	if (sign_q < 82) {
		mes "What? I look familiar to you?";
		mes "Eh, you know what they say.";
		mes "Everyone has a lookalike in the";
		mes "world somewhere. Am I right";
		mes "or am I right?";
		close;
	}
	else if (sign_q < 96) {
		mes "Niflheim ain't such a bad";
		mes "place to live. Sure, Asgard's";
		mes "all pretty and stuff, but there's too many rules. In this place, you";
		mes "can enjoy a lot more freedom. After you get used to all the stink.";
		next;
		mes "[Laichin]";
		mes "Did I say 'stink?'";
		mes "I meant... 'fragrance.'";
		mes "Alright, so the gods expelled";
		mes "me, but I really oughtta thank";
		mes "'em for sending me here!";
		next;
		mes "[Laichin]";
		mes "What's that look for...?";
		mes "What, you can't believe";
		mes "that someone like me used";
		mes "to live in Valhalla? Me neither! They really made a mistake when they put me up to live in Asgard!";
		close;
	}
	else if (sign_q == 96) {
		mes "Angrboda...?";
		mes "Yeah, yeah!";
		mes "I remember hearing something";
		mes "about her when I usedta hang";
		mes "with the gods up in Asgard.";
		next;
		mes "[Laichin]";
		mes "Yeah, those guys were pretty";
		mes "gangster about it. I mean, they took her soul, broke it in four pieces and stashed them in the deepest hole in Midgard!";
		next;
		mes "[Laichin]";
		mes "Sure, she was a giant, but";
		mes "they were pretty scared of her.";
		mes "All her children ended up to be legendary monsters! Well, I'm";
		mes "not sure if Lady Hell counts.";
		next;
		mes "[Laichin]";
		mes "That's pretty harsh.";
		mes "I mean, even if you die,";
		mes "your soul has no place to";
		mes "rest. Angrboda's soul is";
		mes "all cut up and stuff!";
		next;
		select("So where are the soul pieces again?");
		mes "[Laichin]";
		mes "What...? I just said,";
		mes "the deepest underground";
		mes "place in Midgard.";
		mes "It's a dangerous joint";
		mes "protected by gangs";
		mes "of monsters.";
		next;
		mes "[Laichin]";
		mes "Wait, you tellin' me";
		mes "that you're gonna find";
		mes "all of Angrboda's soul?!";
		mes "You're crazy! If they end up";
		mes "missing, the gods'll know I was";
		mes "the one who tipped you off!";
		next;
		mes "[Laichin]";
		mes "If I was gonna risk my soul,";
		mes "I'd wanna enjoy the rest of my";
		mes "afterlife as my much as I could";
		mes "before the gods offed me. Man,";
		mes "I'd need at least 40,000 Zeny to even have a decent time...";
		next;
		switch(select("Pay Laichin 40,000 Zeny:Don't pay Laichin.")) {
		case 1:
			if (Zeny < 40000) {
				mes "[Laichin]";
				mes "Hey...";
				mes "This is sooo";
				mes "not enough money";
				mes "for me to enjoy myself";
				mes "if my soul ends up getting";
				mes "busted by the gods.";
				emotion ET_HNG;
				close;
			}
			else {
				mes "[Laichin]";
				mes "Now we're talkin'!";
				mes "You're a true hero!";
				mes "Right, you gotta go to the";
				mes "lowest part of Glast Heim to";
				mes "find Angrboda's soul pieces.";
				next;
				set .@select_s,rand(1,5);
				if (.@select_s == 1) {
					mes "[Laichin]";
					mes "Check out the";
					mes "big 1 o' clock,";
					mes "big 5 o' clock,";
					mes "big 7 o' clock and";
					mes "the small 6 o' clock.";
					next;
				}
				else if (.@select_s == 2) {
					mes "[Laichin]";
					mes "Check out the";
					mes "big 4 o' clock,";
					mes "big 10 o' clock,";
					mes "small 6 o' clock and the";
					mes "very small 11 o' clock.";
					next;
				}
				else if (.@select_s == 3) {
					mes "[Laichin]";
					mes "Check out the";
					mes "big 5 o' clock,";
					mes "small 11 o' clock,";
					mes "small 6 o' clock and the";
					mes "very small 11 o' clock.";
					next;
				}
				else if (.@select_s == 4) {
					mes "[Laichin]";
					mes "Check out the";
					mes "big 4 o' clock,";
					mes "big 5 o' clock,";
					mes "big 10 o' clock and";
					mes "the small 11 o' clock.";
					next;
				}
				else {
					mes "[Laichin]";
					mes "Heh heh!";
					close;
				}
				mes "[Laichin]";
				mes "Her soul pieces are really";
				mes "well hidden, so you gotta look around, even if you know the general location. And don't";
				mes "tell anyone else about these locations or there'll be trouble.";
				next;
				switch(select("I promise.:What do you mean by big and small?")) {
				case 1:
					mes "[Laichin]";
					mes "Alright, kid.";
					mes "Have fun!";
					if (.@select_s == 1) set sign_q,97;
					else if (.@select_s == 2) set sign_q,98;
					else if (.@select_s == 3) set sign_q,99;
					else if (.@select_s == 4) set sign_q,100;
					else {
						mes "[Laichin]";
						mes "Heh heh!";
						close;
					}
					set Zeny, Zeny-40000;
					close;
				case 2:
					mes "[Laichin]";
					mes "What do I mean by";
					mes "big and small? Hey man,";
					mes "the answer to that is worth";
					mes "at least... 20,000 Zeny.";
					mes "If you wanna know,";
					mes "cough up the cash!";
					next;
					switch(select("Don't pay him.:Pay him.")) {
					case 1:
						mes "[Laichin]";
						mes "Fine, fine.";
						mes "Just don't come";
						mes "crawling back when";
						mes "you can't figure out";
						mes "where the soul pieces are!";
						set Zeny, Zeny-40000;
						if (.@select_s == 1) set sign_q,97;
						else if (.@select_s == 2) set sign_q,98;
						else if (.@select_s == 3) set sign_q,99;
						else if (.@select_s == 4) set sign_q,100;
						else {
							mes "[Laichin]";
							mes "Hehehehe~";
							close;
						}
						emotion ET_HNG;
						close;
					case 2:
						if (Zeny < 60000) {
							mes "[Laichin]";
							mes "What is this?";
							mes "You tryin to welch";
							mes "me or somethin'?";
							emotion ET_HNG;
							close;
						}
						else {
							mes "[Laichin]";
							mes "Alright, listen up.";
							mes "Big, small and very small";
							mes "mean the distances from the";
							mes "center of the map. So for big,";
							mes "I mean look near the border of";
							mes "the map. Easy, huh?";
							next;
							mes "[Laichin]";
							mes "When I say small, you";
							mes "gotta look in areas closer";
							mes "than the borders of the map.";
							mes "For very small, you gotta";
							mes "look near the center. Got it?";
							set Zeny, Zeny-60000;
							if (.@select_s == 1) set sign_q,101;
							else if (.@select_s == 2) set sign_q,102;
							else if (.@select_s == 3) set sign_q,103;
							else if (.@select_s == 4) set sign_q,104;
							else {
								mes "[Laichin]";
								mes "Eh heh";
								mes "heh heh heh!";
								close;
							}
							close;
						}
					}
				}
			}
		case 2:
			mes "[Laichin]";
			mes "Huh...?";
			mes "Okay pal.";
			close;
		}
	}
	else if ((sign_q == 97) || (sign_q == 98) || (sign_q == 99) || (sign_q == 100)) {
		mes "Oh yeah, about those";
		mes "directions I gave you";
		mes "last time? They work, but";
		mes "you gotta know what I mean";
		mes "by 'big' or 'small' whatever";
		mes "o' clock means. That's right... ";
		next;
		mes "[Laichin]";
		mes "Matter of fact, I'll";
		mes "tell you all about it.";
		mes "Right after you pay me,";
		mes "oh, I don't know, ^FF000020,000 zeny^000000.";
		next;
		switch(select("Pay him.:Don't pay him.")) {
		case 1:
			if (Zeny < 20000) {
				mes "[Laichin]";
				mes "What is this?";
				mes "You tryin to welch";
				mes "me or somethin'?";
				close;
			}
			else {
				mes "[Laichin]";
				mes "Alright, listen up.";
				mes "Big, small and very small";
				mes "mean the distances from the";
				mes "center of the map. So for big,";
				mes "I mean look near the border of";
				mes "the map. Easy, huh?";
				next;
				mes "[Laichin]";
				mes "When I say small, you";
				mes "gotta look in areas closer";
				mes "than the borders of the map.";
				mes "For very small, you gotta";
				mes "look near the center. Got it?";
				set Zeny, Zeny-20000;
				if (sign_q == 97) set sign_q,101;
				else if (sign_q == 98) set sign_q,102;
				else if (sign_q == 99) set sign_q,103;
				else if (sign_q == 100) set sign_q,104;
				else {
					mes "[Laichin]";
					mes "Bwahahaha!";
					close;
				}
				close;
			}
		case 2:
			mes "[Laichin]";
			mes "Whatever, dude!";
			mes "Freakin' cheapskate...";
			emotion ET_HNG;
			close;
		}
	}
	else if (sign_q < 105) {
		mes "Oh yeah. Uh, I forgot to tell";
		mes "you that Angrboda's soul pieces are sealed with the power of the gods. You can't just smash them open.";
		next;
		mes "[Laichin]";
		mes "...Or maybe you could.";
		mes "Anyway, it'll be better";
		mes "if you had a weapon that";
		mes "was solid, heavy and powerful.";
		next;
		mes "[Laichin]";
		mes "But yeah, think about";
		mes "what it means to break";
		mes "a godly seal. Remember there's";
		mes "^FF0000some kinda rule^000000 that the gods imposed which you gotta follow";
		mes "to release Angrboda's soul.";
		next;
		mes "[Laichin]";
		mes "Ah, right. If you wanna";
		mes "try different weapons for";
		mes "breaking those seals, make";
		mes "sure you got 'em in your";
		mes "inventory and that they're";
		mes "not equipped, alright?";
		next;
		switch(select("Thanks~!:Where am I supposed to go again?")) {
		case 1:
			mes "[Laichin]";
			mes "Oh no...";
			mes "Thank you for all";
			mes "of this zeny! Money";
			mes "might not be able to";
			mes "buy happiness, but it";
			mes "sure comes real close!";
			close;
		case 2:
			mes "[Laichin]";
			mes "Hey... You gotta";
			mes "go to the lowest part";
			mes "of Glast Heim to find all";
			mes "of Angrboda's soul pieces.";
			mes "Once you get there...";
			next;
			mes "[Laichin]";
			if (sign_q == 101) {
				mes "Check out the";
				mes "big 1 o' clock,";
				mes "big 5 o' clock,";
				mes "big 7 o' clock and";
				mes "the small 6 o' clock.";
			}
			else if (sign_q == 102) {
				mes "Check out the";
				mes "big 4 o' clock,";
				mes "big 10 o' clock,";
				mes "small 6 o' clock and the";
				mes "very small 11 o' clock.";
			}
			else if (sign_q == 103) {
				mes "Check out the";
				mes "big 5 o' clock,";
				mes "small 11 o' clock,";
				mes "small 6 o' clock and the";
				mes "very small 11 o' clock.";
			}
			else if (sign_q == 104) {
				mes "Check out the";
				mes "big 4 o' clock,";
				mes "big 5 o' clock,";
				mes "big 10 o' clock and";
				mes "the small 11 o' clock.";
			}
			mes "And break those seals";
			mes "in that order, okay?";
			next;
			mes "[Laichin]";
			mes "Big, small and very small";
			mes "mean the distances from the";
			mes "center of the map. So for big,";
			mes "I mean look near the border of";
			mes "the map. Easy, huh?";
			next;
			mes "[Laichin]";
			mes "When I say small, you";
			mes "gotta look in areas closer";
			mes "than the borders of the map.";
			mes "For very small, you gotta";
			mes "look near the center. Got it?";
			close;
		}
	}
	else if (sign_q < 150) {
		mes "Dude, Niflheim rocks.";
		mes "It's like, a million times";
		mes "better than that boring";
		mes "old Asgard. Hell yeah!";
		next;
		mes "[Laichin]";
		mes "Eh, I don't even wanna";
		mes "know if you manage to";
		mes "find all of Angrboda's soul";
		mes "pieces, but if you do, don't";
		mes "go bringin' close to me. If the";
		mes "gods find out you have 'em... ";
		next;
		mes "[Laichin]";
		mes "But for the sake of";
		mes "argument, let's say you";
		mes "do happen to get them all.";
		mes "In that case, you oughta get";
		mes "Angrboda's soul to the Queen";
		mes "of Hell right away, alright?";
		next;
		mes "[Laichin]";
		mes "Ooh.. But not just any";
		mes "yahoo can waltz up to her.";
		mes "The best thing would be to";
		mes "give it to one of her really";
		mes "trusted retainers, I guess.";
		mes "Now, who was he again?";
		next;
		mes "[Laichin]";
		mes "I know he's always in";
		mes "disguise as some sorta";
		mes "really ^666666despressing guy^000000";
		mes "and I can't remember his";
		mes "name for the life of me, but";
		mes "he's around here somewhere...";
		close;
	}
	else if (sign_q == 200) {
		mes "Whoa...";
		mes ".................";
		mes "My freakin' head hurts.";
		close;
	}
	else {
		mes "Whoa...";
		mes ".................";
		close;
	}
}

niflheim,348,257,1	script	#Cursed Soul	-1,1,1,{
OnTouch_:
	callfunc "F_UpdateSignVars";
	if ((sign_q == 83) || (sign_q == 90)) {
		if (sign_sq == 0) {
			killmonster "niflheim","#Cursed Soul::OnMyMobDead";
			mes "[Ashe Bruce]";
			mes "Leave now, or I will";
			mes "remove you by force....";
			next;
			mes "[Ashe Bruce]";
			mes "....And...";
			mes "....Whatever you do...";
			mes "....Do NOT touch my books...";
			next;
			switch(select("Pick up the 1st book.:Pick up the 2nd book.:Pick up the 3rd book.:Leave immediately.")) {
			case 1:
				monster "niflheim",349,259,"Rideword",1478,1;
				mes "[Ashe Bruce]";
				mes "...!...";
				mes "How dare you touch my books";
				mes "when I specifically said";
				mes "'Don't touch my books!'";
				next;
				mes "[Ashe Bruce]";
				mes "....!...Grrrrr!";
				mes "I shall tear you apart...!";
				mes "Be bound by an eternal curse...!";
				close;
				break;
			case 2:
				mes "[Ashe Bruce]";
				mes "...!...";
				mes "You dare touch my books?!";
				mes "Right after I said not";
				mes "to touch them...?!";
				mes "Foolish mortal!";
				mes "...BEGONE!";
				close;
				warp "niflheim",34,162;
				break;
			case 3:
				mes "[Ashe Bruce]";
				mes "Muhahahaha....";
				mes "Stubborn mortal~!";
				mes "Fine! I will give you";
				mes "a fighting chance and let";
				mes "you cast a spell.";
				next;
				if (select("Clover:Klaatu:Kleitos") == 2) set .@spell,.@spell+1;
				if (select("Verit:Veritas:Verata") == 3) set .@spell,.@spell+1;
				if (select("Necktie:Necklace:Nero:^FFFFFFNictu^000000") == 4) set .@spell,.@spell+1;
				if (.@spell == 3) {
					if (rand(1,5) == 5) {
						mes "[Ashe Bruce]";
						mes "That was the right";
						mes "spell! But nothing";
						mes "happened. Madness!";
						close;
					}
					else {
						mes "[Ashe Bruce]";
						mes "That spell...";
						mes "You removed my curse?";
						mes "I don't believe it. I'm free!";
						next;
						mes "[Ashe Bruce]";
						mes "But do not underestimate";
						mes "my awesome powers! In fact,";
						mes "I command you to take this";
						mes "book and give it to that";
						mes "weak, pathetic witch!";
						if (sign_q == 83) {
							if(sign_sq == 0) {
								set sign_sq,1;
								getitem 7304,1; //Witch's_Spell_Book
							}
						}
						else if (sign_q == 90) {
							set sign_q,91;
							getitem 7304,1; //Witch's_Spell_Book
						}
						close;
					}
				}
				else {
					monster "niflheim",345,259,"Orc Skeleton",1462,1,"#Cursed Soul::OnMyMobDead";
					monster "niflheim",347,261,"Orc Skeleton",1462,1,"#Cursed Soul::OnMyMobDead";
					monster "niflheim",344,253,"Orc Skeleton",1462,1,"#Cursed Soul::OnMyMobDead";
					monster "niflheim",346,251,"Orc Skeleton",1462,1,"#Cursed Soul::OnMyMobDead";
					monster "niflheim",349,249,"Orc Skeleton",1462,1,"#Cursed Soul::OnMyMobDead";
					monster "niflheim",350,260,"Orc Skeleton",1462,1,"#Cursed Soul::OnMyMobDead";
					monster "niflheim",353,256,"Orc Skeleton",1462,1,"#Cursed Soul::OnMyMobDead";
					mes "[Ashe Bruce]";
					mes "Muhahahahahaha!";
					mes "That's not the right spell!";
					mes "Now, death awaits you!";
					close;
				}
			case 4:
				mes "[Ashe Bruce]";
				mes "Well then.";
				mes "Try not to trip on";
				mes "your feet in your";
				mes "rush to leave.";
				close;
			}
		}
	}
	end;

OnMyMobDead:
	end;
}

nif_in,102,81,1	script	#Crayu	-1,1,1,{
OnTouch_:
	callfunc "F_UpdateSignVars";
	if (sign_q < 75) end;
	else if (sign_q < 82) {
		mes "[Crayu]";
		mes "Mountain sunset to the west";
		mes "Where the purple dusk falls ";
		mes "Surrounded by beautiful melody";
		mes "^You become the key that ignores its master";
		close;
	}
	else if (sign_q == 86) {
		mes "[Crayu]";
		mes "Mountain sunset to the west";
		mes "Where the purple dusk falls ";
		mes "Surrounded by beautiful melody";
		mes "You become the key that ignores its master";
		next;
		mes "[Crayu]";
		mes "Hello adventurer.";
		mes "I know this is rather";
		mes "abrupt, but what do";
		mes "you think of Serin?";
		next;
		select("She's good.:She's evil!:She could go either way.");
		mes "[Crayu]";
		mes "Hm...?";
		mes "And why do";
		mes "you think so?";
		next;
		switch(select("Just my opinion.:It's the truth!")) {
		case 1:
			if (sign_sq > 1) set sign_sq,0;
			else set sign_sq,sign_sq+1;
		case 2:
			break;
		}
		mes "[Crayu]";
		mes "Ah, I understand.";
		mes "Now, how may I help you?";
		next;
		switch(select("What exactly is Niflheim?:How do I become one of the chosen?")) {
		case 1:
			mes "[Crayu]";
			mes "Niflheim is commonly";
			mes "known as the city of the";
			mes "dead, but it's also the";
			mes "resting place of warriors";
			mes "who failed to enter Valhalla.";
			next;
			mes "[Crayu]";
			mes "Some heroes may think";
			mes "of Niflheim as the tragic end,";
			mes "but it really all depends on";
			mes "your point of view.";
			close;
		case 2:
			mes "["+strcharinfo(0)+"]";
			mes "What do I need";
			mes "to do to become one";
			mes "of the chosen warriors?";
			next;
			mes "[Crayu]";
			mes "First and foremost,";
			mes "you must prove your courage.";
			mes "It will be up to you to decide";
			mes "how you will demonstrate your";
			mes "bravery. The gods will only";
			mes "be watching and judging.";
			next;
			mes "[Crayu]";
			mes "Hmm...";
			mes "I think it would";
			mes "be a good idea if";
			mes "you talk to someone";
			mes "in Niflheim named ^FF0000Gen^000000.";
			set sign_q,87;
			close;
		}
	}
	else if (sign_q == 86) {
		mes "Hmm...";
		mes "I think it would";
		mes "be a good idea if";
		mes "you talk to someone";
		mes "in Niflheim named ^FF0000Gen^000000.";
		close;
	}
	end;
}

nif_in,156,91,1	script	#kidniff	-1,1,1,{
OnTouch_:
	callfunc "F_UpdateSignVars";
	if (sign_q == 83) {
		if (sign_sq == 0) {
			mes "[Alakina Ann]";
			mes "^333333*Cries*^000000";
			mes "Where am I?";
			mes "I... I wanna go home~";
			emotion ET_CRY;
			close;
		}
		else if (sign_sq == 1) {
			mes "[Alakina Ann]";
			mes "W-will you help me get";
			mes "back home? Please? I miss";
			mes "my mommy and my daddy and";
			mes "I don't know how I got here.";
			mes "^333333*Sniff*^000000";
			next;
			switch(select("What can I do?:You can't go back...")) {
			case 1:
				mes "[Alakina Ann]";
				mes "I dunno. I-I think a ";
				mes "singing man told me to";
				mes "go meet a witch, but it's";
				mes "too scary to go outside...";
				set sign_sq,2;
				close;
			case 2:
				mes "[Alakina Ann]";
				mes "^333333*Sniff*^000000";
				mes "N-no...";
				mes "I wanna go home...";
				close2;
				emotion ET_CRY;
				end;
			}
		}
		else if (sign_sq == 2) {
			mes "[Alakina Ann]";
			mes "^333333*Cries*^000000";
			mes "Where am I?";
			mes "I... I wanna go home~";
			emotion ET_CRY;
			close;
		}
		else if ((sign_sq == 3) || (sign_sq == 4)) {
			if (countitem(7309) > 0) {
				mes "[Alakina Ann]";
				mes "I... I can use";
				mes "this to go back home?";
				mes "Thank you! Thank you so much!";
				delitem 7309,countitem(7309); //Wing_Of_Crow
				set sign_sq,5;
				close;
			}
			else {
				mes "[Alakina Ann]";
				mes "How am I gonna";
				mes "find that witch?";
				mes "She's the only one";
				mes "who knows how to";
				mes "get me back home...";
				mes "^333333*Cries*^000000";
				emotion ET_CRY;
				close;
			}
		}
		else if (sign_sq == 5) {
			mes "[Alakina Ann]";
			mes "Y-you lied to me!";
			mes "This wing doesn't do";
			mes "anything! I-I'm still here";
			mes "in this scary place! ^333333*Cries*^000000";
			set sign_sq,6;
			emotion ET_CRY;
			close;
		}
		else {
			mes "[Alakina Ann]";
			mes "You said that you";
			mes "could help me get home,";
			mes "but you didn't help me";
			mes "at all. Y-you lied to me!";
			mes "I... I hate you! ^333333*Wah~!*^000000";
			emotion ET_CRY;
			close;
		}
	}
	else {
		mes "[Alakina Ann]";
		mes "^333333*Cries*^000000";
		mes "Where am I?";
		mes "I... I wanna go home~";
		emotion ET_CRY;
		close;
	}
	end;
}

function	script	F_SignSeal	{
	function F_SealFail;
	function F_SealFail {
		mes "^3355FFYou hit the seal as hard";
		mes "as you can with the weapon in your hand. However, the seal is merely shaken by the force of your blow. Perhaps you need something";
		mes "more powerful to break the seal...^000000";
		close;
	}
	.@r = getarg(0);
	if (countitem(1558) || countitem(1963)) {
		if (.@r < 980) F_SealFail; }
	else if (countitem(1227) || countitem(1228) || countitem(1240) || countitem(1241) || countitem(1962) || countitem(1813)) {
		if (.@r < 960) F_SealFail; }
	else if (countitem(1719) || countitem(1130) || countitem(1133) || countitem(1223) || countitem(1229) || countitem(1231) || countitem(1413) || countitem(1814) || countitem(1242)) {
		if (.@r < 940) F_SealFail; }
	else if (countitem(1131) || countitem(1230) || countitem(1232)) {
		if (.@r < 920) F_SealFail; }
	else if (countitem(1132) || countitem(1134) || countitem(1233) || countitem(1234) || countitem(1235) || countitem(1414) || countitem(1523) || countitem(1236)) {
		if (.@r < 900) F_SealFail; }
	else if (countitem(1237) || countitem(1524) || countitem(1525) || countitem(1557) || countitem(1415) || countitem(1964)) {
		if (.@r < 880) F_SealFail; }
	else if (countitem(1135) || countitem(1140) || countitem(1141) || countitem(1527)) {
		if (.@r < 860) F_SealFail; }
	else if (countitem(1164) || countitem(1165) || countitem(1467) || countitem(1138) || countitem(1139) || countitem(1224) || countitem(1225) || countitem(1416) || countitem(1526)) {
		if (.@r < 840) F_SealFail; }
	else if (countitem(1305) || countitem(1720) || countitem(1136) || countitem(1137) || countitem(1166)) {
		if (.@r < 820) F_SealFail; }
	else if (countitem(1261) || countitem(1528) || countitem(1167)) {
		if (.@r < 800) F_SealFail; }
	else if (countitem(1364) || countitem(1913)) {
		if (.@r < 780) F_SealFail; }
	else if (countitem(1170) || countitem(1468) || countitem(1168) || countitem(1169)) {
		if (.@r < 760) F_SealFail; }
	else if (countitem(1365) || countitem(1366) || countitem(1473)) {
		if (.@r < 740) F_SealFail; }
	else if (countitem(1367) || countitem(1368) || countitem(1466) || countitem(1469)) {
		if (.@r < 720) F_SealFail; }
	else if (countitem(1369) || countitem(1470)) {
		if (.@r < 700) F_SealFail; }
	else if (countitem(1722) || countitem(1471)) {
		if (.@r < 680) F_SealFail; }
	else if (countitem(1363)) {
		if (.@r < 660) F_SealFail; }
	else if (countitem(1530)) {
		if (.@r < 500) F_SealFail; }
	else {
		mes "^3355FFThe weapon you're holding";
		mes "right now doesn't look like it has any chance of breaking this seal. You'll definitely need something";
		mes "more powerful...^000000";
		close;
	}
	if (getarg(1,0)) {
		mes "^3355FFUpon obtaining the last piece";
		mes "of Agrboda's soul, all four soul pieces emitted a strange light, rose to the air and combined into";
		mes "a single transparent jewel.^000000";
		next;
		mes "^3355FFThe jewel floated";
		mes "down to your waiting";
		mes "hands, and you hear its";
		mes "voice speak directly into";
		mes "the depths of your heart...^000000";
		next;
		mes "[Agrboda's Soul]";
		mes "^333333I'm...";
		mes "I'm leaving my soul";
		mes "with you. Please guide";
		mes "me to the queen of the dead...^000000";
		delitem 7306,3; //Fragment_Of_Soul
		set sign_q,117;
		getitem 7307,1; //Whisper_Of_Soul
	}
	else {
		mes "^3355FFOnce you strike the seal,";
		mes "it cracks open and a flash of mysterious light floods out of it. Inside of the seal, you find a very peculiar object...^000000";
		next;
		mes "^3355FFYou have";
		mes "obtained a^6E7B8B";
		mes "Piece of Spirit^3355FF.^000000";
		getitem 7306,1; //Fragment_Of_Soul
	}
	return;
}

gl_dun02,262,265,0	script	Mysterious Energy#1	111,{
	callfunc "F_UpdateSignVars";
	set .@crash_s,rand(1,1000);
	if (sign_q == 101) {
		callfunc "F_SignSeal",.@crash_s;
		set sign_q,105;
		close;
	}
	else {
		mes "^3355FFYou sense a strange,";
		mes "mysterious energy emanating from this area. For some reason, this power strikes you with a faint feeling of sadness.^000000";
		close;
	}
}

// Angrboda's Seal 2 big 4 O'clock 270 198
gl_dun02,271,100,0	script	Mysterious Energy#2	111,{
	callfunc "F_UpdateSignVars";
	set .@crash_s,rand(1,1000);
	if ((sign_q == 102) || (sign_q == 104)) {
		callfunc "F_SignSeal",.@crash_s;
		if (sign_q == 102) set sign_q,106;
		else if (sign_q == 104) set sign_q,108;
		close;
	}
	else {
		mes "^3355FFYou sense a strange,";
		mes "mysterious energy emanating from this area. For some reason, this power strikes you with a faint feeling of sadness.^000000";
		close;
	}
}

// Angrboda's Seal 3 big 5 O'clock 268 32
gl_dun02,268,32,0	script	Mysterious Energy#3	111,{
	callfunc "F_UpdateSignVars";
	set .@crash_s,rand(1,1000);
	if ((sign_q == 103) || (sign_q == 105) || (sign_q == 108)) {
		callfunc "F_SignSeal",.@crash_s;
		if (sign_q == 103) set sign_q,107;
		else if (sign_q == 105) set sign_q,109;
		else if (sign_q == 108) set sign_q,112;
		close;
	}
	else {
		mes "^3355FFYou sense a strange,";
		mes "mysterious energy emanating from this area. For some reason, this power strikes you with a faint feeling of sadness.^000000";
		close;
	}
}

// Angrboda's Seal 4 big 7 O'clock 16 26
gl_dun02,16,26,0	script	Mysterious Energy#4	111,{
	callfunc "F_UpdateSignVars";
	set .@crash_s,rand(1,1000);
	if (sign_q == 109) {
		callfunc "F_SignSeal",.@crash_s;
		if (sign_q == 109) set sign_q,113;
		close;
	}
	else {
		mes "^3355FFYou sense a strange,";
		mes "mysterious energy emanating from this area. For some reason, this power strikes you with a faint feeling of sadness.^000000";
		close;
	}
}

// Angrboda's Seal 5 big 11 O'clock 42 251
gl_dun02,42,251,0	script	Mysterious Energy#5	111,{
	callfunc "F_UpdateSignVars";
	set .@crash_s,rand(1,1000);
	if ((sign_q == 106) || (sign_q == 112)) {
		callfunc "F_SignSeal",.@crash_s;
		if (sign_q == 106) set sign_q,110;
		else if (sign_q == 112) set sign_q,116;
		close;
	}
	else {
		mes "^3355FFYou sense a strange,";
		mes "mysterious energy emanating from this area. For some reason, this power strikes you with a faint feeling of sadness.^000000";
		close;
	}
}

// Angrboda's Seal 6 small 11 O'clock 123 234
gl_dun02,123,234,0	script	Mysterious Energy#6	111,{
	callfunc "F_UpdateSignVars";
	set .@crash_s,rand(1,1000);
	if (sign_q == 107) {
		callfunc "F_SignSeal",.@crash_s;
		if (sign_q == 107) set sign_q,111;
		close;
	}
	else if (sign_q == 116) {
		callfunc "F_SignSeal",.@crash_s,1;
		close;
	}
	else {
		mes "^3355FFYou sense a strange,";
		mes "mysterious energy emanating from this area. For some reason, this power strikes you with a faint feeling of sadness.^000000";
		close;
	}
}

// Angrboda's Seal 7 small 6 O'clock 140 72
gl_dun02,140,72,0	script	Mysterious Energy#7	111,{
	callfunc "F_UpdateSignVars";
	set .@crash_s,rand(1,1000);
	if ((sign_q == 110) || (sign_q == 111)) {
		callfunc "F_SignSeal",.@crash_s;
		if (sign_q == 110) set sign_q,114;
		else if (sign_q == 111) set sign_q,115;
		close;
	}
	else if (sign_q == 113) {
		callfunc "F_SignSeal",.@crash_s,1;
		close;
	}
	else {
		mes "^3355FFYou sense a strange,";
		mes "mysterious energy emanating from this area. For some reason, this power strikes you with a faint feeling of sadness.^000000";
		close;
	}
}

// Angrboda's Seal 8 very small 119 182
gl_dun02,119,182,0	script	Mysterious Energy#8	111,{
	callfunc "F_UpdateSignVars";
	set .@crash_s,rand(1,1000);
	if ((sign_q == 114) || (sign_q == 115)) {
		callfunc "F_SignSeal",.@crash_s,1;
		close;
	}
	else {
		mes "^3355FFYou sense a strange,";
		mes "mysterious energy emanating from this area. For some reason, this power strikes you with a faint feeling of sadness.^000000";
		close;
	}
}

que_sign01,46,56,0	script	Fountain#sign	111,{
	callfunc "F_UpdateSignVars";
	if (sign_q < 118) {
		mes "^3355FFThe water in this";
		mes "fountain looks clean";
		mes "enough to drink...^000000";
		next;
		switch(select("Drink.:Don't Drink.")) {
		case 1:
			mes "...";
			close2;
			percentheal -100,0;
			end;
		case 2:
			mes "...";
			close;
		}
	}
	else {
		mes "^3355FFThe water in this";
		mes "fountain looks clean";
		mes "enough to be bottled...^000000";
		next;
		switch(select("Bottle the water.:Don't bottle the water.")) {
		case 1:
			if (checkweight(1201,1) == 0) {
				mes "^3355FFUnfortunately, it";
				mes "looks like you don't";
				mes "have enough inventory";
				mes "space to carry any more items...^000000";
				close;
			}
			else {
				if (countitem(713) > 0) {
					delitem 713,1; //Empty_Bottle
					getitem 12020,1; //Water_Of_Darkness
					close;
				}
				else {
					mes "^3355FFUnfortunately, it";
					mes "looks like you don't";
					mes "have any Empty Bottles";
					mes "to carry any of this water... ^000000";
					close;
				}
			}
		case 2:
			mes "...";
			close;
		}
	}
}

geffen,119,55,0	script	Dreamland Warp	45,1,1,{
OnInit:
	disablenpc "Dreamland Warp";
	end;

OnTouch_:
	// .@Dreamland_warp = rand(1,4);
	// if (.@Dreamland_warp == 1) warp "gefenia01",58,169;
	// else if (.@Dreamland_warp == 2) warp "gefenia02",116,115;
	// else if (.@Dreamland_warp == 3) warp "gefenia03",130,206;
	// else if (.@Dreamland_warp == 4) warp "gefenia04",133,88;
	// // Unreachable, but original code is like this [Lemongrass]
	// else warp "geffen",116,115;
	// Biali
	if(BaseLevel < 220) {
		pushpc 2,6;
		end;
	}
	warp "dreamland",0,0;
	end;

OnEnable:
	initnpctimer;
	enablenpc "Dreamland Warp";
	specialeffect EF_MAPPILLAR2;
	end;

OnDisable:
	disablenpc "Dreamland Warp";
	end;

OnTimer10000:
OnTimer20000:
OnTimer30000:
OnTimer40000:
	specialeffect EF_MAPPILLAR2;
	end;

OnTimer45000:
	donpcevent "Dreamland Warp::OnDisable";
	mapannounce "geffen","The portal to Dreamland is now closed.",bc_map,"0x9CFF00";
	stopnpctimer;
	end;

// TEMPORARY FIX
// OnMinute00:
// 	if(gettime(DT_HOUR)%2 == 1) {
// 		announce "With a flash of light from Geffen Fountain, the door to Dreamland has opened.",bc_blue|bc_all;
// 		callsub OnEnable;
// 	}
// 	end;
// END
}

geffen,119,48,0	script	Fountain#s	111,{
	callfunc "F_UpdateSignVars";
	if (countitem(7025) > 0) {
		mes "^3355FFAs you approach the fountain,";
		mes "a strange light begins to emit from the Lucifer's Lament in your pocket and from something deep within";
		mes "the fountain's water.^000000";
		specialeffect EF_LEVEL99;
		specialeffect2 EF_LEVEL99;
		next;
		switch(select("Throw Lucifer's Lament into the fountain.:Ignore the light.")) {
		case 1:
			mapannounce "geffen","With a flash of light from Geffen Fountain, the door to Dreamland has opened.",bc_map,"0x9CFF00";
			mes "^3355FFOnce the Lucifer's Lament";
			mes "splashes into the water, the";
			mes "light reveals a peculiar warp";
			mes "in front of the fountain...^000000";
			specialeffect EF_MAPPILLAR2;
			donpcevent "Dreamland Warp::OnEnable";
			close;
		case 2:
			mes ".......";
			close;
		}
	}
	else {
		mes "^3355FFThis is the";
		mes "Geffen Fountain.^000000";
		close;
	}
}

que_sign01,196,44,0	script	Starter#serin	-1,32,32,{
OnTouch_:
	donpcevent "Timer#serin::OnStart";
	disablenpc "Starter#serin";
	end;

OnEnable:
	enablenpc "Starter#serin";
	end;
}

que_sign01,196,44,0	script	Warp#serin	-1,35,35,{
OnDisable:
OnInit:
	disablenpc "Warp#serin";
	end;

OnTouch_:
	warp "niflheim",30,156;
	end;

OnEnable:
	enablenpc "Warp#serin";
	end;
}

que_sign01,1,0,0	script	Timer#serin	-1,{
OnStart:
	initnpctimer;
	end;

OnTimer600000:
	donpcevent "Warp#serin::OnEnable";
	end;

OnTimer620000:
	set $@sign_w2,0;
	donpcevent "Starter#serin::OnEnable";
	donpcevent "Warp#serin::OnDisable";
	donpcevent "Serin#serin::OnEnable";
	donpcevent "Dark Lord#serin::OnDisable";
	donpcevent "Serin#dummy::OnDisable";
	donpcevent "CallMonster#serin::OnReset";
	stopnpctimer;
	end;
}

que_sign01,50,1,0	script	CallMonster#serin	-1,{
Oncall:
	monster "que_sign01",196,44,"Dark Lord Incarnation",1605,1,"CallMonster#serin::OnMyMobDead";
	end;

OnMyMobDead:
	if (mobcount("que_sign01","CallMonster#serin::OnMyMobDead") < 1)
		donpcevent "Serin#serin::OnEnable";
	end;

OnReset:
	killmonster "que_sign01","CallMonster#serin::OnMyMobDead";
}

que_sign01,197,195,0	script	Starter#witch	-1,32,32,{
OnTouch_:
	donpcevent "Timer#witch::OnStart";
	disablenpc "Starter#witch";
	end;

OnEnable:
	enablenpc "Starter#witch";
	end;
}

que_sign01,1,1,0	script	Timer#witch	-1,{
OnStart:
	initnpctimer;
	end;

OnTimer600000:
	donpcevent "Warp#witch::OnEnable";
	end;

OnTimer620000:
	donpcevent "Starter#witch::OnEnable";
	donpcevent "Warp#witch::OnDisable";
	donpcevent "CallMonster#witch::OnReset";
	donpcevent "Serin#witch::OnEnable";
	set $@sign_w1,0;
	stopnpctimer;
	end;
}

que_sign01,197,195,0	script	Warp#witch	-1,35,35,{
OnDisable:
OnInit:
	disablenpc "Warp#witch";
	end;

OnEnable:
	enablenpc "Warp#witch";
	end;

OnTouch_:
	warp "niflheim",30,156;
	end;
}

que_sign01,1,2,0	script	CallMonster#witch	-1,{
Oncall:
	monster "que_sign01",196,195,"Dark Lord Incarnation",1605,1,"CallMonster#witch::OnMyMobDead";
	monster "que_sign01",180,180,"Ancient Mummy",1522,1,"CallMonster#witch::OnMyMobDead";
	monster "que_sign01",210,210,"Ancient Mummy",1522,1,"CallMonster#witch::OnMyMobDead";
	monster "que_sign01",200,200,"Ancient Wraith",1475,1,"CallMonster#witch::OnMyMobDead";
	monster "que_sign01",200,180,"Ancient Wraith",1475,1,"CallMonster#witch::OnMyMobDead";
	monster "que_sign01",180,200,"Rotten Corpse",1423,1,"CallMonster#witch::OnMyMobDead";
	monster "que_sign01",205,205,"Rotten Corpse",1423,1,"CallMonster#witch::OnMyMobDead";
	monster "que_sign01",190,190,"Rotten Corpse",1423,1,"CallMonster#witch::OnMyMobDead";
	monster "que_sign01",205,190,"Rotten Corpse",1423,1,"CallMonster#witch::OnMyMobDead";
	monster "que_sign01",190,205,"Rotten Corpse",1423,1,"CallMonster#witch::OnMyMobDead";
	end;

OnMyMobDead:
	if (mobcount("que_sign01","CallMonster#witch::OnMyMobDead") < 1) {
		donpcevent "Serin#witch::OnEnable";
	}
	end;

OnReset:
	killmonster "que_sign01","CallMonster#witch::OnMyMobDead";
	end;
}

que_sign02,0,0	monster	Ancient Mummy	1522,8
que_sign02,0,0	monster	Evil Druid	1435,8
que_sign02,0,0	monster	Ghoul	1423,20
que_sign02,0,0	monster	Incubus	1580,8
que_sign02,0,0	monster	Injustice	1446,8
que_sign02,0,0	monster	Skeleton Prisoner	1479,15
que_sign02,0,0	monster	Zombie Prisoner	1480,15
que_sign02,0,0	monster	Wraith	1475,15
que_sign02,0,0	monster	Wraith Dead	1566,8

que_sign02,378,235,0	script	sign_w6	45,1,1,{
OnTouch_:
	callfunc "F_UpdateSignVars";
	if ((countitem(7313) == 1) && ((sign_q != 124) || (sign_q != 125) || (sign_q != 126))) {
		warp "que_sign01",197,190;
		end;
	}
	if ($@sign_w1 == 1) {
		mes "^3355FFSome sort of";
		mes "strange force";
		mes "is blocking you";
		mes "from entering.^000000";
		close;
	}
	else {
		set $@sign_w1,1;
		warp "que_sign01",197,190;
		end;
	}
}

function	script	F_UpdateSignVars	{
	if (!sign_q) {
		// Attempt to save current progress, to some degree...
		// P.S. I want to slit someone's throat.

		// Attmept to save using the main (old) tracting variable
		if (signquest <= 4) { set sign_q,signquest; }
		// ariantest = 5-11
		// gaanantest = 12 & 13
		else if (signquest == 5) { set sign_q,14; }
		else if (signquest == 6) { set sign_q,15; }
		// SighJore = 16
		else if (signquest == 7) { set sign_q,17; }
		// ScareAlchSign = 18
		else if (signquest == 8) { set sign_q,19; }
		else if (signquest == 9) { set sign_q,20; }
		// There is noequivilent for sign_q 21-24
		else if (signquest == 10) { set sign_q,25; }
		// There is noequivilent for sign_q 26
		else if (signquest == 11) { set sign_q,27; }
		// deales_test = 28-30
		// 31 is not used.
		// SignDance = 32 & 33
		// there is no equivilent to sign_q 34
		else if (signquest == 12) { set sign_q,35; }
		// bakerlan_test - 36-42
		// there is no equivilent to sign_q 43-45
		// bakerlan_test - 46-52
		else if (signquest == 13) { set sign_q,53; }
		else if ((signquest >= 14) && (signquest <= 15)) { set sign_q,54; }
		else if ((signquest >= 16) && (signquest <= 18)) { set sign_q,signquest+39; }
		// signanvil = 58-61
		else if ((signquest == 19) && (countitem(7278))) { set sign_q,61; }
		// there is no equivilent to sign_q 62-64
		else if (signquest == 20) { set sign_q,65; }
		// there is no equivilent to sign_q 66-68
		else if (signquest == 21) { set sign_q,69; }
		else if ((signquest >= 22) && (signquest <= 28)) { set sign_q,signquest+48; } // 70-76
		// there is no equivilent to sign_q 77
		else if ((signquest >= 29) && (signquest <= 34)) { set sign_q,signquest+49; } // 78-83
		else if (signquest == 35) { set sign_q,83; set sign_sq,1; }
		else if (signquest == 36) { set sign_q,83; set sign_sq,1; }
		else if (signquest == 37) { set sign_q,83; set sign_sq,2; }
		else if (signquest == 38) { set sign_q,83; set sign_sq,3; }
		// there is no equivilent to sign_sq 4
		else if (signquest == 39) { set sign_q,83; set sign_sq,5; }
		else if (signquest == 40) { set sign_q,83; set sign_sq,6; }
		else if (signquest == 41) { set sign_q,83; set sign_sq,7; }
		else if (signquest == 42) { set sign_q,83; set sign_sq,8; }
		// there is no equivilent to sign_q 84
		else if ((signquest >= 43) && (signquest <= 48)) { set sign_q,signquest+42; } // 85-90
		// 91-92
		else if ((signquest >= 49) && (signquest <= 52)) { set sign_q,signquest+44; } // 93-96
		// signlaichin97-99
		else if (signquest == 53) { set sign_q,100; }
		// 101-116
		else if (signquest == 54) { set sign_q,117; }
		else if (signquest == 55) { set sign_q,118; }
		// 119-126
		else if (signquest == 56) { set sign_q,127; }
		// 128
		else if (signquest == 57) { set sign_q,129; }
		else if (signquest == 58) { set sign_q,130; }
		// 131-136
		else if ((signquest >= 59) && (signquest <= 66)) { set sign_q,signquest+78; } // 137-144
		// 144-199

		// Attmept to save using the intermediate variables.
		if (sign_fail == 1) { set sign_q,200; }
		else if (sign_fail >= 2) { set sign_q,201; }

		if (ariantest >= 2) { set sign_q,ariantest+3; }
		if (gaanantest == 1) { set sign_q,12; }

		if (SignJore == 1) { set sign_q,16; }
		if (ScareAlchSign == 1) { set sign_q,18; }

		if (dearles_test == 1) { set sign_q,28; }
		else if (dearles_test == 2) { set sign_q,29; }
		else if (dearles_test == 3) { set sign_q,30; }

		if (SignDance == 1) { set sign_q,32; }
		else if (SignDance == 2) { set sign_q,33; }

		if ((bakerlan_test >= 1) && (bakerlan_test <= 3)) { set sign_q,bakerlan_test+35; }
		else if ((bakerlan_test >= 4) && (bakerlan_test <= 6)) { set sign_q,bakerlan_test+36; }
		else if ((bakerlan_test >= 7) && (bakerlan_test <= 13)) { set sign_q,bakerlan_test+39; }

		if ((signanvil >= 1) && (signanvil <= 4)) { set sign_sq,signanvil+57; }

		// Because of the horrible way this was scripted, it's incompatable
		// With the new script, So I am resetting the quest to the start
		// of this step.
		if (signlaichin >= 1) { 
			mes "^FF0000You stumble and drop the your^000000";
			if (countitem(7306)) {
				mes "^FF0000"+getitemname(7306)+"^000000";
			}
			if (countitem(7306) && countitem(7307)) {
				mes "^FF0000and^000000";
			}
			if (countitem(7307)) {
				mes "^FF0000"+getitemname(7307)+"^000000";
			}
			mes "^FF0000pieces on the ground and they vanish! Perhaps you should talk to Lachin.^000000";
			delitem 7306,countitem(7306); //Fragment_Of_Soul
			delitem 7307,countitem(7307); //Whisper_Of_Soul
			set sign_q,rand(97,100); 
		}

		// Same BS as above, unable to save pickup time for 'The Sign' from Engel.
		if (signengelhour) { 
			mes "^FF0000You see that Engel has forgotten to look at 'The Sign', how you got it back is a mystery too you, but you should remind Engel that he needs to look at it.^000000";
			getitem 7314,1; //The_Sign
			set sign_q,139;
		}

		if (Sign_Branch8A == 1) { set sign_q,119; }
		else if (Sign_Branch8A == 2) { set sign_q,120; }
		else if (Sign_Branch8A == 3) { set sign_q,122; }
		else if (Sign_Branch8A == 4) { set sign_q,124; }
		else if (Sign_Branch8A == 5) { set sign_q,134; }
		else if ((Sign_Branch8A == 7) || (Sign_Branch8A == 8)) { set sign_q,126; }

		// Incompatable with the new version.
		if (Sign_Branch8B > 0) {
			mes "^FF0000Something is wrong, perhaps you should go talk to Serin again.^000000";
			set sign_q,132;
		}

		// Incompatable with the new version. Again.
		if (Sign_Branch2B) {
			set sign_q,91;
		}

		// Unable to save when the Sign should be picked up from Metz
		if (signmetzhour) { 
			mes "^FF0000You see that Metz has forgotten to look at 'The Sign', how you got it back is a mystery too you, but you should remind Metz that he needs to look at it.^000000";
			getitem 7314,1; //The_Sign
			set sign_q,138;
		}

		// Clear old variables.
		set signquest,0;
		set sign_fail,0;
		set gaananpoint,0;
		set gaanantest,0;
		set ariantest,0;
		set SignJore,0;
		set ScareAlchSign,0;
		set dearles_test,0;
		set SignDance,0;
		set bakerlan_test,0;
		set signanvil,0;
		set signengelhour,0;
		set signlaichin,0;
		set Sign_Seal1,0;
		set Sign_Seal2,0;
		set Sign_Seal3,0;
		set Sign_Seal4,0;
		set Sign_Seal1$,"";
		set Sign_Seal2$,"";
		set Sign_Seal3$,"";
		set Sign_Seal4$,"";
		set brokenseal,0;
		set Sign_Branch8A,0;
		set Sign_Branch8B,0;
		set Sign_Branch2B,0;
		set serinring,0;
		set signmetzhour,0;
	}
	return;
}

prt_castle,107,58,5	duplicate(Soldier#s11_)	Soldier#s11	8W_SOLDIER

