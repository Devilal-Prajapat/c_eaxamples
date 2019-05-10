/*
 ============================================================================
 Name        : unix_client.c
 Author      : Devilal Prajapat
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_NAME "/tmp/DemoSock1"
#define SIZE 1024

#if 0
	struct sockaddr_un{
	  sa_family_t sun_family;
	  char sun_path[108];
	};
#endif

int main(){
  int data_socket;
  struct sockaddr_un server;
  int ret;
  int i;
  char buffer[SIZE];
  char msg[] ="Hello welcome to socket world!!!";
  printf("%s", msg);

 data_socket = socket(AF_UNIX,SOCK_STREAM,0);
  if(data_socket== -1){
    perror("Socket creation error\n");
    exit(1);
  }

	memset(&server, 0, sizeof(struct sockaddr_un));
	server.sun_family = AF_UNIX;
	strncpy(server.sun_path,SOCKET_NAME,sizeof(server.sun_path)-1);

	ret = connect(data_socket,(struct sockaddr *)&server,sizeof(struct sockaddr_un));

	if(ret == -1){
	  perror("connect");
	  exit(1);
	}

	do{
	  printf("eneter number to send\n");
	  scanf("%d",&i);
	  ret = write(data_socket,&i, sizeof(int));
	  if(ret == -1){
		perror("write");
		break;
	  }

	  printf("send %d bytes and data is %d\n",ret, i);
	 if(i == 0)break;
	}while(1);

	memset(buffer,0,SIZE);

	ret = read(data_socket,buffer,SIZE);
	if(ret == -1){
		perror("read");
		exit(EXIT_FAILURE);
	  }
	printf("Received %s from server\n",buffer);

	close(data_socket);

	exit(0);
}
