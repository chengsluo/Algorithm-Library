#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
       long long n,lim,ct,n_o,k=0;
       while(scanf("%lld%lld",&n,&lim)==2){
              if(n==-1&&lim==-1) break;
              k++;
              n_o=n;
              ct=0;
              while(n!=1&&n<=lim){
                     if(n%2){
                            n=n*3+1;
                     }
                     else{
                            n=n/2;
                     }
                     ct++;
              }
              if(n==1) ct++;
              printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",k,n_o,lim,ct);
       }
       return 0;
}
