#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "basedialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public BaseDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

protected:
    void closeEvent(QCloseEvent *e);
private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
