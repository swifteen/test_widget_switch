#include "setting_dialog.h"
#include "ui_setting_dialog.h"
#include <QDebug>
SettingDialog::SettingDialog(QWidget *parent)
    : BaseMainDialog(MAIN_DIALOG_TYPE_SETTING,parent)
    , ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    setWindowTitle("SettingDialog");
}

SettingDialog::~SettingDialog()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    delete ui;
}

void SettingDialog::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<this<<event<<event->key();
    Qt::Key key = static_cast<Qt::Key>(event->key());

    switch(key)
    {
    case Qt::Key_F1:
    case Qt::Key_F2:
    case Qt::Key_F3:
    case Qt::Key_F4:
    case Qt::Key_F5:
    case Qt::Key_F6:
    case Qt::Key_F7:
		handleKeyPressEvent(key);
        break;
    case Qt::Key_Escape:
        close();
        break;
    default:
        break;
    }
    BaseMainDialog::keyPressEvent(event);
}

void SettingDialog::s_func_trigger(int func_index,const QVariant& data)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<func_index<<data;
}

