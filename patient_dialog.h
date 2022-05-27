#ifndef PATIENT_DIALOG_H
#define PATIENT_DIALOG_H

#include "base_dialog.h"

namespace Ui {
class Patient_Dialog;
}

class Patient_Dialog : public BaseDialog
{
    Q_OBJECT

public:
    explicit Patient_Dialog(QWidget *parent = nullptr);
    ~Patient_Dialog();

private:
    Ui::Patient_Dialog *ui;
};

#endif // PATIENT_DIALOG_H
