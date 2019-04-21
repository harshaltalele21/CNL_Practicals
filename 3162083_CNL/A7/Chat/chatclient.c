/* 
    Chat Application Using TCP
    Sushrut Patil
    3162083
    
*/

#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main()
{
	int client_socket;
	
	client_socket = socket(AF_INET , SOCK_STREAM , 0); // domain , type   , protocol
	
	struct sockaddr_in s;
	
	s.sin_family = AF_INET;  // Sets family
	
	s.sin_port = htons(9029);  // convert original port number
	
	s.sin_addr.s_addr = INADDR_ANY;
	
	int a = connect(client_socket , (struct sockaddr *)&s , sizeof(s)); // socket , s , s
	
	if(a == 0)
	{
	    printf("Connected Properly");
	}
	else
	printf("Connection Failed");
	
	
	char server_response[250];
	
	recv(client_socket , &server_response , sizeof(server_response),0); // socket , location to put , size ,flag

    printf("The server sent %s \n" , server_response);
    char msg[50];
    while(1)
    {
        bzero(msg,50);
        recv(client_socket, &msg , sizeof(msg) ,0 );
        printf("Sushrut : %s" , msg);
        bzero(msg,50);
        printf("Prashant : ");
        fgets(msg,50,stdin);
        send(client_socket, &msg , sizeof(msg) ,0);
        
    }
    close(client_socket);
    return 0;
    

}
