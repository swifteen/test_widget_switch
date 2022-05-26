#ifndef BaseMainWidget_H
#define BaseMainWidget_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include "funcbar.h"
#include "statusbar.h"
#include "main_widget_def.h"

class BaseMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BaseMainWidget(MainWidgetType_e mainWidgetType,QWidget *parent = nullptr);
    virtual ~BaseMainWidget();
    virtual MainWidgetType_e mainWidgetType(){
        return MAIN_WIDGET_TYPE_UNKNOW;
    };

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    void initFuncBarControl(MainWidgetType_e mainWidgetType);
private slots:
    void s_close_clicked();
    virtual void s_func_trigger(int func_index,int index) = 0;
private:
    QPushButton* m_pClosePbtn;
    QPoint m_move_point;      //移动的距离
    bool m_bMousePress;       //按下鼠标左键
    StatusBar* m_pStatusBar;
    FuncBar* m_pFuncBar;
};

#endif // BaseMainWidget_H
