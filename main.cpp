#include "sample_dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SampleDialog w;
    w.exec();
    qApp->setStyleSheet("*{font: normal 100px “微软雅黑”;}");
    return a.exec();
}
