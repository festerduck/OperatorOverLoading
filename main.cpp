#include "Date.h"
using namespace std;

int main()
{
	Date lhs(0, 10, 30), rhs(0, 4, 31), sum;
	sum = lhs + rhs;
	cout <<	sum.to_string() << endl;
	return 0;
}

