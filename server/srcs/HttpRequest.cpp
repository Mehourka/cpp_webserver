#include "HttpRequest.hpp"

// ========== ========== Constructor ========== ========== 
HttpRequest::HttpRequest(std::string const &raw_string)
	: _raw(raw_string), _valid(false)
{
	parse_http_request(_raw);
}


// ========== ========== Validation ========== ========== 
void HttpRequest::parse_http_request(std::string const &raw_string)
{
	std::cout << "Parsing:\n" << raw_string;
}

// ========== ========== Getters ========== ========== 
std::string HttpRequest::methode() const
{
	if (_valid)
		return _methode;
	return "Invalid";
}

std::string const &HttpRequest::uri() const
{
	return _uri;
}

std::string const &HttpRequest::version() const
{
	return _version;
}

std::string const &HttpRequest::headers() const
{
	return _headers;
}

std::string const &HttpRequest::body() const
{
	return _body;
}
