#include "Customer.h"
#include "sstream"

//std::string filename = "customers.txt";

Customer::Customer()
{
	this->fullName = "No Name";
	this->contactNumber = "No_Number";
}

Customer::Customer(std::string name, std::string surname, std::string contactNumber) : Recordable()
{
	this->setFullName(name, surname);
	this->setContactNumber(contactNumber);
}

int Customer::setFullName(std::string name, std::string surname)
{
	name[0] = toupper(name[0]);
	surname[0] = toupper(surname[0]);
	this->fullName = name + " " + surname;
	return 0;
}

int Customer::setContactNumber(std::string contactNumber)
{
	this->contactNumber = contactNumber;
	return 0;
}

std::string Customer::getFullName()
{
	return this->fullName;
}

std::string Customer::getContactNumber()
{
	return this->contactNumber;
}

int Customer::getServiceCount()
{
	return this->serviceCount;
}

void Customer::setData()
{
	this->data["fullName"] = this->fullName;
	this->data["contactNumber"] = this->contactNumber;
}

void Customer::getData()
{
	this->fullName = this->data["fullName"];
	this->contactNumber = this->data["contactNumber"];
}

Customer::~Customer()
{
}
