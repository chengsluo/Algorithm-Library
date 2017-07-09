#include<iostream>
using namespace std;

long long cal[25],ca[25];
int main()
{
	cal[1] = 0;cal[2] = 1;ca[1]=1;ca[2]=2;
	for (int i = 3;i < 25;i++)
		cal[i] = (i - 1)*(cal[i - 2] + cal[i - 1]);
    for (int i = 3;i < 25;i++)
		ca[i] = i*ca[i -1];
	int n;
	while (cin >> n)
	{
		cout << cal[n]*1.0 /ca[n]<< endl;
	}
	return 0;
}
