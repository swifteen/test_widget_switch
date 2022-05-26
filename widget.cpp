#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "patient_dialog.h"
#include "file_manager_widget.h "
#include "setting_widget.h"
Widget::Widget(QWidget *parent)
    : BaseMainWidget(MAIN_WIDGET_TYPE_SAMPLE,parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<this<<event<<event->key();
    Qt::Key key = static_cast<Qt::Key>(event->key());

    switch(key)
    {
    //F1~F7键转给FuncBar处理
    case Qt::Key_F1:
        openPatientDialog();
        break;
    case Qt::Key_F2:
    case Qt::Key_F3:
    case Qt::Key_F4:
    case Qt::Key_F5:
    case Qt::Key_F6:
        open_fileManager();
        break;
    case Qt::Key_F7:
        open_setting();
        break;
    default:
        break;
    }
    BaseMainWidget::keyPressEvent(event);
}

void Widget::s_func_trigger(int func_index, const QVariant& data)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<func_index<<data;
    switch(func_index)
    {
    //F1~F7键转给FuncBar处理
    case FuncBar::FUNC_BAR_F1:
        openPatientDialog();
        break;
    case FuncBar::FUNC_BAR_F2:
    case FuncBar::FUNC_BAR_F3:
    case FuncBar::FUNC_BAR_F4:
    case FuncBar::FUNC_BAR_F5:
    case FuncBar::FUNC_BAR_F6:
        open_fileManager();
        break;
    case FuncBar::FUNC_BAR_F7:
        open_setting();
        break;
    default:
        break;
    }
}

void Widget::openPatientDialog()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<"enter Patient_Dialog";
    Patient_Dialog dlg;
    dlg.exec();
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<"exit Patient_Dialog";
}

void Widget::open_fileManager()
{
        qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<"enter FileManagerWidget";
    FileManagerWidget * widget = new FileManagerWidget;
    widget->show();
     qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<"exit FileManagerWidget";
}

void Widget::open_setting()
{
    SettingWidget * widget = new SettingWidget;
    widget->show();
}
