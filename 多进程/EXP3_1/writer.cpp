#include "sem_shm.h"
#include <cstring>
int main()
{
    using namespace std;    
    FILE *file;
    file = fopen("animal farm.txt", "rb");
    if(file == NULL){
        cout << "open file failed " << endl;
        return 0;
    }
    struct sembuf sops;
    int ret, status;
    semun arg;
    int shmid = shmget(MY_KEY, sizeof(BUFF_T), IPC_CREAT | 0666);      //0666表示：创建者和其他用户创建的进程都可以进行读和写操作， 4为只读
    if(-1 == shmid){
        cout << "shmget () error !" << endl;
        return 0;
    }
    BUFF_T* sMem = (BUFF_T *)shmat(shmid, NULL, SHM_R | SHM_W);      // NULL表示让系统自动分配内存地址
    if((void *)-1 == sMem){
        cout << "shmid () error !" << endl;
        return 0;
    }
    cout << "writer :共享内存连接地址： " << (int*)sMem << endl ;
    semid = semget(888, 2, IPC_CREAT|0600); // 创建信号灯，自动，2个，不存在则创建。成功返回信号灯集ID，失败返回-1
    if (semid == -1)
    {
        cout << "create sem failed!" << endl;
        return -1;
    }
    
    int in = 0;
    BUFF_T *ptr = NULL;
    while(1){
        P(semid, 0);
        in %= 8;
        sMem->total[in].len = fread(sMem->total[in].msg, 1, BUFF_SIZE, file);
        if( !sMem->total[in].len ) {
            in++;
            in %= 8;
            V(semid, 1); 
            memset(sMem->total[in].msg, 0, BUFF_SIZE);
            strcpy(sMem->total[in].msg, "OZEL");
            sMem->total[in].len = 4;
            V(semid, 1);
            break;
        }
        in++;
        V(semid, 1); 
    }
    fclose(file);
    exit(-1);
}