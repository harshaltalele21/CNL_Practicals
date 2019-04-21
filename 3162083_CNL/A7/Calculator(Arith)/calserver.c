/*
    TCP Calculator (Arithmetic)
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
    char server_message[250] = "You have reached server !";
    int server_socket;
    
    server_socket = socket(AF_INET , SOCK_STREAM ,0);
    
    struct sockaddr_in ss;
    
    ss.sin_family = AF_INET;
    
    ss.sin_port = htons(9023);
    
    ss.sin_addr.s_addr = INADDR_ANY;
    //bind to IP and Port
    
    bind(server_socket , (struct sockaddr*)&ss , sizeof(ss));
    
    listen(server_socket , 5); //socket , backlog
    
    int client_socket = accept(server_socket, NULL , NULL); // accept
    
    send(client_socket , server_message , sizeof(server_message) , 0); // send message to client
    
    while(1)
    {
    int a=0 ,b=0;
    int op = 0;
    float result = 0.0;
	
	recv(client_socket , &a , sizeof(a),0);
	recv(client_socket , &b , sizeof(b),0);
	recv(client_socket , &op , sizeof(op),0);
	
	switch (op) 
	{
	    case 1 :
	            result = a+b;
	            break;
	            
        case 2 :
	            result = a-b;
	            break;
	            
        case 3 :
	            result = a*b;
	            break;
	            
        case 4 :
	            result = a/b;
	            break;
	            
	}
	
	send(client_socket , &result , sizeof(result) , 0);
	
    }   
    close (server_socket);
    
    return 0; 
}
