#ifndef FILE_MANAGER_WIDGET_H
#define FILE_MANAGER_WIDGET_H

#include <QWidget>
#include "BaseMainWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class FileManagerWidget; }
QT_END_NAMESPACE

class FileManagerWidget : public BaseMainWidget
{
    Q_OBJECT

public:
    FileManagerWidget(QWidget *parent = nullptr);
    ~FileManagerWidget();
    MainWidgetType_e mainWidgetType(){return MAIN_WIDGET_TYPE_FILE_MANAGER;}

private:
    Ui::FileManagerWidget *ui;
};
#endif // FILE_MANAGER_WIDGET_H
