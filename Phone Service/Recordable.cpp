#include "Recordable.h"
#include "sstream"
#include "fstream"


int Recordable::count = 0;
//std::string Recordable::filename = "records.txt";
Recordable::Recordable()
{
}



Recordable::~Recordable()
{
	Recordable::count--;
}

int Recordable::log()
{
	std::fstream fs;
	fs.open(this->getFileName(), std::fstream::out | std::fstream::app);
	if (fs.rdstate() & std::fstream::failbit)
	{
		return 1;
	}
	fs << this->stringify();
	fs << rDel;
	fs.close();
	return 0;
}



std::string Recordable::stringify()
{
	std::stringstream ss;
	this->setData();
	for (auto pair : this->data)
	{
		ss << pair.first << kDel;
		ss << pair.second << fDel;
	}
	return ss.str();
}
void Recordable::logArr(std::vector<Recordable*>& arr)
{
	for (auto p : arr)
	{
		p->log();
	}
}
//void Recordable::load(std::vector<Recordable*>& arr, size_t size, std::string filename)
//{
//	std::fstream fs;
//	std::string record;
//	fs.open(filename, std::fstream::in);
//	if (fs.rdstate() & std::fstream::failbit)
//	{
//		return;
//	}
//	
//	do {
//		std::getline(fs, record, rDel);
//		if (!record.empty())
//		{
//			Recordable * r = (Recordable*)malloc(size);
//			r->parse(record);
//			arr.push_back(r);
//		}
//	} while (!fs.eof());
//	
//	fs.close();
//}

//std::vector<Recordable> Recordable::load()
//{
//	int code;
//	std::fstream fs;
//	std::string record;
//	fs.open(Recordable::filename, std::fstream::in);
//	std::vector<Recordable> records;
//	if (fs.rdstate() & std::fstream::failbit)
//	{
//		return records;
//	}
//
//	do {
//		fs >> code;
//		std::getline(fs, record, rDel);
//		if (!record.empty())
//		{
//			records.push_back(Recordable::parse(record));
//			records.back().code = code;
//		}
//	} while (!fs.eof());
//
//	fs.close();
//	return records;
//}


void Recordable::parse(std::string data)
{

	if (data.empty())
	{
		return;
	}
	std::string key;
	std::stringstream ss(data);


	while (ss.peek() != EOF)
	{
		std::getline(ss, key, kDel);
		std::getline(ss, this->data[key], fDel);
	}
	this->getData();
}


