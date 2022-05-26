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
protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    virtual void s_func_trigger(int func_index,const QVariant& data);
private:
    Ui::FileManagerWidget *ui;
    void open_preview();
};
#endif // FILE_MANAGER_WIDGET_H
