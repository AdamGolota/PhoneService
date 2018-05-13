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
	std::map<std::string, std::string> getData();
	int getCode();

protected:
	std::map<std::string, std::string> data;
	static int count;
	int code;
private:
	//static std::string filename;
};

