#include "dialog.h"
#include "ui_dialog.h"
#include "basedialog.h"
#include <QDebug>
Dialog::Dialog(QWidget *parent)
    : BaseDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("long long \n test title");
    setFixedSize(1000,800);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::closeEvent(QCloseEvent *e)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    BaseDialog::closeEvent(e);
}
