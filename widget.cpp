#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : BaseMainWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    delete ui;
}

