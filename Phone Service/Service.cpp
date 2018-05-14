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

std::string Service::stringify()
{
	this->data["customer"] = this->customer.getFullName();
	this->data["phone"] = this->phone.getModel();
	this->data["description"] = this->description;
	return this->Recordable::stringify();
}



Service::~Service()
{
}
