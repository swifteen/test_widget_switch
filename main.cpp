#include "sample_dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SampleDialog w;
    w.exec();
    return a.exec();
}
