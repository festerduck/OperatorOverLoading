#include "Date.h"
Date::Date(){}
Date::Date(int y, int m, int d)
{
	this->year = y;
	this->month = m;
	this->day = d;
}
Date Date::operator + (const Date& rhs) const
{
	Date sum;
	sum.year = this->year + rhs.year;
	sum.month = this->month + rhs.month;
	sum.day = this->day + rhs.day;
	while(sum.day >= 28)
	{
		if(sum.month % 2 == 0)
		{
			sum.day -= 31;
			sum.month++;
			continue;
		}
		if(sum.month % 2 != 0)
		{
			if(sum.month % 12 == 1)
                {
			sum.day -= 28;
			sum.month++;
			continue;
		}
			sum.day -= 30;
			sum.month++;
			continue;

	  }

	}	
	while(sum.month >= 12)
	{
		sum.month -= 12;
		sum.year++;
	}
	return sum;
}
string Date::to_string()
{
	string date = std::to_string(this->year) + " years " + std::to_string(this->month) + " months " + std::to_string(this->day) + " days ";
	return date;
}
