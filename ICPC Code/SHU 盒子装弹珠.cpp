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
			ans =ans* (n + r - 1)/n;//����д��ans*= (n + r - 1)/n;
			n--;
		}
		cout <<setiosflags(ios::fixed)<< setprecision(0) << ans << endl;//�������0λС���Ĺ̶���ʽ��<<setiosflags(ios::fixed)<< setprecision(0) << ans;
	}
}