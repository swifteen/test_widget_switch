#include "file_manager_widget.h"
#include "ui_file_manager_widget.h"
#include <QDebug>
#include "preview_widget.h"
FileManagerWidget::FileManagerWidget(QWidget *parent)
    : BaseMainWidget(MAIN_WIDGET_TYPE_FILE_MANAGER,parent)
    , ui(new Ui::FileManagerWidget)
{
    ui->setupUi(this);
    setWindowTitle("FileManagerWidget");
}

FileManagerWidget::~FileManagerWidget()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    delete ui;
}

void FileManagerWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<this<<event<<event->key();
    Qt::Key key = static_cast<Qt::Key>(event->key());

    switch(key)
    {
    //F1~F7键转给FuncBar处理
    case Qt::Key_F1:
        open_preview();
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

void FileManagerWidget::s_func_trigger(int func_index,const  QVariant& data)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<func_index<<data;
    switch(func_index)
    {
    //F1~F7键转给FuncBar处理
    case FuncBar::FUNC_BAR_F1:
        open_preview();
        break;
    case FuncBar::FUNC_BAR_F2:
    case FuncBar::FUNC_BAR_F3:
    case FuncBar::FUNC_BAR_F4:
    case FuncBar::FUNC_BAR_F5:
    case FuncBar::FUNC_BAR_F6:

        break;
    case FuncBar::FUNC_BAR_F7:

        break;
    default:
        break;
    }
}
void FileManagerWidget::open_preview()
{
    PreviewWidget*  widget = new PreviewWidget;
    widget->show();
}
