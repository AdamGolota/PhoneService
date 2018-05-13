#include "Service.h"
#include "conio.h"
#include "vector"
#include "iostream"
#include "Price.h"
int main()
{
	Customer customer("Mister", "Postman", "666");
	std::cout << customer.stringify() << "\n";
	Phone phone("IPhone", "Apple");
	std::string str = phone.stringify();
	std::cout << str << "\n";
	Phone phone2 = Phone::parse(str);
	std::string str2 = phone2.stringify();
	std::cout << str2 << "\n";
	Phone phone3 = Phone::parse(str);
	std::string str3 = phone3.stringify();
	std::cout << str3 << "\n";
	Service service(customer, phone2, "Hello world");
	std::cout << service.stringify() << "\n";
	_getch();
	return 0;
}