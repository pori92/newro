-- ----------------------------
-- Table structure for `sales`
-- ----------------------------

CREATE TABLE `sales` (
  `nameid` smallint(5) unsigned NOT NULL,
  `start` datetime NOT NULL,
  `end` datetime NOT NULL,
  `price` int(10) unsigned NOT NULL,
  `amount` int(11) NOT NULL,
  PRIMARY KEY (`nameid`)
) ENGINE=MyISAM;
