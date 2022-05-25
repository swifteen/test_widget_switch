#include "preview_widget.h"
#include "ui_preview_widget.h"

PreviewWidget::PreviewWidget(QWidget *parent)
    : BaseDialog(parent)
    , ui(new Ui::PreviewWidget)
{
    ui->setupUi(this);
    setWindowTitle("PreviewWidget");
}

PreviewWidget::~PreviewWidget()
{
    delete ui;
}

