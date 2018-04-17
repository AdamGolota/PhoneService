#include "Service.h"
#include "fstream"
#include "iostream"
#include "sstream"

const std::string servicesFileName = "services.txt";

int Service::servicesCount = 0;

Service::Service() : code(Service::servicesCount++)
{
	this->customer = Customer();
	this->phone = Phone();
	this->description = "No description";
}

Service::Service(const Service & s)
	:
	code(s.code),
	customer(s.customer),
	phone(s.phone),
	description(s.description)
{
	Service::servicesCount++;
}

Service::Service (
	Customer customer, 
	Phone phone, 
	std::string description, 
	int code = Service::servicesCount
) : 
	code(code)
{
	this->customer = customer;
	this->phone = phone;
	this->description = description;
	Service::servicesCount++;
}

int Service::getServicesCount()
{
	return Service::servicesCount;
}

std::string Service::stringify()
{
	std::stringstream infoStr;
	char code[5];
	sprintf_s(code, "%03i", this->code);

	infoStr << code << " ";
	infoStr << this->customer.getFullName() << " ";
	infoStr << this->customer.getContactNumber() << " ";
	infoStr << this->phone.getModel() + " ";
	infoStr << this->phone.getManufacturer() + " ";
	infoStr << this->description << " " << std::endl;
	return infoStr.str();
}

std::vector<Service> Service::loadServices()
{
	std::fstream services;
	std::string serviceLine;
	services.open(servicesFileName, std::fstream::in);
	std::vector<Service> servicesVector;
	if (services.rdstate() & std::fstream::failbit)
	{
		return servicesVector;
	}
	do {
		std::getline(services, serviceLine);
		if (!serviceLine.empty()) 
		{
			servicesVector.push_back(Service::parse(serviceLine));
		}
	} while (!services.eof());
	services.close();
	return servicesVector;
}

Service Service::parse(std::string info)
{
	if (info.empty())
	{
		return Service();
	}

	std::stringstream infoStr(info);
	std::string name, surname, contactNumber, model, manufacturer, description;
	int code;
	infoStr >> code;
	infoStr >> name;
	infoStr >> surname;
	infoStr >> contactNumber;
	infoStr >> model;
	infoStr >> manufacturer;
	getline(infoStr, description);
	Service service (
		Customer(name, surname, contactNumber),
		Phone(model, manufacturer),
		description,
		code
	);
	return service;
}

int Service::erase()
{
	const std::string tempFileName = "temp.txt";
	std::string serviceStr;
	std::fstream services, temp;
	services.open(servicesFileName, std::fstream::in);
	if (services.rdstate() & std::fstream::failbit)
	{
		return 1;
	}
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
	if (!(services.rdstate() & std::fstream::goodbit))
	{
		return 1;
	}
	temp.open(tempFileName, std::fstream::in);
	if (!(temp.rdstate() & std::fstream::goodbit))
	{
		return 1;
	}
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
	if (services.rdstate() & std::fstream::failbit)
	{
		return 1;
	}
	services << this->stringify();
	services.close();
	return 0;
}


Service::~Service()
{
	Service::servicesCount--;
}
