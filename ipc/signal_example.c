#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void sigint_sig_handler(int sig_id)
{
    printf("sig_id %d\r\n", sig_id);
    printf("Bye\r\n");
    exit(0);
}

void abort_sig_handler(int sig_id)
{
  printf("sig_id %d\r\n", sig_id); 
  printf("Bye\r\n");
  exit(0);
}

int main()
{
    printf("Hello World\r\n");
    signal(SIGINT,sigint_sig_handler);
    signal(SIGABRT,abort_sig_handler);
    char ch;
    printf("Abort process y/n \r\n"); 
    scanf("%c",&ch);
    if(ch == 'y')
    {
        abort();
    }
     

    return 0;
}
