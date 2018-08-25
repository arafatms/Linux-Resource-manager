#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sem_shm.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    using namespace std;
    struct sembuf sops;
    pid_t pw, tw, pr, tr;                                           //读pr 写pw
    int ret, status;
    semun arg;
    int shmid = shmget(MY_KEY, sizeof(BUFF_T), IPC_CREAT | 0666);      //0666表示：创建者和其他用户创建的进程都可以进行读和写操作， 4为只读
    if(-1 == shmid){
        cout << "shmget () error !" << endl;
        exit(0);
    }
    //失败返回-1, 成功返回指向共享内存第一个字节的指针。
    BUFF_T* sMem = (BUFF_T *)shmat(shmid, NULL, SHM_R | SHM_W);      // NULL表示让系统自动分配内存地址
    if((void *)-1 == sMem){
        cout << "shmid () error !" << endl;
        exit(0);
    }
    cout << "main :共享内存连接地址： " << (int*)sMem << endl ;

    semid = semget(888, 2, IPC_CREAT|0600); // 创建信号灯，自动，2个，不存在则创建。成功返回信号灯集ID，失败返回-1
    if (semid == -1)
    {
        cout << "create sem failed!" << endl;
        exit(0);
    }
    //对信号灯 赋初值1 (1表示占用)
    arg.val = 8;
    ret = semctl(semid, 0, SETVAL, arg);
    if (ret == -1)
        cout << "semctl failed!" << endl;
    arg.val = 0;
    ret = semctl(semid, 1, SETVAL, arg);
    if (ret == -1)
        cout << "semctl failed!" << endl;

    pr = fork();                                        //创建进程
        if(!pr){
//            while(1){

//            }
            cout << "没去读进程里" << endl;
            exit(0);
        }
        else{
            pw = fork();
            if(!pw){

                cout << "没去写进程里" << endl;
                exit(0);
            }
            else{

                //主进程
                //删除信号灯，删除共享内存
                cout << "wait " << pr<<endl;
                cout << "wait " << pw<<endl;
                tw = wait(&pr);
                cout << "writer out!" << endl;
                tw = wait(&pw);
                cout << "reader out!" << endl;
                semctl(semid, 0, IPC_RMID, arg);
                if( -1 == shmctl(shmid, IPC_RMID, 0))
                    cout << "Delete shm failed" << endl;
                cout << "Delete shm successfully" << endl;
            }
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::labelText(char *str)
{
    ui->label->setText(str);
}
