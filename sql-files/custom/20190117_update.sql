# item fixes
REPLACE INTO `item_db2_re` (`id`, `name_english`, `name_japanese`, `type`, `price_buy`, `price_sell`, `weight`, `atk:matk`, `defence`, `range`, `slots`, `equip_jobs`, `equip_upper`, `equip_genders`, `equip_locations`, `weapon_level`, `equip_level`, `refineable`, `view`, `script`, `equip_script`, `unequip_script`) VALUES
(18791, 'Shrine_Maiden_Hat', 'Shrine Maiden Hat', 4, 20, NULL, 200, NULL, 30, NULL, 1, 4294967295, 63, 2, 256, NULL, NULL, 1, 908, '.@r = getrefine(); bonus2 bSkillAtk,\"PR_MAGNUS\",30 + (.@r/2 * 5); if(.@r>6) { bonus3 bAutoSpellWhenHit, \"AL_HEAL\", MAX(getskilllv(\"AL_HEAL\"), 0), 20; } if(.@r>8) { bonus bFixedCastrate,1; }', NULL, NULL),
(18908, 'Isabella_Red_Ear', 'Isabella Red Ear', 4, 10, NULL, 300, NULL, 8, NULL, 1, 4294967295, 63, 2, 256, NULL, '1', 1, 1030, 'bonus bStr,5; bonus bMaxHPrate,5; bonus2 bSubDefEle,Ele_Fire,10; .@r = getrefine(); if (.@r >= 9) bonus bAspd,1+((.@r-8)/2);', NULL, NULL);

# remove special mission
DELETE FROM `mission_board` WHERE `npc_id` LIKE '|99|';