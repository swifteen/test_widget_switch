#include "sample_widget.h"

#include <QApplication>
#include "windowmanager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SampleWidget w;
    w.show();
    return a.exec();
}
