#include "preview_widget.h"
#include "ui_preview_widget.h"
#include <QDebug>
PreviewWidget::PreviewWidget(QWidget *parent)
    : BaseMainWidget(parent)
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

