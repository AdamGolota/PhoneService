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
	~Phone();
private:
	void setData();
	void getData();
	static int code;
	std::string model;
	std::string manufacturer;
};

