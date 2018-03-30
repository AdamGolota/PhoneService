#include "Phone.h"
#include "sstream"


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


Phone::~Phone()
{
}
