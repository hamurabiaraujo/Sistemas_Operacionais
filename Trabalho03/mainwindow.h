#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mythread.h"
#include <QSemaphore>
#include <vector>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void  updateInterface(int,int,int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MyThread *trem1;
    MyThread *trem2;
    MyThread *trem3;
    MyThread *trem4;
    MyThread *trem5;
};

#endif // MAINWINDOW_H
