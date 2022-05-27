#include "base_main_dialog.h"
#include <QDebug>
#include <QFontMetrics>
#include <QFont>
#include <QPainter>
#include <QStyleOptionTitleBar>
#include <QApplication>
#include <QGraphicsDropShadowEffect>

BaseMainDialog::BaseMainDialog(MainDialogType_e mainWidgetType,QWidget *parent) :
    QDialog(parent,Qt::FramelessWindowHint),
    m_pClosePbtn(nullptr),
    m_bMousePress(false),
    m_pStatusBar(nullptr),
    m_pFuncBar(nullptr)
{
    setWindowModality(Qt::ApplicationModal);
    //setAttribute(Qt::WA_DeleteOnClose);
    //setWindowState(Qt::WindowFullScreen);//TODO 统一设置窗口全屏属性
//    setAttribute(Qt::WA_TranslucentBackground);//实现圆角窗口时，需要设置的最关键属性
    //    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    //    effect->setBlurRadius(20);
    //    effect->setColor(QColor(Qt::darkYellow));
    //    this->setGraphicsEffect(effect);
    this->setObjectName("BaseMainDialog");//用于qss
    this->setStyleSheet("QWidget::title {"

                        "height: 50px;"/*标题栏高度*/
                        "background: #1E2D5A;"/*标题栏背景色*/
                        "border-top-left-radius: 10px;"
                        "border-top-right-radius: 10px;}"

                        "QWidget#BaseMainDialog{"
                        "color: #00ff00;"/*标题栏文字颜色*/
                        "font-size: 24px;"/*标题栏文字大小*/
                        "font-weight:900;"
                        "background: #3E81DA;"/*Dialog背景色*/
                        "border-bottom-left-radius: 10px;"
                        "border-bottom-right-radius: 10px;}"
                        );
    //初始化关闭按钮
//    m_pClosePbtn = new QPushButton(this);
//    m_pClosePbtn->setText("X");
//    m_pClosePbtn->setObjectName("DialogCloseButton");//用于qss
//    connect(m_pClosePbtn,&QPushButton::clicked,this,&BaseMainDialog::close);
//    connect(m_pClosePbtn,&QPushButton::clicked,this,&BaseMainDialog::s_close_clicked);
//    m_pClosePbtn->setStyleSheet("QPushButton#DialogCloseButton{"
//                                "min-width: 70px;"
//                                "color:white;"
//                                "border-radius: 10px;"
//                                "background:transparent;"
//                                "border-color: transparent;}"

//                                "QPushButton#DialogCloseButton:focus{"
//                                "border:0px solid lightgray;"
//                                "background: #DA3610;}"

//                                "QPushButton#DialogCloseButton:hover{"
//                                "border:0px solid lightgray;"
//                                "background: #DA36F0;}"

//                                "QPushButton#DialogCloseButton:pressed{"
//                                "border:0px solid lightgray;"
//                                "background: #990000;}"
//                                );

    m_pStatusBar = new StatusBar(this);
    connect(m_pStatusBar,&StatusBar::sig_back_button_clicked,this,&BaseMainDialog::close);
    connect(this,&BaseMainDialog::windowTitleChanged,m_pStatusBar,&StatusBar::s_windowTitleChanged);

    m_pFuncBar = new FuncBar(this);
     connect(m_pFuncBar,&FuncBar::sig_func_trigger,this,&BaseMainDialog::s_func_trigger);
    initFuncBarControl(mainWidgetType);
}
BaseMainDialog::~BaseMainDialog()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<this;
}

void BaseMainDialog::initFuncBarControl(MainDialogType_e mainWidgetType)
{
    if(m_pFuncBar)
        m_pFuncBar->initFuncBarControl(mainWidgetType);
}
void BaseMainDialog::s_close_clicked()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;

}
void BaseMainDialog::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)

    QPainter p(this);
    QStyle* style = this->style();
    QRect active_area = this->rect();
    int titlebar_height = 50;

    // Titlebar.
    QStyleOptionTitleBar t_opt;
    t_opt.initFrom(this);//可以获取this的qss风格
    titlebar_height = style->pixelMetric(QStyle::PM_TitleBarHeight, &t_opt, this);

    t_opt.rect = QRect(0, 0, this->width(), titlebar_height);
    t_opt.titleBarState = this->windowState();
    t_opt.text = t_opt.fontMetrics.elidedText(this->windowTitle(), Qt::ElideRight, t_opt.rect.width());
    //绘制标题栏，不包含标题文字
//    style->drawComplexControl(QStyle::CC_TitleBar, &t_opt, &p, this);
    //绘制标题文字
//    style->drawItemText(&p, t_opt.rect, Qt::AlignCenter, t_opt.palette, true, t_opt.text, QPalette::Text);//注意参数QPalette::Text决定文字的颜色
    m_pStatusBar->setGeometry(QRect(0, 0, this->width(), 50));
    m_pFuncBar->setGeometry(QRect(0, this->height() - 50, this->width(), 50));
    //设置关闭按钮位置
//    m_pClosePbtn->setGeometry(QRect(this->width() - m_pClosePbtn->width(), 0, m_pClosePbtn->width(), titlebar_height));
    // Background widget.
    active_area.setTopLeft(QPoint(0, titlebar_height));
    this->setContentsMargins(0, titlebar_height, 0, 50);

    QStyleOption w_opt;
    w_opt.initFrom(this);//可以获取this的qss风格
    w_opt.rect = active_area;
    style->drawPrimitive(QStyle::PE_Widget, &w_opt, &p, this);
}

void BaseMainDialog::closeEvent(QCloseEvent *e)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    QWidget::closeEvent(e);
}
void BaseMainDialog::mousePressEvent(QMouseEvent* event)
{
    //只能是鼠标左键移动和改变大小
    if(Qt::LeftButton == event->button())
    {
        m_bMousePress = true;
    }

    //窗口移动距离
    m_move_point = event->globalPos() - pos();
    QWidget::mousePressEvent(event);
}
void BaseMainDialog::mouseReleaseEvent(QMouseEvent* event)
{
    m_bMousePress = false;
    QWidget::mouseReleaseEvent(event);
}

void BaseMainDialog::mouseMoveEvent(QMouseEvent* event)
{
    //移动窗口
    if(m_bMousePress)
    {
        QPoint move_pos = event->globalPos();
        move(move_pos - m_move_point);
    }
    QWidget::mouseMoveEvent(event);
}

void BaseMainDialog::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<mainWidgetType()<<this<<event<<event->key();
    QWidget::keyPressEvent(event);
}

void BaseMainDialog::resizeEvent(QResizeEvent *event)
{
//    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<windowTitle();
    QWidget::resizeEvent(event);
}
