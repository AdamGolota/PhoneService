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


void Phone::load(std::vector<Recordable*>& arr)
{
	std::fstream fs;
	std::string record;
	fs.open(filename, std::fstream::in);
	if (fs.rdstate() & std::fstream::failbit)
	{
		return;
	}
	do {
		std::getline(fs, record, rDel);
		if (!record.empty())
		{
			Phone *p = new Phone;
			p->parse(record);
			arr.push_back(p);
		}
	} while (!fs.eof());

	fs.close();
}

Phone::~Phone()
{
}
