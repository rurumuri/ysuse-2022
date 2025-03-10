/*（1）查询操作：
①检索年龄小于19岁的男学生的学生信息。*/
SELECT * FROM S   
WHERE SEX = 'M' AND AGE < 19  

 
/*②检索男学生所学课程的课程名。*/
SELECT DISTINCT CNAME FROM C,S  
WHERE S.SEX='M'

 
/*③检索女学生所学课程的任课教师的工号和姓名。*/
SELECT DISTINCT T.T#, T.TNAME FROM S,T,C,SC  
WHERE S.S# = SC.S#   
AND C.C# = SC.C#   
AND C.T#=T.T#   
AND S.SEX = 'F' 

 
/*④检索至少选修3门课程的学生姓名。*/
SELECT SNAME FROM S AS X  
WHERE (SELECT COUNT(SC.S#) FROM SC WHERE SC.S#=X.S#)>=3  

 

/*⑤检索学号S5、S7学生共同选修的课程的课程号和课程名。*/
SELECT SC.C#,CNAME FROM SC,C  
WHERE   
SC.C# IN (SELECT C# FROM SC WHERE S#='S5')  
AND S#='S3' AND SC.C#=C.C# 

 

/*⑥检索jack同学不学的课程的课程号和课程名。*/
SELECT C#,CNAME  
FROM C   
WHERE NOT EXISTS  
(SELECT *  
FROM S,SC  
WHERE C.C#=SC.C# AND S.S#=SC.S# AND SNAME='JACK') 

 

/*⑦检索全部学生都选修的课程的课程号与课程名。*/
SELECT C#,CNAME  
FROM C  
WHERE NOT EXISTS  
(SELECT * FROM S  
WHERE NOT EXISTS  
(SELECT * FROM SC  
WHERE S#=S.S# AND C#=C.C#)) 

 

/*⑧检索选修课程包含wu老师所授课程的学生姓名。*/
SELECT DISTINCT SNAME  
FROM SC AS X,S  
WHERE NOT EXISTS(  
(SELECT C#   
FROM C,T  
WHERE C.T#=T.T# AND TNAME ='WU')  
EXCEPT   
(SELECT C#  
FROM SC AS Y  
WHERE Y.S#=X.S# AND S.S#=X.S#) 
)

 


/*（2）组合查询：
①统计有学生选修的课程门数。*/
SELECT COUNT(DISTINCT C#) FROM SC;

 

/*②统计选修C2课程的男学生的平均年龄。*/
SELECT AVG(AGE) FROM S,SC  
WHERE SC.C#='C2' AND S.SEX='M' AND S.S#=SC.S#

 

/*③统计zhang老师所授课程的课程名与平均成绩。*/
SELECT CNAME, AVG(GRADE)   
FROM C JOIN SC ON SC.C# = C.C#   
WHERE T# = (SELECT T# FROM T WHERE TNAME = 'zhang')   
GROUP BY CNAME;

 

/*④统计每门课程的学生选修人数（至少3人的课程才统计）。
要求显示课程号和选课人数，按人数降序展示结果。*/
SELECT C#, COUNT(*) FROM SC  
GROUP BY C# 
HAVING COUNT(*) >= 3  
ORDER BY COUNT(*) DESC; 

 

/*⑤检索学号比mary同学大，但年龄也她小的女学生姓名。*/
SELECT SNAME FROM S
WHERE S# > (
SELECT S# FROM S
WHERE SNAME = 'mary'
) AND SEX = 'F' AND AGE < (
SELECT AGE FROM S
WHERE SNAME = 'mary');

 


/*⑥检索成绩在A等（90及90分以上）的学生姓名、课程名字、课程成绩。*/
SELECT SNAME,CNAME,GRADE FROM S,SC,C  
WHERE GRADE>=90 AND SC.C#=C.C# AND S.S#=SC.S#


 

/*⑦检索姓名以t打头的所有学生的姓名和选修课程名。*/
SELECT SNAME,CNAME FROM S,C,SC  
WHERE SNAME LIKE 'T%' AND C.C#=SC.C# AND SC.S#=S.S#

 

/*⑧检索年龄小于女同学平均年龄的男学生姓名和年龄。*/
SELECT S.SNAME, S.AGE FROM S  
WHERE S.SEX = 'M' AND S.AGE < (
SELECT AVG(S.AGE) FROM S WHERE SEX = 'F'
);  

 



/*2.使用SQL进行数据完整性控制。
①添加S表的约束条件，性别只能取值M和F。*/
ALTER TABLE S  
ADD CONSTRAINT CSEX CHECK (SEX IN ('F', 'M'));  

 

/*然后验证当操作违反了完整性约束时系统的处理方式
如：在S中插入一条性别写其他不符合规矩字符的记录。*/
INSERT INTO S   
VALUES (1, 'LI', 20, 'L'); 

 

/*②添加S表的约束条件，年龄<26岁。（同时要注意年龄下限）*/
ALTER TABLE S  
ADD CONSTRAINT CAGE CHECK (AGE < 26 AND AGE > 0); 

 
/*进行插入操作*/
INSERT INTO S   
VALUES (1, 'LI', -1, 'M');  



/*③删除S表中年龄的约束条件。*/
ALTER TABLE S  
DROP CONSTRAINT CAGE;


/*④添加SC表的约束条件，成绩在0-150之间。*/
ALTER TABLE SC  
ADD CONSTRAINT CSCORE CHECK (GRADE >= 0 AND GRADE <= 150); 

 

/*然后验证当操作违反了完整性约束时，系统如何处理？
如：在SC中插入一条记录，成绩不在0-150之间。
执行语句*/
INSERT INTO SC   
VALUES ('S51','C51','200') 
 


/*⑤修改SC表的约束条件，成绩在0-100之间。*/
ALTER TABLE SC  
DROP CONSTRAINT CSCORE 
ALTER TABLE SC  
ADD CONSTRAINT CSCORE CHECK (GRADE >= 0 AND GRADE <= 100)  

 

/*执行语句*/
INSERT INTO SC   
VALUES ('S51','C51','120') 

 


/*3.数据更新。
①在SC表中插入3条新的数据：S8，C5，76；S9，C3，88；S10，C3，65。*/
INSERT INTO SC VALUES ('S8', 'C5', 76);  
INSERT INTO SC VALUES ('S9', 'C3', 88);  
INSERT INTO SC VALUES ('S10', 'C3', 65); 

 

/*②修改tang同学所学C5课程的成绩为80分*/
UPDATE SC   
SET SCORE = 80   
WHERE S# = (SELECT S#   
FROM S   
WHERE SNAME = 'tang') AND C# = 'C5';  

 

/*③将选LIU老师所授chinese课程的全体学生的成绩置零。*/
UPDATE SC   
SET SCORE = 0   
WHERE C# IN (
SELECT C# FROM C WHERE T# = (
SELECT T# FROM T WHERE TNAME = 'LIU')
AND CNAME = 'CHINESE'); 

 
/*④删除SC中学生S10选课C3的数据。*/
DELETE FROM SC   
WHERE S# = 'S10' AND C# = 'C3'; 
