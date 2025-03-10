--(1)插入数据：模拟实际用户和车辆登记
INSERT INTO [User] (UID, UNAME, UContact, UVehNum, UAddress)
VALUES
	('U9','FILTERED','trisuyan@ysu.edu.cn',1,'4a414');
INSERT INTO Vehicle (VID, VType, VProfile, VNote, UID)
VALUES
('V14','自行车','捷安特ATX系列，橘白色有磨损','刹车不很灵敏','U9');


--(2)删除数据：
DELETE FROM Vehicle 
WHERE VID='V14'
 

--(3)更改数据：更新用户信息
UPDATE [User]
SET
	UContact='QQ114514191',
	UAddress='5a114'
WHERE UID='U9';

--(4)查询数据：
--常规查询：查询UID为U1的用户的不良行为记录
SELECT BRID, BRTime, BRContent
FROM BadRecord
WHERE UID = 'U1';

--连接查询：查询所有车辆及其车主基本信息
SELECT [User].UID, [User].UName, Vehicle.VID, Vehicle.VProfile
FROM [User]
INNER JOIN Vehicle ON [User].UID = Vehicle.UID;

--嵌套查询：查询某用户的不良行为记录数量
SELECT UID, UName,
    (SELECT COUNT(*) FROM BadRecord WHERE BadRecord.UID = [User].UID) AS BadRecordCount
FROM [User]
WHERE UID = 'U7';

--查询所有车辆信息，并且按照数字顺序而非字典序排列
SELECT VID,VType,VProfile,VNote,[UID]
FROM Vehicle
ORDER BY CAST(SUBSTRING(VID, 2, LEN(VID)) AS INT);


--(5)约束验证：
--非空值：以用户信息为例
INSERT INTO [User] ([UID], UName, UContact, UVehNum, UAddress)
VALUES
('U10', NULL, 'olivia@example.com', 2, '4c414');
 
--车辆数量非负
INSERT INTO [User] ([UID], UName, UContact, UVehNum, UAddress)
VALUES
('U10', 'keqing', 'olivia@example.com', -1, '3c414');
 
--充电结束时间不早于开始时间
INSERT INTO VehicleCharge (VCID, VCStartTime, VCEndTime, VCState, VID, CDID)
VALUES
('VC9', '2023-10-30 08:00:00', '2023-10-29 10:00:00', '充电结束', 'V1', 'CD1');
 
--车辆类型取值验证：
INSERT INTO Vehicle (VID, VType, VProfile, VNote, [UID])
VALUES
    ('V100', '直升飞机', '国产', '无', 'U1');
 

--(6)触发器效果验证：
--停车位实体与停车关系之间停车位占用状态的同步
--首先模拟停车时间，由于尚未结束，结束时间为NULL
INSERT INTO VehiclePark (VPID, VPStartTime, VPEndTime, VID, PSID)
VALUES
    ('VP16', '2023-10-01 08:00:00', NULL, 'V1', 'PS1')
 

--接下来模拟车辆离开
UPDATE VehiclePark
SET
    VPEndTime = '2023-10-01 08:30:00'
WHERE VPID='VP16'
 

--充电设备实体与充电关系之间充电状态的同步 和 触发器实现自动计算和收费
--首先模拟开始充电，插入一条数据
INSERT INTO VehicleCharge (VCID, VCStartTime, VCEndTime, VCState, VID, CDID)
VALUES
    ('VC9', '2023-10-01 08:00:00', NULL, '充电中', 'V1', 'CD1')
 
 
--而后更新状态：
UPDATE VehicleCharge
SET VCEndTime = '2023-10-09 08:00:00',
	VCState = '充电结束'
WHERE VCID = 'VC9';

 
