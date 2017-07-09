#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	long long a, b;
	while (scanf("%lld%lld", &a, &b) == 2) {
		printf("%lld\n", a + b);
	}
	return 0;
}