#include "welcome.h"
//#include "book.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Welcome welcome_dialog;
    welcome_dialog.show();

    return a.exec();
}
