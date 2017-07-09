#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
       int a,b,c,d;
       int t;
       scanf("%d",&t);
       while(t--){
              scanf("%d%d%d%d",&a,&b,&c,&d);
              if(a+b+c+d>=80)
              printf("Yes\n");
              else
              printf("No\n");
       }
       return 0;
}
