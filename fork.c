#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    int pid;
    pid = fork();
    if (pid== -1){
      printf("unable to create child\n");
      exit(1);
    }
    sleep(1);
    if(pid==0){
        
        printf("child process with pid = %d \t%d\n", getpid(),getppid());
        
        
    }
    else{
     
        printf("parent process with pid =  %d\t %d\n", getpid(),getppid());
        
       
    }
    return 0;
}