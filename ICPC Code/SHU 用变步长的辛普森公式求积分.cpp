#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double f(double  x)//原函数
{
	return x*x;
}

int main()
{
	double a,b,eps=1e-8;
	int n;
	double I2, I1, T2, T1,h;
	cin >> a >> b;
	if (a > b) cout << "Input Error!" << endl;//
	else {
		h = b - a;
		I2 =T2= (f(b) + f(a))*h / 2 ;
		I1 = 0;
		n = 1;
		while (fabs(I2 - I1) >=eps) {
			T1 = T2;
			I1 = I2;
			double sigma = 0.0;//sigma表示求和符号
			for(int k = 0;k < n;k++) {//部分和
				double x = a + (k + 0.5)*h;
				sigma += f(x);
			}
			T2 = (T1 + h*sigma) / 2;//变步长梯形法
			I2 = (4 * T2 - T1) / 3;//辛普森公式

			n *= 2;
			h /= 2;
		}
		cout << a << "到" << b << "之间对函数f(n)的积分为（精度为" <<eps<< "):" << setiosflags(ios::fixed) << setprecision(8) <<I2<< endl;
	}
	return 0;
}