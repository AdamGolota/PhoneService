#include "Phone.h"
#include "sstream"
#include "fstream"
//std::string filename = "phones.txt";
const std::string Phone::filename = "Phones.txt";
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

std::string Phone::getFileName()
{
	return filename;
}

void Phone::read(std::fstream &fs)
{
	fs >> this->model;
	fs >> this->manufacturer;
}

int Phone::write(std::fstream & fs)
{
	fs << this->model << " ";
	fs << this->manufacturer << "\n";
	return 0;
}

void Phone::setModel(std::string model)
{
	this->model = model;
}

Phone::~Phone()
{
}
