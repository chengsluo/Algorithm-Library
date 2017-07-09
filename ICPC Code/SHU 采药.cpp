#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef  long long int  ll ;

struct node{
       int t;
       int v;
};
node num[110];

int dp[1010];


int main()
{
       int tt,n;
       while(scanf("%d%d",&tt,&n)==2){
              for(int i=0;i<n;i++){
                     scanf("%d%d",&num[i].t,&num[i].v);
              }
              memset(dp,0,sizeof(dp));
              for(int i=0;i<n;i++){
                     for(int j=tt;j>=num[i].t;j--){
                            dp[j]=(dp[j]>dp[j-num[i].t]+num[i].v)?dp[j]:dp[j-num[i].t]+num[i].v;
                     }
              }
              cout<<dp[tt]<<endl;
       }
       return 0;
}
