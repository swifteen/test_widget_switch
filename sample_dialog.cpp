#include "sample_dialog.h"
#include "ui_sample_dialog.h"
#include <QDebug>
#include <QStackedLayout>
#include "sample_widget_std.h"

SampleDialog::SampleDialog(QWidget *parent)
    : BaseMainDialog(MAIN_DIALOG_TYPE_SAMPLE,parent)
    , ui(new Ui::SampleDialog),
    m_pSampleWidget(nullptr)
{
    ui->setupUi(this);
	
	setupSampleWidget();
}

SampleDialog::~SampleDialog()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    delete ui;
}

void SampleDialog::setupSampleWidget()
{
    this->setStyleSheet("QLabel {"
                        "color: #FFFFFF;"/*标题栏文字颜色*/
                        "font-size: 24px;"/*标题栏文字大小*/
                        "font-weight:900;}"
                        );
	ui->lab_message->setStyleSheet("QStackedWidget QLabel {"
                        "color: #FFFFFF;"/*标题栏文字颜色*/
                        "font-size: 24px;"/*标题栏文字大小*/
                        "font-weight:900;}"
                        );

	//设置波形区域大小，frame会自动居中显示
	ui->stackedWidget->setFixedSize(1024,768 - 50 - 50);
    QStackedLayout* layout=(QStackedLayout*)ui->stackedWidget->layout();
    layout->setStackingMode(QStackedLayout::StackAll);//All widgets are visible.
	
	m_pSampleWidget = new SampleWidgetStd();
	ui->stackedWidget->addWidget(m_pSampleWidget);
	
    //强制显示第一页的提示信息页
    ui->stackedWidget->setCurrentIndex(0);
}

void SampleDialog::showEvent(QShowEvent* event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<rect();
	qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<ui->lab_message->styleSheet()<<ui->lab_progress->styleSheet();
    BaseMainDialog::showEvent(event);//调用父类的，使父类完成绘制网格背景
}

void SampleDialog::resizeEvent(QResizeEvent *event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<event;
    BaseMainDialog::resizeEvent(event);
}

void SampleDialog::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<this<<event<<event->key();
    Qt::Key key = static_cast<Qt::Key>(event->key());

    switch(key)
    {
    default:
        break;
    }
    BaseMainDialog::keyPressEvent(event);
}

void SampleDialog::s_func_trigger(int func_index, const QVariant& data)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<func_index<<data;
    switch(func_index)
    {
    //F1~F7键转给FuncBar处理
    case FuncBar::FUNC_BAR_F1:
        openPatientDialog();
        break;
    case FuncBar::FUNC_BAR_F2:
        break;
    case FuncBar::FUNC_BAR_F3:
        break;
    case FuncBar::FUNC_BAR_F4:
        break;
    case FuncBar::FUNC_BAR_F5:
        break;
    case FuncBar::FUNC_BAR_F6:
        open_fileManager();
        break;
    case FuncBar::FUNC_BAR_F7:
        open_setting();
        break;
    default:
        break;
    }
}

void SampleDialog::openPatientDialog()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<"enter Patient_Dialog";
}

void SampleDialog::open_fileManager()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<"enter FileManagerDialog";
}

void SampleDialog::open_setting()
{

}
