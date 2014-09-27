#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int velocidade = 100;

    QSemaphore trilho1(1);
    QSemaphore trilho2(1);
    QSemaphore trilho3(1);
    QSemaphore trilho4(1);
    QSemaphore trilho5(1);

    vector<QSemaphore> semaforos_trem1 (trilho1, trilho4);
    vector<QSemaphore> semaforos_trem2 (trilho1, trilho2, trilho3, trilho4);
    vector<QSemaphore> semaforos_trem3 (trilho2, trilho3);
    vector<QSemaphore> semaforos_trem4 (trilho4, trilho5);
    vector<QSemaphore> semaforos_trem5 (trilho3, trilho5);

    trem1 = new MyThread(1, 40, 120, velocidade, 40, 120, 330, 310, semaforos_trem1);
    trem2 = new MyThread(2, 340, 120, velocidade, 340, 120, 630, 310, semaforos_trem2);
    trem3 = new MyThread(3, 640, 120, velocidade, 640, 120, 930, 310, semaforos_trem3);
    trem4 = new MyThread(4, 200, 320, velocidade, 200, 320, 490, 510, semaforos_trem4);
    trem5 = new MyThread(5, 500, 320, velocidade, 500, 320, 790, 510, semaforos_trem5);

    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

}


void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1:
        ui->label_6->setGeometry(x,y,31,31);
        break;
    case 2:
        ui->label_7->setGeometry(x,y,31,31);
        break;
    case 3:
        ui->label_8->setGeometry(x,y,31,31);
        break;
    case 4:
        ui->label_9->setGeometry(x,y,31,31);
        break;
    case 5:
        ui->label_10->setGeometry(x,y,31,31);
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}
