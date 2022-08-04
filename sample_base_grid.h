#ifndef GRID_WIDGET_H
#define GRID_WIDGET_H

#include <QWidget>
#include <QResizeEvent>
#include <QPaintEvent>
#define DEF_GRID_PIX (15)//网格宽度，单位是像素点
#define DEF_BIG_GRID_COUNT (5) //大网格包含的小网格个数

class SampleBaseGrid : public QWidget
{
	Q_OBJECT

public:
	explicit SampleBaseGrid(QWidget *parent = 0);
	virtual ~SampleBaseGrid();
protected:
	virtual void resizeEvent(QResizeEvent *event);
private:
	void initUI();
	void setGridBackground();
	QPixmap proc_paint_grid(int column_grid,int row_grid);
	QPixmap initBgImage();
private:
};

#endif // GRID_WIDGET_H
