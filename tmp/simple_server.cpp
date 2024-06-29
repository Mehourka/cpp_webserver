#include "Common.hpp"
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#include "TcpListener.hpp"

using namespace std;

#define PORT 1234

void test_make(void);

int main(void)
{
	std::cout << "[SERVER] ";
	test_make();
}

int main2(void) 
{
	// int server_fd = socket(domain, type, protocole);
	int			server_fd = socket(AF_INET, SOCK_STREAM, 0);
	int			new_socket;
	int long	valread;
	struct sockaddr_in address;
	int			addrlen = sizeof(address);

	string body = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
	// body = "SERVER RESPONSE";

	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("In socket");
		exit(EXIT_FAILURE);
	}

	memset((char *)&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(PORT);

	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("Bind failed");
		close(server_fd);
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0)
	{
		perror("In listen");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }
        
        char buffer[30000] = {0};
        valread = read( new_socket , buffer, 30000);
        printf("%s\n",buffer );
        write(new_socket , body.data() , body.length());
        printf("------------------body message sent-------------------\n");
        close(new_socket);
	}
	return 0;
}

