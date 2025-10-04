-- Tạo database
CREATE DATABASE RentVehicleSystem;
GO
USE RentVehicleSystem;
GO

-- Bảng người dùng
CREATE TABLE [User] (
    UserId UNIQUEIDENTIFIER DEFAULT NEWID() PRIMARY KEY,
    FullName NVARCHAR(100) NOT NULL,
    Phone VARCHAR(20) UNIQUE NOT NULL,
    Email VARCHAR(100),
    PasswordHash NVARCHAR(255),
    Role NVARCHAR(20) CHECK (Role IN ('Customer', 'Admin')) DEFAULT 'Customer',
    CreatedAt DATETIME DEFAULT GETDATE()
);
GO

-- Bảng trạm (station)
CREATE TABLE Station (
    StationId UNIQUEIDENTIFIER DEFAULT NEWID() PRIMARY KEY,
    StationName NVARCHAR(100) NOT NULL,
    Address NVARCHAR(255),
    TotalSlots INT DEFAULT 20, -- sức chứa tối đa
    CreatedAt DATETIME DEFAULT GETDATE()
);
GO

-- Bảng xe điện
CREATE TABLE Vehicle (
    VehicleId UNIQUEIDENTIFIER DEFAULT NEWID() PRIMARY KEY,
    LicensePlate VARCHAR(20) UNIQUE,
    Model NVARCHAR(50),
    BatteryPercent INT CHECK (BatteryPercent BETWEEN 0 AND 100),
    Status NVARCHAR(20) CHECK (Status IN ('Available','InUse','Maintenance')) DEFAULT 'Available',
    CurrentStationId UNIQUEIDENTIFIER NULL,
    FOREIGN KEY (CurrentStationId) REFERENCES Station(StationId)
);
GO

-- Bảng hợp đồng thuê xe
CREATE TABLE RentalContract (
    ContractId UNIQUEIDENTIFIER DEFAULT NEWID() PRIMARY KEY,
    UserId UNIQUEIDENTIFIER NOT NULL,
    VehicleId UNIQUEIDENTIFIER NOT NULL,
    StationStartId UNIQUEIDENTIFIER NOT NULL,
    StationEndId UNIQUEIDENTIFIER NULL,
    StartTime DATETIME DEFAULT GETDATE(),
    EndTime DATETIME NULL,
    TotalCost DECIMAL(10,2) NULL,
    Status NVARCHAR(20) CHECK (Status IN ('Active','Completed','Cancelled')) DEFAULT 'Active',
    FOREIGN KEY (UserId) REFERENCES [User](UserId),
    FOREIGN KEY (VehicleId) REFERENCES Vehicle(VehicleId),
    FOREIGN KEY (StationStartId) REFERENCES Station(StationId),
    FOREIGN KEY (StationEndId) REFERENCES Station(StationId)
);
GO

-- Bảng thanh toán
CREATE TABLE Payment (
    PaymentId UNIQUEIDENTIFIER DEFAULT NEWID() PRIMARY KEY,
    ContractId UNIQUEIDENTIFIER NOT NULL,
    Amount DECIMAL(10,2) NOT NULL,
    PaymentMethod NVARCHAR(30) CHECK (PaymentMethod IN ('Cash','Card','Momo','Banking')),
    PaymentDate DATETIME DEFAULT GETDATE(),
    FOREIGN KEY (ContractId) REFERENCES RentalContract(ContractId)
);
GO

-- Bảng lịch sử di chuyển xe
CREATE TABLE VehicleHistory (
    HistoryId INT IDENTITY(1,1) PRIMARY KEY,
    VehicleId UNIQUEIDENTIFIER NOT NULL,
    FromStationId UNIQUEIDENTIFIER,
    ToStationId UNIQUEIDENTIFIER,
    MoveDate DATETIME DEFAULT GETDATE(),
    FOREIGN KEY (VehicleId) REFERENCES Vehicle(VehicleId),
    FOREIGN KEY (FromStationId) REFERENCES Station(StationId),
    FOREIGN KEY (ToStationId) REFERENCES Station(StationId)
);
GO

