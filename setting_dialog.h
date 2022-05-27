#ifndef SETTING_DIALOG_H
#define SETTING_DIALOG_H

#include <QWidget>
#include "base_main_dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class SettingDialog; }
QT_END_NAMESPACE

class SettingDialog : public BaseMainDialog
{
    Q_OBJECT

public:
    SettingDialog(QWidget *parent = nullptr);
    ~SettingDialog();
protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    virtual void s_func_trigger(int func_index,const QVariant& data);
private:
    Ui::SettingDialog *ui;
};
#endif // SETTING_DIALOG_H
