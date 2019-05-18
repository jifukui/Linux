#include <stdio.h>
#include <pthread.h>

int i=0;
int output();
int main()
{
    int status;
    pthread_t pthread_id,pthread_id1,pthread_id2;
    pthread_id2=pthread_self();
    status=pthread_create(&pthread_id,NULL,output,NULL);
    if(status)
    {
        printf("创建线程失败\n");
    }
    else
    {
        printf("创建线程成功子线程的id为%u\n",pthread_id);
        /*status=pthread_join(pthread_id,NULL);
        if(status)
        {
            printf("链接线程%u失败\n",pthread_id);
        }
        else
        {
            printf("链接线程%u成功\n",pthread_id);
        }*/
        
    }
    status=pthread_create(&pthread_id1,NULL,output,NULL);
    if(status)
    {
        printf("创建线程1失败\n");
    }
    else
    {
        printf("创建线程1成功子线程的id为%u\n",pthread_id1);
        /*status=pthread_join(pthread_id1,NULL);
        if(status)
        {
            printf("链接线程%u失败\n",pthread_id1);
        }
        else
        {
            printf("链接线程%u成功\n",pthread_id1);
        }*/
    }
    while (i<2000)
    {
        printf("The father %u %d\n",pthread_id2,i);
        i++;
    }
    status=pthread_join(pthread_id,NULL);
    if(status)
    {
        printf("链接线程%u失败\n",pthread_id);
    }
    else
    {
        printf("链接线程%u成功\n",pthread_id);
    }
    status=pthread_join(pthread_id1,NULL);
    if(status)
    {
        printf("链接线程%u失败\n",pthread_id1);
    }
    else
    {
        printf("链接线程%u成功\n",pthread_id1);
    }
    printf("主线程退出\n");
    return 0;
}
int output()
{
    pthread_t pthread_id;
    pthread_id=pthread_self();
    printf("我的线程的id 为%u,当前的全局变量的值为%d\n",pthread_id,i);
    while (i<2000)
    {
        printf("The thread %u %d\n",pthread_id,i);
        i++;
    }
    printf("子线程退出\n");
    return 0;
}