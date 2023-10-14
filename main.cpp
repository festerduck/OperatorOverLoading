#include "Date.h"
using namespace std;

int main()
{
	cout << "Enter the Date in Format (YY MM DD): " << endl;
	int y, m, d;
	cin >> y >> m >> d;
	Date date_1(y, m, d);
	cout << "Enter the Date in Format (YY MM DD): " << endl;
	cin >> y >> m >> d;
	Date date_2(y, m, d);
	Date sum;
	sum = date_1 - date_2;
	cout << "Result = " << sum.to_string() << endl;
	return 0;
}

