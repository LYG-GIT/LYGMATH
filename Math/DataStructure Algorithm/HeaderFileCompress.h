#pragma once

#include <iostream>
#include <fstream>
#include <string>
class HeaderFileCompress
{
public:
	HeaderFileCompress();
	HeaderFileCompress(const std::string& filePath);
	~HeaderFileCompress();

	int open(const std::string& filePath);
	void print();
	void compress();

private:
	std::ofstream fout;
	std::fstream fin;
};

