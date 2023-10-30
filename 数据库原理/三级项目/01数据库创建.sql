USE master  
  
CREATE DATABASE YSUNMVMS  
ON PRIMARY
    (NAME='ysunmvms_data',  
    FILENAME='E:\Files\Proj\SQLServer\ysunmvms\ysunmvms_data.mdf',  
    SIZE=64MB,  
    FILEGROWTH=10%  
    )  
LOG ON  
    (NAME='ysunmvms_log',  
    FILENAME='E:\Files\Proj\SQLServer\ysunmvms\ysunmvms_log.ldf',  
    SIZE=10MB,  
    FILEGROWTH=10%  
    ) 