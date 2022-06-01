#include "sample_dialog.h"
#include "ui_sample_dialog.h"
#include <QDebug>
#include "patient_dialog.h"
#include "file_manager_dialog.h"
#include "setting_dialog.h"

SampleDialog::SampleDialog(QWidget *parent)
    : BaseMainDialog(MAIN_DIALOG_TYPE_SAMPLE,parent)
    , ui(new Ui::SampleDialog)
{
    ui->setupUi(this);
}

SampleDialog::~SampleDialog()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    delete ui;
}

void SampleDialog::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<this<<event<<event->key();
    Qt::Key key = static_cast<Qt::Key>(event->key());

    switch(key)
    {
    default:
        break;
    }
    BaseMainDialog::keyPressEvent(event);
}

void SampleDialog::s_func_trigger(int func_index, const QVariant& data)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<func_index<<data;
    switch(func_index)
    {
    //F1~F7键转给FuncBar处理
    case FuncBar::FUNC_BAR_F1:
        openPatientDialog();
        break;
    case FuncBar::FUNC_BAR_F2:
        break;
    case FuncBar::FUNC_BAR_F3:
        break;
    case FuncBar::FUNC_BAR_F4:
        break;
    case FuncBar::FUNC_BAR_F5:
        break;
    case FuncBar::FUNC_BAR_F6:
        open_fileManager();
        break;
    case FuncBar::FUNC_BAR_F7:
        open_setting();
        break;
    default:
        break;
    }
}

void SampleDialog::openPatientDialog()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<"enter Patient_Dialog";
    Patient_Dialog dlg;
    dlg.exec();
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<"exit Patient_Dialog";
}

void SampleDialog::open_fileManager()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<"enter FileManagerDialog";
    FileManagerDialog dlg;
    dlg.exec();
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<"exit FileManagerDialog";
}

void SampleDialog::open_setting()
{
    SettingDialog dlg;
    dlg.exec();
}
