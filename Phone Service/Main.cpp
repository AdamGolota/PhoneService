#include "Service.h"
#include "conio.h"
#include "vector"
#include "iostream"
#include "Price.h"
#include "string"
#include "fstream"
#include "RecordablePointerList.h"
int main()
{
	Customer customer("Mister", "Postman", "666");
	Customer customer2("Alina", "Sematska", "000");
	Phone phone("A", "B");
	Service service(customer, phone, "Doesn't work!");
	RecordablePointerList list;
	//list.push(&customer);
	//list.push(&customer2);
	//list.push(&phone);
	//list.push(&service);
	std::fstream fs;
	fs.open(Customer::filename, std::fstream::in);
	while (!fs.eof())
	{
		Customer *c = new Customer;
		c->loadToList(fs, list);
	}
	fs.close();
	fs.open(Phone::filename, std::fstream::in);
	while (!fs.eof())
	{
		Phone *p = new Phone;
		p->loadToList(fs, list);
	}
	fs.close();
	fs.open(Service::filename, std::fstream::in);
	while (!fs.eof())
	{
		Service *s = new Service;
		s->loadToList(fs, list);
	}
	fs.close();

	remove(Customer::filename.c_str());
	remove(Phone::filename.c_str());
	remove(Service::filename.c_str());

	Recordable *p;
	while (p = list.pop()) 
	{
		p->log();
	}

	_getch();
	return 0;
}