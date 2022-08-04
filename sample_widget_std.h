#ifndef SAMPLE_WIDGET_STD_H
#define SAMPLE_WIDGET_STD_H
#include <QWidget>
#include "sample_widget_base.h"
#include "sample_plot_wave_std.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SampleWidgetStd; }
QT_END_NAMESPACE

class SampleWidgetStd : public SampleWidgetBase
{
    Q_OBJECT
public:
    SampleWidgetStd(QWidget* parent = 0);
    virtual ~SampleWidgetStd();
    //开始波形绘制
    void s_start_sample();
    //停止波形绘制
    void s_stop_sample();

    /**
     * @brief 获取采集控件类型
     * @返回 状态
     */
    int get_sample_type();
    /**
     * @brief 获取采集控件状态
     * @返回 状态
     */
    int get_sample_status();
public slots:

    /**
     * @brief 响应F1~F7按键
     * @param func_index 为0~6，分别对应F1~F7按键
     * @param index 在控件为combobox时，为其索引值
     */
    void s_func_trigger(int func_index,int index);
private:	
    Ui::SampleWidgetStd *ui;
	SampleWavePlotStd* m_pWavePlot;
};

#endif // SAMPLE_WIDGET_STD_H

