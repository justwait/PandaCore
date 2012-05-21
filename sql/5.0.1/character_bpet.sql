-- ----------------------------
-- Table structure for `character_bpet`
-- ----------------------------
DROP TABLE IF EXISTS `character_bpet`;
CREATE TABLE `character_bpet` (
  `guID` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `petID` int(11) unsigned NOT NULL DEFAULT '0',
  `ownerID` int(11) unsigned NOT NULL DEFAULT '0',
  `Name` varchar(100) DEFAULT 'BPet',
  `Ability1` int(11) unsigned NOT NULL DEFAULT '0', -- 0= not lvl req
  `Ability2` int(11) unsigned NOT NULL DEFAULT '0', -- 1= active in actionbar
  `Ability3` int(11) unsigned NOT NULL DEFAULT '0', -- 2= not in actionbar
  `Level` int(11) unsigned NOT NULL DEFAULT '1',
  `Xp` int(11) unsigned NOT NULL DEFAULT '1',
  `Health` int(11) unsigned NOT NULL DEFAULT '0',
  `Attack` int(11) unsigned NOT NULL DEFAULT '0',
  `Defense` int(11) unsigned NOT NULL DEFAULT '0',
  `Movement` int(11) unsigned NOT NULL DEFAULT '0',
  `Item` int(11) unsigned NOT NULL DEFAULT '0', -- pet item ??
  `Slot` int(11) unsigned NOT NULL DEFAULT '0', -- 3= not in team, 0,1,2 = team slot
  `Favourite` int(11) unsigned NOT NULL DEFAULT '0',
  `savetime` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='BPet System';

-- ----------------------------
-- Records of character_bpet
-- ----------------------------