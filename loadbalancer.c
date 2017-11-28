#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
	int socket_desc,client_sock,c,read_size,ssocket1,ssocket2;
	struct sockaddr_in loadbalancer,client,s1,s2;
	char client_message[3000];

	socket_desc=socket(AF_INET,SOCK_STREAM,0);
	
	if(socket_desc==-1){
	printf("Cant create socket");
	}
	puts("loadbalancer socket created");
	

	loadbalancer.sin_family=AF_INET;
	loadbalancer.sin_addr.s_addr=INADDR_ANY;
	loadbalancer.sin_port=htons(1000);

	if(bind(socket_desc,(struct sockaddr *)&loadbalancer,sizeof(loadbalancer))<0){
	perror("Fail to bind the socket to server");
	return 1;
	}
	
	puts("Bind done");

	listen(socket_desc,3);

	puts("Waiting for incoming connection");
	c=sizeof(struct sockaddr_in);


	client_sock=accept(socket_desc,(struct sockaddr *)&client,(socklen_t *)&c);
	if(client_sock<0){
	perror("Accept failed");
	return 1;
	}
	puts("Connection accepted");

	read_size=recv(client_sock,client_message,3000,0);
	
	if(strcmp(client_message,"server 1")==0){
	serversocket1=socket(AF_INET,SOCK_STREAM,0);
	s1.sin_family=AF_INET;
	s1.sin_addr.s_addr=inet_addr("192.168.32.128");
	s1.sin_port=htons(3000);
	if(connect(ssocket1,(struct sockaddr *)&s1,sizeof(s1))<0){
	perror("fail to connect to loadbalancer");
	return 1;
	}

	if(send(ssocket1,client_message,strlen(client_message),0)<0){
	puts("Fail to send");
	return 1;
	}	
	close(ssocket1);
	}
	
	else if(strcmp(client_message,"server 2")==0){
	serversocket2=socket(AF_INET,SOCK_STREAM,0);
	s2.sin_family=AF_INET;
	s2.sin_addr.s_addr=inet_addr("192.168.32.129");
	s2.sin_port=htons(4000);
	if(connect(ssocket2,(struct sockaddr *)&s2,sizeof(s2))<0){
	perror("Fail to connect to loadbalancer");
	return 1;
	}
		
	if(send(ssocket2,client_message,strlen(client_message),0)<0){
	puts("Fail to send");
	return 1;
	}
	close(ssocket2);	
	}
	
	else{
	printf("ERROR!!! the message did not redirected to any server");	
	}	
}
