#pragma once
#include "Customer.h"
#include "Phone.h"
#include "string"
#include "vector"
#include "Price.h"
#include "Recordable.h"
class Service : public Recordable
{
public:
	~Service();
	Service();
	Service(Customer customer, Phone phone, std::string description);
	std::string stringify();

	Price price;
private:
//	static std::string filename;
	Customer customer;
	Phone phone;
	std::string description;
	bool status;
};

