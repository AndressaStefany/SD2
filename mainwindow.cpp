#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *p)
{
    ui->lcdNumber->display(temp); //temperatura
    ui->lcdNumber_2->display(fluxo); //fluxo
}


MainWindow::~MainWindow()
{
    delete ui;
}
