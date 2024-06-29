#include "Parser.hpp"  
#include <vector>
#include "Common.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

Parser::Parser(const Parser & other)
{
  *this = other;
}

Parser::Parser(const std::string &str)
  : _str(str)
{
}

Parser & Parser::operator = (const Parser &other)
{
  this->_str = other._str;
  this->_tokens = other._tokens;
  return *this;
}

void Parser::set_str(const std::string &str)
{
  _str = str;
}

std::string Parser::get_str()
{
  return this->_str;
}

void Parser::print_tokens()
{
  for ( std::vector<std::string>::iterator it = _tokens.begin(); it != _tokens.end(); ++it)
       std::cout << " - " << *it << std::endl;
}

void Parser::tokenize()
{
  _tokens.push_back(std::string("NEW TOKEN"));
}


