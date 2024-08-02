#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class REG_LIST;    // 前置声明

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_REG_LIST_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
    REG_LIST* REG_LISTS;

};
#endif // MAINWINDOW_H
