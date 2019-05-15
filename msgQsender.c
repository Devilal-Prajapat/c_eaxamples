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
#define MSG_BUFFER_SIZE (MAX_MSG_SIZE+10)
#define msgq_name "/client"
#define permission 666

//int main(int argc, char *argv[])
int main(){
  char buffer[MSG_BUFFER_SIZE];
  int recv_msgq_fd = 0;
  int ret;
  /*if(argc<=1){
    printf("please provide MsgQ name\n");
    exit(1);
  }*/
  memset(buffer,0,MSG_BUFFER_SIZE);
  //printf("Enter msg to send to receiver %s", argv[1]);
  printf("Enter msg to send to receiver %s", msgq_name);
  scanf("%s", buffer);
  recv_msgq_fd = mq_open(msgq_name, O_WRONLY | O_CREAT, 0,0);
  if(recv_msgq_fd == -1){
    printf("error : %s\n",strerror(errno));
    exit(1);
  }
  ret = mq_send(recv_msgq_fd, buffer,strlen(buffer)-1,0);
  if(ret == -1){
    printf("error in sending %d\n", errno);
    exit(1);
  }
  printf("msg to send is %s\n", buffer);
  mq_close(recv_msgq_fd); 
}