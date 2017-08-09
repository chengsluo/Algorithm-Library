//
// Created by chengs on 17-8-8.
//
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
int data[20][10];
int res[20][10];

int main()
{
    while(cin>>n>>m&&n){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>data[i][j];
            }
        }
        for(int j=0;j<m;j++){
            res[0][j]=0;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j]=res[i-1][0]+abs((data[i][j]-data[i-1][0]));//init
                for(int k=1;k<m;k++){
                    res[i][j]=min(res[i][j],res[i-1][k]+abs((data[i][j]-data[i-1][k])));
                }
            }
        }
        int ans=res[n-1][0];//init
        for(int j=1;j<m;j++){
            ans=min(ans,res[n-1][j]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
