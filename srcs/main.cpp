#include "Common.hpp"
#include "Parser.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int ft_sum(int, int);

int main(void) {
  std::string text = "Hello, World! LAST_TOKEN\n\
Line two \n\
Line Three";
  std::stringstream ss(text);
  std::string line;
  
  /* while(std::getline(ss,  line)) */
  /* { */
  /*   std::cout << " - " << line <<std::endl; */
  /* } */

  std::getline(ss, line);
}

