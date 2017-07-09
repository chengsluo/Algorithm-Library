#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef  long long int  ll ;
///，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，///
///，，，，，，，，，， 芙氏麼吶挫，，，，，，，，，，，，，///
///，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，///

ll dp[2014];
void init()
{
       dp[1]=0;
       dp[2]=1;
       for(int i=3;i<=2013;i++){
              dp[i]=1*(i-1)+dp[i]+dp[i-1];
              for(int j=2;j<=i/2;j++){
                     dp[i]=min(dp[i],j*(i-j)+dp[j]+dp[i-j]);
              }
       }
}
int main()
{
       init();
       int t;
       scanf("%d",&t);
       while(t--){
              int n;
              scanf("%d",&n);
              if(n==1){
                     printf("Mission Complete!\n");
                     continue;
              }
              if(n==2){
                     printf("Needs at least 1 ATP!\n");
                     continue;
              }
              printf("Needs at least %lld ATPs!\n",dp[n]);
       }
       return 0;
}
