#ifndef SAMPLE_WIDGET_BASE_H
#define SAMPLE_WIDGET_BASE_H

#include <QWidget>

class SampleWidgetBase : public QWidget
{
    Q_OBJECT
public:
    SampleWidgetBase(QWidget* parent = 0):QWidget(parent) {};
    virtual ~SampleWidgetBase() {};
    //开始波形绘制
    virtual void s_start_sample() = 0;
    //停止波形绘制
    virtual void s_stop_sample() = 0;

    /**
     * @brief 获取采集控件类型
     * @返回 状态
     */
    virtual int get_sample_type() = 0;
    /**
     * @brief 获取采集控件状态
     * @返回 状态
     */
    virtual int get_sample_status() = 0;
public slots:

    /**
     * @brief 响应F1~F7按键
     * @param func_index 为0~6，分别对应F1~F7按键
     * @param index 在控件为combobox时，为其索引值
     */
    virtual void s_func_trigger(int func_index,int index) = 0;

    virtual void s_hover_trigger(int func_index,int index) {
	Q_UNUSED(func_index)
		Q_UNUSED(index)
		};
signals:
    void sig_func_bar_change(int func_type);
    void sig_func_bar_status_change(int status);//用于给底部功能条，发送信号，修改控件状态
};

#endif // ECG_WAVE_H

