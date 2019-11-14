#include "../../apue.h"
#include <dirent.h>
int main(int argc ,char **argv)
{
    DIR * dp=NULL;
    struct dirent *dirp=NULL;
    if(argc!=2)
    {
        err_quit("usage:ls directory_name\n");
    }
    if((dp=opendir(argv[1]!=NULL)))
    {
        err_sys("cann't open %s\n",argv[1]);
    }
    while ((dirp=readdie(dp)!=NULL))
    {
        printf("%s\n",dirp->d_name);
    }
    closedir(dp);
    exit(0);
}