#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

long long dp[55];
int main()
{
    int t;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<=50;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    while(scanf("%d",&t)==1){
        printf("%lld\n",dp[t]);
    }
    return 0;
}
