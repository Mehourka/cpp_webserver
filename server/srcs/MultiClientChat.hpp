#pragma once

#include "Common.hpp"
#include "TcpListener.hpp"
#include <string>

#define WELCOM_MSG "Welcome to The WebServ:\n\n"

class MultiClientChat : public TcpListener
{

	public:
		MultiClientChat(const char* ipAddress, int port);

		virtual void onClientConnected(int client);

		virtual void onClientDisconnected(int client);

		virtual void onMessageReceived(int clientSocket, const char* msg, int length);
};
