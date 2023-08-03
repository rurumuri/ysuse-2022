#ifndef BOOK_STATICS_H
#define BOOK_STATICS_H

#include <QDialog>

namespace Ui {
class book_statics;
}

class book_statics : public QDialog
{
    Q_OBJECT

public:
    explicit book_statics(QWidget *parent = nullptr);
    ~book_statics();
    unsigned long long book_total;
    double sale_total;
    void updatevalue();

private slots:
    void on_pushButton_clicked();

private:
    Ui::book_statics *ui;
};

#endif // BOOK_STATICS_H
