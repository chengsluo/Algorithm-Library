//牛顿法求解的是f(x)=0的解x0.
//f'(x1)=f(x1)/(x1-x2)-->x2=x1-f(x1)/f'(x1);

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double f(double x)
{
	return cos(x) - x;
}
double ff(double x)//ff(x) is f'(x)
{
	return -sin(x) - 1;
}
int main()
{
	const double  eps = 1e-6;
	double x2, x1;
	x1 = 3.14159 / 4;
	x2 = x1 - f(x1) / ff(x1);
	while (x1 - x2 >= eps) {
		double temp = x2;
		x2 = x1 - f(x1) / ff(x1);
		x1 = temp;
	}
	cout << cos(0.739536) << endl;//验证
	cout << setiosflags(ios::fixed) << setprecision(6) << x2 << endl;
	return 0;
}
