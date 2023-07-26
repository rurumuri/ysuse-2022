#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QSqlDatabase>//连接数据库
#include <QSqlQuery>//查询数据库
#include <QSqlError>//数据库错误信息
#include <QDebug>//Qt调试

class Book
{
public:
    Book();
    static bool connectSQLite();//建立连接，初始化数据库
//    static QSqlDatabase *bookdb;

    QString book_name;
    QString book_author;
    QString book_press;
    QString book_isbn;
    double book_price;

    unsigned long long book_quantity = 0;
    unsigned long long book_sold_total = 0;
    unsigned long long book_purchase_total = 0;

    //其实这个book类是不很必要的
};

#endif // BOOK_H
