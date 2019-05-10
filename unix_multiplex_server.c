/*
 ============================================================================
 Name        : unix_multiplex_server.c
 Author      : Devilal Prajapat
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <string.h>

#define SOCKET_NAME "/tmp/DemoSock1"
#define MAX_ALLOWED_CLIENT 32
#define BUFFER_SIZE 128
int monitor_fd_set[MAX_ALLOWED_CLIENT];
int client_result[MAX_ALLOWED_CLIENT]={0};

// function prototype for select system calls

static void initialize_monitor_fd_set();
static void add_to_monitor_fd_set(int skt_fd_set);

static void initialize_monitor_fd_set(){
	int i = 0;
	for(; i<MAX_ALLOWED_CLIENT;i++){
		monitor_fd_set[i] = -1;
	}
}

static void add_to_monitor_fd_set(int skt_fd_set){
	int i = 0;
	for(; i<MAX_ALLOWED_CLIENT;i++){
		if(monitor_fd_set[i]!= -1)
			continue;
		monitor_fd_set[i] = skt_fd_set;
		break;
	}
}

static void remove_from_monitor_fd_set(int skt_fd_set){
	int i = 0;
	for(; i<MAX_ALLOWED_CLIENT;i++){
		if(monitor_fd_set[i] != skt_fd_set)
			continue;
		monitor_fd_set[i] = -1;
		break;
	}
}

static void refresh_monitor_fd_set(fd_set *fd_set_ptr){
	FD_ZERO(fd_set_ptr);
	for(int i= 0;i<MAX_ALLOWED_CLIENT;i++){
		if(monitor_fd_set[i] != -1){
			FD_SET(monitor_fd_set[i],fd_set_ptr);
		}
	}
}

static int get_max_fd(){
	int i = 0;
	int max = -1;
	for(;i<MAX_ALLOWED_CLIENT;i++){
		if(monitor_fd_set[i]>max){
			max = monitor_fd_set[i];
		}
	}
	return max;
}

int main(void) {
	//required declartion for socket_unix
	struct sockaddr_un name;
	fd_set readfs;
	int master_socket, data_socket;
	int ret;
	int client_sock_fd,i;
	char buffer[BUFFER_SIZE];
	int data;

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	initialize_monitor_fd_set();
	master_socket = socket(AF_UNIX,SOCK_STREAM,0);
	if(master_socket == -1){
		perror("Socket");
		exit(EXIT_FAILURE);
	}
	memset(&name, 0,sizeof(struct sockaddr_un));
	name.sun_family = AF_UNIX;
	strncpy(&name.sun_path,SOCKET_NAME,sizeof(name.sun_path)-1);

	ret = bind(master_socket,(struct sockaddr *)&name, sizeof(struct sockaddr_un));
	if(ret == -1){
		perror("Bind");
		exit(EXIT_FAILURE);
	}

	ret = listen(master_socket,20);
	if(ret == -1){
		perror("Listen");
		exit(EXIT_FAILURE);
	}
	// add master socket to monitor_fd_set list
	add_to_monitor_fd_set(master_socket);
	for(;;){
		refresh_monitor_fd_set(&readfs);
		printf("waiting select syscall\n");
		select(get_max_fd()+1,&readfs,NULL,NULL,NULL);
		if(FD_ISSET(master_socket,&readfs)){
			printf("New connection request accept sys call\n");
			data_socket = accept(master_socket,NULL,NULL);// accept sys call
			if(data_socket == -1){
				perror("accept");
				exit(EXIT_FAILURE);
			}
			printf("connection accepted\n");
			add_to_monitor_fd_set(data_socket);
		}
		else{
			i = 0;
			client_sock_fd = -1;
			for(;i<MAX_ALLOWED_CLIENT;i++){
				if(FD_ISSET(monitor_fd_set[i],&readfs)){
					client_sock_fd = monitor_fd_set[i];
					printf("waiting data from client\n");
					ret = read(client_sock_fd,buffer,BUFFER_SIZE);// reading data from client
					if(ret == -1){
						perror("read");
						exit(EXIT_FAILURE);
					}
					memcpy(&data,buffer,sizeof(int));
					printf("data received : %d\n",data);
					if(data == 0){
						memset(buffer,0,BUFFER_SIZE);
						sprintf(buffer,"result : %d\n",client_result[i]);
						printf("sending data to client\n");
						ret = write(client_sock_fd, buffer, BUFFER_SIZE);//writing dta to client
						if(ret == -1){
							perror("read");
							exit(EXIT_FAILURE);
						}
						close(client_sock_fd);
						client_result[i] = 0;
						remove_from_monitor_fd_set(client_sock_fd);
						continue;
					}
					client_result[i] += data;
				}
			}
		}
	}
	close(master_socket);
	remove_from_monitor_fd_set(master_socket);
	printf("closing connection !!!\n");
	unlink(SOCKET_NAME);


	return EXIT_SUCCESS;
}
