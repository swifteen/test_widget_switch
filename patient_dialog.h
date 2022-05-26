#ifndef PATIENT_DIALOG_H
#define PATIENT_DIALOG_H

#include <QDialog>

namespace Ui {
class Patient_Dialog;
}

class Patient_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Patient_Dialog(QWidget *parent = nullptr);
    ~Patient_Dialog();

private:
    Ui::Patient_Dialog *ui;
};

#endif // PATIENT_DIALOG_H
