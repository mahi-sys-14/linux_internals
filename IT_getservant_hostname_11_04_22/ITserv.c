#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

#define PORT	8000
#define MAXSIZ	100

int main()
{
	int sock_fd;	// to create socket
       	int connfd;	// for accept connection
       	int retval;
	char s_buf[MAXSIZ];

	int n;

	socklen_t clilen;
	struct sockaddr_in clientaddr, servaddr;

	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_fd < 0)
	{
		perror("sock: ");
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT); // 16 bit short 	TCP protocol HTTP---port

	retval = bind(sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if(retval < 0)
	{
		perror("bind: ");
		exit(2);
	}

	listen(sock_fd, 5);

	// accept a connection
	while(1)
	{
		printf(".......Server waiting for client connection\n");

		printf("socket bound to port 8000\n");
		clilen = sizeof(clientaddr);
		connfd = accept(sock_fd, (struct sockaddr *) &clientaddr, &clilen);
		printf("client connected\n");

		// receive from client
	while(1)
	{
		printf("\nbefore recvfrom\n");
		printf("%d bytes\t %s\n", n, s_buf);

		n = recv(connfd, s_buf, MAXSIZ	, 0);
		printf("value of n after recv in client: %d\n", n);
		if(n == 0)
		{
			printf("server connection closed\n");
			close(connfd);
			break;
		}

		printf("rec’d %d bytes\n", n);
		s_buf[n] = 0;
		printf("msg from client to server is: %s\n", s_buf);
		getchar();

		send(connfd, s_buf, n, 0);
//		printf("msg from client is: %s\n", s_buf);
	
	} // close interior while
	} // close exterior while

//	close(sock_fd);

	return 0;
}
