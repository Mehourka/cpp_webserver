#include "Common.hpp"

// #include "TcpListener.hpp"
// #include "MultiClientChat.hpp"
#include "HttpRequest.hpp"
// #include "FileHandler.hpp"

void test_http_request()
{
	std::string str = "GET /index.php HTTP/1.1";
	
	HttpRequest req(str);

}

#include <string>
void test_split_line()
{

	std::istringstream is("Hello World");
	std::string a, b;

	is >> a >> b;

	std::cout << "a: " << a << "\nb: " << b;
}

#include <map>


int main(void)
{

	std::string http_txt = 
		"GET /myTarget/ HTTP/1.1\n"
		"header1:one\n"
		"inivalid header :<cause of spaces\n"
		"header2:two\n"
		"not a header\n"
		" cant-have:leadingspace\n"
		"header3:three\n"
		"\n"
		"This is the b.o.d";

	// HttpRequest, reads as request, gets
	HttpRequest request(http_txt);

	



	// std::map<std::string, std::string> headers;
	// The header (map)
	request.print_headers();

	// the body (str)
}
