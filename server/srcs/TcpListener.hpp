// Source: https://www.youtube.com/watch?v=Kc1kwm1WyVM
#pragma once

#include <iostream>
// #include <WS2tcpip.h>
#include <string>
#include <sstream>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

class TcpListener
{
	public:

		TcpListener(const char *ipAddres, int port);

		// Initialize the listener
		int init();

		// Run the listener
		int run();
	protected:

	private:

		const char*	m_ipAddress;
		int			m_port;
		int			m_socket;
		fd_set		m_master;		//Master file descriptor set
};
