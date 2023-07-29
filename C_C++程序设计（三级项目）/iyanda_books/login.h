#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void login_successful();//成功登录信号，由welcome接受并进行下一步操作（关闭自己，打开图书管理页面）

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
