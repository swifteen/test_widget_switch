#include "patient_dialog.h"
#include "ui_patient_dialog.h"
#include <QDebug>
Patient_Dialog::Patient_Dialog(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::Patient_Dialog)
{
    ui->setupUi(this);
	setWindowTitle("long long \n test title");
}

Patient_Dialog::~Patient_Dialog()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    delete ui;
}
