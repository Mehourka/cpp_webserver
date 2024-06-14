#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 4242

int main(void)
{
	int sock = 0;
	struct sockaddr_in serv_addr;
	std::string hello = "Hello from client";

	if ((sock = socket(AF_INET, SOCK_STREAM, 0) ) == 0)
	{
		perror("In socket CLient");
		exit(EXIT_FAILURE);
	}

	memset((void*)&serv_addr, 0, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	inet_pton(AF_INET, "127.0.0.1", (void*)&serv_addr.sin_addr); // Convert IPv4 address to binary

	if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		perror("COnnection failed\n");
		exit(EXIT_FAILURE);
	}

	long valread;
	char buffer[1024] = {0};

	send(sock, hello.data(), hello.length(), 0);
	std::cout << "Hello message sent!" << std::endl;
	valread = read(sock, buffer, 1024);
	close(sock);


	
	}
