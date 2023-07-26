#include "book_filter.h"
#include "ui_book_filter.h"

book_filter::book_filter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book_filter)
{
//    setAttribute(Qt::WA_DeleteOnClose);//后续还会重复调用，不需要释放
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
}

book_filter::~book_filter()
{
    delete ui;
}

void book_filter::on_pushButton_2_clicked()
{
    this->close();
}


void book_filter::on_pushButton_clicked()
{
    int fromwhere = ui->comboBox->currentIndex();
    QString searchdata = ui->lineEdit->text();
    bool isAscending;//递增与否
    if(ui->radioButton->isChecked()){
        isAscending = true;
    }
    else{
        isAscending = false;
    }
//    qDebug()<<fromwhere<<" "<<searchdata;
    emit book_filter_request(fromwhere, searchdata, isAscending);//发送查询请求信号
    this->close();
}

