#include "Service.h"
#include "conio.h"
#include "vector"
#include "iostream"
int main()
{
	// GET FROM DATABASE

	std::vector<Service> services;
	services = Service::loadServices();
	
	
	// SERVICE MANIPULATION

	//services.push_back(Service());
	//services.push_back(Service (
	//	Customer("Marco", "Rubio", "+380504824"),
	//	Phone("IPhone_7", "Apple"),
	//	"No mini jack!",
	//	Service::getServicesCount()
	//));

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
	
	for (Service s : services)
	{
		s.erase();
	}

	_getch();
	return 0;
}