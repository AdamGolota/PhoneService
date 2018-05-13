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
	std::string stringify();
	static Phone parse(std::string data);
	~Phone();
private:
	static int code;
	std::string model;
	std::string manufacturer;
};

