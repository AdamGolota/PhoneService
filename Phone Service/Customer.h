#pragma once
#include "string"
class Customer
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
	std::string fullName;
	std::string contactNumber;
	int serviceCount;
};

