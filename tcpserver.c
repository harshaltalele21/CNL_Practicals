# include<stdlib.h>
# include<netinet/in.h>//The header file in.h contains constants and structures needed for internet domain addresses
# include<time.h>
# include<arpa/inet.h>
# include<string.h>
# include<unistd.h>
# include<netdb.h>
#include<stdio.h> //This header file contains declarations used in most input and output and is typically included in all C programs.
#include<sys/types.h> //This header file contains definitions of a number of data types used in system calls. These types are used in the next two include files.
#include<sys/socket.h>

int main(int argc, char *argv[]) {

	int listensocket;
	struct sockaddr_in  serversocket, clientsocket;
	int buffer[256];
	int ackbuffer[10];

	if(argc<2) {
		printf("\nEnter the port number");
		exit(0);
	}

	printf("\nThis is the SERVER");

	listensocket = socket(AF_INET,SOCK_STREAM,0);

	if(listensocket<0) {
		printf("\nError in creating the socket");
	}
	else {
		printf("\nSocket Created");
	}

	bzero((char *)&serversocket, sizeof(serversocket));

	serversocket.sin_family = AF_INET;
	serversocket.sin_addr.s_addr = INADDR_ANY;
	serversocket.sin_port = htons(atoi(argv[1]));

	int i = bind(listensocket,(struct sockaddr *)&serversocket,sizeof(serversocket));

	if(i==0) {
		printf("\nBinding Successful");
	}
	else {
		printf("\nError in binding");
	}

	
	i = listen(listensocket,1);

	if(i==0) {
		printf("\nListen Successful");
	}
	else {
		printf("\nError in listening");
	}


	int connsd = accept(listensocket, (struct sockaddr*)&clientsocket, sizeof(struct sockaddr_in));

	bzero(buffer,256);
	read(connsd,buffer,255);
	
	printf("\nMessage from the client : \t");
    for(int j=0;j!='\n';j++)
    	printf("%d",buffer[j]);
}