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

int num[1010];
int main()
{
       int t,n;
       scanf("%d",&t);
       while(t--){
              scanf("%d",&n);
              for(int i=0;i<n;i++){
                     scanf("%d",num+i);
              }
              for(int j=n+1;j>0;j--)
                     for(int i=n-1;i>0;i--){
                            if(num[i]>num[i-1]+1){
                                   int temp=num[i];
                                   num[i]=num[i-1]+1;
                                   num[i-1]=temp-1;
                            }
                     }
              int i;
              for( i=0;i<n-1;i++){
                     if(num[i]<num[i+1]) break;
              }
              if(i<n-1)
                     printf("Impossible\n");
              else
              for(int i=0;i<n;i++)
                     printf("%d%c",num[i],i==n-1?'\n':' ');
       }
       return 0;
}
