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

int num[12];
int main()
{
       int k=0;
       while(scanf("%d",num+k)==1){
              k++;
              if(k==12){
                     int i,r=0,ans=0;
                     for(i=0;i<12;i++){
                            if(300+r<num[i]){
                                   cout<<-(i+1)<<endl;
                                   break;
                            }
                            else{
                                   ans+=(300+r-num[i]-(300+r-num[i])%100);
                                   r=(300+r-num[i])%100;
                            }
                     }

                     if(i>=12){
                            cout<<ans*1.2+r<<endl;
                     }
                     k=0;
              }
       }
       return 0;
}
