#pragma once
#include "string"
#include "Recordable.h"
class Customer : public Recordable
{
public:
	Customer();
	~Customer();
	Customer(std::string name, std::string surname, std::string contactNumber);
	int setFullName(std::string name, std::string surname);
	int setContactNumber(std::string contactNumber);
	std::string getFullName();
	std::string getContactNumber();
	int getServiceCount();

private:
	void setData();
	void getData();
//	static std::string filename;
	std::string fullName;
	std::string contactNumber;
	int serviceCount;
};

