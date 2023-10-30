--充电设备实体与充电关系之间充电状态的同步
CREATE TRIGGER SyncVCStateAndCDStateWhenChange
ON VehicleCharge
AFTER UPDATE, INSERT
AS
BEGIN
    UPDATE cd
    SET cd.CDState = 
        CASE
            WHEN i.VCState = '充电中' THEN '占用中'
            WHEN i.VCState = '充电结束' THEN '空闲'
            ELSE '不可用'
        END
    FROM ChargeDevice cd
    INNER JOIN inserted i ON cd.CDID = i.CDID;
END;

--启用触发器
ENABLE TRIGGER SyncVCStateAndCDStateWhenChange
ON VehicleCharge




--停车位实体与停车关系之间停车位占用状态的同步
CREATE TRIGGER SyncPSStateWhenChange
ON VehiclePark 
AFTER UPDATE, INSERT
AS
BEGIN
    UPDATE ParkSpace
    SET ParkSpace.PSState = 
        CASE
            WHEN i.VPEndTime IS NULL THEN '占用中'
            WHEN i.VPEndTime IS NOT NULL THEN '空闲'
			ELSE '不可用'
        END
    FROM ParkSpace ps
	INNER JOIN VehiclePark vp ON vp.PSID = ps.PSID
    INNER JOIN inserted i ON vp.VID = i.VID;
END;

--启用触发器
ENABLE TRIGGER SyncPSStateWhenChange
ON VehiclePark




--触发器实现自动计算和收费
CREATE TRIGGER AutoCharge
ON VehicleCharge
AFTER UPDATE
AS
BEGIN
    INSERT INTO Payment (PType, PAmount, PState, UID, AID)
    SELECT '充电收费',
           DATEDIFF(MINUTE, i.VCStartTime, i.VCEndTime) * 0.01, -- 计算费用，每分钟0.1
           '待付款',  -- 设置初始状态
           u.UID,     -- 使用UID
           'SYSTEM'       -- AID设置为SYSTEM
    FROM inserted i
	JOIN Vehicle v ON i.VID = v.VID
    JOIN [User] u ON v.UID = u.UID
    WHERE i.VCEndTime IS NOT NULL AND i.VCState='充电结束';
END;

--启用触发器
ENABLE TRIGGER AutoCharge
ON VehicleCharge
