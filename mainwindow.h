#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent*p);
    ~MainWindow();
    void setTemp(double x) { temp= x; repaint(); }
private:
    Ui::MainWindow *ui;
    double temp;
};

#endif // MAINWINDOW_H
