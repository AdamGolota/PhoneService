#pragma once
#include "string"
#include "map"
class Price
{
public:
	Price();
	Price(const float& value);
	Price toCur(const std::string& currency);			// Convert into specified currency
	static int setCur(const std::string& currency);	// Set standard currency
	std::string toStr();
	float getValue();
	void addDiscount(const float& discount);
	float getDiscount();
	~Price();
private:
	float value;
	float discount;
	static std::string currency;
	static std::map<std::string, float> rates;		// Active USD rates for supported currencies
};

