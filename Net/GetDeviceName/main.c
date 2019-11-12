#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
int main(int argc,char**argv)
{
    struct hostent *h;
    if(argc!=2)
    {
        fprintf(stderr,"Usage :getip address\n");
        extit(1);
    }
    if(h=gethostbyname(argv[1])==NULL)
    {
        herror("Gethostbyname\n");
        exit(1);
    }
    printf("Host name :%s\n",h->h_name);
    printf("IP Address:%s\n",inet_ntoa(*((struct in_addr*)h->h_addr)));
    return 0;
}