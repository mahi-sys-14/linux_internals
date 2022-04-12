#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>

#define PORT 8000
#define SERVER_IP "127.0.0.1"
#define MAXSIZ 100

int main()
{
	int sock_fd, retval, n;
	char msg1[MAXSIZ];
	char msg2[MAXSIZ];

	struct sockaddr_in servaddr;

	// create socket
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_fd < 0)
	{
		perror("sock: ");
		exit(1);
	}

	// Initialize the socket address
	memset(&servaddr, 0, sizeof(servaddr));
//	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
	servaddr.sin_port = htons(PORT);

//	inet_pton(AF_INET, serv_ip, &servaddr.sin_addr);

	retval = connect(sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if(retval < 0)
	{
		perror("connect: ");
		exit(2);
	}

	printf("client established connection with server\n");


	// send data to the server socket, need to connect to server socket.
	while(1)
	{
		printf("\nEnter message to send to server: \n");
		fgets(msg1, MAXSIZ, stdin);
		if(msg1[0] == '#')
			break;

		n = strlen(msg1) + 1;

		send(sock_fd, msg1, strlen(msg1), 0);

		n = recv(sock_fd, msg2, MAXSIZ, 0);
		printf("Received message from server: %s of %d bytes\n", msg2, n);
	}
//	close(sock_fd);

	return 0;
}
