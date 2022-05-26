#ifndef PREVIEW_WIDGET_H
#define PREVIEW_WIDGET_H

#include <QWidget>
#include "BaseMainWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class PreviewWidget; }
QT_END_NAMESPACE

class PreviewWidget : public BaseMainWidget
{
    Q_OBJECT

public:
    PreviewWidget(QWidget *parent = nullptr);
    ~PreviewWidget();
private slots:
    virtual void s_func_trigger(int func_index,int index);
private:
    Ui::PreviewWidget *ui;
};
#endif // PREVIEW_WIDGET_H
