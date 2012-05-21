-- ----------------------------
-- Table structure for `bpet_ability`
-- ----------------------------
DROP TABLE IF EXISTS `bpet_ability`;
CREATE TABLE `bpet_ability` (
  `AbilityID` int(11) unsigned NOT NULL DEFAULT '0',
  `Abilityspell` int(11) unsigned NOT NULL DEFAULT '0',
  `Abilitylvlreq` int(11) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`AbilityID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='BPet System';

-- ----------------------------
-- Records of bpet_ability
-- ----------------------------
INSERT INTO `bpet_ability` VALUES (0, 32703, 10); -- regen
INSERT INTO `bpet_ability` VALUES (1, 32703, 10); -- regen
INSERT INTO `bpet_ability` VALUES (2, 32703, 10); -- regen
INSERT INTO `bpet_ability` VALUES (3, 7160, 10); -- execute
INSERT INTO `bpet_ability` VALUES (4, 7160, 10); -- execute
INSERT INTO `bpet_ability` VALUES (5, 7160, 10); -- execute
INSERT INTO `bpet_ability` VALUES (6, 118442, 10); -- swiftness
INSERT INTO `bpet_ability` VALUES (7, 118442, 10); -- swiftness
INSERT INTO `bpet_ability` VALUES (8, 118442, 10); -- swiftness
INSERT INTO `bpet_ability` VALUES (9, 41410, 10); -- damned
INSERT INTO `bpet_ability` VALUES (10, 41410, 10); -- damned
INSERT INTO `bpet_ability` VALUES (11, 41410, 10); -- damned
INSERT INTO `bpet_ability` VALUES (12, 115997, 10); -- elusiveness
INSERT INTO `bpet_ability` VALUES (13, 115997, 10); -- elusiveness
INSERT INTO `bpet_ability` VALUES (14, 115997, 10); -- elusiveness
INSERT INTO `bpet_ability` VALUES (15, 33054, 10); -- spellshield
INSERT INTO `bpet_ability` VALUES (16, 33054, 10); -- spellshield
INSERT INTO `bpet_ability` VALUES (17, 33054, 10); -- spellshield
INSERT INTO `bpet_ability` VALUES (18, 2380, 10); -- wheather resistance
INSERT INTO `bpet_ability` VALUES (19, 2380, 10); -- wheather resistance
INSERT INTO `bpet_ability` VALUES (20, 2380, 10); -- wheather resistance
INSERT INTO `bpet_ability` VALUES (21, 60075, 10); -- enrage
INSERT INTO `bpet_ability` VALUES (22, 60075, 10); -- enrage
INSERT INTO `bpet_ability` VALUES (23, 60075, 10); -- enrage
INSERT INTO `bpet_ability` VALUES (24, 8361, 10); -- purity
INSERT INTO `bpet_ability` VALUES (25, 8361, 10); -- purity
INSERT INTO `bpet_ability` VALUES (26, 8361, 10); -- purity
INSERT INTO `bpet_ability` VALUES (27, 64668, 10); -- failsafe
INSERT INTO `bpet_ability` VALUES (28, 64668, 10); -- failsafe
INSERT INTO `bpet_ability` VALUES (29, 64668, 10); -- failsafe

-- ----------------------------
-- Table structure for `bpet_template`
-- ----------------------------
DROP TABLE IF EXISTS `bpet_template`;
CREATE TABLE `bpet_template` (
  `petID` int(11) unsigned NOT NULL DEFAULT '0',
  `speciesID` int(11) unsigned NOT NULL DEFAULT '0',
  `creatureID` int(11) unsigned DEFAULT '0',
  `name` varchar(100) DEFAULT 'BPet',
  `Ability0` int(11) unsigned NOT NULL DEFAULT '0', -- passive ability
  `Ability1a` int(11) unsigned NOT NULL DEFAULT '0',
  `Ability1b` int(11) unsigned NOT NULL DEFAULT '0',
  `Ability2a` int(11) unsigned NOT NULL DEFAULT '0',
  `Ability2b` int(11) unsigned NOT NULL DEFAULT '0',
  `Ability3a` int(11) unsigned NOT NULL DEFAULT '0',
  `Ability3b` int(11) unsigned NOT NULL DEFAULT '0',
  `Level` int(11) unsigned NOT NULL DEFAULT '1',
  `Health` int(11) unsigned NOT NULL DEFAULT '0',
  `Attack` int(11) unsigned NOT NULL DEFAULT '0',
  `Defense` int(11) unsigned NOT NULL DEFAULT '0',
  `Movement` int(11) unsigned NOT NULL DEFAULT '0',
  `Item` int(11) unsigned NOT NULL DEFAULT '0',
  `icon` varchar(100) DEFAULT 'BPet',
  `WeakVs1` int(11) unsigned NOT NULL DEFAULT '0',
  `WeakVs2` int(11) unsigned NOT NULL DEFAULT '0',
  `StrongVs1` int(11) unsigned NOT NULL DEFAULT '0',
  `StrongVs2` int(11) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`petID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='BPet System';

-- ----------------------------
-- Records of bpet_template
-- ----------------------------
INSERT INTO `bpet_template` VALUES (0, 0, 6293, 'HUMANOID', 0, 0, 1, 2, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (1, 1, 6293, 'DRAGON', 0, 3, 4, 5, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (2, 2, 4185, 'FLYING', 0, 6, 7, 8, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (3, 3, 36499, 'UNDEAD', 0, 9, 10, 11, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (4, 4, 27627, 'CRITTER', 0, 12, 13, 14, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (5, 5, 28482, 'MAGICAL', 0, 15, 16, 17, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (6, 6, 28482, 'ELEMENTAL', 0, 18, 19, 20, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (7, 7, 38065, 'BEAST', 0, 21, 22, 23, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (8, 8, 38065, 'AQUATIC', 0, 24, 25, 26, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (9, 9, 38065, 'MECHANICAL', 0, 27, 28, 29, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);