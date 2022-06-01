#include "file_manager_dialog.h"
#include "ui_file_manager_dialog.h"
#include <QDebug>
#include "preview_dialog.h"
FileManagerDialog::FileManagerDialog(QWidget *parent)
    : BaseMainDialog(MAIN_DIALOG_TYPE_FILE_MANAGER,parent)
    , ui(new Ui::FileManagerDialog)
{
    ui->setupUi(this);
    setWindowTitle("FileManagerDialog");
}

FileManagerDialog::~FileManagerDialog()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    delete ui;
}

void FileManagerDialog::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<this<<event<<event->key();
    Qt::Key key = static_cast<Qt::Key>(event->key());

    switch(key)
    {
    case Qt::Key_Escape:
        close();
        break;
    default:
        break;
    }
    BaseMainDialog::keyPressEvent(event);
}

void FileManagerDialog::s_func_trigger(int func_index,const  QVariant& data)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<func_index<<data;
    switch(func_index)
    {
    //F1~F7键转给FuncBar处理
    case FuncBar::FUNC_BAR_F1:
        open_preview();
        break;
    case FuncBar::FUNC_BAR_F2:
    case FuncBar::FUNC_BAR_F3:
    case FuncBar::FUNC_BAR_F4:
    case FuncBar::FUNC_BAR_F5:
    case FuncBar::FUNC_BAR_F6:

        break;
    case FuncBar::FUNC_BAR_F7:

        break;
    default:
        break;
    }
}
void FileManagerDialog::open_preview()
{
    PreviewDialog dlg;
    dlg.exec();
}
