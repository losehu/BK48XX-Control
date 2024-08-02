#ifndef LIST_H
#define LIST_H


#include "mainwindow.h"
#include "ui_mainwindow.h"
#define MAX_REG_NUM 0X7F

class MainWindow;   // 前置声明

class REG_LIST : public QMainWindow
{
    Q_OBJECT
public:
    explicit REG_LIST(Ui::MainWindow * p);
 void REG_RENAME(int index, uint16_t number, const QString& suffix) ;

    Ui::MainWindow* ui;

signals:

};

#endif // LIST_H
