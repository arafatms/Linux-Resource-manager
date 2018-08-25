#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include<sys/wait.h>

const int BUFF_SIZE = 100;
const int MY_KEY = 528;
const int shm_size = 8;
int semid;

typedef struct {
    char msg[BUFF_SIZE];
    int len;
}BUFF;

typedef struct {
    BUFF total[shm_size];
}BUFF_T;

/* arg for semctl system calls. */
union semun {
	int val;			/* value for SETVAL */
	struct semid_ds *buf;	/* buffer for IPC_STAT & IPC_SET */
	unsigned short *array;	/* array for GETALL & SETALL */
	struct seminfo *__buf;	/* buffer for IPC_INFO */
	void *__pad;
};
void P(int semid, int index)
{
    struct sembuf sem;
    sem.sem_num = index;
    sem.sem_op = -1;
    sem.sem_flg = 0;
    semop(semid, &sem, 1);
    return;
}

void V(int semid, int index){
    struct sembuf sem;
    sem.sem_num = index;
    sem.sem_op = 1;
    sem.sem_flg = 0;
    semop(semid, &sem, 1);
    return;
}
