#include "HttpRequest.hpp"

// ========== ========== Constructor ========== ========== 
HttpRequest::HttpRequest(std::string const &raw_string)
	: _raw(raw_string), _valid(true), _http_stream(_raw)
{
	_parse_http_request();
}


// ========== ========== Validation ========== ========== 
void HttpRequest::_parse_http_request()
{
	_parse_request_line();
	_parse_headers();
}

// ========== ========== Getters ========== ========== 
std::string HttpRequest::method() const
{
	if (_valid)
		return _method;
	return "Invalid";
}

std::string const &HttpRequest::target() const
{
	return _target;
}

std::string const &HttpRequest::version() const
{
	return _version;
}

std::map<std::string, std::string> const &HttpRequest::headers() const
{
	return _headers;
}

std::string const &HttpRequest::body() const
{
	return _body;
}

void HttpRequest::_parse_request_line()
{
	std::string start_line;
	std::getline(_http_stream, start_line);

	try {
		std::istringstream iss(start_line);

		_validate_request_line(start_line);
		iss >> _method >> _target >> _version;
		
		// DEBUG
		// print_request();
	}
	catch (std::exception const &e)
	{
		_valid = false;
		std::cerr << "[Parsing Error] Invalid Request line : " << e.what() << std::endl;
		std::cerr << start_line;
	}
}

void HttpRequest::_validate_request_line(std::string const &request_line) const {

	std::regex re_request_line(
		"^(GET|POST|DELETE)"
		" \\/[^\\s]* "
		"HTTP\\/1.[1,3]$");

	if (!std::regex_match(request_line, re_request_line))
	{
		throw std::exception();
	}
}


void HttpRequest::_parse_headers()
{
	std::string header_line;

	std::getline(_http_stream, header_line);
	while (!header_line.empty() && header_line != "\n")
	{
		// Skip invalid headers
		if (!_valid_header(header_line))
		{
			std::getline(_http_stream, header_line);
			continue;
		}

		// Add header to map
		int const pos = header_line.find(":");
		std::string key = header_line.substr(0, pos);
		std::string value = header_line.substr(pos + 1, header_line.size());
		value = trim(value);

		_headers[key] = value;

		std::getline(_http_stream, header_line);
	}
	// _http_stream now should be stopped after \n
}


bool HttpRequest::_valid_header(std::string const &line) const
{
	std::regex const re("^\\w+:[ ]?\\w+[ ]?$");

	return std::regex_match(line, re);
}

void HttpRequest::print_request() const
{
	std::cout << "method: " << _method << std::endl;
	std::cout << "Target: " << _target << std::endl;
	std::cout << "Version: " << _version << std::endl;
}

void HttpRequest::print_headers() const
{
	std::map<std::string, std::string>::const_iterator cit;

	for(cit = _headers.begin(); cit != _headers.end(); ++cit)
		std::cout << cit->first << ": " << cit->second << std::endl;
}
