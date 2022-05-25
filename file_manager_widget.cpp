#include "file_manager_widget.h"
#include "ui_file_manager_widget.h"
#include <QDebug>
FileManagerWidget::FileManagerWidget(QWidget *parent)
    : BaseMainWidget(parent)
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

