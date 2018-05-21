#pragma once
#include "string"
#include "Recordable.h"
class Customer : public Recordable
{
public:
	Customer();
	~Customer();
	Customer(Recordable);
	Customer(std::string name, std::string surname, std::string contactNumber);
	int setFullName(std::string name, std::string surname);
	int setContactNumber(std::string contactNumber);
	std::string getFullName();
	std::string getContactNumber();
	int getServiceCount();
	std::string stringify();

private:
//	static std::string filename;
	std::string fullName;
	std::string contactNumber;
	int serviceCount;
};

