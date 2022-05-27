#ifndef DATETIME_DIALOG_H
#define DATETIME_DIALOG_H

#include "base_dialog.h"

namespace Ui {
class DateTimeDialog;
}

class DateTimeDialog : public BaseDialog
{
    Q_OBJECT

public:
    explicit DateTimeDialog(QWidget *parent = nullptr);
    ~DateTimeDialog();

private:
    Ui::DateTimeDialog *ui;
};

#endif // DATETIME_DIALOG_H
