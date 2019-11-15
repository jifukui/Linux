#include "../../apue.h"
static void my_exit1(void);
static void my_exit2(void);
int main(void)
{
    if(atexit(my_exit2)!=0)
    {
        err_sys("cann't register my exit2\n");
    }
    if(atexit(my_exit1)!=0)
    {
        err_sys("cann't register my exit1\n");
    }
    if(atexit(my_exit1)!=0)
    {
        err_sys("cann't register my exit1\n");
    }
    printf("main is done\n");
    return 0;
}
static void my_exit1(void)
{
    printf("first exit handler\n");
}
static void my_exit2(void)
{
    printf("second exit handler\n");
}
/**atexit函数用于登记函数，
 * 当函数退出的时候调用登记的函数执行顺序与登记顺序相反
 * *