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
	char s_buf[10000];

	int n;

	socklen_t clilen;
	struct sockaddr_in clientaddr, servaddr;

	sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_fd < 0)
	{
		perror("sock: ");
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //htonl(INADDR_ANY);
	servaddr.sin_port = htons(8000); // 16 bit short 	TCP protocol HTTP---port

	retval = bind(sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if(retval < 0)
	{
		perror("bind: ");
		exit(2);
	}

	printf("socket bound to port 8000\n");
	clilen = sizeof(clientaddr);

	while(1)
	{
		printf("before recvfrom\n");

		n = recvfrom(sock_fd, s_buf, 10000, 0, (struct sockaddr *) &clientaddr, &clilen);
		printf("rec’d %d bytes\n", n);
		s_buf[n] = '\0';
		printf("msg from client is: %s\n", s_buf);
	}

	close(sock_fd);

	return 0;
}
