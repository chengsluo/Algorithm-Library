//
// Created by chengs on 17-8-8.
//

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
typedef long long ll;

using namespace std;
#define MAXINT 2147483647
int   dp[2000][1000];

int main()
{
    int n,k;
    int data[2000];
    //dp[i][j]在i个物体中取j对的最小消耗
    //如果包含i中的最后一个,必然会包含倒数第二个
    while(cin>>n>>k){
        for(int i=0;i<n;i++){
            cin>>data[i];
        }
        sort(data,data+n);
//        for(int i=0;i<n;i++){
//            cout<<data[i]<<" ";
//        }
//        cout<<endl;
        //init
        //在不影响复杂度的情况下，不要过多的纠结初始化的方法,乱用巧计容易出错
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            for(int j=1;j<=k;j++){
                dp[i][j]=MAXINT;
            }
        }
        dp[2][1]=(data[1]-data[0])*(data[1]-data[0]);
        for(int i=3;i<=n;i++){
            int j;
            for( j=1;j<=i/2&&j<=k;j++){
                dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+(data[i-1]-data[i-2])*(data[i-1]-data[i-2]));
                //cout<<i<<":"<<j<<"-"<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        printf("%lld\n",dp[n][k]);
    }
    return 0;
}