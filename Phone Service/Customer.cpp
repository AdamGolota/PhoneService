#include "Customer.h"
#include "sstream"
#include "fstream"

//std::string filename = "customers.txt";
const std::string Customer::filename = "Customers.txt";
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

std::string Customer::getFileName()
{
	return filename;
}

void Customer::read(std::fstream & fs)
{
	std::string name, surname;
	fs >> name;
	fs >> surname;
	this->setFullName(name, surname);
	fs >> this->contactNumber;
}

int Customer::write(std::fstream & fs)
{
	fs << this->fullName << " ";
	fs << this->contactNumber << "\n";
	return 0;
}

Customer::~Customer()
{
}
