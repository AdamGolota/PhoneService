#pragma once
#include "Customer.h"
#include "Phone.h"
#include "string"
#include "vector"
#include "Price.h"
class Service
{
public:
	~Service();
	Service();
	Service(const Service&);
	Service(Customer customer, Phone phone, std::string description, int code);
	static int getServicesCount();
	std::string stringify();
	static std::vector<Service> loadServices();
	static Service parse(std::string info);
	int erase();
	int	log();

	Price price;
private:
	const int code;
	static int servicesCount;
	Customer customer;
	Phone phone;
	std::string description;
	bool status;

};

