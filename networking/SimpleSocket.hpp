#pragma once

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

class SimpleSocket
{
private:
	int					_sock;
	struct sockaddr_in	_address;
	int					_connection;

	void test_connection(int);
public:
	SimpleSocket(int domain, int service_type, int protocol, int port, u_long interface);
	virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;

	struct sockaddr_in get_address();
	int get_sock();
	int get_connection();
}; /* class SimpleSocket */
