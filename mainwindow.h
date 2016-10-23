#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent*p);
    void timerEvent(QTimerEvent*e);
    ~MainWindow();
    void setTemp(double x) { temp= x; }
    void setFluxo(double x) { fluxo= x;}
    void setTempo(double x) { tempo= x; }

private:
    Ui::MainWindow *ui;
    double temp, fluxo, tempo, min,seg;
};

#endif // MAINWINDOW_H
