#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DashboardProcess w;
    w.setUsedValue(70);
    w.show();

    return a.exec();
}
