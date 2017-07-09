#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int data[100001][11];
int dp[100001][11];
int main()
{
       int n,x,t,max_t,ans;
       while(scanf("%d",&n)==1&&n){
              max_t=0;
              memset(data,0,sizeof(data));
              for(int i=0;i<n;i++){
                     scanf("%d%d",&x,&t);
                     data[t][x]++;
                     max_t=max(max_t,t);
              }
              memset(dp,0,sizeof(dp));
              for(int i=1;i<=max_t;i++){
                     for(int j=0;j<=10;j++){
                                   t=dp[i-1][j];
                                   if(j>=1) t=max(t,dp[i-1][j-1]);
                                   if(j<=9) t=max(t,dp[i-1][j+1]);
                                   dp[i][j]=t;
                                   if(i<5){
                                          if(j>5-i-1&&j<5+i+1){
                                                 dp[i][j]+=data[i][j];
                                          }
                                          //cout<<dp[i][j];
                                   }
                                   else{
                                          dp[i][j]+=data[i][j];
                                   }
                     }
              }
              ans=0;
              for(int j=0;j<=10;j++){
                     ans=max(ans,dp[max_t][j]);
              }
              printf("%d\n",ans);
       }
       return 0;
}
