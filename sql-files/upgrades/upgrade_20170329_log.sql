ALTER TABLE `atcommandlog` ALTER `atcommand_date` SET DEFAULT '1000-01-01 00:00:00';
ALTER TABLE `branchlog` ALTER `branch_date` SET DEFAULT '1000-01-01 00:00:00';
ALTER TABLE `cashlog` ALTER `time` SET DEFAULT '1000-01-01 00:00:00';
ALTER TABLE `chatlog` ALTER `time` SET DEFAULT '1000-01-01 00:00:00';
ALTER TABLE `feedinglog` ALTER `time` SET DEFAULT '1000-01-01 00:00:00';
ALTER TABLE `loginlog` ALTER `time` SET DEFAULT '1000-01-01 00:00:00';
ALTER TABLE `mvplog` ALTER `mvp_date` SET DEFAULT '1000-01-01 00:00:00';
ALTER TABLE `npclog` ALTER `npc_date` SET DEFAULT '1000-01-01 00:00:00';
ALTER TABLE `picklog` ALTER `time` SET DEFAULT '1000-01-01 00:00:00';
ALTER TABLE `zenylog` ALTER `time` SET DEFAULT '1000-01-01 00:00:00';

UPDATE `atcommandlog` SET `atcommand_date` = '1000-01-01 00:00:00' WHERE `atcommand_date` = '0000-00-00 00:00:00';
UPDATE `branchlog` SET `branch_date` = '1000-01-01 00:00:00' WHERE `branch_date` = '0000-00-00 00:00:00';
UPDATE `cashlog` SET `time` = '1000-01-01 00:00:00' WHERE `time` = '0000-00-00 00:00:00';
UPDATE `chatlog` SET `time` = '1000-01-01 00:00:00' WHERE `time` = '0000-00-00 00:00:00';
UPDATE `feedinglog` SET `time` = '1000-01-01 00:00:00' WHERE `time` = '0000-00-00 00:00:00';
UPDATE `loginlog` SET `time` = '1000-01-01 00:00:00' WHERE `time` = '0000-00-00 00:00:00';
UPDATE `mvplog` SET `mvp_date` = '1000-01-01 00:00:00' WHERE `mvp_date` = '0000-00-00 00:00:00';
UPDATE `npclog` SET `npc_date` = '1000-01-01 00:00:00' WHERE `npc_date` = '0000-00-00 00:00:00';
UPDATE `picklog` SET `time` = '1000-01-01 00:00:00' WHERE `time` = '0000-00-00 00:00:00';
UPDATE `zenylog` SET `time` = '1000-01-01 00:00:00' WHERE `time` = '0000-00-00 00:00:00';
