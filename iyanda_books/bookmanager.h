#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <QMainWindow>
#include <QSqlTableModel>//将数据库显示和增删改查与QTableView显示便利地关联
#include <QTableView>
#include <QString>
#include <QLabel>
#include <QDebug>

#include "book_filter.h"
#include "book_add.h"
#include "book_change.h"
#include "book.h"
#include "book_statics.h"



namespace Ui {
class BookManager;
}

class BookManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookManager(QWidget *parent = nullptr, bool islogin = false);
    ~BookManager();
    void showBooks();
    void get_book_filter_request(int, QString, bool);//响应book_filter_dialog的查询请求
    void get_book_add_request(Book);//响应book_add_dialog的录入请求
    void get_book_change_request(Book);//响应book_change_dialog的修改请求

private slots:

    void on_actionexit_triggered();

    void on_actionlogout_triggered();

    void on_action_about_triggered();

    void on_action_filter_triggered();

    void on_actionadd_book_triggered();

    void on_actionrefresh_filter_triggered();

    void on_tableView_clicked(const QModelIndex &index);

    void on_actiondelete_book_triggered();

    void on_actiondisable_action_for_selected_row_triggered();

    void on_actionenable_action_for_selected_row_triggered();

    void on_actionchange_book_triggered();

    void on_action_3_triggered();

    void on_actionpurchase_triggered();

    void on_actionstatistics_triggered();

private:
    Ui::BookManager *ui;
    QLabel *current_select_label;
    QSqlTableModel *books_model;

    book_filter *book_filter_dialog;
    book_add *book_add_dialog;
    book_change *book_change_dialog;
    book_statics *book_statics_dialog;

    int curRow;
    bool _islogin;
};

#endif // BOOKMANAGER_H
