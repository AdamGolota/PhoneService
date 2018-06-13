#pragma once
#include "string"
#include "Recordable.h"
class Phone : public Recordable
{
public:
	Phone();
	Phone(std::string model, std::string manufacturer);
	std::string getModel();
	std::string getManufacturer();
	std::string getFileName();
	static const std::string filename;
	void read(std::fstream&);
	int write(std::fstream&);
	void setModel(std::string model);
	~Phone();
private:

	static int code;
	std::string model;
	std::string manufacturer;
};

