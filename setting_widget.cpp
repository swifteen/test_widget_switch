#include "setting_widget.h"
#include "ui_setting_widget.h"
#include <QDebug>
SettingWidget::SettingWidget(QWidget *parent)
    : BaseMainWidget(parent)
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

