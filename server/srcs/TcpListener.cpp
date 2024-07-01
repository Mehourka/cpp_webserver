#include "TcpListener.hpp"

TcpListener::TcpListener(const char *ipAddres, int port) :
	m_ipAddress(ipAddres), m_port(port) { }

int TcpListener::init()
{
	// Create Socket
	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_socket <= 0)
	{
		perror("socket() Failed");
		exit(EXIT_FAILURE);
	}

	// Allow socket to be reusable
	setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, NULL, 0);

	// Set to non blocking
	fcntl(m_socket, F_SETFL, O_NONBLOCK);


	// Bind ip addres s an port to a socket
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	inet_pton(AF_INET, m_ipAddress, &address.sin_addr);
	address.sin_port = htons(m_port);
	
	// Bind socket
	if (bind(m_socket, (sockaddr*)&address, sizeof(address)) < 0)
	{
		perror("In Bind");
		close(m_socket);
		exit(EXIT_FAILURE);
	}

	// Listen for socket
	if (listen(m_socket, 32) < 0)
	{
		perror("In Listen");
		exit(EXIT_FAILURE);
	}

	// Zero out poll structures
	memset(m_fds, 0, sizeof(m_fds));
	m_fds[0].fd = m_socket;
	m_fds[0].events = POLLIN;
	m_timeout = (3 * 60 * 1000);
	
	LogInfo("[TcpListener] Initialized ...");
	return 0;
}

int TcpListener::run()
{
	bool running = true;
	int timeout = (3 * 60 * 1000);
	int rc;

	while (running)
	{
		Log('Waiting on poll() ...');

		rc = poll(m_fds, m_nfds, timeout);

		if (rc == 0)
		{
			LogInfo("Poll() timed out");
			break;
			// << GOT HERERERERE
			//https://www.ibm.com/docs/en/i/7.4?topic=designs-using-poll-instead-select
		}

		// Get number of available sockets
		select(FD_SETSIZE, &ready_sockets, nullptr, nullptr, nullptr);
		for (int i = 0; i < FD_SETSIZE; i++)
		{
			if(!FD_ISSET(i, &ready_sockets))
			{
				continue;
			}
			std::cout << "Got to socket: " << i << std::endl;
			int sock = i;
			// Is it an inbout connection
			if (sock == m_socket)
			{
				// Accept new connection
				LogInfo("[TcpListener] Inbound Connection");
				int client = accept(m_socket, nullptr, nullptr);

				// Add the new connection to the list of connected clients
				FD_SET(client, &m_master);
				onClientConnected(client);
			}
			else {
				Log("Here");
				char buf[4096];
				bzero(buf, 4096 * sizeof(char));

				// Receive message
				int bytesIn = recv(sock, buf, 4096, 0);
				if (bytesIn <= 0)
				{
					onClientDisconnected(sock);
					close(sock);
					FD_CLR(sock, &m_master);
				}
				else
				{
					LogInfo("[TcpListener] Received Message");
					onMessageReceived(sock, buf, bytesIn);
				}
			}
		}
	}

	FD_CLR(m_socket, &m_master);
	// closesocket(m_socket);
	close(m_socket);

	
	return 0;
}

void TcpListener::onClientConnected(int client)
{
	UNUSED(client);
	std::cout << "Client Connection" << std::endl;
}

void TcpListener::onClientDisconnected(int client)
{
	UNUSED(client);
	std::cout << "Client Disonnection" << std::endl;
	exit(1);
}

void TcpListener::sendToClient(int clientSocket, const char *msg, int length)
{
	std::cout << "Sending to client" << clientSocket << std::endl;
	send(clientSocket, msg, length, 0);
}

void TcpListener::broadcastToClients(int sendingClient, const char *msg, int length)
{
	fd_set ready_sockets = m_master;
	for (int i = 0; i < FD_SETSIZE; i++)
	{
		Log("Here");
		if(!FD_ISSET(i, &ready_sockets))
			continue;
		if (m_master.fds_bits[i] != sendingClient && m_master.fds_bits[i] != m_socket)
		{
			sendToClient(m_master.fds_bits[i], msg, length);
		}
	}
}


void TcpListener::onMessageReceived(int clientSocket, const char* msg, int length)
{
	UNUSED(clientSocket);
	UNUSED(msg);
	UNUSED(length);

	broadcastToClients(m_socket, msg, length);
}
