/*
 Navicat Premium Dump SQL

 Source Server         : learn240626
 Source Server Type    : MySQL
 Source Server Version : 80037 (8.0.37)
 Source Host           : localhost:3306
 Source Schema         : lab

 Target Server Type    : MySQL
 Target Server Version : 80037 (8.0.37)
 File Encoding         : 65001

 Date: 27/06/2024 08:54:47
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for record
-- ----------------------------
DROP TABLE IF EXISTS `record`;
CREATE TABLE `record`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `money` decimal(10, 2) NULL DEFAULT NULL,
  `date` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `user_id` int NULL DEFAULT NULL,
  `remarks` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 23 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of record
-- ----------------------------
INSERT INTO `record` VALUES (1, 'ipad2021', 3700.50, '2024-06-27 00:37:56', 1, '');
INSERT INTO `record` VALUES (3, 'iphone13 256g', 3600.00, '2024-06-26 21:15:05', 1, '');
INSERT INTO `record` VALUES (5, 'ipad2021', 3500.00, '2024-06-14 11:11:52', NULL, NULL);
INSERT INTO `record` VALUES (6, 'ipad air 1', 200.00, '2024-06-26 21:15:07', 1, '');
INSERT INTO `record` VALUES (7, 'ipad air 2', 1000.00, '2024-06-27 00:37:49', 1, '');
INSERT INTO `record` VALUES (8, 'ipad air 3rd gen', 2000.00, '2024-06-27 00:37:50', 1, '');
INSERT INTO `record` VALUES (19, '麦克不可', 114514.00, '2024-06-27 03:51:10', 1, NULL);
INSERT INTO `record` VALUES (20, '爪洼咖啡', 1919810.00, '2024-06-27 04:43:37', 1, NULL);
INSERT INTO `record` VALUES (21, 'Nvidia A100', 1.00, '2024-06-27 04:43:54', 1, NULL);
INSERT INTO `record` VALUES (22, 'Tesla P40', 998.00, '2024-06-27 05:08:53', 1, '');

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`  (
  `uid` int NOT NULL AUTO_INCREMENT,
  `username` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `password` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `isAdmin` tinyint(3) UNSIGNED ZEROFILL NULL DEFAULT NULL,
  PRIMARY KEY (`uid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 12 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES (1, 'admin', 'admin', 001);
INSERT INTO `user` VALUES (7, 'dpsufb7z', '233233', NULL);
INSERT INTO `user` VALUES (8, 'sycui', '526333', NULL);
INSERT INTO `user` VALUES (11, 'add', 'adsasdssad', NULL);

SET FOREIGN_KEY_CHECKS = 1;
