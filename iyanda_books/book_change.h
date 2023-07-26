#ifndef BOOK_CHANGE_H
#define BOOK_CHANGE_H

#include <QDialog>
#include <QMessageBox>
#include "book.h"

namespace Ui {
class book_change;
}

class book_change : public QDialog
{
    Q_OBJECT

public:
    explicit book_change(QWidget *parent = nullptr);
    ~book_change();

signals:
    void book_change_request(Book);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


private:
    Ui::book_change *ui;
};

#endif // BOOK_CHANGE_H
