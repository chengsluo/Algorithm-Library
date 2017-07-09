#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int ct(long long a)
{
	int ans = 0;
	if (a == 1||a==0) return 0;
	if (a % 2) ans = 1+ct(a / 2) + ct(a / 2 + 1);
	else ans = 2 * ct(a / 2);
	return ans;
}

int main()
{
	int t;
	long long a;
	cin >> t;
	while (t--) {
		cin >> a;
		cout << ct(a) << endl;
	}
	return 0;
}