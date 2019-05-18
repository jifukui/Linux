#include <stdio.h>
#include <pthread.h>

int i=0;
int output();
int main()
{
    int status;
    pthread_t pthread_id;
    status=pthread_create(&pthread_id,NULL,output,NULL);
    if(status)
    {
        printf("创建线程失败\n");
    }
    else
    {
        printf("创建线程成功子线程的id为%ld\n",pthread_id);
    }
    
    while (i<2000)
    {
        printf("The father %d\n",i);
        i++;
    }
    return 0;
}
int output()
{
    pthread_t pthread_id;
    printf("我的线程的id 为%ld,当前的全局变量的值为%d\n",pthread_id,i);
    pthread_id=pthread_self();
    while (i<2000)
    {
        printf("The thread %d\n",i);
        i++;
    }
    return 0;
}