#include "statusbar.h"
#include "ui_statusbar.h"
#include <QDebug>
#include <QDateTime>
StatusBar::StatusBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusBar)
{
    ui->setupUi(this);
    setStyleSheet("#StatusBar{"
                  "height: 50px;"/*标题栏高度*/
                  "background: #1E2D5A;"/*标题栏背景色*/
                  "background-color: #1E2D5A;"/*标题栏背景色*/
                  "border-top-left-radius: 10px;"
                  "border-top-right-radius: 10px;}"

//                  "QWidget#BaseMainWidget{"
//                  "color: #00ff00;"/*标题栏文字颜色*/
//                  "font-size: 24px;"/*标题栏文字大小*/
//                  "font-weight:900;"
//                  "background: #3E81DA;"/*Dialog背景色*/
//                  "border-bottom-left-radius: 10px;"
//                  "border-bottom-right-radius: 10px;}"

                  "*{color: #ff0000;}"
                  );
    startTimer(1000);
}

StatusBar::~StatusBar()
{
    delete ui;
}
void StatusBar::timerEvent(QTimerEvent* event)
{
    QString str = QDateTime::currentDateTime().toString("yyyy-MM-dd\nhh:mm:ss");
    ui->label_time->setText(str);
}
void StatusBar::s_windowTitleChanged(const QString &title)
{
    ui->label->setText(title);
}

void StatusBar::on_pushButton_clicked()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    emit sig_back_button_clicked();
}

void StatusBar::on_pushButton_2_clicked()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
}
