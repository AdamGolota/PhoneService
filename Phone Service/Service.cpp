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

void Service::load(std::vector<Recordable*>& arr)
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
			Service *s = new Service;
			s->parse(record);
			arr.push_back(s);
		}
	} while (!fs.eof());
		
	fs.close();

}

void Service::setData()
{
	this->data["customer"] = this->customer.getFullName();
	this->data["phone"] = this->phone.getModel();
	this->data["description"] = this->description;
}

void Service::getData()
{
	this->customer.getFullName() = this->data["customer"];
	this->phone.getModel() = this->data["phone"];
	this->description = this->data["description"];
}




Service::~Service()
{
}
