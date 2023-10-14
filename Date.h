#include <iostream>
#include <string>
using namespace std;
class Date
{
	public:
		Date();
		Date(int y, int m, int d);
		Date operator + (const Date& rhs) const;
		Date operator - (const Date& rhs) const;
	//	bool operator == (const Date& rhs) const;
	//	bool operator < (const Date& rhs) const;
	//	bool operator > (const Date& rhs) const;
	//	Date& operator = (const Date& rhs) const;
		
		string to_string(void);
	private:
		int year;
		int month;
		int day;
};
