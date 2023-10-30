/*新建数据库*/
USE master  
  
CREATE DATABASE [FILTERED]  
ON PRIMARY   
    (NAME='dbexp_data',  
    FILENAME='E:\Files\Proj\SQLServer\exp\FILTERED_data.mdf',  
    SIZE=30MB,  
    FILEGROWTH=10%  
    )  
LOG ON  
    (NAME='dbexp_log',  
    FILENAME='E:\Files\Proj\SQLServer\exp\FILTERED_log.ldf',  
    SIZE=10MB,  
    FILEGROWTH=10%  
    ) 


/*创建表结构*/
USE [FILTERED]  
CREATE TABLE T(  
    T# NVARCHAR(32) NOT NULL PRIMARY KEY,  
    TNAME NVARCHAR(32) NOT NULL,  
    TITLE NVARCHAR(32)  
    )  
  
CREATE TABLE C(  
    C# NVARCHAR(32) NOT NULL PRIMARY KEY,  
    CNAME NVARCHAR(32) NOT NULL,  
    T# NVARCHAR(32) NOT NULL REFERENCES T(T#)  
    )  
  
CREATE TABLE S(  
    S# NVARCHAR(32) NOT NULL PRIMARY KEY,  
    SNAME NVARCHAR(32) NOT NULL,  
    AGE SMALLINT NOT NULL,  
    SEX NVARCHAR(1) NOT NULL,  
    )  
 
CREATE TABLE SC(  
    S# NVARCHAR(32) NOT NULL PRIMARY KEY REFERENCES S(S#),  
    C# NVARCHAR(32) NOT NULL REFERENCES C(C#),  
    GRADE SMALLINT,  
    )  



/*录数据*/
INSERT INTO S  
VALUES('S1','TOM','20','M'),  
      ('S10','ZHOU','16','F'),  
      ('S2','JACK','20','M'),  
      ('S3','MARY','21','F'),  
      ('S4','WANG','21','F'),  
      ('S5','ZHAO','24','M'),  
      ('S6','LI','25','M'),  
      ('S7','DU','19','F'),  
      ('S8','TANG','19','M'),  
      ('S9','MAO','17','M')  
INSERT INTO T  
VALUES('T1','ZHANG',NULL),  
      ('T2','WU',NULL),  
      ('T3','LIU',NULL),  
      ('T4','ZHOU',NULL)  
INSERT INTO C  
VALUES('C1','MATHS','T1'),  
      ('C2','ENGLISH','T2'),  
      ('C3','CHINESE','T3'),  
      ('C4','PHYSICS','T3'),  
      ('C5','COMPUTER','T4')  
INSERT INTO SC  
VALUES('S1','C1','70'),  
      ('S1','C2','80'),  
      ('S1','C4','90'),  
      ('S10','C1','81'),  
      ('S2','C1','70'),  
      ('S2','C5','90'),  
      ('S3','C1','80'),  
      ('S3','C4','90'),  
      ('S4','C1','90'),  
      ('S4','C2','60'),  
      ('S5','C1','60'),  
      ('S5','C2','60'),  
      ('S5','C3',NULL),  
      ('S5','C4','60'),  
      ('S5','C5','78'),  
      ('S6','C1','76'),  
      ('S7','C1','68'),  
      ('S7','C4','70'),  
      ('S8','C1','76'),  
      ('S9','C1','90')  


/*表结构修改*/
ALTER TABLE S  
ADD BIRTH DATE 

ALTER TABLE S  
DROP COLUMN BIRTH 


