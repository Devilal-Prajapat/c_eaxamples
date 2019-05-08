#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
  int sock, cli , sent;
  struct sockaddr_in server, client;
  unsigned int len;
  char msg[] ="Hello welcome to socket world!!!";
  printf("%s", msg);
// create a socket using socket syscall.
  if((sock = socket(AF_INET,SOCK_STREAM,0))== -1){
    perror("Socket creation error\n");
    exit(1);
  }

server.sin_family = AF_INET;
server.sin_port = htons(10000);
server.sin_addr.s_addr = INADDR_ANY;
bzero(&server.sin_zero,8);
len = sizeof(struct sockaddr_in);
// bind the host and port to socket.
if((bind(sock,(struct sockaddr *)&server,len))==-1){
  perror("bind");
  exit(1);
}
//listen to connection.
if((listen(sock,10))==-1)
{
  perror("listen");
  exit(1);
}

// accept the incomming connection 
while(1){
  if((cli = accept(sock,(struct sockaddr *)&client,&len))==-1){
    perror("accept");
    exit(1);
  }
  sent  = send(cli, msg, strlen(msg),0);
  printf("send - %d bytes to client : %s\n",sent, inet_ntoa(client.sin_addr));
 close(cli);
}
close(sock);
exit(0);
}
