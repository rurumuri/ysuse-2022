#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qsqldatabase.h"
#include "qmessagebox.h"
#include "db.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMessageBox qm1, qm2;
    qm1.setText("db connet failed.");
    qm2.setText("Insert successed. the table will be deleted.");

    //test
    if(!DatabaseInitialize()) qm1.exec();
    else {
        SQLTest("CREATE TABLE dbo.tst (ID INT PRIMARY KEY NOT NULL, NAME NVARCHAR(10) NOT NULL)");
        qm2.exec();
        SQLTest("DROP TABLE dbo.tst");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

