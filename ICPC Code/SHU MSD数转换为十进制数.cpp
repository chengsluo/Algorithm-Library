#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char str[1010];
int main()
{
	while (scanf("%s", str) == 1)
	{
		long long ans=0;
		for (int i = 0;str[i] != '\0';i++)
		{
			if(str[i]=='u')
				ans = ans * 2 -1;
			else
			{
				ans = ans * 2 + str[i]-'0';
			}
		}
		cout << ans << endl;
	}
	return 0;
}