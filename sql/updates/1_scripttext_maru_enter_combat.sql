-- 
-- Insert the text from Maru when we enter the combat
-- 

DELETE FROM `script_texts`  WHERE `entry`='-1469003';
INSERT INTO script_texts (`entry`, `content_default`, `comment`) VALUES (-1469003, "You dare to disturb my waters? Death! Death for you all!", "maru SAY_ENTER_COMBAT");