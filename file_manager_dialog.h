#ifndef FILE_MANAGER_DIALOG_H
#define FILE_MANAGER_DIALOG_H

#include <QWidget>
#include "base_main_dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class FileManagerDialog; }
QT_END_NAMESPACE

class FileManagerDialog : public BaseMainDialog
{
    Q_OBJECT

public:
    FileManagerDialog(QWidget *parent = nullptr);
    ~FileManagerDialog();
protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    virtual void s_func_trigger(int func_index,const QVariant& data);
private:
    void open_preview();
private:
    Ui::FileManagerDialog *ui;
};
#endif // FILE_MANAGER_DIALOG_H
