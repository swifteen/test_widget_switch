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
private slots:
    virtual void s_func_trigger(int func_index,int index);
private:
    Ui::SettingWidget *ui;
};
#endif // SETTING_WIDGET_H
