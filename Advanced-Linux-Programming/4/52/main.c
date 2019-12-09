#include <pthread.h>
#include <stdio.h>
struct data
{
    char value;
    int count;
};
void *  cprint(void *value)
{
    struct data *p=(struct data *)value;
    int i;
    for(i=0;i<p->count;++i)
    {
        fputc(p->value,stderr);
    }
    return NULL;
}
int main()
{
    pthread_t th1;
    pthread_t th2;
    struct data thd1;
    struct data thd2;
    thd1.value='x';
    thd1.count=30000;
    pthread_create(&th1,NULL,&cprint,&thd1);
    thd2.value='o';
    thd2.count=20000;
    pthread_create(&th2,NULL,&cprint,&thd2);
}