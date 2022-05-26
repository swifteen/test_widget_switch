#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "BaseMainWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public BaseMainWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
MainWidgetType_e mainWidgetType(){return MAIN_WIDGET_TYPE_SAMPLE;}
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
