#include "book_change.h"
#include "ui_book_change.h"

book_change::book_change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book_change)
{
    ui->setupUi(this);
}

book_change::~book_change()
{
    delete ui;
}

void book_change::on_pushButton_2_clicked()
{
    this->close();
}


void book_change::on_pushButton_clicked()
{
    Book thebook;//使用book类封装数据
    thebook.book_name = ui->lineEdit->text();
    thebook.book_author = ui->lineEdit_2->text();
    thebook.book_press = ui->lineEdit_3->text();
    thebook.book_isbn = ui->lineEdit_4->text();
    thebook.book_price = ui->doubleSpinBox->text().toDouble();
    if(thebook.book_name==""||thebook.book_author==""||thebook.book_press==""||thebook.book_isbn==""){//检查值非空
        QMessageBox::warning(this,"错误","图书信息不能有空字段！");
    }
    else{
        emit book_change_request(thebook);
        this->close();
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        ui->doubleSpinBox->setValue(0.0);
    }
}

