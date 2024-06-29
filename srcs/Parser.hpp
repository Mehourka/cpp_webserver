#pragma once

#include <vector>
#include <iostream>
#include <string>

enum Token_Kind
{
  TOKEN_END = 0,
  HEADER,
  BODY,
  TOKEN_POUND,
  TOKEN_SYMBOL
};

struct Token {
  Token_Kind kind;
  std::string text;
};

class Parser
{
private:
  std::string _str;
  std::vector<std::string> _tokens;


public:
  Parser();
  ~Parser();
  Parser(const Parser &);
  Parser & operator = (const Parser &);
  Parser(const std::string &);

  void set_str(const std::string &);
  std::string get_str();

  void tokenize();
  void print_tokens();
};
