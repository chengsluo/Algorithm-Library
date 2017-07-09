#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int m, n;
	int a[100];
	while (cin >> m >> n)
	{
		long long ans = 1;
		for (int i = 1;i <= n - 1;i++)
			ans *= i;
		for (int i = n-m+1;i <= n;i++)
			ans *= i;
		cout << ans << endl;
	}
	return 0;
}
