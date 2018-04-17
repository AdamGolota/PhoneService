#include "Service.h"
#include "conio.h"
#include "vector"
#include "iostream"
#include "Price.h"
int main()
{

	Customer customer2("Alina", "Sematska", "0000000000");
	Customer customer;
	Price price(40);
	price.addDiscount(0.5);
	Price price2(80);
	float priceFloat = price2.toCur("UAH");
	Price price3 = price + price2;
	float priceInUsd = price.getValue();
	Price::setCur("UAH");
	float priceInUah = price.getValue();
	float price2InUah = price2.getValue();
	std::string cur = Price::getCurrency();
	Service service(customer, Phone(), "description", Service::getServicesCount());
	Service service2 = service;
	// GET FROM DATABASE
	customer2.setFullName("Alina", "Nesematska");
	customer2.setContactNumber("11111111111");
	customer.setContactNumber(customer2.getContactNumber());
	service.log();
	service.stringify();



	std::vector<Service> services;
	services = Service::loadServices();

	
	// SERVICE MANIPULATION

	services.push_back(Service());
	services.push_back(Service (
		Customer("Marco", "Rubio", "+380504824"),
		Phone("IPhone_7", "Apple"),
		"No mini jack!",
		Service::getServicesCount()
	));

	// DISPLAY SERVICES LIST

	for (Service s : services)
	{
		std::cout << s.stringify();
	}

	// LOG SERVICES

	//for (Service s : services)
	//{
	//	s.log();
	//}


	// ERASE SERVICES
	
	//for (Service s : services)
	//{
	//	s.erase();
	//}

	_getch();
	return 0;
}