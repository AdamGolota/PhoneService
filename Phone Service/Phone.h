#pragma once
#include "string"
class Phone
{
public:
	Phone();
	Phone(std::string model, std::string manufacturer);
	std::string getModel();
	std::string getManufacturer();
	~Phone();
private:
	std::string model;
	std::string manufacturer;
};

