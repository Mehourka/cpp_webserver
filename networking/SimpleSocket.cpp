#include "SimpleSocket.hpp"

SimpleSocket::SimpleSocket(int domain, int type, int protocol, int port, u_long interface){
	// Define address structure
	_address.sin_family = domain;
	_address.sin_port = htons(port);
	_address.sin_addr.s_addr = htonl(interface);

	// Establish Socket
	_sock = socket(domain, type, protocol);
	test_connection(_sock);

	// Establish Connection
	_connection = connect_to_network(_sock, _address);
	test_connection(_connection);
}

void SimpleSocket::test_connection(int fd)
{
	if (fd < 0)
	{
		perror("Failed to connect ...");
		exit(EXIT_FAILURE);
	}
}

struct sockaddr_in SimpleSocket::get_address(){
	return _address;
}

int SimpleSocket::get_sock(){
	return _sock;
}

int SimpleSocket::get_connection(){
	return _connection;
}