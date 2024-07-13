#pragma once
#include <iostream>
#include <fstream>

using std::string;

class FileHandler
{
private:
	int _fd;
	string _path;
	FileHandler();

public:
	FileHandler(string const &);

	void dump();
};
