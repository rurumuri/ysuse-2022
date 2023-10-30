#include "db.h"

QSqlDatabase db;

//connect to SQLServer through ODBC data source
//the return value shows the initialization's result
bool DatabaseInitialize(){
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("YSUNMVMS");//db's name
    //db.setUserName("");
    //db.setPassword("");// use Windows NT Authentication
    return db.open();//open the connection  **don't forget to close it!!!**
}

//just use QSqlQuery to execute a certain SQL Sentence (Transact-SQL here)
bool SQLTest(QString sql){
    QSqlQuery query;
    return query.exec(sql);
}
