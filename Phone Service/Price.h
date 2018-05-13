#pragma once
#include "string"
#include "map"
class Price
{
public:
	Price();
	friend Price operator+(Price price1, Price price2);
	friend Price operator-(Price price1, Price price2);
	Price(const float& value);	
	float toCur(const std::string& currency);		// Convert into specified currency
	static int setCur(const std::string& currency);	// Set standard currency
	std::string toStr();
	float getValue();
	void addDiscount(const float& discount);
	float getDiscount();
	static std::string getCurrency();
	void setValue(float value);
	~Price();
private:
	float value;
	float discount;
	static std::string currency;
	static std::map<std::string, float> rates;		// Active USD rates for supported currencies
};

