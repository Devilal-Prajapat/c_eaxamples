#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
  
  int client_socket,sent;
  struct sockaddr_in remote_server;
  unsigned int len;
  int ret;
  char input[BUFFER_SIZE];
  char output[BUFFER_SIZE];
  char msg[] ="Hello welcome to socket world!!!";
  printf("%s", msg);
// create a socket using socket syscall.
  if((client_socket = socket(AF_INET,SOCK_STREAM,0))== -1){
    perror("Socket creation error\n");
    exit(1);
  }

remote_server.sin_family = AF_INET;
remote_server.sin_port = htons(atoi(argv[2]));
remote_server.sin_addr.s_addr =inet_addr(argv[1]);
bzero(&remote_server.sin_zero,8);
len = sizeof(struct sockaddr_in);
// bind the host and port to socket.
ret = connect(client_socket,(struct sockaddr *)&remote_server,sizeof(struct sockaddr_in));

if(ret == -1){
  perror("connect");
  exit(1);
}
while(1){
  printf("Enter data\n");
  fgets(input,BUFFER_SIZE,stdin);
  send(client_socket,input,strlen(input),0);
  len = recv(client_socket, output, strlen(output),0);
  output[len] ='\0';
  printf("received %s from remote_server\n", output);
}
close(client_socket);
// accept the incomming connection 

  exit(0);
}
