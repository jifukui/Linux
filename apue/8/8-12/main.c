#include "../../apue.h"
static void charatatime(char *);
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        err_sys("fork error");
    }
    else if(pid==0)
    {
        charatatime("abcdefghijklmnopqrstuvwxyz\n");
    }
    else
    {
        charatatime("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    }
    exit(0);
    
}
static void charatatime(char * str)
{
    char *prt;
    int c ;
    setbuf(stdout,NULL);
    for(ptr=str;(c=*prt++)!=0;)
    {
        putc(c,stdout);
    }
}