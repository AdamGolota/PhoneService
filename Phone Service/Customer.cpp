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

void Customer::load(std::vector<Recordable*>& arr)
{
	std::fstream fs;
	std::string record;
	fs.open(filename, std::fstream::in);
	if (fs.rdstate() & std::fstream::failbit)
	{
		return;
	}
	do {
		std::getline(fs, record, rDel);
		if (!record.empty())
		{
			Customer *c = new Customer;
			c->parse(record);
			arr.push_back(c);
		}
	} while (!fs.eof());

	fs.close();
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
