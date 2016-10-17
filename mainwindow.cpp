#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTimer(500);
}


void MainWindow::timerEvent(QTimerEvent *e)
{
    ui->lcdNumber->display(temp); //temperatura
    ui->lcdNumber_2->display(fluxo); //fluxo
}

void MainWindow::paintEvent(QPaintEvent *p)
{

}


MainWindow::~MainWindow()
{
    delete ui;
}
