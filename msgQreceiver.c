#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>

#define MAX_MSG_SIZE 256
#define MAX_BUFFER_SIZE (MAX_MSG_SIZE+10)
#define MAX_MSG 10
#define msgq_name "/client"
#define permission 0666

//int main(int argc, char *argv[])
int main(){
  fd_set readfs;
  char buffer[MAX_BUFFER_SIZE];
  int msgq_fd = 0;
  int ret;
  struct mq_attr attr;
   /* initialize the queue attributes */
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MSG;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;
  /*if(argc<=1){
    printf("please provide MsgQ name\n");
    exit(1);
  }*/
  
  msgq_fd = mq_open(msgq_name, O_RDONLY | O_CREAT, 0666,0);
  if(msgq_fd == -1){
    printf("error : %s\n",strerror(errno));
    exit(1);
  }
  while(1){
    FD_ZERO(&readfs);
    FD_SET(msgq_fd, &readfs);
    select(msgq_fd+1, &readfs,NULL,NULL,NULL);
    printf("block on select sys call\n");
    if(FD_ISSET(msgq_fd,&readfs)){
        printf("msg from msgQ is %s\n",msgq_name);
        memset(buffer, 0, MAX_BUFFER_SIZE);
        ret  =  mq_receive(msgq_fd, buffer, MAX_BUFFER_SIZE, NULL);
        if(ret == -1){
          printf("error in sending %d and %s\n", errno, strerror(errno));
          exit(1);
        }
        printf("Msg Received from sender is %s\n", buffer);
    }
    printf("msg to send is %s\n", buffer);
  } 
}