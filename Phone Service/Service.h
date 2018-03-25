#pragma once
#include "Customer.h"
#include "Phone.h"
#include "string"

class Service
{
public:
	~Service();
	Service();
	Service(Customer customer, Phone phone, std::string description);
	static int getServicesCount();
	std::string stringify();
	static Service parse(std::string info);

private:
	const int code;
	static int servicesCount;
	Customer customer;
	Phone phone;
	std::string description;
	bool status;

	int erase();
	int	log();
};

