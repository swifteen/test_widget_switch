#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "BaseMainWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public BaseMainWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    virtual void s_func_trigger(int func_index,int index);
private:
    void openPatientDialog();
    void open_fileManager();
    void open_setting();
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
