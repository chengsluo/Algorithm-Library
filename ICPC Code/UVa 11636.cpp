#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long n,ans;
	int k=1;
	while(scanf("%lld",&n)==1&&n>0){
		ans=0;
		int key=0;
		while(n>=2){
			if(n%2) key=1;
			n=n>>1;       
			ans++;
		}
		if(key==1) ans++;
		printf("Case %d: %lld\n",k++,ans);
	}
	return 0;
}