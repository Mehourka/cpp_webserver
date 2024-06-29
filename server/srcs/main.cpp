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

int main(void)
{
	std::cout << "[SERVER] ";
	test_make();
}
