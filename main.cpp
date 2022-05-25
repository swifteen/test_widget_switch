#include "widget.h"

#include <QApplication>
#include "windowmanager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    WindowManager* obj = new WindowManager;
    return a.exec();
}
