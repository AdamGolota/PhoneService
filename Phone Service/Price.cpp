#include "Price.h"

std::map<std::string, float> Price::rates = {
	{"USD", 1.f},
	{"UAH", 26.3},
	{"RUB", 57.99},
	{"EUR", 0.81}
};

std::string Price::currency = "USD";

Price::Price()
{
	this->value = 0;
	this->discount = 0;
}

Price::Price(const float& USD)
{
	this->value = USD;
	this->discount = 0;
}

Price Price::toCur(const std::string& currency)
{
	return Price();
}

int Price::setCur(const std::string& currency)
{
	std::map<std::string, float>::iterator it = rates.find(currency);
	if (it == rates.end())
		return 1;
	Price::currency = it->first;
	return 0;
}

std::string Price::toStr()
{
	std::string str = std::to_string(this->getValue()) + " " + Price::currency;
	return str;
}

float Price::getValue()
{
	float value = this->value * Price::rates[Price::currency];
	value -= value * this->discount;
	return value;
}

void Price::addDiscount(const float& discount)
{
	this->discount += discount;
}

float Price::getDiscount()
{
	if (this->discount < 0.f)
		return 0.f;
	if (this->discount > 1.f)
		return 1.f;
	return this->discount;
}


Price::~Price()
{
}
