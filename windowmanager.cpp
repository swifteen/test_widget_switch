#include "windowmanager.h"
#include "preview_widget.h"
#include "file_manager_widget.h "
#include "setting_widget.h"
#include <QApplication>
#include <QDebug>
#include "widget.h"
#include "statusbar.h"
WindowManager::WindowManager(QObject *parent) : QObject(parent)
{
    Widget* w = new Widget;
    w->initFuncBarControl();
    w->show();
    qApp->installEventFilter(this);
}

bool WindowManager::eventFilter(QObject* watched, QEvent* event)
{
    if ((QEvent::KeyPress == event->type()))
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

        if (keyEvent->isAutoRepeat())
        {
            keyEvent->ignore();
            return false;
        }
        qDebug()<< __FILE__ << __FUNCTION__ << __LINE__<<watched
                <<QString::number(keyEvent->key(),16)
               <<QApplication::focusWidget()<<QApplication::activePopupWidget();
        Qt::Key key = static_cast<Qt::Key>(keyEvent->key());
        bool bFlag = true;

        switch (key)
        {
        case Qt::Key_F1:
            s_open_preview();
            break;
        case Qt::Key_F2:
            s_open_fileManager();
            break;
        case Qt::Key_F3:
            s_open_setting();
            break;
        default:
            bFlag = false;
            break;
        }

//        if (bFlag)
//        {
//            return bFlag;//返回true,代表该事件已经处理，不再向上冒泡
//        }
    }

    return QObject::eventFilter(watched, event);
}

void WindowManager::s_open_preview()
{
    PreviewWidget*  widget = new PreviewWidget;
    widget->initFuncBarControl();
    widget->show();
//    PreviewWidget  widget;
//    widget.show();
}

void WindowManager::s_open_fileManager()
{
    FileManagerWidget * widget = new FileManagerWidget;
    widget->initFuncBarControl();
    widget->show();
//    FileManagerWidget widget;
//    widget.show();
}

void WindowManager::s_open_setting()
{
    SettingWidget * widget = new SettingWidget;
    widget->initFuncBarControl();
    widget->show();
//    SettingWidget widget;
//    widget.show();
}
