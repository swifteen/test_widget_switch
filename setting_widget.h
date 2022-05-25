#ifndef SETTING_WIDGET_H
#define SETTING_WIDGET_H

#include <QWidget>
#include "basedialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class SettingWidget; }
QT_END_NAMESPACE

class SettingWidget : public BaseDialog
{
    Q_OBJECT

public:
    SettingWidget(QWidget *parent = nullptr);
    ~SettingWidget();

private:
    Ui::SettingWidget *ui;
};
#endif // SETTING_WIDGET_H
