#include "Recordable.h"
#include "sstream"
#include "fstream"

const char cDel = '#';		//code delimiter
const char kDel = ':';		//key delimiter
const char fDel = ';';		//field delimiter
const char rDel = '\n';		//record delimiter
int Recordable::count = 0;
std::string Recordable::filename = "records.txt";
Recordable::Recordable()
{
	this->code = 0;
}


Recordable::~Recordable()
{
	Recordable::count--;
}

int Recordable::log()
{
	std::fstream fs;
	fs.open(this->filename, std::fstream::out | std::fstream::app);
	if (fs.rdstate() & std::fstream::failbit)
	{
		return 1;
	}
	this->code = ++Recordable::count;
	fs << this->code << cDel;
	fs << this->stringify();
	fs.close();
	return 0;
}

int Recordable::erase(int code)
{
	std::string record;
	std::fstream fs;
	
	std::vector<Recordable> records = Recordable::load();
	remove(this->filename.c_str());

	for (int i = 0; i < records.size(); i++)
	{
		if (records[i].code != code)
		{
			if(records[i].log() == 1)
				return 1;
		}
	}
	Recordable::count--;
	return 0;
}

std::string Recordable::stringify()
{
	std::stringstream ss;
	for (auto pair : this->data)
	{
		ss << pair.first << kDel;
		ss << pair.second << fDel;
	}
	ss << rDel;
	return ss.str();
}

std::vector<Recordable> Recordable::load()
{
	int code;
	std::fstream fs;
	std::string record;
	fs.open(Recordable::filename, std::fstream::in);
	std::vector<Recordable> records;
	if (fs.rdstate() & std::fstream::failbit)
	{
		return records;
	}

	do {
		fs >> code;
		std::getline(fs, record, rDel);
		if (!record.empty())
		{
			records.push_back(Recordable::parse(record));
			records.back().code = code;
		}
	} while (!fs.eof());

	fs.close();
	return records;
}

Recordable Recordable::parse(std::string data)
{
	if (data.empty())
	{
		return Recordable();
	}
	std::string key;
	std::stringstream ss(data);
	Recordable object;
	
	while (!ss.eof())
	{
		std::getline(ss, key, kDel);
		std::getline(ss, object.data[key], fDel);
	}
	return object;
}
