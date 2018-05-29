#include "Service.h"
#include "fstream"
#include "iostream"
#include "sstream"

//std::string Service::filename = "services.txt";

Service::Service (
	Customer &customer, 
	Phone phone, 
	std::string description
) : customer(customer),
	Recordable()
{
	this->phone = phone;
	this->description = description;
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
