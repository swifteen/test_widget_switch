#ifndef SAMPLE_DIALOG_H
#define SAMPLE_DIALOG_H

#include <QWidget>
#include "base_main_dialog.h"
#include "sample_widget_base.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SampleDialog; }
QT_END_NAMESPACE

class SampleDialog : public BaseMainDialog
{
    Q_OBJECT

public:
    SampleDialog(QWidget *parent = nullptr);
    ~SampleDialog();
protected:
	void resizeEvent(QResizeEvent *event);
    void keyPressEvent(QKeyEvent *event);
private slots:
    virtual void s_func_trigger(int func_index,const QVariant& data);
private:
	void setupSampleWidget();
    void openPatientDialog();
    void open_fileManager();
    void open_setting();
private:
    Ui::SampleDialog *ui;
	SampleWidgetBase* m_pSampleWidget;
};
#endif // SAMPLE_DIALOG_H
