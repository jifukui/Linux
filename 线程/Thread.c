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
        printf("创建线程成功\n");
    }
    
    while (i<200)
    {
        printf("The father %d\n",i);
        i++;
    }
    return 0;
}
int output()
{
    while (i<200)
    {
        printf("The thread %d\n",i);
        i++;
    }
    return 0;
}