/*
    TCP File Transfer (Text)
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
    
    ss.sin_port = htons(9004);
    
    ss.sin_addr.s_addr = INADDR_ANY;
    //bind to IP and Port
    
    bind(server_socket , (struct sockaddr*)&ss , sizeof(ss));
    
    listen(server_socket , 5); //socket , backlog
    
    int client_socket = accept(server_socket, NULL , NULL); // accept
    
    send(client_socket , server_message , sizeof(server_message) , 0); // send message to client
       
    
    char buffer[1000];
    
    FILE *fp;
    
    read(client_socket,buffer,1000);
    
    fp=fopen("a1.txt","w");
    
    fprintf(fp,"%s",buffer);
    
    printf("the file was received successfully");
    
    printf("the new file created is a1.txt");
    
    close (server_socket);
    
    return 0; 
}


