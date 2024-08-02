#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    REG_LISTS = new REG_LIST(ui);  // 将ui指针传入Test类
}


MainWindow::~MainWindow()
{
    delete REG_LISTS;
    delete ui;
}



void MainWindow::on_REG_LIST_itemSelectionChanged()
{
    REG_LISTS->REG_RENAME(ui->REG_LIST->currentRow(), 88,"hello");
}
