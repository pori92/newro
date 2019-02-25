# rename GMT coin
REPLACE INTO `item_db2_re` (`id`, `name_english`, `name_japanese`, `type`, `price_buy`, `price_sell`, `weight`, `atk:matk`, `defence`, `range`, `slots`, `equip_jobs`, `equip_upper`, `equip_genders`, `equip_locations`, `weapon_level`, `equip_level`, `refineable`, `view`, `script`, `equip_script`, `unequip_script`) VALUES
(6671, 'Geffen_Magic_Tournament_Coin', 'Geffen Magic Tournament Coin', 3, 10, NULL, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

# food box
REPLACE INTO `item_db2_re` (`id`, `name_english`, `name_japanese`, `type`, `price_buy`, `price_sell`, `weight`, `atk:matk`, `defence`, `range`, `slots`, `equip_jobs`, `equip_upper`, `equip_genders`, `equip_locations`, `weapon_level`, `equip_level`, `refineable`, `view`, `script`, `equip_script`, `unequip_script`) VALUES
(8503, '10_Food_Box', '+10 Food Box', 18, 20, NULL, 0, NULL, NULL, NULL, NULL, 4294967295, 63, 2, NULL, NULL, NULL, NULL, NULL, 'getrandgroupitem(IG_Cash_Food);', NULL, NULL);

# Blacksmith Blessing boxes
REPLACE INTO `item_db2_re` (`id`, `name_english`, `name_japanese`, `type`, `price_buy`, `price_sell`, `weight`, `atk:matk`, `defence`, `range`, `slots`, `equip_jobs`, `equip_upper`, `equip_genders`, `equip_locations`, `weapon_level`, `equip_level`, `refineable`, `view`, `script`, `equip_script`, `unequip_script`) VALUES
(8504, 'Blacksmith_Blessing_20Box', 'Blacksmith Blessing x 20 Box', 2, 20, NULL, 10, NULL, NULL, NULL, NULL, 4294967295, 63, 2, NULL, NULL, NULL, NULL, NULL, 'getitem 6635,20;', NULL, NULL),
(8505, 'Blacksmith_Blessing_40Box', 'Blacksmith Blessing x 40 Box', 2, 20, NULL, 10, NULL, NULL, NULL, NULL, 4294967295, 63, 2, NULL, NULL, NULL, NULL, NULL, 'getitem 6635,40;', NULL, NULL),
(8506, 'Blacksmith_Blessing_1000Box', 'Blacksmith Blessing x 100 Box', 2, 20, NULL, 10, NULL, NULL, NULL, NULL, 4294967295, 63, 2, NULL, NULL, NULL, NULL, NULL, 'getitem 6635,100;', NULL, NULL);

# All mission board now requires at least lv lv99
UPDATE `mission_board` SET `min_lv` = '99' WHERE `mission_board`.`min_lv` < 100;
REPLACE INTO `mission_board` (`id`, `title`, `desc`, `mob_list`, `mob_qty`, `item_list`, `item_qty`, `class_limitation`, `class_branch`, `min_lv`, `max_lv`, `repeat`, `duration`, `reward_list`, `reward_qty`, `base_exp`, `job_exp`, `zeny`, `cash`, `aid`, `name`, `time_update`, `npc_id`, `redo_delay`) VALUES
(1545197000, 'Santa Poring Hat [1]', 'If you have a jumping poring, and an antonio\'s hat, I can help you combine them to create Santa Poring Hat[1]. If you want to show your love to Poring, why not get one yourself. All you need to do is just get me the material. - Poring Lover', '', '', '|2236|5335|5136|25184|', '|10|1|1|1|', 1023, 31, 99, 175, 0, 0, '|5381|', '|1|', 100000, 100000, 500000, 0, 2000000, '<GM>Nubs', '2018-12-12 00:01:00', '|99|', 21),
(1545197010, 'Costume SantaPoring Cap', 'I want to spread the love of cosplaying to the world. I want to convert the Santa Poring Hat into a costume. I will give you one for the effort. - Cosplayer Designer', '', '', '|5381|25184|', '|1|1|', 1023, 31, 99, 175, 0, 0, '|19682|', '|1|', 100000, 100000, 500000, 0, 2000000, '<GM>Nubs', '2018-12-12 00:01:00', '|99|',  21),
(1545197020, 'C Shining Santa Poring', 'I want to spread the love of cosplaying to the world. I want to convert the Santa Poring Hat into a costume. I will give you one for the effort. - Cosplayer Designer', '', '', '|19682|7938|710|969|25184|', '|1|100|25|25|1|', 1023, 31, 99, 175, 0, 0, '|31420|', '|1|', 100000, 100000, 500000, 0, 2000000, '<GM>Nubs', '2018-12-12 00:01:00', '|99|', 21),
(1545197030, 'Antler Fedora', 'There is one character in one of the anime that I watch. I love it so much that I want to make a similar headgear. Please help me gather the material. - Anime Lover', '', '', '|2284|5409|975|25184|', '|1|1|5|1|', 1023, 31, 99, 175, 0, 0, '|18662|', '|1|', 100000, 100000, 500000, 0, 2000000, '<GM>Nubs', '2018-12-12 00:01:00', '|99|', 21),
(1545197040, 'Rudolph Santa Hat', 'I came up with a great idea! If we combine two of these headgear, we will be able to get a Santa Hat with antlers. I name it Rudolph Santa Hat. If you want one please get me the materials. - Antlers Fan', '', '', '|18662|2236|5136|25184|', '|1|10|1|1|', 1023, 31, 99, 175, 0, 0, '|5742|', '|1|', 100000, 100000, 500000, 0, 2000000, '<GM>Nubs', '2018-12-12 00:01:00', '|99|', 21),
(1545197050, 'Costume Rudolph Santa Hat', 'I want to spread the love of cosplaying to the world. I want to convert the Rudolph Santa Hat into a costume. I will give you one for the effort. - Cosplayer Designer', '', '', '|5742|25184|', '|1|1|', 1023, 31, 99, 175, 0, 0, '|19697|', '|1|', 100000, 100000, 500000, 0, 2000000, '<GM>Nubs', '2018-12-12 00:01:00', '|99|', 21),
(1545197060, 'Santa\'s Bag', 'I finally manage to create a full body costume. I call it Santa\'s Bag. If you are interested, please gather materials for me. - Cosplayer Designer', '', '', '|530|7174|7175|644|2236|25184|', '|50|50|50|10|10|1|', 1023, 31, 99, 175, 0, 0, '|12132|', '|1|', 100000, 100000, 500000, 0, 2000000, '<GM>Nubs', '2018-12-12 00:01:00', '|99|', 21),
(1545197070, 'Sleeping Kitty Cat [1]', 'I finally manage to create a full body costume. I call it Santa\'s Bag. If you are interested, please gather materials for me. - Cosplayer Designer', '', '', '|7038|914|1059|975|5099|25184|', '|1|100|100|5|1|1|', 1023, 31, 99, 175, 0, 0, '|18693|', '|1|', 100000, 100000, 500000, 0, 2000000, '<GM>Nubs', '2018-12-12 00:01:00', '|9|', 21),
(1545197080, 'Shield of Death', 'There aren\'t enough darkness and death elements around. This not fair. I will make something dark and grim so you could scare kids. Get me enough materials, and I will make Shield of Death for you. - Gloomy Person', '', '', '|6471|6654|7108|2130|2128|', '|200|2|2|2|1|', 1023, 31, 99, 175, 0, 0, '|2177|', '|1|', 100000, 100000, 500000, 0, 2000000, '<GM>Nubs', '2018-12-12 00:01:00', '|10|', 21);

INSERT INTO `item_cash_db` (`tab`, `item_id`, `price`) VALUES ('0', '28916', '35'), ('4', '28916', '35');
REPLACE INTO `item_db2_re` (`id`, `name_english`, `name_japanese`, `type`, `price_buy`, `price_sell`, `weight`, `atk:matk`, `defence`, `range`, `slots`, `equip_jobs`, `equip_upper`, `equip_genders`, `equip_locations`, `weapon_level`, `equip_level`, `refineable`, `view`, `script`, `equip_script`, `unequip_script`) VALUES
(28916, 'Gaia_Shield', 'Gaia Shield', 4, 20, NULL, 2000, NULL, 150, NULL, 1, 4294967295, 63, 2, 32, NULL, '90', 1, 1, 'bonus bMdef,10; bonus2 bSubEle,Ele_Earth,10; bonus2 bAddEle,Ele_Earth,5; bonus2 bMagicAddEle,Ele_Earth,5; .@r = getrefine(); if(.@r>=8) { bonus2 bSubEle,Ele_Earth,15; bonus2 bAddEle,Ele_Earth,10; bonus2 bMagicAddEle,Ele_Earth,10; } if(.@r>=12) { if(readparam(bStr)>=90) { bonus bBaseAtk,50; } if(readparam(bAgi)>=90) { bonus bAspdRate,5; } if(readparam(bVit)>=90) { bonus bHealPower2,10; bonus bAddItemHealRate,10; } if(readparam(bInt)>=90) { bonus bMatk,30; } if(readparam(bDex)>=90) { bonus bVariableCastrate,-5; } if(readparam(bLuk)>=90) { bonus bCritAtkRate,5; } }', NULL, NULL);
