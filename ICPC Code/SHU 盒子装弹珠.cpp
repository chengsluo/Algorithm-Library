#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n, r;
	while (cin >> n >> r)
	{
		double ans = 1;
		while (n > 0)
		{
			ans =ans* (n + r - 1)/n;//不能写成ans*= (n + r - 1)/n;
			n--;
		}
		cout <<setiosflags(ios::fixed)<< setprecision(0) << ans << endl;//输出保留0位小数的固定格式：<<setiosflags(ios::fixed)<< setprecision(0) << ans;
	}
}