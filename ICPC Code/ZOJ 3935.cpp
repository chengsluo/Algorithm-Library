#include<iostream>
#include<cstdio>
using namespace std;
typedef long long  ll;

bool isleap(int year)
{
return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int main()
{
       int i=63;
       int j=32;
       int a=1;
       while(a<990528){
              a=i*(i+1)/2;
              while(a>j*(2*j-1)){
                     j++;
              }
              if(a==j*(2*j-1)){ if(isleap(a)) printf("%d\n",a);}
              i++;
       }
       return 0;
}

