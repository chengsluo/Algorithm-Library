#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;


int main()
{
	long long  a,b,sum;
	while(cin>>a>>b){
		if(a==0&&b==0)break;
		sum=1;
		a=a%1000;
		while(b--){
			sum=(sum*a)%1000;
		}
		cout<<sum<<endl;
	}
	return 0;
}