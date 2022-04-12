#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>

int main()
{
	char *serv_ip = "127.0.0.1";
	int sock_fd, retval;
	char *msg = "abcdefghijklmn";

	struct sockaddr_in servaddr;
	socklen_t addr_len;

	sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_fd < 0)
	{
		perror("sock: ");
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8000);
	inet_pton(AF_INET, serv_ip, &servaddr.sin_addr);

	printf("client established connection with server\n");

	addr_len = sizeof(struct sockaddr_in);

	// send data to the server socket, need to connect to server socket.
	retval = sendto(sock_fd, msg, strlen(msg), 0, (struct sockaddr *) &servaddr, addr_len);
	printf("ret val of sendto: %d\n", retval);

//	getchar();	// for checking mulitiple servers running

	close(sock_fd);

	return 0;
}
