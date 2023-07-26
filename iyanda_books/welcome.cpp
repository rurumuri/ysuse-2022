#include "welcome.h"
#include "ui_welcome.h"
#include "about.h"
#include "login.h"
#include "signup.h"
#include "bookmanager.h"

Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_commandLinkButton_clicked()//两个窗体互相调用导致内存泄漏，问题没有完全解决！
{
    Login login_dialog(this);
    connect(&login_dialog, &Login::login_successful, this, [=](){
        bm_main = new BookManager(nullptr, true);
        this->close();
        bm_main->show();
    });
    login_dialog.exec();
}


void Welcome::on_commandLinkButton_2_clicked()
{
    Signup signup_dialog(this);
    signup_dialog.exec();
}


void Welcome::on_commandLinkButton_3_clicked()
{
    bm_main = new BookManager(nullptr);
    this->close();
    bm_main->show();
}

