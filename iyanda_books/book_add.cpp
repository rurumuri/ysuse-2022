#include "book_add.h"
#include "ui_book_add.h"
#include "book.h"
#include <QMessageBox>

book_add::book_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book_add)
{
    ui->setupUi(this);
}

book_add::~book_add()
{
    delete ui;
}

void book_add::on_pushButton_2_clicked()
{
    this->close();
}


void book_add::on_pushButton_clicked()
{
    Book new_book;//使用book类封装数据
    new_book.book_name = ui->lineEdit->text();
    new_book.book_author = ui->lineEdit_2->text();
    new_book.book_press = ui->lineEdit_3->text();
    new_book.book_isbn = ui->lineEdit_4->text();
    new_book.book_price = ui->doubleSpinBox->text().toDouble();
    if(new_book.book_name==""||new_book.book_author==""||new_book.book_press==""||new_book.book_isbn==""){//检查值非空
        QMessageBox::warning(this,"错误","图书信息不能有空字段！");
    }
    else{
        emit book_add_request(new_book);
        this->close();
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        ui->doubleSpinBox->setValue(0.0);
    }
}

