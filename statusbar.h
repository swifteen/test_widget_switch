#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QWidget>

namespace Ui {
class StatusBar;
}

class StatusBar : public QWidget
{
    Q_OBJECT

public:
    explicit StatusBar(QWidget *parent = nullptr);
    ~StatusBar();
public:
    void s_windowTitleChanged(const QString &title);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void sig_back_button_clicked();
protected:
    void timerEvent(QTimerEvent *event);
private:
    Ui::StatusBar *ui;
};

#endif // STATUSBAR_H
