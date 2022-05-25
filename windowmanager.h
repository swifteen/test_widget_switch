#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QObject>

class WindowManager : public QObject
{
    Q_OBJECT
public:
    explicit WindowManager(QObject *parent = nullptr);

signals:

protected:
    bool eventFilter(QObject *watched, QEvent *event);
private slots:
    void s_open_preview();
    void s_open_fileManager();
    void s_open_setting();
};

#endif // WINDOWMANAGER_H
