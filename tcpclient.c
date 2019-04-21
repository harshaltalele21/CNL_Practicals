#include <stdlib.h>
#include <netinet/in.h>
#include <time.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {

	int listensocket;
	int buffer[256];
	int ackbuffer[10];
	struct sockaddr_in serversocket;

	if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    printf("This is the CLIENT\n");

    listensocket = socket(AF_INET,SOCK_STREAM,0);

    if(listensocket<0) {
		printf("\nError in creating the socket");
	}
	else {
		printf("\nSocket Created");
	}

	bzero((char*)&serversocket, sizeof(serversocket));
	serversocket.sin_family = AF_INET;
	serversocket.sin_addr.s_addr = INADDR_ANY;
	serversocket.sin_port = htons(atoi(argv[2]));

	int i = connect(listensocket,(struct sockaddr *)&serversocket, sizeof(serversocket));

	if(i==0) {
		printf("\nConnection Successful");
	}
	else {
		printf("\nError in Connection");
	}

	//int data[15]=[1,2,3,4,5];

	//write(listensocket,data,sizeof(data));

}