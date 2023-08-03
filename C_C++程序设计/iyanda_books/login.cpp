#include "login.h"
#include "ui_login.h"
#include "bookmanager.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
{
    this->close();
}


void Login::on_pushButton_clicked()
{
    this->close();
    emit login_successful();
}

