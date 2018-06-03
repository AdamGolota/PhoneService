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
	static void load(std::vector<Recordable*>& arr);
	~Phone();
private:
	void setData();
	void getData();
	static int code;
	std::string model;
	std::string manufacturer;
};

