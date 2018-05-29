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
//	void parse(std::string data);
	int getCode();
	void parse(std::string);
protected:
	virtual void setData() = 0;
	virtual void getData() = 0;
	std::map<std::string, std::string> data;
	static int count;
	int code;
private:
	//static std::string filename;
};

