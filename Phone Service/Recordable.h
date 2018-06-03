#pragma once
#include "map"
#include "string"
#include "vector"

const char cDel = '#';		//code delimiter
const char kDel = ':';		//key delimiter
const char fDel = ';';		//field delimiter
const char rDel = '\n';		//record delimiter

class Recordable
{
public:
	Recordable();
	~Recordable();
	int log();
//	int erase(int code);
	
	virtual std::string getFileName() = 0;
	std::string stringify();
	static void logArr(std::vector<Recordable*>& arr);
//	static void load(std::vector<Recordable*>& arr) = 0;
//	void parse(std::string data);

	void parse(std::string);
protected:
	virtual void setData() = 0;
	virtual void getData() = 0;

	std::map<std::string, std::string> data;
	static int count;
private:
	//static std::string filename;
};

