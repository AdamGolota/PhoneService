#include "Recordable.h"
#include "sstream"
#include "fstream"
#include "RecordablePointerList.h"


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
		return 0;
	}
	this->write(fs);
	if (fs.rdstate() & std::fstream::failbit)
	{
		return 0;
	}
	fs.close();
	return 1;
}

int Recordable::load(std::fstream& fs)
{
	if (fs.rdstate() & std::fstream::failbit)
	{
		return 0;
	}
	this->read(fs);
	if (fs.rdstate() & std::fstream::failbit)
	{
		return 0;
	}
	return 1;
}

void Recordable::loadToList(std::fstream& fs, RecordablePointerList& list)
{
	if (this->load(fs))
		list.push(this);
	else
		delete this;
}
