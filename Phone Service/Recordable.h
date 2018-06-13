#pragma once
#include "map"
#include "string"
#include "vector"
#include "fstream"
const char cDel = '#';		//code delimiter
const char kDel = ':';		//key delimiter
const char fDel = ';';		//field delimiter
const char rDel = '\n';		//record delimiter

class RecordablePointerList;

class Recordable
{
public:
	Recordable();
	~Recordable();
	int log();
	virtual std::string getFileName() = 0;
	virtual void read(std::fstream&) = 0;
	virtual int write(std::fstream&) = 0;
	int load(std::fstream &fs);
	void loadToList(std::fstream& fs, RecordablePointerList& list);

protected:
	static int count;
private:
	//static std::string filename;
};

