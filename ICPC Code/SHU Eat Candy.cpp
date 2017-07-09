#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
       long long n,k;
       while(scanf("%lld%lld",&n,&k)==2){
                     long long t1=n;
                     n=n/2+k;
                     long long t2=n;
                     while(t1!=t2){
                            t1=t2;
                            n=n/2+k;
                            t2=n;
                     }
                     printf("%lld\n",t2);
       }
       return 0;
}
