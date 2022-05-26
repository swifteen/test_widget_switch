#ifndef SETTING_WIDGET_H
#define SETTING_WIDGET_H

#include <QWidget>
#include "BaseMainWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class SettingWidget; }
QT_END_NAMESPACE

class SettingWidget : public BaseMainWidget
{
    Q_OBJECT

public:
    SettingWidget(QWidget *parent = nullptr);
    ~SettingWidget();
    MainWidgetType_e mainWidgetType(){return MAIN_WIDGET_TYPE_SETTING;}
private:
    Ui::SettingWidget *ui;
};
#endif // SETTING_WIDGET_H
