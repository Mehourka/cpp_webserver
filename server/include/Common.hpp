#pragma once

// Common Libraries
#include <iostream>
#include <string>
#include <sstream>
#include <exception>

// ANSI Colors
#define GRAY "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define YELLOW "\033[33m"

// Set true for debug
#define _LOG true

// std::cout Macros
#define Log(x) \
	if (_LOG)  \
	std::cout << GRAY << (x) << WHITE << std::endl
#define LogInfo(x) std::cout << WHITE << (x) << WHITE << std::endl
#define LogInfoC(x, COLOR) std::cout << COLOR << (x) << WHITE << std::endl
#define LogErr(x) std::cerr << RED << (x) << WHITE << std::endl

#define UNUSED(x) (void)(x)


using std::string;

