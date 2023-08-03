#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include "bookmanager.h"

namespace Ui {
class Welcome;
}

class Welcome : public QDialog
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

private:
    Ui::Welcome *ui;
    BookManager *bm_main;
};

#endif // WELCOME_H
