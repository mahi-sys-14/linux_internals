#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int sock_fd, connfd, retval;

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
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");//htonl(INADDR_ANY);
	servaddr.sin_port = htons(8000);//TCP protocol HTTP---port

	retval = bind(sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if(retval < 0)
	{
		perror("bind: ");
		exit(2);
	}

	listen(sock_fd, 5);

	while(1)
	{
		clilen = sizeof(clientaddr);
		connfd = accept(sock_fd, (struct sockaddr *) &clientaddr, &clilen);
		printf("client connected\n");
	}

	close(sock_fd);

	return 0;
}
