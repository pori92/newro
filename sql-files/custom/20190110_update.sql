# Pendant of Harmony Effect
REPLACE INTO `item_db2_re` (`id`, `name_english`, `name_japanese`, `type`, `price_buy`, `price_sell`, `weight`, `atk:matk`, `defence`, `range`, `slots`, `equip_jobs`, `equip_upper`, `equip_genders`, `equip_locations`, `weapon_level`, `equip_level`, `refineable`, `view`, `script`, `equip_script`, `unequip_script`) VALUES
(2990, 'Pendant_Of_Harmony', 'Pendant of Harmony', 4, 20, NULL, 100, NULL, 0, NULL, 0, 4294967295, 63, 2, 136, NULL, '130', NULL, NULL, 'bonus bMatkRate,6; bonus bHPrecovRate,50; bonus bSPrecovRate,50; bonus2 bSubEle,Ele_Holy,5; autobonus \"{ bonus2 bHPRegenRate,1000,1000; }\",100,5000,BF_NORMAL,\"{ specialeffect2 EF_ENHANCE; }\"; bonus4 bAutoSpellWhenHit,\"PR_SANCTUARY\",3,100,0; bonus bStr,-5;', NULL, NULL);

# Add white siege potion to the treasure
REPLACE INTO `mob_db2_re` (`ID`, `Sprite`, `kName`, `iName`, `LV`, `HP`, `SP`, `EXP`, `JEXP`, `Range1`, `ATK1`, `ATK2`, `DEF`, `MDEF`, `STR`, `AGI`, `VIT`, `INT`, `DEX`, `LUK`, `Range2`, `Range3`, `Scale`, `Race`, `Element`, `Mode`, `Speed`, `aDelay`, `aMotion`, `dMotion`, `MEXP`, `MVP1id`, `MVP1per`, `MVP2id`, `MVP2per`, `MVP3id`, `MVP3per`, `Drop1id`, `Drop1per`, `Drop2id`, `Drop2per`, `Drop3id`, `Drop3per`, `Drop4id`, `Drop4per`, `Drop5id`, `Drop5per`, `Drop6id`, `Drop6per`, `Drop7id`, `Drop7per`, `Drop8id`, `Drop8per`, `Drop9id`, `Drop9per`, `DropCardid`, `DropCardper`) VALUES
(2288, 'GLD_TREASURE', 'Treasure Chest', 'Treasure Chest', 140, 5, 0, 0, 0, 1, 0, 0, 100, 0, 0, 0, 0, 0, 1199, 0, 0, 0, 0, 0, 26, 102760448, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11547, 2000, 11503, 1000, 11504, 1000, 12675, 50, 7444, 50, 12680, 50, 11547, 2000, 1661, 10, 11548, 2000, 0, 0);

