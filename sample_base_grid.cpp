#include "sample_base_grid.h"
#include <QPainter>
#include <QPalette>
#include <QDebug>

#define PIX_MM                          (3)      //每mm有多少个像素点
#define GRID_LEN_MM                     (5)         //每个小网格的边长为5mm

SampleBaseGrid::SampleBaseGrid(QWidget *parent) :
	QWidget(parent)
{
	initUI();
}

SampleBaseGrid::~SampleBaseGrid()
{
}

void SampleBaseGrid::initUI()
{
	setWindowFlags(Qt::FramelessWindowHint);
	setAutoFillBackground(true);
}

void SampleBaseGrid::setGridBackground()
{
#if 0
	QPixmap background = proc_paint_grid(5,5);
	QPalette palette;
	palette.setBrush(QPalette::Window, QBrush(background));
	setPalette(palette);

#else
	QPixmap background = initBgImage();
	QPalette palette;
	palette.setBrush(QPalette::Background, QBrush(background));
	setPalette(palette);
#endif
}

void SampleBaseGrid::resizeEvent(QResizeEvent *event)
{
	setGridBackground();
	QWidget::resizeEvent(event);
}

//column_grid为一个大网格下纵向有多少个小网格，row_grid为一个大网格下横向有多少个小网格
QPixmap SampleBaseGrid::proc_paint_grid(int column_grid,int row_grid)
{
	QPixmap background = QPixmap(PIX_MM*GRID_LEN_MM*column_grid, PIX_MM*GRID_LEN_MM*row_grid);
	QRect bg_rect = background.rect();

	QPainter painter(&background);//创建一个画笔
	painter.fillRect(bg_rect,Qt::black);

	//1、画实线
	painter.setPen(QPen(QColor(47,49,50), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.drawRect(bg_rect);
	//2、画虚线
	painter.setPen(QPen(QColor(39,40,41), 1, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin));
	//2.1、画水平线
	for(int row = 1; row < row_grid; row++)
	{
		int y = bg_rect.top() + PIX_MM * GRID_LEN_MM * row;
		painter.drawLine(QPoint(bg_rect.left(),y),QPoint(bg_rect.right(),y));
	}
	//2.2、画垂直线
	for(int column = 1; column < column_grid; column++)
	{
		int x = bg_rect.left() + PIX_MM * GRID_LEN_MM * column;
		painter.drawLine(QPoint(x,bg_rect.top()),QPoint(x,bg_rect.bottom()));
	}
	return background;
}

/*设置普通心电波形显示背景图片*/
QPixmap SampleBaseGrid::initBgImage()
{
	QPixmap background = QPixmap(this->size());

	//开始绘制背景
	QPainter painter;
	painter.begin(&background);

	//网格绘制
	QPen pen;
	pen.setWidth(1);  //画笔的宽度为1pix
	pen.setColor(QColor(255,255,255));
	QBrush brush(QColor(0,0,0,255)); //画刷

	painter.setPen(pen); //添加画笔
	painter.setBrush(brush); //绘制设备添加画刷
	painter.fillRect(background.rect(),brush); //填充画刷

	int X = 0,Y = 0;
	int margins[4] = {5,2,5,2}; //Top,Left, Botton,Right，

	int table_w = background.width();
	int table_h = background.height();

	printf("table_w=%d,table_h=%d\n",table_w,table_h);

	X = margins[1];

	pen.setColor(QColor(39,40,41));
	pen.setStyle(Qt::DotLine);
	painter.setPen(pen);

	//画虚线格子
	while(X <= table_w - margins[3])  //画竖线
	{
		if((X - margins[1]) % (DEF_BIG_GRID_COUNT*DEF_GRID_PIX) != 0)
		{
			painter.drawLine(X,margins[0],X,table_h - 1 - margins[2]);
		}
		X += DEF_GRID_PIX;
	}

	Y = margins[0];
	while (Y <= table_h - margins[2] ) //画横线
	{
		if((Y - margins[0]) % (DEF_BIG_GRID_COUNT*DEF_GRID_PIX) != 0)
		{
			painter.drawLine(margins[1],Y,table_w - 1 - margins[3],Y);
		}
		Y += DEF_GRID_PIX;
	}

	//画实线格式
	X = margins[1];

	pen.setColor(QColor(47,49,50));
	pen.setStyle(Qt::SolidLine);  //实线
	painter.setPen(pen);

	while(X <= table_w - margins[3])  //画竖线
	{
		if((X - margins[1]) % (DEF_BIG_GRID_COUNT*DEF_GRID_PIX) == 0)
		{
			painter.drawLine(X,margins[0],X,table_h - 1 - margins[2]);
		}
		X += DEF_GRID_PIX;
	}

	Y = margins[0];
	while (Y <= table_h - margins[2] ) //画横线
	{
		if((Y - margins[0]) % (DEF_BIG_GRID_COUNT*DEF_GRID_PIX) == 0)
		{
			painter.drawLine(margins[1],Y,table_w - 1 - margins[3],Y);
		}
		Y += DEF_GRID_PIX;
	}
	painter.end();
	return background;
}

