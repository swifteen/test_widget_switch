#include "preview_widget.h"
#include "ui_preview_widget.h"
#include <QDebug>
PreviewWidget::PreviewWidget(QWidget *parent)
    : BaseMainWidget(MAIN_WIDGET_TYPE_PREVIEW,parent)
    , ui(new Ui::PreviewWidget)
{
    ui->setupUi(this);
    setWindowTitle("PreviewWidget");
}

PreviewWidget::~PreviewWidget()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    delete ui;
}
void PreviewWidget::keyPressEvent(QKeyEvent *event)
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
void PreviewWidget::s_func_trigger(int func_index,const QVariant& data)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<func_index<<data;
    switch(func_index)
    {
    case FuncBar::FUNC_BAR_F1:

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

