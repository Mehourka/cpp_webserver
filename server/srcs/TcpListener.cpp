#include "TcpListener.hpp"

TcpListener::TcpListener(const char *ipAddres, int port) :
	m_ipAddress(ipAddres), m_port(port) { }

int TcpListener::init()
{
	// Create Socket
	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_socket <= 0)
	{
		perror("In Socket");
		exit(EXIT_FAILURE);
	}

	// Bind ip addres s an port to a socket
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(m_port);
	inet_pton(AF_INET, m_ipAddress, &address.sin_addr);
	
	// Bind socket
	if (bind(m_socket, (sockaddr*)&address, sizeof(address)) < 0)
	{
		perror("In Bind");
		exit(EXIT_FAILURE);
	}

	// Listen for socket
	if (listen(m_socket, 10) < 0)
	{
		perror("In Listen");
		exit(EXIT_FAILURE);
	}

	FD_ZERO(&m_master);

	FD_SET(m_socket, &m_master);
	return 0;
}

int TcpListener::run()
{
	// bool running = true;

	// while (running)
	// {
	// 	fd_set copy = m_master;

	// 	int socketCount = select(0, &copy, nullptr, nullptr, nullptr);

	// 	for (int i = 0; i < socketCount; i++)
	// 	{
	// 		SOCKET sock = copy.fd_array[i];∫ 
	// 	}
	// }
	return 0;
}
