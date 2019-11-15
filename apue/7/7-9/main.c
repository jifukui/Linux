#include "../../apue.h"
#define TOK_ADD 5
void do_line(char *);
void cmd_add(void);
int get_token(void);
int main(void)
{
    char line[MAXLINE];
    while (fgets(line,MAXLINE,stdin)!=NULL)
    {
        do_line(line);
    }
    exit(0);
}
char 