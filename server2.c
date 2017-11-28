#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
	int socket_desc,client_sock,c,read_size;
	struct sockaddr_in server,cl;
	char client_message[3000];

	socket_desc=socket(AF_INET,SOCK_STREAM,0);
	if(socket_desc==-1){
		printf("cant create socket");
	}
	
	puts("socket created");

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(4000);

	if(bind(socket_desc,(struct sockaddr *)&server,sizeof(server))<0){
	perror("fail to bind the socket to server");
	return 1;
	}
	
	puts("bind done");

	listen(socket_desc,3);

	puts("waiting for incoming connection");
	c=sizeof(struct sockaddr_in);

	client_sock=accept(socket_desc,(struct sockaddr *)&cl,(socklen_t *)&c);
	if(client_sock<0){
	perror("accept failed");
	return 1;
	}
	puts("connection accepted");

	read_size=recv(client_sock,client_message,3000,0);

	printf("%s",client_message);
	
	
}
