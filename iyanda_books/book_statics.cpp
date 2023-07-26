#include "book_statics.h"
#include "ui_book_statics.h"

book_statics::book_statics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book_statics)
{
    ui->setupUi(this);
}

book_statics::~book_statics()
{
    delete ui;
}

void book_statics::on_pushButton_clicked()
{
    this->close();
}

void book_statics::updatevalue(){
    ui->label_3->setText(QString::number(book_total));
    ui->label_5->setText(QString::number(sale_total));
}

