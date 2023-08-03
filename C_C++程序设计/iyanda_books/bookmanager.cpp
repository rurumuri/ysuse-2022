#include <QDebug>
#include <QSqlQuery>//查询数据库
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QSqlRecord>

#include "bookmanager.h"
#include "ui_bookmanager.h"
#include "welcome.h"
#include "about.h"
#include "book.h"



BookManager::BookManager(QWidget *parent, bool islogin) :
    QMainWindow(parent),
    ui(new Ui::BookManager)
{
    _islogin = islogin;
    setAttribute(Qt::WA_DeleteOnClose);//防止反复打开或互相调用可能造成运行过程中的内存泄漏，但目前没有完美解决互相调用的问题
    ui->setupUi(this);

    current_select_label = new QLabel;
    current_select_label->setText("当前选中：");
    ui->statusBar->addWidget(current_select_label);


    if(!islogin){//通过登录状态启用管理员功能
        ui->actionadd_book->setEnabled(false);
        ui->actionchange_book->setEnabled(false);
        ui->actiondelete_book->setEnabled(false);
        ui->actionlogout->setEnabled(false);
        ui->actionpurchase->setEnabled(false);
        ui->actionstatistics->setEnabled(false);
        ui->action_3->setEnabled(false);


//        connect(ui->tableView, &QTableView::doubleClicked(QModelIndex &index), [=](QModelIndex index){
//            qDebug()<<index.row()<<" "<<index.column();
//        });
//        connect(book_filter_dialog, &book_filter::book_filter_request, this, &get_book_filter_request);//无语，改了八百回发现原来是因为在if里面 上面的也是
    }
    emit on_actiondisable_action_for_selected_row_triggered();//当前未选中对象，禁用管理功能

    showBooks();//建立数据库连接并装载到QTableView
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁用自带的编辑

    book_filter_dialog = new book_filter(this);
    book_add_dialog = new book_add(this);
    book_change_dialog = new book_change(this);
    book_statics_dialog = new book_statics(this);

    books_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    connect(ui->tableView, &QTableView::doubleClicked, [=](QModelIndex index){
//        qDebug()<<index.row()<<" "<<index.column();
//    });测试双击返回值


    connect(book_filter_dialog, &book_filter::book_filter_request, this, &get_book_filter_request);//注意这里用到了子窗口对象，所以要提前new出来
    connect(book_add_dialog, &book_add::book_add_request, this, &get_book_add_request);//同上
    connect(book_change_dialog, &book_change::book_change_request, this, &get_book_change_request);//同上
}

BookManager::~BookManager()
{
    delete ui;
}

void BookManager::showBooks(){
    Book::connectSQLite();//建立与数据库的连接

    books_model = new QSqlTableModel(this);
    books_model->setTable("book");//连接到数据库中的表（书的数据）
    books_model->select();//选择查询所有

//    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableView->setHorizontalHeader(QStringList() << "ID" << "书名" << "作者" << "出版社" << "ISBN" << "单价" << "库存量" << "总销量" << "总进货量");
// 以上在尝试修改QTableView的表头，未果。

    ui->tableView->setModel(books_model);//装载到ui
}

void BookManager::get_book_filter_request(int fromwhere, QString searchdata, bool isAscending){
    QString filter;
    if(searchdata!=""){//若查询内容非空，则正常查询
        QString fromcolumn = books_model->headerData(fromwhere + 1, Qt::Horizontal, Qt::DisplayRole).toString();
        filter = QString("%1 like '%%2%'").arg(fromcolumn).arg(searchdata);//使用like语句和通配符实现模糊匹配

        //    books_model->setFilter(QString("book_name = %1").arg(searchdata));//test,没查到东西是因为字段名错了awa，实际上是对的
    }
    else{//否则就设置整个查询语句为空，达到选择所有的效果
        filter="";
    }
    qDebug()<<filter;

    if(isAscending){
        books_model->setSort(fromwhere + 1, Qt::AscendingOrder);
    }
    else{
        books_model->setSort(fromwhere + 1, Qt::DescendingOrder);
    }

    books_model->setFilter(filter);
    books_model->select();

    ui->tableView->setModel(books_model);//装载到ui

    emit on_actiondisable_action_for_selected_row_triggered();
}


void BookManager::get_book_add_request(Book newbook){
    QString sqls = QString("insert into book (name, author, press, isbn, price) values ('%1', '%2', '%3', '%4', %5)").arg(newbook.book_name).arg(newbook.book_author).arg(newbook.book_press).arg(newbook.book_isbn).arg(newbook.book_price);
    qDebug()<<sqls;

//    QSqlError error = Book::bookdb->lastError();
//    qDebug()<<error;



    QSqlQuery add_query;
    bool res = add_query.exec(sqls);
    if(!res){
        QMessageBox::critical(this, "录入失败", "ISBN重复，请检查已有图书");//执行失败，说明isbn重复（不完美的解决方案）
    }
    else{
        books_model->submitAll();
        //刷新
        books_model->setFilter("");
        books_model->select();
        ui->tableView->setModel(books_model);//装载到ui

        emit on_actiondisable_action_for_selected_row_triggered();
    }
}


void BookManager::get_book_change_request(Book thebook){
    QModelIndex Index1 = books_model->index(curRow, 1);
    QModelIndex Index2 = books_model->index(curRow, 2);
    QModelIndex Index3 = books_model->index(curRow, 3);
    QModelIndex Index4 = books_model->index(curRow, 4);
    QModelIndex Index5 = books_model->index(curRow, 5);
    books_model->setData(Index1, thebook.book_name);
    books_model->setData(Index2, thebook.book_author);
    books_model->setData(Index3, thebook.book_press);
    books_model->setData(Index4, thebook.book_isbn);
    books_model->setData(Index5, thebook.book_price);
    bool res = books_model->submitAll();
    if(!res){
        QMessageBox::critical(this, "修改失败", "ISBN重复，请检查已有图书");//执行失败，说明isbn重复（不完美的解决方案）
        emit on_actionrefresh_filter_triggered();//刷新，撤销修改的显示效果
    }
    else{
        emit on_actiondisable_action_for_selected_row_triggered();
    }
}



void BookManager::on_actionexit_triggered()//退出应用程序
{
    this->close();
}


void BookManager::on_actionlogout_triggered()//退出登录，返回到欢迎界面
{
    Welcome *welcome_dialog = new Welcome;
    welcome_dialog->show();
    this->close();
}


void BookManager::on_action_about_triggered()//关于界面
{
    About about_this_app(this);
    about_this_app.exec();
}



//以下为添加，筛选按钮的相应，不依托TableView中选中的项，操作逻辑类似。
void BookManager::on_action_filter_triggered()//筛选，唤起筛选界面
{
    book_filter_dialog->exec();
}


void BookManager::on_actionadd_book_triggered()//添加，唤起添加界面
{
    book_add_dialog->exec();
}



void BookManager::on_actionchange_book_triggered()
{
    book_change_dialog->exec();
}

void BookManager::on_actionstatistics_triggered()
{
    unsigned long long books_sum = books_model->rowCount();
    double sale_sum = 0;


    for(int row=0; row<books_model->rowCount(); ++row) {
        QModelIndex index5 = books_model->index(row, 5);
        QModelIndex index7 = books_model->index(row, 7);

        QSqlRecord record5 = books_model->record(index5.row());
        QSqlRecord record7 = books_model->record(index7.row());

        double temp = record5.value("price").toDouble()*record7.value("sold_total").toInt();

        sale_sum += temp;
    }
    book_statics_dialog->book_total = books_sum;
    book_statics_dialog->sale_total = sale_sum;
    book_statics_dialog->updatevalue();
    book_statics_dialog->exec();
}




void BookManager::on_actionrefresh_filter_triggered()
{
    emit on_actiondisable_action_for_selected_row_triggered();

    books_model->setSort(0, Qt::AscendingOrder);
    books_model->setFilter("");
    books_model->select();
    ui->tableView->setModel(books_model);//装载到ui
}


void BookManager::on_tableView_clicked(const QModelIndex &index)//这是单击TableView的槽函数，用于侦测当前选中的行对象供删除和修改
{
    if(_islogin){//未登录下，无法启用管理功能
        emit on_actionenable_action_for_selected_row_triggered();
    }
    curRow = ui->tableView->currentIndex().row();
    current_select_label->setText("当前选中：第 "+QString::number(curRow+1)+" 行");
    qDebug()<<curRow;
}


void BookManager::on_actiondelete_book_triggered()//删除，直接作用于当前选中行
{
    int res = QMessageBox::warning(this, "警告", "你确定要删除第 " + QString::number(curRow+1) + " 行的数据吗", QMessageBox::Yes | QMessageBox::No);
    if(res == QMessageBox::Yes){
        books_model->removeRow(curRow);
        books_model->submitAll();
        current_select_label->setText("当前选中：");
        emit on_actionrefresh_filter_triggered();
        emit on_actiondisable_action_for_selected_row_triggered();
    }
}


void BookManager::on_actiondisable_action_for_selected_row_triggered()//禁用仅限选中行后的功能
{
    current_select_label->setText("当前选中：");
    ui->actiondelete_book->setEnabled(false);
    ui->actionchange_book->setEnabled(false);
    ui->actionpurchase->setEnabled(false);
    ui->action_3->setEnabled(false);
}


void BookManager::on_actionenable_action_for_selected_row_triggered()
{
    ui->actiondelete_book->setEnabled(true);
    ui->actionchange_book->setEnabled(true);
    ui->actionpurchase->setEnabled(true);
    ui->action_3->setEnabled(true);
}




void BookManager::on_action_3_triggered()
{
    //获取当前存量
    QModelIndex Index6 = books_model->index(curRow, 6);
    QSqlRecord recordd = books_model->record(Index6.row());
    unsigned long long current_quantity = recordd.value("quantity").toInt();

    //获取出售数量
    long long addsale = QInputDialog::getInt(this, "售卖", "输入售卖数量:");

    //获取当前总销量
    QModelIndex Index7 = books_model->index(curRow, 7);
    QSqlRecord record = books_model->record(Index7.row());
    unsigned long long currentsalenum = record.value("sold_total").toInt();

    if(addsale<0){
        QMessageBox::critical(this, "错误", "数值非法");
    }
    else if(current_quantity < addsale){
        QMessageBox::critical(this, "错误", "库存量不够，售卖失败");
    }
    else{

        unsigned long long salenum = addsale + currentsalenum;
        unsigned long long quantitynum = current_quantity - addsale;
        books_model->setData(Index7, salenum);
        books_model->setData(Index6, quantitynum);
        books_model->submitAll();
    }
}


void BookManager::on_actionpurchase_triggered()
{
    //获取当前存量
    QModelIndex Index6 = books_model->index(curRow, 6);
    QSqlRecord recordd = books_model->record(Index6.row());
    unsigned long long current_quantity = recordd.value("quantity").toInt();

    //获取购入量
    long long addpurchase = QInputDialog::getInt(this, "购入", "输入购入数量:");

    //获取当前总购买量
    QModelIndex Index8 = books_model->index(curRow, 8);
    QSqlRecord record = books_model->record(Index8.row());
    unsigned long long currentpurchasenum = record.value("purchase_total").toInt();

    if(addpurchase<0){
        QMessageBox::critical(this, "错误", "数值非法");
    }
    else{
        unsigned long long purchasenum = addpurchase + currentpurchasenum;
        books_model->setData(Index6, current_quantity + addpurchase);
        books_model->setData(Index8, purchasenum);
        books_model->submitAll();
    }

}



