#include <iostream>
#include <cstdio>
using namespace std;

long long dp[10010];
void DP()
{
	dp[1]=2;
	dp[2]=7;
	for(int i=2;i<10010;i++){
		dp[i]=dp[i-1]+4*(i-1)+1;
	}
}
int main()
{
	DP();
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
}