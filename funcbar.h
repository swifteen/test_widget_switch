#ifndef FUNCBAR_H
#define FUNCBAR_H

#include <QWidget>

namespace Ui {
class FuncBar;
}

class FuncBar : public QWidget
{
    Q_OBJECT
public:
    enum FuncBarType_e
    {
        FUNC_BAR_TYPE_SAMPLE,
        FUNC_BAR_TYPE_PREVIEW,
        FUNC_BAR_TYPE_REPORT,
    };
public:
    explicit FuncBar(QWidget *parent = nullptr);
    ~FuncBar();

private:
    Ui::FuncBar *ui;
};

#endif // FUNCBAR_H
