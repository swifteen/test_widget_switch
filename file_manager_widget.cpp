#include "file_manager_widget.h"
#include "ui_file_manager_widget.h"

FileManagerWidget::FileManagerWidget(QWidget *parent)
    : BaseMainWidget(parent)
    , ui(new Ui::FileManagerWidget)
{
    ui->setupUi(this);
    setWindowTitle("FileManagerWidget");
}

FileManagerWidget::~FileManagerWidget()
{
    delete ui;
}

