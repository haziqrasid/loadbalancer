#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
	int sock;
	struct sockaddr_in server;
	char message[3000];
	
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock==-1){
	   printf("Could not create socket");
	}
	puts("Socket created");

	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_family=AF_INET;
	server.sin_port=htons(1000);

	if(connect(sock,(struct sockaddr *)&server,sizeof(server))<0){
		perror("Fail to connect to loadbalancer");
		return 1;
	}

	printf("Enter your message");
	scanf("%s",message);
	if(send(sock,message,strlen(message),0)<0){
	puts("Fail to send");
	return 1;
	}
	close(sock);
return 0;
}
