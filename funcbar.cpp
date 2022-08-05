#include "funcbar.h"
#include "ui_funcbar.h"
#include <QDebug>

FuncBar::FuncBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FuncBar)
{
    ui->setupUi(this);
    setStyleSheet("*{color: #ff0000;}"
                  " *{font: normal 18px “微软雅黑”;}"
                  "QAbstractButton,QLabel{min-height: 50px;}"
                  "QAbstractButton:focus{\
                      border: 5px solid #1AAB1A;  \
                      outline: none;\
                  }");
}

FuncBar::~FuncBar()
{
    delete ui;
}

void FuncBar::handleKeyPressEvent(Qt::Key key)
{
    switch(key)
    {
        case Qt::Key_F1:
            handleCrtlPress(FUNC_BAR_F1);
            break;

        case Qt::Key_F2:
            handleCrtlPress(FUNC_BAR_F2);
            break;

        case Qt::Key_F3:
            handleCrtlPress(FUNC_BAR_F3);
            break;

        case Qt::Key_F14://F4
            handleCrtlPress(FUNC_BAR_F4);
            break;

        case Qt::Key_F5:
            handleCrtlPress(FUNC_BAR_F5);
            break;

        case Qt::Key_F6:
            handleCrtlPress(FUNC_BAR_F6);
            break;

        case Qt::Key_F7:
            handleCrtlPress(FUNC_BAR_F7);
            break;

        default:
            break;
    }
}

void FuncBar::handleCrtlPress(int func_index)
{
	int count = layout()->count();
    for(int i = 0; i < count; ++i)
    {
        QWidget* w = layout()->itemAt(i)->widget();
        //combobox
        QComboBox* pCbox = qobject_cast<QComboBox*>(w);

        if((pCbox) &&(pCbox->isEnabled()))
        {
            if(func_index == pCbox->objectName().toInt())
            {
                int index = pCbox->currentIndex();
                index++;

                if(index > pCbox->count() - 1)
                {
                    index=0;
                }

                pCbox->setCurrentIndex(index);
                pCbox->setFocus();
                break;
            }
        }

        //按钮
        QPushButton* pBtn = qobject_cast<QPushButton*>(w);

        if((pBtn) &&(pBtn->isEnabled()))
        {
            if(func_index == pBtn->objectName().toInt())
            {
                pBtn->setFocus();
                emit sig_func_trigger(func_index,0);
                break;
            }
        }

        //ToolButton
        QToolButton* tBtn = qobject_cast<QToolButton*>(w);

        if((tBtn) &&(tBtn->isEnabled()))
        {
            if(func_index == tBtn->objectName().toInt())
            {
                tBtn->showMenu();
                break;
            }
        }
    }
}

void FuncBar::initFuncBarControl(MainDialogType_e mainWidgetType)
{
    switch (mainWidgetType) {
    case MAIN_DIALOG_TYPE_SAMPLE:
        createSampeFuncBar();
        break;
    case MAIN_DIALOG_TYPE_PREVIEW:
        createPreviewFuncBar();
        break;
    case MAIN_DIALOG_TYPE_FILE_MANAGER:
        createFileManagerFuncBar();
        break;
    default:
        qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<"unknow mainWidgetType "<<mainWidgetType;
        break;
    }
	QHBoxLayout* hBoxLayout = qobject_cast<QHBoxLayout*>(layout());
	if(hBoxLayout)
	{
		int count = hBoxLayout->count();
		for (int i = 0; i < count; ++i)
		{
			hBoxLayout->setStretch(i,1);
		}
	}
    layout()->setSpacing(10);//设置按钮之间的间距
    layout()->setContentsMargins(48,0,48,3);
}

void FuncBar::createSampeFuncBar()
{
    //第一个
    add_button(tr("登记"),FUNC_BAR_F1);
    //第二个
    QStringList list;
    list.clear();
    list << "5mm/s" << "6.25mm/s"<< "10mm/s" << "12.5mm/s" << "25mm/s" << "50mm/s";
    add_combobox(list,0,FUNC_BAR_F2);
    //第三个
    list.clear();
    list << "2.5mm/mv" << "5mm/mv" << "10mm/mv" << "20mm/mv" << "40mm/mv";
    add_combobox(list,0,FUNC_BAR_F3);

    //第四个
    list.clear();
    list << "3x4" << "3x4+1" << "3x4+3" << "6x2" << "6x2+1" << "12x1";
    add_combobox(list,0,FUNC_BAR_F4);
    //第五个
    add_button(tr("冻结"),FUNC_BAR_F5);
    //第六个
    add_button(tr("报告"),FUNC_BAR_F6);
    //第七个
    add_button(tr("设置"),FUNC_BAR_F7);
}

void FuncBar::createPreviewFuncBar()
{
    add_button(tr("保存"),FUNC_BAR_F1);
    //第二个
    QStringList list;
    list.clear();
    list << "5mm/s" << "6.25mm/s"<< "10mm/s" << "12.5mm/s" << "25mm/s" << "50mm/s";
    add_combobox(list,3,FUNC_BAR_F2);
    //第三个
    list.clear();
    list << "2.5mm/mv" << "5mm/mv" << "10mm/mv" << "20mm/mv" << "40mm/mv";
    add_combobox(list,3,FUNC_BAR_F3);
    add_placeholder(FUNC_BAR_F4);
    add_button(tr("上一秒"),FUNC_BAR_F5);
    add_button(tr("下一秒"),FUNC_BAR_F6);
    add_button(tr("打印"),FUNC_BAR_F7);
}

