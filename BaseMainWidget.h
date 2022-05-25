#ifndef BaseMainWidget_H
#define BaseMainWidget_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include "funcbar.h"
#include "statusbar.h"
class BaseMainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseMainWidget(QWidget *parent = nullptr);
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
signals:

private slots:
    void s_close_clicked();
private:
    QPushButton* m_pClosePbtn;
    QPoint m_move_point;      //移动的距离
    bool m_bMousePress;       //按下鼠标左键
    StatusBar* m_pStatusBar;
    FuncBar* m_pFuncBar;
};

#endif // BaseMainWidget_H
