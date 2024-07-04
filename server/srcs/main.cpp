#include "Common.hpp"

// #include "TcpListener.hpp"
#include "MultiClientChat.hpp"
#include "HttpRequest.hpp"

void test_http_request()
{
	std::string str = "GET /index.php HTTP/1.1";
	
	HttpRequest req(str);

}

int main(void)
{

	test_http_request();

}
