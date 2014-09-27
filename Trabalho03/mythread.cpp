
#include "mythread.h"
#include <QtCore>


MyThread::MyThread(int ID, int x, int y, int sono, int x1, int y1, int x2, int y2, vector<QSemaphore> semaforos){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->sono = sono;
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->semaforos = semaforos;
}

void MyThread::entrarZona(){
    switch (ID) {
    case 1:
        semaforos[1].acquire();
        semaforos[0].acquire();
        break;
    case 2:
        semaforos[3].acquire();
        semaforos[2].acquire();
        semaforos[1].acquire();
        semaforos[0].acquire();
        break;
    case 3:
        semaforos[1].acquire();
        semaforos[0].acquire();
        break;
    case 4:
        semaforos[1].acquire();
        semaforos[0].acquire();
        break;
    case 5:
        semaforos[1].acquire();
        semaforos[0].acquire();
        break;
    default:
        break;
    }
}

void MyThread::sairZona(){
    switch (ID) {
    case 1:
        semaforos[0].release();
        semaforos[1].release();
        break;
    case 2:
        semaforos[0].release();
        semaforos[1].release();
        semaforos[2].release();
        semaforos[3].release();
        break;
    case 3:
        semaforos[0].release();
        semaforos[1].release();
        break;
    case 4:
        semaforos[0].release();
        semaforos[1].release();
        break;
    case 5:
        semaforos[0].release();
        semaforos[1].release();
        break;
    default:
        break;
    }
}

void MyThread::mover(){

    if (x < x2 && y == y1){
        if (x == x2-1){
            entrarZona();
            x++;
            sairZona();
        }else{
            x++;
        }
    }
    else if (x == x2 && y < y2){
        y++;
    }
    else if(y == y2 && x > x1){
        x--;
    }
    else{
        y--;
    }
}

void MyThread::run(){
    stop = true;

    while(stop){
        mover();
        emit updateGUI(ID, x,y);
        usleep(sono);
    }
}

void MyThread::finalizar(){
    stop = false;
}
