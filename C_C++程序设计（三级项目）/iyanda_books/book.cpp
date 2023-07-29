#include "book.h"

Book::Book()
{

}

bool Book::connectSQLite(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("books.db");
    if(!db.open()){//打开数据库失败直接返回，避免出现SQL错误
        return false;
    }

    QSqlQuery query;
    query.exec("create table book(id integer primary key autoincrement, name varchar(100), author varchar(50), press varchar(40), isbn varchar(30) unique, price real, quantity integer default 0, sold_total integer default 0, purchase_total integer default 0)");
    //query.exec("insert into book (name, author, press, isbn, price) values ('senbai', 'tiansuo', 'sukipress', '1145141919810', 11.4)");//sql语句执行测试

//    bookdb = &db;

    return true;
}
