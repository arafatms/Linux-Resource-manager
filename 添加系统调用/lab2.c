#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <linux/sem.h>
void *subp1();
void *subp2();
int semid;
int a = 0;
pthread_t id1,id2;
void P(int semid,int index);
void V(int semid,int index);
int main()
{
    semid = semget(IPC_PRIVATE,2,IPC_CREAT|0666);
    semctl(semid,0,SETVAL,1);
    semctl(semid,1,SETVAL,0);
    pthread_create(&id1,NULL,subp1,NULL);
    pthread_create(&id2,NULL,subp2,NULL);
    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
    putchar('\n');
    semctl(semid,0,IPC_RMID);
    return 0;
}
void *subp1()
{
    int i=1;
    for( ; i<101;++i )
    {
	syscall(333,semid,0);//P(semid,0);
	a += i;
	syscall(334,semid,1);//V(semid,1);
    }
}
void *subp2()
{
    int i=1;
    for( ; i<101;++i)
    {
	syscall(333,semid,1);//P(semid,1);
	//P(semid,1);
        printf("%d",a);
	if(i%10) putchar(' ');
	else putchar('\n');
	syscall(334,semid,0);//V(semid,0);
    }
}
void P(int semid,int index)
{	struct sembuf sem;	
        sem.sem_num = index;
        sem.sem_op = -1;	
        sem.sem_flg = 0; //操作标记：0或IPC_NOWAIT等
        semop(semid,&sem,1);	//1:表示执行命令的个数	
        return;
}
void V(int semid,int index)
{	
      struct sembuf sem;	
      sem.sem_num = index;
      sem.sem_op =  1;
      sem.sem_flg = 0;	
      semop(semid,&sem,1);	
      return;
}

