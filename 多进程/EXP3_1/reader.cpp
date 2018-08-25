#include "sem_shm.h"
#include <cstring>
int main()
{
    using namespace std;
    FILE *file;
    file = fopen("Copy.txt", "wb+");
    if(feof(file)){
        cout << "open file failed " << endl;
        return 0;
    }
    struct sembuf sops;
    int ret, status;
    semun arg;
    //int shmid = shmget(MY_KEY, 8*sizeof(BUFF), IPC_CREAT | 0666);      //0666表示：创建者和其他用户创建的进程都可以进行读和写操作， 4为只读
    int shmid = shmget(MY_KEY, sizeof(BUFF_T), IPC_CREAT | 0666);
    if(-1 == shmid){
        cout << "shmget () error !" << endl;
        return 0;
    }
    //失败返回-1, 成功返回指向共享内存第一个字节的指针。
    BUFF_T* sMem = (BUFF_T *)shmat(shmid, NULL, SHM_R | SHM_W);      // NULL表示让系统自动分配内存地址
    if((void *)-1 == sMem){
        cout << "shmid () error !" << endl;
        return 0;
    }
    cout << "reader: 共享内存连接地址： " << (int*)sMem << endl ;
    semid = semget(888, 2, IPC_CREAT|0600); // 创建信号灯，自动，2个，不存在则创建。成功返回信号灯集ID，失败返回-1
    if (semid == -1)
    {
        cout << "create sem failed!" << endl;
        return -1;
    }
    
    int out = 0;
    while (1){
        P(semid, 1);
        out %= 8;
        if(!strncmp(sMem->total[out].msg, "OZEL", 4))
            break;
        fwrite(sMem->total[out].msg, sMem->total[out].len, 1, file);
        out++;
        V(semid, 0); 
    }
    fclose(file);
    exit(-1);
}