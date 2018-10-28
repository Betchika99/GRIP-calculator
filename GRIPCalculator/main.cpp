#include "view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View view;
    view.setMinimumSize(870, 760);
    view.setMaximumSize(870, 760);
    view.show();

    return a.exec();
}
