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
    ui->lcdNumber->display(temp);
    cout << "AAA";
}

void MainWindow::paintEvent(QPaintEvent *p)
{

}


MainWindow::~MainWindow()
{
    delete ui;
}
