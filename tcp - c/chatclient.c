
#include <stdlib.h>
#include <netinet/in.h> //The header file in.h contains constants and structures needed for internet domain addresses
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h> //read write close functions
#include <netdb.h>
#include <stdio.h> //This header file contains declarations used in most input and output and is typically included in all C programs.
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{
        struct sockaddr_in serversocket;
        int listensocket, i, connsd, size;
        char arr[100], sendbuff[100], recvbuff[100];
        if (argc < 3)
        {
                fprintf(stderr, "usage %s hostname port\n", argv[0]);
                exit(0);
        }
        printf("\tThis is Chat Client.\n");
        bzero((char *)&serversocket, sizeof(serversocket));

        listensocket = socket(AF_INET, SOCK_STREAM, 0); //int socket(domain, type, protocol)

        if (listensocket < 0)
                printf("Socket Could Not Be Created");
        else
                printf("Socket Created Succesfully");

        printf("\nListensocket Value : %d", listensocket);

        serversocket.sin_family = AF_INET;
        serversocket.sin_port = htons(atoi(argv[2]));
        serversocket.sin_addr.s_addr = INADDR_ANY;
        i = connect(listensocket, (struct sockaddr *)&serversocket, sizeof(serversocket)); /*The connect() system call connects the socket referred to by the file descriptor sockfd to the address specified by addr. The addrlen argument specifies the size of addr.*/

        if (i == 0)
                printf("\nConnect SUCCESS\n");
        else
                printf("\nConnect ERROR\n");

        while (1)
        {
                printf("\nEnter the message to the Server : ");
                bzero(sendbuff, 256);
                fgets(sendbuff, 100, stdin);
                // send(listensocket,sendbuff,strlen(sendbuff),0);
                write(listensocket, sendbuff, strlen(sendbuff));
                bzero(sendbuff, 256);
                read(listensocket, sendbuff, 255);
                printf("\nMessage from Server : ");
                printf("%s\n", sendbuff);
        }
        close(listensocket);
}
/*
$ ./cli localhost 5004
	This is Chat Client.
Socket Created Succesfully
Listensocket Value : 3
Connect SUCCESS

Enter the message to the Server : hello from client

Message from Server : received from the client


Enter the message to the Server : thank you

Message from Server : bye


Enter the message to the Server : 

*/
