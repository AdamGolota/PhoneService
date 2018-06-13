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
	Service();
	~Service();
	Service(Customer customer, Phone phone, std::string description);
	std::string getFileName();
	static const std::string filename;
	Price price;
	void read(std::fstream&);
	int write(std::fstream&);
private:
	Customer customer;
	void setData();
	void getData();
	Phone phone;
	std::string description;
	bool status;
};

