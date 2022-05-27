#ifndef FUNCBAR_H
#define FUNCBAR_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QMenu>
#include <QStyledItemDelegate>
#include <QToolButton>
#include "main_dialog_def.h"
namespace Ui {
class FuncBar;
}

class FuncBar : public QWidget
{
    Q_OBJECT
public:
    enum FuncBarKeyMap_e
    {
        FUNC_BAR_F1 = 0,
        FUNC_BAR_F2,
        FUNC_BAR_F3,
        FUNC_BAR_F4,
        FUNC_BAR_F5,
        FUNC_BAR_F6,
        FUNC_BAR_F7,
    };
public:
    explicit FuncBar(QWidget *parent = nullptr);
    ~FuncBar();
    void initFuncBarControl(MainDialogType_e mainWidgetType);
private slots:
    void s_pbtn_click();

    void s_toolButton_triggered(QAction *action);
    void s_combox_press_ex(int index);
    void s_combox_press(int index);
signals:
    void sig_func_trigger(int func_index,const QVariant& data);
private:
    void createSampeFuncBar();
    void createPreviewFuncBar();
    void createFileManagerFuncBar();
    QAbstractButton *add_button(const QString& text, int func_index);
    QAbstractButton *add_toolButton(QMenu *menu, QString text, int func_index);
    QComboBox *add_combobox(QStringList &value, int index, int func_index);
    QComboBox *add_combobox_ex(QStringList &value, int index, int func_index);
    void add_placeholder(int func_index);
private:
    Ui::FuncBar *ui;


};

#endif // FUNCBAR_H
