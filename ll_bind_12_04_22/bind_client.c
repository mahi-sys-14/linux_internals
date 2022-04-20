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

	struct sockaddr_in servaddr;

	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_fd < 0)
	{
		perror("sock: ");
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8000);
	inet_pton(AF_INET, serv_ip, &servaddr.sin_addr);

	retval = connect(sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if(retval < 0)
	{
		perror("connect: ");
		exit(2);
	}

	printf("client established connection with server\n");

//	while(1)
//	{
//		char buffer[200] = "Hello server!";
		int n;

		char s_buffer[200];
		char r_buffer[200];

		printf("\nEnter the data to send to the server: \n");
		gets(s_buffer);
	
		write(sock_fd , s_buffer, strlen(s_buffer));

		n = read(sock_fd, r_buffer, sizeof(r_buffer));
		r_buffer[n] = '\0';
		printf("\nData rec'd from server:\n %s\n", r_buffer);

//		printf("In while\n");
//	}

	close(sock_fd);

	return 0;
}
