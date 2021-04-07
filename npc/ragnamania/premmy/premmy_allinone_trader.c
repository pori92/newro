//===== rAthena Script =======================================
//= Shop Street
//===== By: ==================================================
//= Masao(Shopstreet) - Original Mall Script
//= Virtue(All in 1 Mall NPC)
//===== Current Version: =====================================
//= 1.0 [Masao]
//===== Compatible With: =====================================
//= rAthena SVN
//= Judas SVN
//===== Description: =========================================
// Street Mall in One NPC
// Change "Your Server Name" to your Server Name or whhat ever you desire"
//============================================================
sala_premmy,42,49,2	script	Quick Mall	556,{
	callfunc "allinonemall";
	end;
}

function	script	allinonemall	{
	if ( vip_status(VIP_STATUS_ACTIVE) == false ) end; 
	mes "[Quick Mall]";
	mes "Hello there ^FF0000" + strcharinfo(0) + "^000000.";
	mes "Please select what you want";
	next;
	switch(select("^FF0000Sell Items^000000:Consumables:Miscellaneous:Arrows:Ninja:Gunslinger:Pet Foods:Pet Accessories:Tools")) {
	close2;
	case 1: callshop "Tools", 2; end;
	case 2: callshop "Consumables", 1; end;
	case 3: callshop "Miscellaneous", 1; end;
	case 4: callshop "Arrows", 1; end;
	case 5: callshop "Ninja", 1; end;
	case 6: callshop "Gunslinger", 1; end;
	case 7: callshop "Pet Foods", 1; end;
	case 8: callshop "Pet Accessories", 1; end;
	case 9: callshop "Tools", 1; end;
	}
}
//shops

-	shop	Tools	-1,501:-1
-	shop	Consumables	-1,601:60,602:300,506:40,547:5000,545:300,645:1000,656:1500,657:3000,1065:100,522:8500,610:5000,12070:15000,14579:15000,12045:15000,12050:15000,12055:15000,12060:15000
-	shop	Miscellaneous	-1,985:50000,984:50000,715:600,717:600,716:600,999:5000,1000:5000,990:5000,991:5000,992:5000,993:5000,994:20000,995:20000,996:20000,997:20000,1025:2000,612:2000,613:3000,614:5000,615:10000,929:5000,1059:5000
-	shop	Arrows	-1,1750:2,1751:3,1766:50,1767:30,1755:5,1754:5,1761:30,1752:3,1759:30,1765:50,1764:50,1753:20,1756:5,1757:5,1758:30
-	shop	Ninja	-1,13250:4,13252:20,13253:40,13254:100,2117:10000,7522:150,7523:150,7524:300
-	shop	Gunslinger	-1,13150:3000,13102:20000,13151:17500,13154:12000,13155:32000,13163:40000,13165:56000,13168:76000,13200:1,13201:15,13202:30
-	shop	Pet Foods	-1,508:40,511:10,507:18,537:1000,534:10000,531:10000,1002:20000,532:20000,7766:20000,7824:20000,6098:20000,6108:20000,6106:20000,6105:20000,12192:20000,5065:20000,6094:20000
-	shop	Pet Accessories	-1,10012:20000,10002:20000,10015:20000,10003:20000,10014:20000,10017:20000,10010:20000,10003:20000,10019:20000,10018:20000,10009:20000,10008:20000,10006:20000,10011:20000,10020:20000,10035:20000,10025:20000,10032:20000,10027:20000,10028:20000,10037:20000,10034:20000,10026:20000,10030:20000,10029:20000,10033:20000,10031:20000,10024:20000,10022:20000,10023:20000,10021:20000,10038:20000