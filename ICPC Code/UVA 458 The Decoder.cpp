#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

char str[1000];
int main()
{
       while(scanf("%s",&str)==1){
              for(int i=0;str[i]!='\0';i++){
                     printf("%c",str[i]-7);
              }
              printf("\n");
       }
       return 0;
}
