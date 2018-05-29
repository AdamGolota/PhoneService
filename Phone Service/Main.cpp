#include "Service.h"
#include "conio.h"
#include "vector"
#include "iostream"
#include "Price.h"
#include "string"
int main()
{

	Customer customer("Mister", "Postman", "666");
	Customer customer2("Alina", "Sematska", "000");
	Recordable *p = &customer;
	std::string str = ((Customer*)p)->getFullName();

	Recordable *pArr[2] = { &customer, &customer2 };
	
	std::string str4 = customer.stringify();
	std::string str5 = customer.stringify();
	std::string str6 = customer.stringify();
	std::cout << str4;

	_getch();
	return 0;
}