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
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //htonl(INADDR_ANY);	32 bit nw byte
	servaddr.sin_port = htons(8000); // 16 bit short 	TCP protocol HTTP---port

	retval = bind(sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if(retval < 0)
	{
		perror("bind: ");
		exit(2);
	}

	listen(sock_fd, 5);
	
	clilen = sizeof(clientaddr);
	connfd = accept(sock_fd, (struct sockaddr *) &clientaddr, &clilen);
	printf("client connected\n");

	while(1)
	{
		char s_buf[200];
		char r_buf[200];

		int n;
/*
		clilen = sizeof(clientaddr);
		connfd = accept(sock_fd, (struct sockaddr *) &clientaddr, &clilen);
		printf("client connected\n");
*/
		n = read(connfd, r_buf , 200);
		r_buf[n] = '\0';
		printf("\nData rec'd from client: \n%s\n", r_buf);

		printf("\nEnter data to send to client: \n");
		gets(s_buf);
//		write(connfd, "Good Bye", 8);
		write(connfd, s_buf, strlen(s_buf));

	}

	close(sock_fd);

	return 0;
}
