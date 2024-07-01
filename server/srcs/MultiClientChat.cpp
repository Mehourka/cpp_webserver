
#include "MultiClientChat.hpp"

MultiClientChat::MultiClientChat(const char* ipAddress, int port) :
	TcpListener(ipAddress, port)
{

}


void MultiClientChat::onClientConnected(int clientSocket)
{
	std::string welcomeMsg = WELCOM_MSG;
	sendToClient(clientSocket, welcomeMsg.c_str(), welcomeMsg.size() + 1);
	Log("[MCC] Client Connected");
}

void MultiClientChat::onClientDisconnected(int client)
{
	Log("[MCC] Client Disconnected");
	UNUSED(client);
}

void MultiClientChat::onMessageReceived(int clientSocket, const char* msg, int length)
{
	Log("[MCC] Message Received");
	broadcastToClients(clientSocket, msg, length);
}
