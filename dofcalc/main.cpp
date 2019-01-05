#include "mainwindow.h"
#include <QApplication>
#include "logger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./icon.png"));
    InitLog();
    MainWindow w;
    w.show();
    int result = a.exec();
    CloseLog();
    return result;
}
