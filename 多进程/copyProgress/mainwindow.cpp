#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //create();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::create()
{
//    using namespace std;
//    struct sembuf sops;
//    pid_t pw, tw, pr, tr;                                           //读pr 写pw
//    int ret, status;
//    semun arg;
//    int shmid = shmget(MY_KEY, sizeof(BUFF_T), IPC_CREAT | 0666);      //0666表示：创建者和其他用户创建的进程都可以进行读和写操作， 4为只读
//    if(-1 == shmid){
//        cout << "shmget () error !" << endl;
//        return 0;
//    }
//    //失败返回-1, 成功返回指向共享内存第一个字节的指针。
//    BUFF_T* sMem = (BUFF_T *)shmat(shmid, NULL, SHM_R | SHM_W);      // NULL表示让系统自动分配内存地址
//    if((void *)-1 == sMem){
//        cout << "shmid () error !" << endl;
//        return 0;
//    }
//    cout << "main :共享内存连接地址： " << (int*)sMem << endl ;

//    semid = semget(888, 2, IPC_CREAT|0600); // 创建信号灯，自动，2个，不存在则创建。成功返回信号灯集ID，失败返回-1
//    if (semid == -1)
//    {
//        cout << "create sem failed!" << endl;
//        return -1;
//    }
//    //对信号灯 赋初值1 (1表示占用)
//    arg.val = 8;
//    ret = semctl(semid, 0, SETVAL, arg);
//    if (ret == -1)
//        cout << "semctl failed!" << endl;
//    arg.val = 0;
//    ret = semctl(semid, 1, SETVAL, arg);
//    if (ret == -1)
//        cout << "semctl failed!" << endl;
}
