#include "setting_widget.h"
#include "ui_setting_widget.h"
#include <QDebug>
SettingWidget::SettingWidget(QWidget *parent)
    : BaseMainWidget(MAIN_WIDGET_TYPE_SETTING,parent)
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

void SettingWidget::s_func_trigger(int func_index, int index)
{
qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<func_index<<index;
}

