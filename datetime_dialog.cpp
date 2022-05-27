#include "datetime_dialog.h"
#include "ui_datetime_dialog.h"
#include <QDebug>
DateTimeDialog::DateTimeDialog(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DateTimeDialog)
{
    ui->setupUi(this);
    setWindowTitle("DateTime Setting");
}

DateTimeDialog::~DateTimeDialog()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    delete ui;
}
