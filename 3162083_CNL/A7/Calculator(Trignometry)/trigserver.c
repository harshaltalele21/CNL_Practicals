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
#include<math.h>

int main()
{
	char server_message[250]="You have reached the server \n";
	int server_socket;
	server_socket = socket(AF_INET , SOCK_STREAM , 0);
	
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(7898);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	bind(server_socket , (struct sockaddr *) &server_address , sizeof(server_address));
	listen(server_socket , 5);
	int client_socket;
	client_socket = accept (server_socket , NULL ,NULL);
	
	send(client_socket , server_message , sizeof(server_message) , 0);
	
	int ch,no1;
	float result;
	recv(client_socket , &ch , sizeof(ch),0);
	recv(client_socket , &no1 , sizeof(no1),0);
	
	
	switch(ch)
	{
	    case 1:
	            result = sqrt(no1);
	            break;
	            
        case 2:
                result = sin(no1);
                break;
                
        case 3:
                result = cos(no1);
                break;
                
        case 4:
                result = tan(no1);
                break;
                	            
	}
	send(client_socket , &result , sizeof(result),0);
	//while(1)
	//{
		//bzero(msg,50);
		//fgets(msg,50,stdin);
		//send(client_socket , msg , sizeof(msg),0);
		//recv(client_socket , &msg , sizeof(msg),0);
		//printf("client : %s\n" , msg);	
	//}
	close (server_socket);
	return 0;
}
