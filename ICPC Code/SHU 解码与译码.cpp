#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

char str[20000];
char ans[20000];
int len;
void Zip()
{
	int k = 0;
	for (int i = 0;i < len;)
	{
		if (str[i] - '0' + (str[i + 1] - '0') * 10 < 25 && str[i + 2] == '1')
		{
			ans[k++] = str[i] - '0' + (str[i + 1] - '0') * 10 + 100;//注意，在操作数字字符时，是否需要-'0';
			i += 3;
		}
		else 
		{
			ans[k++] = str[i] - '0' + (str[i + 1] - '0') * 10;
			i += 2;
		}
	}
	for (int i = k - 1;i >= 0;i--)
		cout << ans[i];
	cout << endl;
}
void Code()
{
	int k = 0;
	for (int i = len - 1;i >= 0;i--)
	{
		while (str[i]!=0)
		{
			ans[k++] = str[i] % 10+'0';
			str[i] /=10;
		}
	}
	ans[k] = '\0';
	puts(ans);
}
int main()
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{
		//fgets(str, 20000, stdin);//会在str末尾加‘\n';
		gets_s(str);//gets的安全版本；其他与gets无异；//SHU-OJ上需要用gets(),不然会挂，233！
		len = strlen(str);
		int i;
		for (i = 0;i < len;i++)
		{
			if (str[i]<'0' || str[i]>'9') break;
		}
		if (i >= len) Zip();
		else Code();
	}
	return 0;
}