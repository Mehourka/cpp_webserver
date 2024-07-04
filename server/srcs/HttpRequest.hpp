#include <iostream>

class HttpRequest
{
private:
	std::string _raw;
	std::string	_methode;
	std::string	_uri;
	std::string	_version;
	std::string	_headers;
	std::string	_body;

	bool _valid;

public:
	HttpRequest(std::string const &raw_str);

	std::string methode() const;
	std::string const &uri() const;
	std::string const &version() const;
	std::string const &headers() const;
	std::string const &body() const;

private:
	void parse_http_request(std::string const &raw_string);
};
