#ifndef BaseMainDialog_H
#define BaseMainDialog_H

#include <QDialog>
#include <QPushButton>
#include <QMouseEvent>
#include "funcbar.h"
#include "statusbar.h"
#include "main_dialog_def.h"

class BaseMainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BaseMainDialog(MainDialogType_e mainWidgetType,QWidget *parent = nullptr);
    virtual ~BaseMainDialog();
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    void initFuncBarControl(MainDialogType_e mainWidgetType);
private slots:
    void s_close_clicked();
    virtual void s_func_trigger(int func_index,const QVariant& data) = 0;
private:
    QPoint m_move_point;      //移动的距离
    bool m_bMousePress;       //按下鼠标左键
    StatusBar* m_pStatusBar;
    FuncBar* m_pFuncBar;
};

#endif // BaseMainDialog_H
