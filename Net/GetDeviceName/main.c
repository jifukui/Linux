#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
int main(int argc,char**argv)
{
    struct hostent *h;
    printf("The input is %d\n",argc);
    if(argc!=2)
    {
        printf("Usage :getip address\n");
        return 0;
    }
    if((h=gethostbyname(argv[1]))==NULL)
    {
        herror("Gethostbyname error\n");
        return 0;
    }
    printf("Get Ip Address Successfully\n");
    printf("Host name :%s\n",h->h_name);
    printf("IP Address:%s\n",inet_ntoa(*((struct in_addr*)h->h_addr)));
    return 0;
}