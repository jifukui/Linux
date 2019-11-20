#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <stdio.h>
/**
 * 创建信号量int semget(key_t key, int nsems, int semflg)
 * key为信号量的标识符，nsems为信号量的数量，semflg为权限的标识符
*/
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int array;
    struct seminfo *__buf;
};
int binary_semaphore_allocation(key_t key,int sem_flags)
{
    return semget(key,1,sem_flags);
}
int binary_semaphore_deallocate(int semid)
{
    union semun ignored_argument;
    return semctl(semid,1,IPC_RMID,ignored_argument);
}
int binary_semaphore_initialize(int semid)
{
    union semun argument;
    unsigned short values[1];
    values[0]=1;
    argument.array=values;
    return semctl(semid,0,SETALL,argument);
}
int binary_semaphore_wait(int semid)
{
    struct sembuf operations[1];
    operations[0].sem_num=0;
    operations[0].sem_op=-1;
    operations[0].sem_flag=SEM_UNDO;
    printf("now is %d\n",(int)getpid());
    return semop(semid,operations,1);
}
int binary_semaphore_post(int semid)
{
    struct sembuf operations[1];
    operations[0].sem_num=0;
    operations[0].sem_op=1;
    operations[0].sem_flag=SEM_UNDO;
    printf("now is %d\n",(int)getpid());
    return semop(semid,operations,1);
}
int main()
{
    int err=binary_semaphore_allocation(1,IPC_CREAT | IPC_EXCL|0666);
    if(err==-1)
    {
        printf("error of greated\n");
    }
    err=binary_semaphore_initialize(1);
    if(err==-1)
    {
        printf("init error\n");
    }
    int i=0;
    for(i;i<5;i++)
    {
        err=fork();
        if(err<0)
        {
            printf("%d have error\n",i);
        }
        else if(err==0)
        {
            printf("now is %d\n",(int)getpid());
            binary_semaphore_wait(1);
            binary_semaphore_post(1);
        }
        
    }
}