#include "Service.h"
#include "fstream"
#include "iostream"
#include "sstream"
const std::string Service::filename = "Services.txt";
//std::string Service::filename = "services.txt";

Service::Service (
	Customer customer, 
	Phone phone, 
	std::string description
) : customer(customer),
	Recordable()
{
	this->phone = phone;
	this->description = description;
}

Service::Service()
	: 
	customer(Customer()),
	phone(Phone())
{
}


std::string Service::getFileName()
{
	return filename;
}

void Service::read(std::fstream & fs)
{
	std::string name, surname, model;
	fs >> name;
	fs >> surname;
	this->customer.setFullName(name, surname);
	fs >> model;
	this->phone.setModel(model);
	fs.ignore(1);
	std::getline(fs, this->description);
}

int Service::write(std::fstream &fs)
{
	fs << this->customer.getFullName() << " ";
	fs << this->phone.getModel() << " ";
	fs << this->description << "\n";
	return 0;
}

Service::~Service()
{
}
