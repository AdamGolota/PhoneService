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

Price operator+(Price price1, Price price2)
{
	Price sum;
	sum.value = price1.toCur("USD") + price2.toCur("USD");
	return sum;
}

Price operator-(Price price1, Price price2)
{
	Price sum;
	sum.value = price1.toCur("USD") - price2.toCur("USD");
	return sum;
}


Price::Price(const float& value)
{
	this->setValue(value);
	this->discount = 0;
}

float Price::toCur(const std::string& currency)
{
	return this->value * Price::rates[currency];
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

std::string Price::getCurrency()
{
	return Price::currency;
}

void Price::setValue(float value)
{
	this->value = value / this->rates[Price::currency];
}


Price::~Price()
{
}
