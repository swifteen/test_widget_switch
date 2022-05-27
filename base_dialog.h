#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QMouseEvent>
class BaseDialog : public QDialog
{
    Q_OBJECT
public:
    explicit BaseDialog(QWidget *parent = nullptr);
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
signals:

private:
    QPushButton* m_pClosePbtn;
    QPoint m_move_point;      //移动的距离
    bool m_bMousePress;       //按下鼠标左键
};

#endif // BASEDIALOG_H
