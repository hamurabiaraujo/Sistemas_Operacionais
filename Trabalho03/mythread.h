#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QSemaphore>
#include <vector>

using namespace std;

class MyThread: public QThread{
 Q_OBJECT
public:
    MyThread(int, int, int, int, int, int, int, int, vector<QSemaphore>);
    void run();
    void finalizar();
    bool stop;
    void mover();
    void entrarZona();
    void sairZona();

signals:
    void updateGUI(int,int,int);

private:
   int x;
   int y;
   int ID;
   int x1;
   int y1;
   int x2;
   int y2;
   int sono;
   vector<QSemaphore> semaforos;
};


#endif // MYTHREAD_H
