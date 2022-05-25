#include "funcbar.h"
#include "ui_funcbar.h"

FuncBar::FuncBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FuncBar)
{
    ui->setupUi(this);
}

FuncBar::~FuncBar()
{
    delete ui;
}
