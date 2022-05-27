#include "base_main_dialog.h"
#include <QDebug>
#include <QFontMetrics>
#include <QFont>
#include <QPainter>
#include <QStyleOptionTitleBar>
#include <QApplication>

BaseMainDialog::BaseMainDialog(MainDialogType_e mainWidgetType,QWidget *parent) :
    QDialog(parent,Qt::FramelessWindowHint),
    m_bMousePress(false),
    m_pStatusBar(nullptr),
    m_pFuncBar(nullptr)
{
	setFixedSize(1024,768);
    setWindowModality(Qt::ApplicationModal);
    //setAttribute(Qt::WA_DeleteOnClose);
    //setWindowState(Qt::WindowFullScreen);//TODO 统一设置窗口全屏属性
    //    setAttribute(Qt::WA_TranslucentBackground);//实现圆角窗口时，需要设置的最关键属性
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

void BaseMainDialog::handleKeyPressEvent(Qt::Key key)
{
    if(m_pFuncBar)
        m_pFuncBar->handleKeyPressEvent(key);
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

    m_pStatusBar->setGeometry(QRect(0, 0, this->width(), 50));
    m_pFuncBar->setGeometry(QRect(0, this->height() - 50, this->width(), 50));
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
