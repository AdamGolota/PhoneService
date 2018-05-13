#pragma once
#include "map"
#include "string"
#include "vector"
class Recordable
{
public:
	Recordable();
	~Recordable();
	int log();
	int erase(int code);
	std::string stringify();
	static std::vector<Recordable> load();
	static Recordable parse(std::string data);

protected:
	static std::string filename;
	std::map<std::string, std::string> data;
	static int count;
	int code;
};

