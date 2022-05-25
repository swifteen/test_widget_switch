#include "setting_widget.h"
#include "ui_setting_widget.h"

SettingWidget::SettingWidget(QWidget *parent)
    : BaseDialog(parent)
    , ui(new Ui::SettingWidget)
{
    ui->setupUi(this);
    setWindowTitle("SettingWidget");
}

SettingWidget::~SettingWidget()
{
    delete ui;
}