void FuncBar::createFileManagerFuncBar()
{
    add_button(tr("预览"),FUNC_BAR_F1);
    add_button(tr("上一页"),FUNC_BAR_F2);
    add_button(tr("下一页"),FUNC_BAR_F3);
    add_button(tr("删除"),FUNC_BAR_F4);
    QStringList textLists;
    textLists.clear();
    textLists << tr("本地") << "SD" <<tr("U盘");
    QMenu* storage_menu = new QMenu;
    for(int i = 0; i < textLists.length(); i++)
    {

        QAction* action = new QAction(textLists.at(i), storage_menu);
        action->setObjectName(QString::number(i));
        storage_menu->addAction(action);

    }
    add_toolButton(storage_menu,tr("存储"),FUNC_BAR_F6);
    //添加远程诊断按钮
    add_button(tr("刷新"),FUNC_BAR_F7);
}
void FuncBar::s_pbtn_click()
{
    QPushButton* p = qobject_cast<QPushButton*>(sender());
    int func_index = p->objectName().toInt();
    emit sig_func_trigger(func_index,0);
}
void FuncBar::s_combox_press(int index)
{
    QComboBox* p = qobject_cast<QComboBox*>(sender());
    int func_index = p->objectName().toInt();
    qDebug()<<__FILE__<<__LINE__<<"QComboBox==func_index = "<<func_index<<"index = "<<index;
    emit sig_func_trigger(func_index,index);
}

void FuncBar::s_combox_press_ex(int index)
{
    QComboBox* p = qobject_cast<QComboBox*>(sender());
    int func_index = p->objectName().toInt();
    qDebug()<<__FILE__<<__LINE__<<"QComboBox==func_index = "<<func_index<<"index = "<<index<<p->itemText(index);
    emit sig_func_trigger(func_index,0);
}

void FuncBar::s_toolButton_triggered(QAction* action)
{
    qDebug()<< __FILE__ << __FUNCTION__ << __LINE__<<action->text();
    int real_index = 0;
    emit sig_func_trigger(FUNC_BAR_F6,real_index);
}
QAbstractButton* FuncBar::add_button(const QString& text,int func_index)
{
    QPushButton* btn = new QPushButton(this);
    btn->setText(text);
    QString object_name = QString::number(func_index);
    btn->setObjectName(object_name);
    btn->setFixedHeight(45);
    connect(btn,SIGNAL(clicked(bool)),this,SLOT(s_pbtn_click()));

    layout()->addWidget(btn);
    return btn;
}

QComboBox* FuncBar::add_combobox(QStringList& value,int index,int func_index)
{
    QComboBox* cbox = new QComboBox(this);
    cbox->addItems(value);
    QString object_name = QString::number(func_index);
    cbox->setObjectName(object_name);

    if(index < value.count())
    {
        cbox->setCurrentIndex(index);
    }

    cbox->setItemDelegate(new QStyledItemDelegate());
    cbox->setFixedHeight(45);
    connect(cbox,SIGNAL(currentIndexChanged(int)),this,SLOT(s_combox_press(int)));

    layout()->addWidget(cbox);
    return cbox;
}

QComboBox* FuncBar::add_combobox_ex(QStringList& value,int index,int func_index)
{
    QComboBox* cbox = new QComboBox(this);
    cbox->addItems(value);
    QString object_name = QString::number(func_index);
    cbox->setObjectName(object_name);

    if(index < value.count())
    {
        cbox->setCurrentIndex(index);
    }

    cbox->setItemDelegate(new QStyledItemDelegate());
    cbox->setFixedHeight(45);
    connect(cbox,SIGNAL(currentIndexChanged(int)),this,SLOT(s_combox_press_ex(int)));

    layout()->addWidget(cbox);
    return cbox;
}

QAbstractButton* FuncBar::add_toolButton(QMenu* menu,QString text,int func_index)
{
    QAbstractButton* btn = NULL;
    if((menu != NULL) &&
            (!menu->isEmpty()))
    {
        QToolButton* tBtn = new QToolButton(this);
        tBtn->setMenu(menu);
        tBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtn->setPopupMode(QToolButton::InstantPopup);
        connect(tBtn,SIGNAL(triggered(QAction*)),this,SLOT(s_toolButton_triggered(QAction*)));
        btn = tBtn;
    }
    else
    {
        btn = new QPushButton(this);
        btn->setDisabled(true);
    }
    QString object_name = QString::number(func_index);
    btn->setObjectName(object_name);
    btn->setText(text);
    btn->setMinimumWidth(120);
    //cbox->setItemDelegate(new QStyledItemDelegate());
    btn->setFixedHeight(45);
    layout()->addWidget(btn);
    return btn;
}

//添加占位按钮
void FuncBar::add_placeholder(int func_index)
{
    QPushButton* btn = new QPushButton(this);
    btn->setStyleSheet("QPushButton {background: #1E2D5A;border-radius: 0px;border: 0px none transparent;} QPushButton:disabled {background: #1E2D5A;border-radius: 0px;border: 0px none transparent;}");
    QString object_name = QString::number(func_index);
    btn->setObjectName(object_name);
    btn->setFocusPolicy(Qt::NoFocus);
    btn->setEnabled(false);
    layout()->addWidget(btn);
}
