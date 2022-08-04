#ifndef SAMPLE_PLOT_H
#define SAMPLE_PLOT_H
#include "sample_base_grid.h"
#include <QPainter>
#include "sample_plot_wave_std.h"
class SampleWavePlotStd : public SampleBaseGrid
{
	Q_OBJECT

public:
	explicit SampleWavePlotStd(QWidget *parent = 0);
	virtual ~SampleWavePlotStd();
protected:
	virtual void resizeEvent(QResizeEvent *event);
private:
	void initUI();
	void clearWave();	
	void setWaveCoordinates();	
	void drawLeadName(QPainter& painter);
private:
    QPixmap* m_wavePixmap;   //波形显示图片
    QPolygon m_sWaveBasePolyon; //用来保存每行的基准坐标
    int m_iMaxWaveHeight;  //每行波形显示时的最大高度
    int m_iMaxWaveWidth;  //每行波形显示时的最大宽度
    enum
	{
		EDGE_MARGIN = 2,
		MAX_LEAD_SUM = 12,
	};
};

#endif // SAMPLE_PLOT_H