# fix sphere can't be equip
REPLACE INTO `item_db2_re` (`id`, `name_english`, `name_japanese`, `type`, `price_buy`, `price_sell`, `weight`, `atk:matk`, `defence`, `range`, `slots`, `equip_jobs`, `equip_upper`, `equip_genders`, `equip_locations`, `weapon_level`, `equip_level`, `refineable`, `view`, `script`, `equip_script`, `unequip_script`) VALUES
(13203, 'Flare_Sphere', 'Flare Sphere', 10, 80, NULL, 5, '50', NULL, NULL, NULL, 1090519040, 63, 2, 32768, NULL, NULL, NULL, 5, 'bonus bAtkEle,Ele_Fire;', NULL, NULL),
(13204, 'Lighting_Sphere', 'Lightning Sphere', 10, 80, NULL, 5, '50', NULL, NULL, NULL, 1090519040, 63, 2, 32768, NULL, NULL, NULL, 5, 'bonus bAtkEle,Ele_Wind;', NULL, NULL),
(13205, 'Poison_Sphere', 'Poison Sphere', 10, 80, NULL, 5, '50', NULL, NULL, NULL, 1090519040, 63, 2, 32768, NULL, NULL, NULL, 5, 'bonus bAtkEle,Ele_Poison; bonus2 bAddEff,Eff_Poison,500;', NULL, NULL),
(13206, 'Blind_Sphere', 'Blind Sphere', 10, 80, NULL, 5, '50', NULL, NULL, NULL, 1090519040, 63, 2, 32768, NULL, NULL, NULL, 5, 'bonus bAtkEle,Ele_Dark; bonus2 bAddEff,Eff_Blind,500;', NULL, NULL),
(13207, 'Freezing_Sphere', 'Freezing Sphere', 10, 80, NULL, 5, '50', NULL, NULL, NULL, 1090519040, 63, 2, 32768, NULL, NULL, NULL, 5, 'bonus bAtkEle,Ele_Water;', NULL, NULL),
(13223, 'Flare_Sphere_', 'Flare Sphere', 10, 15, NULL, 5, '50', NULL, NULL, NULL, 1090519040, 63, 2, 32768, NULL, NULL, NULL, 5, 'bonus bAtkEle,Ele_Fire;', NULL, NULL),
(13224, 'Lighting_Sphere_', 'Lightning Sphere', 10, 15, NULL, 5, '50', NULL, NULL, NULL, 1090519040, 63, 2, 32768, NULL, NULL, NULL, 5, 'bonus bAtkEle,Ele_Wind;', NULL, NULL),
(13225, 'Poison_Sphere_', 'Poison Sphere', 10, 15, NULL, 5, '50', NULL, NULL, NULL, 1090519040, 63, 2, 32768, NULL, NULL, NULL, 5, 'bonus bAtkEle,Ele_Poison;', NULL, NULL),
(13226, 'Blind_Sphere_', 'Blind Sphere', 10, 15, NULL, 5, '50', NULL, NULL, NULL, 1090519040, 63, 2, 32768, NULL, NULL, NULL, 5, 'bonus bAtkEle,Ele_Dark;', NULL, NULL),
(13227, 'Freezing_Sphere_', 'Freezing Sphere', 10, 15, NULL, 5, '50', NULL, NULL, NULL, 1090519040, 63, 2, 32768, NULL, NULL, NULL, 5, 'bonus bAtkEle,Ele_Water;', NULL, NULL);

