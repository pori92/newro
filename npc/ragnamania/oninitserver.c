-	script	SERVERSTART	-1,{
OnInit:
	set $@MAXLEVEL, 70;
	set $@MAXLEVEL1ST, 65;
	// Status Points up to lvl 99 for the Multiclass Load_Build function
	setarray $@sp[1],48,51,54,57,60,64,68,72,76,80,85,90,95,100,105,111,117,123,129,135,142,149,156,163,170,178,186,194,202,210,219,228,237,246,255,265,275,285,295,305,316,327,338,349,360,372,384,396,408,420,433,446,459,472,485,499,513,527,541,555,570,585,600,615,630,646,662,678,694,710,727,744,761,778,795,813,831,849,867,885,904,923,942,961,980,1000,1020,1040,1060,1080,1101,1122,1143,1164,1185,1207,1229,1251,1273;

	set $@JC_Plat, 1; //Give Platinum skills on Jobchange (Default : 1-yes)
	set $@JC_SupNovM, 1; //Base Level to change into Super Novice (Default : 45)
	setcell "abyss_01",161,186,171,176,cell_basilica,1; // Basilica em Abyss
	setcell "gl_sew01",256,15,261,10,cell_basilica,1; 	// Basilica em Glast Sewers
	
	// Constantes com as coordenadas das entradas das casas
	// Midgardians (rent_mb)
	// Localizacao do warp que leva da praca para o patio da casa
	setarray $@HDWarpMx[0],106,78,40,40,40,40,40,40,49,77,105,133,161,189,217,225,225,225,225,225,225,189,161,108,108,159,159;
	setarray $@HDWarpMy[0],42,42,49,77,105,133,161,189,225,225,225,225,225,225,225,188,160,132,104,76,48,42,42,108,159,159,108;
	
	// Localizacao do Respawn quando sai do patio da casa para a praca
	setarray $@HDRespMx[0],106,78,44,44,44,44,44,44,48,77,105,133,161,189,217,220,220,220,220,220,220,189,161,113,113,155,155;
	setarray $@HDRespMy[0],47,47,49,76,105,133,161,189,220,220,220,220,220,220,220,188,160,132,104,76,48,47,47,113,154,155,114;	
	
	// *** Uncommend these line to setup regions when the server runs for
	// *** the first time after a wipe.
	//	set $Region[23],1; // Midgardian Village
	//	set $Region[24],2; // Baldurian Village
	
	// Coordenadas dos Guardas na entrada das vilas
	// Midgardians Village
	setarray $@mx[0],154,158,162,166,170,174,178,182,186,190,194,198,202,206,210,214,218,222,226,230,234,238,242,246;
	setarray $@my[0],13;
	//Baldurians Village
	setarray $@bx[0],114,110,106,102,98,94,90,86,82,78,74,70,66,62,58,54,50,46,42,38,34,30,26;
	setarray $@by[0],12;


	
	// *****************************
	// Arrays for Oblivion Box
	// *****************************
	//	Job_Swordman	1
	setarray $@SwordmanFoot[0],2402,2404,2405,2406,2407,2408,2409,2419,2417,2418;
	setarray $@SwordmanArmor[0],2303,2304,2305,2306,2308,2310,2312,2313,2320,2322,2339,2311,2316,2317,2344,2345,2346,2347,2348,2350,2354,2319,2353;
	setarray $@SwordmanNeck[0],2502,2504,2506,2508,2522,2518,2507,2520,2536,2519,2516,2517;
	setarray $@SwordmanHead[0],2209,2221,2227,2229,2236,2244,2245,2250,2254,2255,2274,2282,2287,2289,2294,2299,5003,5009,5116,5172,5141,5126,2234,5128,5111,5127,5122,5124;
	//	Job_Mage		2
	setarray $@MageFoot[0],2402,2404,2407,2408,2409,2422,2419,2417,2418;
	setarray $@MageArmor[0],2303,2304,2305,2306,2308,2310,2320,2322,2333,2339,2311,2345,2347,2334,2354,2319,2353;
	setarray $@MageNeck[0],2502,2504,2508,2522,2518,2507,2520,2536,2519,2516,2517;
	setarray $@MageHead[0],2209,2221,2233,2236,2244,2245,2285,2250,2252,2254,2255,2274,2282,2287,2289,2294,5003,5009,5027,5116,5172,5141,5126,2234,5045,5128,5111,5127,5122,5123,5124;
	//	Job_Archer		3
	setarray $@ArcherFoot[0],2402,2404,2405,2406,2407,2408,2409,2419,2417,2418;
	setarray $@ArcherArmor[0],2303,2304,2305,2306,2308,2310,2320,2322,2339,2311,2331,2345,2347,2354,2319,2353;
	setarray $@ArcherNeck[0],2502,2504,2508,2522,2518,2507,2520,2536,2519,2516,2517;
	setarray $@ArcherHead[0],2209,2221,2227,2236,2244,2245,2285,2254,2255,2274,2282,2287,2289,2294,5003,5009,5116,5172,5141,5126,2234,5128,5111,5127,5122,5123,5124;
	//	Job_Acolyte		4
	setarray $@AcolyteFoot[0],2402,2404,2407,2408,2409,2422,2419,2417,2418;
	setarray $@AcolyteArmor[0],2303,2304,2305,2306,2308,2310,2320,2322,2326,2339,2311,2345,2347,2354,2319,2327,2353;
	setarray $@AcolyteNeck[0],2502,2504,2508,2522,2518,2507,2520,2536,2519,2516,2517;
	setarray $@AcolyteHead[0],2217,2221,2236,2244,2245,2251,2254,2285,2255,2274,2277,2282,2287,2289,2294,5003,5009,5116,5141,5126,2234,5045,5128,5111,5127,5122,5123,5124;
	//	Job_Merchant	5
	setarray $@MerchantFoot[0],2402,2404,2405,2406,2407,2408,2409,2422,2419,2417,2418;
	setarray $@MerchantArmor[0],2303,2304,2305,2306,2308,2310,2312,2313,2320,2322,2326,2329,2339,2311,2344,2345,2346,2347,2348,2350,2354,2319,2353,2318;
	setarray $@MerchantNeck[0],2502,2504,2505,2506,2508,2522,2518,2507,2520,2536,2519,2516,2517;
	setarray $@MerchantHead[0],2209,2221,2227,2229,2236,2244,2245,2250,2254,2255,2274,2282,2287,2289,2294,2299,5003,5009,5116,5172,5141,5126,2234,5128,5111,5127,5122,5124;
	//	Job_Thief		6
	setarray $@ThiefFoot[0],2402,2404,2405,2406,2407,2408,2409,2419,2417,2418;
	setarray $@ThiefArmor[0],2303,2304,2305,2306,2308,2310,2312,2313,2320,2336,2339,2311,2345,2346,2347,2337,2354,2319,2353;
	setarray $@ThiefNeck[0],2502,2504,2505,2506,2508,2522,2518,2507,2520,2536,2519,2516,2517;
	setarray $@ThiefHead[0],2209,2221,2227,2236,2244,2245,2254,2255,2274,2282,2287,2289,2294,2299,5003,5009,5116,5172,5141,5126,2234,5128,5111,5002,5127,5122,5123,5124;

	// Armas sao por tipo de arma e nao por classe

	//	Axes (one and two handed axes. the 4 first ones are one handed)
	//	setarray .OB_Axes[0],1301,1302,1307,1304,1352,1355,1358,1361,1364;

		// Spears
		//one hand and two hands (only the 3 first ones are one-handed)
	//	setarray .OB_Weapons[0],1402,1405,1408,1451,1452,1454,1455,1458,1460,1461,1464,1466,1471,1478;

		// Swords
		//one hand
	//	setarray .OB_Weapons[0],1104,1105,1108,1111,1114,1125,1220,1127,1147,1144,1130,1133,1148,13404,13405;
		//two-hands
	//	setarray .OB_Weapons[0],1116,1117,1152,1155,1158,1162,1163,1164,1165,1167,1168,1170;

		// Books
	//	setarray .OB_Weapons[0],1550,1551,1553,1554,1555,1556,1560,1572,1557,1558,1561;

		//Bow
	//	setarray .OB_Weapons[0],1701,1702,1705,1708,1711,1723,1715,1716,1730,1731,1732,1733,1720,1724,1734;

		// Dagger
	//	setarray .OB_Weapons[0],1201,1202,1205,1206,1207,1208,1249,13011,1211,1214,1216,1217,13012,13013,13008,1219,1220,1226,1246,13014,13015,13004,1239,13006,1223,1228,1229,1234,1236,1237,1242,13001;

		// Fist
	//	setarray .OB_Weapons[0],1801,1802,1806,1810,1812,1822,1814;

		// Katar
	//	setarray .OB_Weapons[0],1264,1251,1253,1255,1256,1257,1258,1259,1262,1260;

		// Maces
	//	setarray .OB_Weapons[0],1501,1502,1505,1508,1510,1511,1519,1520,1513,1514,1517,1531,1523,1527,1528,1541;

		// Instruments
	//	setarray .OB_Weapons[0],1902,1904,1906,1908,1909,1910,1914,1915,1916,1917,1918;

		// Staffs
	//	setarray .OB_Weapons[0],1602,1604,1605,1608,1611,1613,1614,1615,1618,1620,1622,1630,1625,1616,1629;

		// Guns
	//	setarray .OB_Weapons[0],13150,13101,13152,13156,13103,13160,13161,13104,13153,13106;

		// Shurikens
	//	setarray .OB_Weapons[0],13301,13302,13303,13300;

		//Whips
	//	setarray .OB_Weapons[0],1951,1957,1965,1966,1967,1968,1971,1969,1962,1964,1970;

		//Guards (1 e 2 sao guards / buckler / shield(e/k/c) / shield(e/k/c/sg) / supernovice guard / Valk shield(todas classes))
	//	setarray .OB_Weapons[0],2101,2102,2104,2106,2108,2116,2115;


	//	Job_Knight		7
	//	Job_Priest		8
	//	Job_Wizard		9
	//	Job_Blacksmith	10
	//	Job_Hunter		11
	//	Job_Assassin	12
	//	Job_Knight2		13
	//	Job_Crusader	14
	//	Job_Monk		15
	//	Job_Sage		16
	//	Job_Rogue		17
	//	Job_Alchemist	18
	//	Job_Bard		19
	//	Job_Dancer		20
	//	Job_Crusader2	21
	//	Job_Wedding		22
	//	Job_SuperNovice	23
	//	Job_Gunslinger	24
	//	Job_Ninja		25	

	end;
}