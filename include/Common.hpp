#pragma once
#include <iostream>
#include <sstream>

#define Log(x) std::cout << "x" << std::endl;

#define SSTR( x ) static_cast< std::ostringstream & > ( \
        ( std::ostringstream() << std::dec << x ) ).str()
