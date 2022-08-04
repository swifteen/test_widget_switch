#include "base_dialog.h"
#include <QDebug>
#include <QFontMetrics>
#include <QFont>
#include <QPainter>
#include <QStyleOptionTitleBar>
#include <QApplication>

BaseDialog::BaseDialog(QWidget *parent) : QDialog(parent,Qt::FramelessWindowHint)
{
    setAttribute(Qt::WA_TranslucentBackground);//实现圆角窗口时，需要设置的最关键属性
    setObjectName("BaseDialog");//用于qss
    setStyleSheet("QDialog::title {"
                        "height: 50px;"/*标题栏高度*/
                  "background: #1E2D5A;"/*标题栏背景色*/
                  "border-top-left-radius: 10px;"
                        "border-top-right-radius: 10px;}"

                        "QDialog#BaseDialog{"
                        "color: #00ff00;"/*标题栏文字颜色*/
                  "font-size: 24px;"/*标题栏文字大小*/
                  "background: #00FF00;"/*Dialog背景色*/
                  "border-bottom-left-radius: 10px;"
                        "border-bottom-right-radius: 10px;}"
                        );
    //初始化关闭按钮
    m_pClosePbtn = new QPushButton(this);
    m_pClosePbtn->setText("X");
    m_pClosePbtn->setObjectName("DialogCloseButton");//用于qss
    connect(m_pClosePbtn,&QPushButton::clicked,this,&QDialog::close);
    m_pClosePbtn->setStyleSheet("QPushButton#DialogCloseButton{"
                                "color:white;"
                                "border-radius: 10px;"
                                "background:transparent;"
                                "border-color: transparent;}"

                                "QPushButton#DialogCloseButton:focus{"
                                "border:0px solid lightgray;"
                                "background: #DA3610;}"

                                "QPushButton#DialogCloseButton:hover{"
                                "border:0px solid lightgray;"
                                "background: #DA36F0;}"

                                "QPushButton#DialogCloseButton:pressed{"
                                "border:0px solid lightgray;"
                                "background: #990000;}"
                                );
}

void BaseDialog::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)

    QPainter p(this);
    QStyle* style = this->style();
    QRect active_area = this->rect();
    int titlebar_height = 0;

    // Titlebar.
    QStyleOptionTitleBar t_opt;
    t_opt.initFrom(this);//可以获取this的qss风格
    titlebar_height = style->pixelMetric(QStyle::PM_TitleBarHeight, &t_opt, this);

    t_opt.rect = QRect(0, 0, this->width(), titlebar_height);
    t_opt.titleBarState = this->windowState();
    t_opt.text = t_opt.fontMetrics.elidedText(this->windowTitle(), Qt::ElideRight, t_opt.rect.width());
    //绘制标题栏，不包含标题文字
    style->drawComplexControl(QStyle::CC_TitleBar, &t_opt, &p, this);
    //绘制标题文字
    style->drawItemText(&p, t_opt.rect, Qt::AlignCenter, t_opt.palette, true, t_opt.text, QPalette::Text);//注意参数QPalette::Text决定文字的颜色
    //设置关闭按钮位置
    m_pClosePbtn->setGeometry(QRect(this->width() - m_pClosePbtn->width(), 0, m_pClosePbtn->width(), titlebar_height));
    // Background widget.
    active_area.setTopLeft(QPoint(0, titlebar_height));
    this->setContentsMargins(0, titlebar_height, 0, 0);
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<rect();
    QStyleOption w_opt;
    w_opt.initFrom(this);//可以获取this的qss风格
    w_opt.rect = active_area;
    style->drawPrimitive(QStyle::PE_Widget, &w_opt, &p, this);
}

void BaseDialog::closeEvent(QCloseEvent *e)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    QDialog::closeEvent(e);
}
void BaseDialog::mousePressEvent(QMouseEvent* event)
{
    //只能是鼠标左键移动和改变大小
    if(Qt::LeftButton == event->button())
    {
        m_bMousePress = true;
    }

    //窗口移动距离
    m_move_point = event->globalPos() - pos();
    QDialog::mousePressEvent(event);
}
void BaseDialog::mouseReleaseEvent(QMouseEvent* event)
{
    m_bMousePress = false;
    QDialog::mouseReleaseEvent(event);
}

void BaseDialog::mouseMoveEvent(QMouseEvent* event)
{
    //移动窗口
    if(m_bMousePress)
    {
        QPoint move_pos = event->globalPos();
        move(move_pos - m_move_point);
    }
    QDialog::mouseMoveEvent(event);
}

void BaseDialog::resizeEvent(QResizeEvent *event)
{
    //qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<windowTitle();
    //qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<rect();
    QDialog::resizeEvent(event);
}
