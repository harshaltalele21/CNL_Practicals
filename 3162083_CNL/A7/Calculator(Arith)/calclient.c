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
	int client_socket;
	
	client_socket = socket(AF_INET , SOCK_STREAM , 0); // domain , type   , protocol
	
	struct sockaddr_in s;
	
	s.sin_family = AF_INET;  // Sets family
	
	s.sin_port = htons(9023);  // convert original port number
	
	s.sin_addr.s_addr = INADDR_ANY;
	
	int a = connect(client_socket , (struct sockaddr *)&s , sizeof(s)); // socket , s , s
	
	if(a == 0)
	{
	    printf("Connected Properly \n");
	}
	else
	printf("Connection Failed \n");
	
	char server_response[250];
	
	recv(client_socket , &server_response , sizeof(server_response),0); // socket , location to put , size ,flag

    printf("The server sent %s \n" , server_response);
	
	while(1)
	{
	    float res = 0.0;
   
        int b =0,c =0;
        int op = 0 ;
        
        printf("\nEnter the first no \n");
        scanf("%d" ,&b);
        send(client_socket , &b , sizeof(b) , 0);
        
        
        printf("Enter the 2nd no \n");
        scanf("%d" ,&c);
        send(client_socket , &c , sizeof(c) , 0);
        
        
        printf("Enter the operation to be performed 1.add  2.substract  3.multiply  4.divide \n");
        scanf("%d" ,&op);
        send(client_socket , &op , sizeof(op) , 0);
        
       
        
        recv(client_socket , &res , sizeof(res),0);
        printf(" Result : %f " , res);
        
    }
    close(client_socket);
    return 0;
    

}
