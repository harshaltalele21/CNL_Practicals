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
    char server_message[250] = "You have reached server !";
    int server_socket;
    
    server_socket = socket(AF_INET , SOCK_STREAM ,0);
    
    struct sockaddr_in ss;
    
    ss.sin_family = AF_INET;
    
    ss.sin_port = htons(9029);
    
    ss.sin_addr.s_addr = INADDR_ANY;
    //bind to IP and Port
    
    bind(server_socket , (struct sockaddr*)&ss , sizeof(ss));
    
    listen(server_socket , 5); //socket , backlog
    
    int client_socket = accept(server_socket, NULL , NULL); // accept
    
    send(client_socket , server_message , sizeof(server_message) , 0); // send message to client
    
    char msg[50];
    while(1)
    {
        bzero(msg,50);
        printf("Sushrut : ");
        fgets(msg,50,stdin);
        send(client_socket, &msg , sizeof(msg) ,0);
        bzero(msg,50);
        recv(client_socket, &msg , sizeof(msg) ,0 );
        printf("Prashant : %s" , msg);
        
        
    }
    close (server_socket);
    
    return 0; 
}