REPLACE INTO `item_db2_re` (`id`, `name_english`, `name_japanese`, `type`, `price_buy`, `price_sell`, `weight`, `atk:matk`, `defence`, `range`, `slots`, `equip_jobs`, `equip_upper`, `equip_genders`, `equip_locations`, `weapon_level`, `equip_level`, `refineable`, `view`, `script`, `equip_script`, `unequip_script`) VALUES
(18572, 'Korean_Judge_Hat', 'Korean Judge Hat', 4, 20, NULL, 300, NULL, 2, NULL, 1, 4294967295, 63, 2, 256, NULL, '0', 1, 377, 'bonus bVariableCastrate,-6; bonus bAspdRate,6; .@r = getrefine(); if(.@r>6){ bonus2 bSubRace,RC_DemiHuman,2; bonus2 bSubRace,RC_Player,2; } if(BaseClass==Job_Swordman || BaseClass==Job_Merchant || BaseClass==Job_Thief || Class==Job_Taekwon || Class==Job_Star_Gladiator || Class==Job_Star_Gladiator2 || Class==Job_Monk || Class==Job_Champion || Class==Job_Sura || Class==Job_Sura_T) bonus2 bAddClass,Class_All,(.@r/2); if(BaseClass==Job_Mage || BaseClass==Job_Acolyte || Class==Job_Ninja || Class==Job_Soul_Linker) bonus bMatkRate,(.@r/2); if(BaseClass==Job_Archer || Class==Job_Gunslinger) bonus bLongAtkRate,.@r; if(vip_status(VIP_STATUS_ACTIVE)){ bonus bAllStats,1; bonus2 bSubRace,RC_DemiHuman,10; bonus2 bSubRace,RC_Player,10; }', NULL, NULL),
(18528, 'Tare_Neko_Cru', 'Drooping Neko Crew', 4, 20, NULL, 100, NULL, 0, NULL, 1, 4294967295, 63, 2, 256, NULL, '1', 1, 692, 'bonus bInt,2; bonus bMdef,5; .@r = getrefine(); bonus bMatkRate,(.@r>8) ? 7 : 2; .@i = (.@r>6)?10:5; bonus2 bIgnoreMdefClassRate,Class_Normal,.@i+.@r; bonus2 bIgnoreMdefClassRate,Class_Boss,.@i+.@r;', NULL, NULL);
(5462, 'Spiked_Scarf', 'Spiked Scarf', 4, 20, NULL, 100, NULL, 1, NULL, 0, 4294967295, 63, 2, 1, NULL, '90', 0, 459, 'bonus bAtk,30; bonus bMaxHPrate,-2; if(vip_status(VIP_STATUS_ACTIVE)){ bonus bAllStats,1; bonus2 bMaxHPrate,2; bonus2 bLongAtkRate,2; }', NULL, NULL),
(5463, 'Rainbow_Scarf', 'Rainbow Scarf', 4, 20, NULL, 0, NULL, 1, NULL, 0, 4294967295, 63, 2, 1, NULL, '90', 0, 460, 'bonus bMatk,30; bonus bMaxSPrate,-2; if(vip_status(VIP_STATUS_ACTIVE)){ bonus bAllStats,1; bonus2 bMaxSPrate,2; bonus bVariableCastrate,2; }', NULL, NULL),
(5597, 'Bubble_Gum_In_Mouth', 'Bubble Gum In Mouth', 4, 20, NULL, 0, NULL, 2, NULL, 0, 4294967295, 63, 2, 1, NULL, '1', 0, 572, 'bonus bBaseAtk,5; bonus bMatk,5; bonus bMdef,2; if(vip_status(VIP_STATUS_ACTIVE)){ bonus bAllStats,1; bonus2 bDropAddRace,RC_All,5; }', NULL, NULL),
(5286, 'Pecopeco_Hairband', 'Pecopeco Hairband', 4, 20, NULL, 0, NULL, 6, NULL, 0, 4294967295, 63, 2, 256, NULL, '70', 0, 314, 'bonus bSpeedRate,25; bonus bAspdRate,5; bonus bVariableCastrate,-5; if(vip_status(VIP_STATUS_ACTIVE)){ bonus bAllStats,1; }', NULL, NULL),


(22876, 'Old_Money_Pocket', 'Old Money Pocket', 2, 0, NULL, 0, NULL, NULL, NULL, NULL, 4294967295, 63, 2, NULL, NULL, NULL, NULL, NULL, 'Zeny += rand(500,550);', NULL, NULL),
(18597, 'Mercury_Helm', 'Mercury Riser', 4, 40, NULL, 200, NULL, 10, NULL, 1, 4294967295, 63, 2, 256, NULL, '0', 1, 759, 'bonus2 bSubRace,RC_DemiHuman,10; bonus2 bAddRace,RC_DemiHuman,10; bonus bAspdRate,3; bonus bDelayrate,-3; bonus bCritical,3; .@r = getrefine(); if(.@r >= 7) { bonus bAspdRate,2; bonus bDelayrate,-2; bonus bCritical,2; } if(.@r >= 9) { bonus bAspdRate,2; bonus bDelayrate,-2; bonus bCritical,2; }', NULL, NULL),
(18600, 'Cat_Ears_Beret', 'Cat Ear Beret', 4, 20, NULL, 100, NULL, 5, NULL, 1, 4294967295, 63, 2, 256, NULL, '0', 1, 761, 'bonus bAtkRate,5; .@r = getrefine(); if(.@r < 5) { .@r = 5; bonus2 bSubRace,RC_DemiHuman,(.@r - 5); bonus2 bAddRace,RC_DemiHuman,(.@r - 5); }', NULL, NULL),
(19086, 'Robo_Eye_', 'Robo Eye', 4, 20, NULL, 200, NULL, 2, NULL, 1, 4294967295, 63, 2, 512, NULL, '10', 0, 345, 'bonus bAtkRate,1; bonus bMatkRate,1; bonus bDex,1;', NULL, NULL);
