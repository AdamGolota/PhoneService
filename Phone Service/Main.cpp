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
	Phone phone("A", "B");
	Service service(customer, phone, "Doesn't work!");

	std::vector<Recordable*> records;
	Customer::load(records);
	Phone::load(records);
	Service::load(records);
	records.push_back(&service);

	remove(Customer::filename.c_str());
	remove(Phone::filename.c_str());
	remove(Service::filename.c_str());

	Recordable::logArr(records);

	_getch();
	return 0;
}