-- Người dùng
INSERT INTO [User] (FullName, Phone, Email, Role)
VALUES 
(N'Nguyễn Văn A', '0901234567', 'a@gmail.com', 'Customer'),
(N'Trần Thị B', '0909876543', 'b@gmail.com', 'Customer'),
(N'Admin', '0999999999', 'admin@system.vn', 'Admin');

-- Trạm xe
INSERT INTO Station (StationName, Address, TotalSlots)
VALUES 
(N'Trạm Bờ Hồ', N'Số 1 Tràng Tiền, Hoàn Kiếm', 25),
(N'Trạm Cầu Giấy', N'85 Cầu Giấy, Cầu Giấy', 30),
(N'Trạm Hà Đông', N'21 Quang Trung, Hà Đông', 20);

-- Xe điện
INSERT INTO Vehicle (LicensePlate, Model, BatteryPercent, Status, CurrentStationId)
SELECT 'HN01' + RIGHT('00' + CAST(ROW_NUMBER() OVER(ORDER BY (SELECT NULL)) AS VARCHAR(2)), 2),
       N'VinFast Evo200', 100, 'Available', StationId
FROM Station;

-- Thuê xe mẫu
DECLARE @User UNIQUEIDENTIFIER = (SELECT TOP 1 UserId FROM [User] WHERE FullName = N'Nguyễn Văn A');
DECLARE @Vehicle UNIQUEIDENTIFIER = (SELECT TOP 1 VehicleId FROM Vehicle);
DECLARE @StartStation UNIQUEIDENTIFIER = (SELECT TOP 1 StationId FROM Station WHERE StationName = N'Trạm Bờ Hồ');
DECLARE @EndStation UNIQUEIDENTIFIER = (SELECT TOP 1 StationId FROM Station WHERE StationName = N'Trạm Hà Đông');

INSERT INTO RentalContract (UserId, VehicleId, StationStartId, StationEndId, StartTime, EndTime, TotalCost, Status)
VALUES (@User, @Vehicle, @StartStation, @EndStation, '2025-10-01 08:00', '2025-10-01 09:30', 60000, 'Completed');

-- Thanh toán
INSERT INTO Payment (ContractId, Amount, PaymentMethod)
SELECT TOP 1 ContractId, 60000, 'Momo' FROM RentalContract;

-- Lịch sử di chuyển
INSERT INTO VehicleHistory (VehicleId, FromStationId, ToStationId)
SELECT @Vehicle, @StartStation, @EndStation;

-- Truy vấn danh sách xe còn trống tại mỗi trạm
SELECT S.StationName, COUNT(V.VehicleId) AS SoXeCon
FROM Station S
LEFT JOIN Vehicle V ON S.StationId = V.CurrentStationId AND V.Status = 'Available'
GROUP BY S.StationName;

--Truy vấn lịch sử thuê xe của một người dùng
SELECT U.FullName, V.LicensePlate, S1.StationName AS DiemNhan, 
       S2.StationName AS DiemTra, RC.StartTime, RC.EndTime, RC.TotalCost
FROM RentalContract RC
JOIN [User] U ON RC.UserId = U.UserId
JOIN Vehicle V ON RC.VehicleId = V.VehicleId
JOIN Station S1 ON RC.StationStartId = S1.StationId
LEFT JOIN Station S2 ON RC.StationEndId = S2.StationId
WHERE U.Phone = '0901234567';

-- Truy vấn tổng doanh thu theo tháng
SELECT 
    YEAR(P.PaymentDate) AS Nam,
    MONTH(P.PaymentDate) AS Thang,
    SUM(P.Amount) AS TongDoanhThu
FROM Payment P
GROUP BY YEAR(P.PaymentDate), MONTH(P.PaymentDate)
ORDER BY Nam, Thang;

-- Truy vấn số lượt thuê tại mỗi trạm
SELECT S.StationName, COUNT(*) AS SoLuotThue
FROM RentalContract R
JOIN Station S ON R.StationStartId = S.StationId
GROUP BY S.StationName;

-- Truy vấn xe đang được thuê
SELECT V.LicensePlate, U.FullName, RC.StartTime, S.StationName AS DiemNhan
FROM RentalContract RC
JOIN Vehicle V ON RC.VehicleId = V.VehicleId
JOIN [User] U ON RC.UserId = U.UserId
JOIN Station S ON RC.StationStartId = S.StationId
WHERE RC.Status = 'Active';