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
    ui->temperatura->display(temp); //temperatura
    ui->fluxo->display(fluxo); //fluxo
    min = (int)tempo/60.0;
    seg = ((int)tempo)%60;

    ui->timeEdit->setTime(QTime(0,min,seg));

    repaint();
}

void MainWindow::paintEvent(QPaintEvent *p)
{
    QPainter painter(this);
    painter.drawPixmap(50,200,565,259,QPixmap(":/grafico.png"),0,0,565,259);

}


MainWindow::~MainWindow()
{
    delete ui;
}
