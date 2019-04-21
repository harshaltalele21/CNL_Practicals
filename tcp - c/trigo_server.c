#include<stdio.h> //This header file contains declarations used in most input and output and is typically included in all C programs.
# include<stdlib.h>
# include<string.h>
# include<unistd.h>
# include<netinet/in.h>//The header file in.h contains constants and structures needed for internet domain addresses
# include<arpa/inet.h>
# include<netdb.h>
#include<sys/types.h> //This header file contains definitions of a number of data types used in system calls. These types are used in the next two include files.
#include<sys/socket.h> // The header file socket.h includes a number of definitions of structures needed for sockets.
#include<math.h>


int main(int argc,char *argv[])
{
        int fd, i, newfd, size,n;
        struct sockaddr_in serversocket,clientsocket;
         char buffer[1000];
        
	if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     	}
        printf("\t This is Chat Server.\n");
		
        fd=socket(AF_INET,SOCK_STREAM,0);//int socket(domain, type, protocol)

        if(fd<0)
                printf("Socket Could Not Be Created");
        else
                printf("Socket Created Succesfully");

        printf("\nListensocket Value : %d",fd);
        
        bzero((char *)&serversocket,sizeof(serversocket));

        serversocket.sin_family=AF_INET;
        serversocket.sin_port=htons(atoi(argv[1]));
        serversocket.sin_addr.s_addr=INADDR_ANY;
        i = bind(fd,(struct sockaddr *) &serversocket,sizeof(serversocket));/*The bind() system call binds a socket to an address, in this case the address of the current host and port number on which the server will run. It takes three arguments, the socket file descriptor, the address to which is bound, and the size of the address to which it is bound. The second argument is a pointer to a structure of type sockaddr, but what is passed in is a structure of type sockaddr_in, and so this must be cast to the correct type. This can fail for a number of reasons, the most obvious being that this socket is already in use on this machine. */
        if(i == 0)
                printf("\nBinding Is Succesful\n");
        else
                printf("\n Binding Not Succesful\n");

        i = listen(fd,1);/*the listen system call allows the process to listen on the socket for connections. The first argument is the socket file descriptor, and the second is the size of the backlog queue, i.e., the number of connections that can be waiting while the process is handling a particular connection. This should be set to 5, the maximum size permitted by most systems*/
        if(i == 0)
               printf("Listen SUCCESS\n");
        else
                printf("Listen ERROR\n");

        size = sizeof(clientsocket);

        newfd = accept(fd, (struct sockaddr *) &clientsocket,&size);/*The accept() system call causes the process to block until a client connects to the server. Thus, it wakes up the process when a connection from a client has been successfully established. It returns a new file descriptor, and all communication on this connection should be done using the new file descriptor. The second argument is a reference pointer to the address of the client on the other end of the connection, and the third argument is the size of this structure. */

       

     
     
float num=0,x=0,result=0;
int choice=0;
	x=0.01745329251; //pi/180
while(1){
	n= write(newfd,"\n\n1.Sine\n2.Cosine\n3.Tan\n5.Quit\n\nEnterChoice : ",strlen("\n\n1.Sine\n2.Cosine\n3.Tan\n5.Quit\n\nEnterChoice : ")); 
	if(n<0) perror("ERROR");
	read(newfd,&choice,sizeof(float));
	printf("\nchoice\t%d",choice);
	
	n= write(newfd,"\nEnter the value (in degree) : ",strlen("\nEnter the value (in degree) : ")); 
	if(n<0) perror("ERROR");
	read(newfd,&num,sizeof(float));
	printf("\nnum\t%f",num);
	

	
	 switch(choice)
        {
        case 1:
        	result=sin(x*num);
        	break;
        case 2:
        	result=cos(x*num);
        	break;
        case 3:
        	result=tan(x*num);
        	break;
        case 5:
        	goto exit;
        }
        
        n= write(newfd,&result,sizeof(float));
        if(n<0) perror("ERROR");
	}
	
exit:	close(newfd);
	close(fd);
	printf("Exiting..");
	return 0;
}

/* read() must use the new File descriptor returned by the accept(). read(new_fd,&variable,255) it will read 255 bytes only! 
write(fd,&variable,lenght_of_the_variable) */

/*
$ ./ser 5002	 This is Chat Server.
Socket Created Succesfully
Listensocket Value : 3
Binding Is Succesful
Listen SUCCESS

choice	2
num	90.000000
choice	3
num	45.000000
choice	5
num	45.000000Exiting..

*/

