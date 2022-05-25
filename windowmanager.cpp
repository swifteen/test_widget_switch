#include "windowmanager.h"
#include "preview_widget.h"
#include "file_manager_widget.h "
#include "setting_widget.h"
#include <QApplication>
#include "widget.h"
#include "statusbar.h"
WindowManager::WindowManager(QObject *parent) : QObject(parent)
{
    Widget* w = new Widget;
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

        if (bFlag)
        {
            return bFlag;//返回true,代表该事件已经处理，不再向上冒泡
        }
    }

    return QObject::eventFilter(watched, event);
}

void WindowManager::s_open_preview()
{
    PreviewWidget * widget = new PreviewWidget;
    widget->show();
}

void WindowManager::s_open_fileManager()
{
    FileManagerWidget * widget = new FileManagerWidget;
    widget->show();
}

void WindowManager::s_open_setting()
{
    SettingWidget * widget = new SettingWidget;
    widget->show();
}
