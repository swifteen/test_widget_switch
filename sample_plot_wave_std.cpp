#include "sample_plot_wave_std.h"
#include <QDebug>
SampleWavePlotStd::SampleWavePlotStd(QWidget *parent) :
	SampleBaseGrid(parent),
		m_pWavePixmap(nullptr)
{
	initUI();
}

SampleWavePlotStd::~SampleWavePlotStd()
{
}

void SampleWavePlotStd::initUI()
{
	setAutoFillBackground(true);
}

void SampleWavePlotStd::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event)
    //SampleBaseGrid::paintEvent(event);//调用父类的，使父类完成绘制网格背景
    #if 1
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<rect();
    if(m_pWavePixmap == NULL)
    {
        return;
    }

    //重绘事件
    QPainter painter(this);
    painter.drawPixmap(0,0,*m_pWavePixmap); //绘制当前画布
    painter.end();
	#endif
}

void SampleWavePlotStd::resizeEvent(QResizeEvent* event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<event;
	#if 1
    //获取波形起始坐标
    setWaveCoordinates();
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;

    //在m_wavePixmap绘制导联名称
    clearWave();
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<rect();
#endif
    SampleBaseGrid::resizeEvent(event);//调用父类的，使父类完成绘制网格背景
}

void SampleWavePlotStd::showEvent(QShowEvent* event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<rect();

    SampleBaseGrid::showEvent(event);//调用父类的，使父类完成绘制网格背景
}

void SampleWavePlotStd::clearWave()
{
    if(m_pWavePixmap == NULL)
    {
        m_pWavePixmap = new QPixmap(this->width(), this->height());
        m_pWavePixmap->fill(Qt::transparent);
    }

    QPainter painter;
    bool ret = painter.begin(m_pWavePixmap);

    if(!ret)
    {
        return;
    }

    painter.setCompositionMode(QPainter::CompositionMode_Source);

    //擦除当前绘制的区域
    painter.eraseRect(0, 0, m_pWavePixmap->width(),m_pWavePixmap->height());
    //还原原来的底色
    painter.fillRect(0, 0, m_pWavePixmap->width(),m_pWavePixmap->height(),QColor(0,0,0,0));
    //绘制导联名称
    drawLeadName(painter);
    painter.end();

    this->repaint(0, 0, m_pWavePixmap->width(),m_pWavePixmap->height());
}

//设置每行起始的坐标
void SampleWavePlotStd::setWaveCoordinates()
{
    m_iMaxWaveHeight = this->height()/MAX_LEAD_SUM;
    m_iMaxWaveWidth = this->width() - 2*EDGE_MARGIN;//边缘有间距
    m_sWaveBasePolyon.clear();  //清空容器
    QPoint tmpPoint;
    //得出各个基准线的起始坐标
    for(int i=0; i < MAX_LEAD_SUM; i++)
    {
        tmpPoint.setX(EDGE_MARGIN);
        int itmpy = i*m_iMaxWaveHeight + m_iMaxWaveHeight/2;
        tmpPoint.setY(itmpy);
        m_sWaveBasePolyon.append(tmpPoint);  //开始添加基准的起始坐标
    }
}

void SampleWavePlotStd::drawLeadName(QPainter& painter)
{
    //绘制导联标识名称
    int t_font_size = 16;
    QFont font;
    font.setPixelSize(t_font_size);
    QFontMetrics fm(font);
    painter.setFont(font);
    painter.setPen(QPen(Qt::white,1, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin));
    QStringList leadNameLists;
    leadNameLists << "I" << "II" << "III" << "aVR" << "aVL" << "aVF" << "V1" << "V2" << "V3" << "V4" << "V5" << "V6";         // 标准导联体系
    for(int i=0; i < MAX_LEAD_SUM; i++)
    {
	    painter.drawText(m_sWaveBasePolyon[i].x(),
						    m_sWaveBasePolyon[i].y()-m_iMaxWaveHeight/2 + fm.height(),
						    leadNameLists.at(i));
	    //qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<m_sWaveBasePolyon[i]<<leadNameLists.at(i);
    }
}

