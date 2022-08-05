#include "sample_widget_std.h"
#include "ui_sample_widget_std.h"
#include <QDebug>

SampleWidgetStd::SampleWidgetStd(QWidget* parent) 
    : SampleWidgetBase(parent)
    , ui(new Ui::SampleWidgetStd),
    m_pWavePlot(nullptr)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
	m_pWavePlot = new SampleWavePlotStd();	
	layout()->addWidget(m_pWavePlot);	
}

SampleWidgetStd::~SampleWidgetStd()
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    delete ui;
}
//开始波形绘制
void SampleWidgetStd::s_start_sample()
{

}

//停止波形绘制
void SampleWidgetStd::s_stop_sample()
{

}


/**
 * @brief 获取采集控件类型
 * @返回 状态
 */
int SampleWidgetStd::get_sample_type()
{
	return 0;
}

/**
 * @brief 获取采集控件状态
 * @返回 状态
 */
int SampleWidgetStd::get_sample_status()
{
	return 0;
}


/**
 * @brief 响应F1~F7按键
 * @param func_index 为0~6，分别对应F1~F7按键
 * @param index 在控件为combobox时，为其索引值
 */
void SampleWidgetStd::s_func_trigger(int func_index,int index)
{
	Q_UNUSED(func_index)
		Q_UNUSED(index)
}

void SampleWidgetStd::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event)
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<rect();
    SampleWidgetBase::paintEvent(event);//调用父类的，使父类完成绘制网格背景
}

void SampleWidgetStd::resizeEvent(QResizeEvent* event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<event;
    SampleWidgetBase::resizeEvent(event);//调用父类的，使父类完成绘制网格背景
}

void SampleWidgetStd::showEvent(QShowEvent* event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<rect();

    SampleWidgetBase::showEvent(event);//调用父类的，使父类完成绘制网格背景
}

