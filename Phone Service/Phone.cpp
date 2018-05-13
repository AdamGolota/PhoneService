#include "Phone.h"
#include "sstream"

//std::string filename = "phones.txt";

Phone::Phone()
{
	this->model = "No_model";
	this->manufacturer = "No_manufacturer";
}

Phone::Phone(std::string model, std::string manufacturer)
{
	this->model = model;
	this->manufacturer = manufacturer;
}


std::string Phone::getModel()
{
	return this->model;
}

std::string Phone::getManufacturer()
{
	return this->manufacturer;
}

std::string Phone::stringify()
{
	this->data["model"] = this->model;
	this->data["manufacturer"] = this->manufacturer;
	return this->Recordable::stringify();
}


Phone Phone::parse(std::string data)
{
	Phone phone;
	phone.data = Recordable::parse(data).getData();
	phone.model = phone.data["model"];
	phone.manufacturer = phone.data["manufacturer"];
	return phone;
}



Phone::~Phone()
{
}
