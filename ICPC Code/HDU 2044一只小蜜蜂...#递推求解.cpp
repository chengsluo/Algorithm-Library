#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

long long dp[55][55];

void DP()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=50;i++){
        dp[i][i+1]=1;
        dp[i][i+2]=2;
    }
    for(int k=3;k<50;k++){
        for(int i=1;i+k<=50;i++)
            dp[i][i+k]=dp[i][i+k-2]+dp[i][i+k-1];///动态规划或者递推，要注意的是，在进行加法的时候，必须保证两者完全独立和互斥
    }
}

int main()
{
    int t,a,b;
    scanf("%d",&t);
    DP();
    while(t--){
        scanf("%d%d",&a,&b);
        printf("%lld\n",dp[a][b]);
    }
    return 0;
}
