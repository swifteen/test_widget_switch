#ifndef PREVIEW_DIALOG_H
#define PREVIEW_DIALOG_H

#include <QWidget>
#include "base_main_dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class PreviewDialog; }
QT_END_NAMESPACE

class PreviewDialog : public BaseMainDialog
{
    Q_OBJECT

public:
    PreviewDialog(QWidget *parent = nullptr);
    ~PreviewDialog();
protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    virtual void s_func_trigger(int func_index,const QVariant& data);
private:
    Ui::PreviewDialog *ui;
};
#endif // PREVIEW_DIALOG_H
