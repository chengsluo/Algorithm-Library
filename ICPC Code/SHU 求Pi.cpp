#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
	double s = 0, x = 1;
	long k = 1;
	int sign = 1;

	while (fabs(x) > 1e-8)
	{
		s += x;
		k += 2;
		sign *= -1;
		x = sign / double(k);
	}
	s *= 4;
	cout << "the pi is"<<setiosflags(ios::fixed) << setprecision(8)<< s << endl;

	return 0;
}