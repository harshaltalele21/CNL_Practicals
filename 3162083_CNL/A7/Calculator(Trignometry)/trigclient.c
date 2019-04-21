/*
    TCP Calculator(Trignometric)
    Sushrut Patil
    3162083
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
	int network_socket;
	network_socket = socket(AF_INET , SOCK_STREAM , 0);
	
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(7898);
	server_address.sin_addr.s_addr = INADDR_ANY;
	int c;
	c = connect (network_socket , (struct sockaddr *) &server_address , sizeof(server_address));
	if(c == -1)
	printf("Error in Connection \n");
	
	char server_response[250];
	recv(network_socket , &server_response , sizeof(server_response),0);
	printf("The server sent %s\n", server_response);
	
	char msg[50];	
	printf("\n Trino \n");
	printf("\n 1. SQRT / 2. sin / 3. cos / 4. tan \n");
	int ch , no1;
	scanf("%d",&ch);
	send(network_socket , &ch , sizeof(ch),0);
	printf("\n Enter no or angle \n");
	scanf("%d",&no1);
	send(network_socket , &no1 ,sizeof(no1),0);
	float result;
	recv(network_socket , &result , sizeof(result),0);
	printf("\n The result of the operation is %f \n" , result);
	//while(1)
	//{
		
		//recv(network_socket , &msg , sizeof(msg),0);
		//printf("server : %s\n" , msg);
		//bzero(msg,50);	
		//fgets(msg,50,stdin);
		//send(network_socket , msg , sizeof(msg),0);
	//}
	close(network_socket);
	return 0;
}
