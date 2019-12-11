#include <pthread.h>
#include <stdio.h>
void *compute(void *arg)
{
    int cand=2;
    printf("the arg is %x\n",arg);
    printf("the *arg is %d\n",(int *)arg);
    printf("the n is %d\n",*((int*)arg));
    int n=*((int*)arg);
    while (1)
    {
        int factor;
        int is_prime=1;
        for(factor=2;factor<cand;++factor)
        {
            if (cand %factor==0)
            {
                is_prime=0;
                break;
            }
        }
        if(is_prime)
        {
            if(--n==0)
            {
                return (void*)cand;
            }
        }
        ++cand;
    }
    return NULL;
}
int main()
{
    pthread_t thread;
    int which_prime=5000;
    int prime;
    pthread_create(&thread,NULL,&compute,&which_prime);
    pthread_join(thread,(void *)&prime);
    printf("The number %d is %d\n",which_prime,prime);
    return 0;
}