#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#include<netpacket/packet.h>
#include<sys/socket.h>
#include<net/ethernet.h>
#include<netinet/in.h>

int main()
{
	int pack_socket, n;
	struct sockaddr_ll sa;

	socklen_t sl;
	char buf[2000];

	sl = sizeof(struct sockaddr_ll);

	// sock_raw keeps physical layer header, sock_dgram removes it.
	pack_socket = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
//	pack_socket = socket(PF_PACKET, SOCK_DGRAM, htons(ETH_P_ALL));
	if(pack_socket < 0)
	{
		printf("Failed to open packet socket\n");
		exit(0);
	}

	printf("Packet socket successful\n");

	while(1)
	{
		n = recvfrom(pack_socket, buf, 2000,0, (struct sockaddr *) &sa, &sl);
		printf("Received packed of length: %d\n",n);
	}

	close(pack_socket);

	return 0;
}
