// Source: https://www.youtube.com/watch?v=Kc1kwm1WyVM
#pragma once

#include "Common.hpp"
#include <iostream>
// #include <WS2tcpip.h>
#include <string>
#include <sstream>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

class TcpListener
{
	public:

		TcpListener(const char *ipAddres, int port);

		// Initialize the listener
		int init();

		// Run the listener
		int run();
	protected:
	virtual void onClientConnected(int client);

	virtual void onClientDisconnected(int client);

	virtual void onMessageReceived(int clientSocket, const char* msg, int length);

	void sendToClient(int clientSocket, const char *msg, int length);

	void broadcastToClients(int sendingClient, const char* msg, int lenght);

	private:

		const char*		m_ipAddress;
		int				m_port;
		int				m_socket;
		struct pollfd	m_fds[200];		//Master file descriptor set
		int				m_nfds;
		
	
};
