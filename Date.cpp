#include "Date.h"
Date::Date(){
	year = 0;
	month = 0;
	day = 0;

}
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
Date Date::operator - (const Date& rhs) const
{
	Date result;
	result.year = this->year - rhs.year;	
	result.month = this->month - rhs.month;
	result.day = this->day - rhs.day;
	
	while(result.day <= 0)
	{
		result.month--;
		if(result.month % 2 == 0)
		{
			if(result.month == 2)
			{
				result.day += 28;
			}
			result.day += 30;
		}
		if(result.month % 2 != 0)
		{
			result.day += 31;
		}
	}
	while(result.month <= 0)
	{
		result.month += 12;
		result.year--;
	}
	return result;
}


string Date::to_string()
{

	string date = std::to_string(this->year) + "-" + std::to_string(this->month) + "-" + std::to_string(this->day);
	return date;
}
