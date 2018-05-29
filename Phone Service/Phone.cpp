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

void Phone::setData()
{
	this->data["model"] = this->model;
	this->data["manufacturer"] = this->manufacturer;
}

void Phone::getData()
{
	this->model = this->data["model"];
	this->manufacturer = this->data["manufacturer"];
}






Phone::~Phone()
{
}
