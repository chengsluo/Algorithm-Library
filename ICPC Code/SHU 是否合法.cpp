#include<iostream>
using namespace std;
int dp[101][101];
int main()
{
    int m,n,t1,t2,key;
    while(cin>>n>>m){
        key=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                dp[i][j]=0;
        }
        for(int i=0;i<m;i++){
            cin>>t1>>t2;
            dp[t1][t2]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(dp[i][j]==1){
                    for(int k=0;k<n;k++){
                        if(dp[k][i]==1){
                            dp[k][j]=1;
                        }
                    }
                    if(dp[j][i]==1){key=1;goto abc;}
                }
        }
        abc:
        if(key==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}

