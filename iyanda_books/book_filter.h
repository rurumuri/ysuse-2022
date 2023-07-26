#ifndef BOOK_FILTER_H
#define BOOK_FILTER_H

#include <QDialog>
#include <QString>

namespace Ui {
class book_filter;
}

class book_filter : public QDialog
{
    Q_OBJECT

public:
    explicit book_filter(QWidget *parent = nullptr);
    ~book_filter();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void book_filter_request(int, QString, bool);//发出查询信号，由bookmanager槽函数接受

private:
    Ui::book_filter *ui;
};

#endif // BOOK_FILTER_H
