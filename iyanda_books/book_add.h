#ifndef BOOK_ADD_H
#define BOOK_ADD_H

#include <QDialog>
#include "book.h"

namespace Ui {
class book_add;
}

class book_add : public QDialog
{
    Q_OBJECT

public:
    explicit book_add(QWidget *parent = nullptr);
    ~book_add();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void book_add_request(Book);//发出添加信号并传递书籍信息，由bookmanager槽函数接受

private:
    Ui::book_add *ui;
};

#endif // BOOK_ADD_H
