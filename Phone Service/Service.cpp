#include "Service.h"
#include "fstream"
#include "iostream"
#include "sstream"

const std::string servicesFileName = "services.txt";

int Service::servicesCount = 0;

Service::Service() :
	code(++Service::servicesCount)
{
}

Service::Service(Customer customer, Phone phone, std::string description) : 
	code(++Service::servicesCount)
{
	this->customer = customer;
	this->phone = phone;
	this->description = description;
}

int Service::getServicesCount()
{
	return Service::servicesCount;
}

std::string Service::stringify()
{
	std::stringstream infoStr;
	infoStr << this->customer.getFullName() << " ";
	infoStr << this->customer.getContactNumber() << " ";
	infoStr << this->phone.getModel() + " ";
	infoStr << this->phone.getManufacturer() + " ";
	infoStr << this->description << " " << std::endl;
	return infoStr.str();
}

Service Service::parse(std::string info)
{
	std::stringstream infoStr;
	std::string name, surname, contactNumber, model, manufacturer, description;
	int number;
	infoStr >> number;
	infoStr >> name;
	infoStr >> surname;
	infoStr >> contactNumber;
	infoStr >> model;
	infoStr >> manufacturer;
	infoStr >> description;
	Service service
	(
		Customer(name, surname, contactNumber),
		Phone(model, manufacturer),
		description
	);
	return service;

}

int Service::erase()
{
	const std::string tempFileName = "temp.txt";
	std::string serviceStr;
	std::fstream services, temp;
	services.open(servicesFileName, std::fstream::in);
	temp.open(tempFileName, std::fstream::out);
	do 
	{
		std::getline(services, serviceStr);
		Service service = Service::parse(serviceStr);
		if (service.code != this->code)
			temp << serviceStr << std::endl;
	} while (!services.eof());
	
	services.close();
	temp.close();

	services.open(servicesFileName, std::fstream::out | std::fstream::trunc);
	temp.open(tempFileName, std::fstream::in);
	do
	{
		std::getline(temp, serviceStr);
		services << serviceStr;
	} while (!temp.eof());
	services.close();
	temp.close();
	remove(tempFileName.c_str());
	return 0;
}

int Service::log()
{
	std::fstream services;
	services.open(servicesFileName, std::fstream::out | std::fstream::app);
	services << this->stringify();
	services.close();
	return 0;
}


Service::~Service()
{
	Service::servicesCount--;
}
