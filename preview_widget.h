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
    MainWidgetType_e mainWidgetType(){return MAIN_WIDGET_TYPE_PREVIEW;}
private:
    Ui::PreviewWidget *ui;
};
#endif // PREVIEW_WIDGET_H
