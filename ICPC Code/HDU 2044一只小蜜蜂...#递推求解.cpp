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
            dp[i][i+k]=dp[i][i+k-2]+dp[i][i+k-1];///��̬�滮���ߵ��ƣ�Ҫע����ǣ��ڽ��мӷ���ʱ�򣬱��뱣֤������ȫ�����ͻ���
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
