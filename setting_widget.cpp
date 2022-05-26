#include "setting_widget.h"
#include "ui_setting_widget.h"
#include <QDebug>
SettingWidget::SettingWidget(QWidget *parent)
    : BaseMainWidget(MAIN_WIDGET_TYPE_SETTING,parent)
    , ui(new Ui::SettingWidget)
{
    ui->setupUi(this);
    setWindowTitle("SettingWidget");
}

SettingWidget::~SettingWidget()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    delete ui;
}

void SettingWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<this<<event<<event->key();
    Qt::Key key = static_cast<Qt::Key>(event->key());

    switch(key)
    {
    case Qt::Key_F1:

        break;
    case Qt::Key_F2:
    case Qt::Key_F3:
    case Qt::Key_F4:
    case Qt::Key_F5:
    case Qt::Key_F6:

        break;
    case Qt::Key_F7:

        break;
    case Qt::Key_Escape:
        close();
        break;
    default:
        break;
    }
    BaseMainWidget::keyPressEvent(event);
}

void SettingWidget::s_func_trigger(int func_index,const QVariant& data)
{
qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<func_index<<data;
}

