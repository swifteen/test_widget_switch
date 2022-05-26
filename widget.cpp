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

void Widget::s_func_trigger(int func_index, int index)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<func_index<<index;
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
    Patient_Dialog dlg;
    dlg.exec();
}

void Widget::open_fileManager()
{
    FileManagerWidget * widget = new FileManagerWidget;
    widget->show();
}

void Widget::open_setting()
{
    SettingWidget * widget = new SettingWidget;
    widget->show();
}
