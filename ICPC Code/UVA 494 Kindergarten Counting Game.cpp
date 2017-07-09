#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

char str[2000];
int main()
{
       int count_w=0;
       while(gets(str)!=NULL){
              count_w=0;
              if((str[0]>='a'&&str[0]<='z')||(str[0]>='A'&&str[0]<='Z'))
              {
                     count_w++;
              }
              for(int i=1;str[i]!='\0';i++){
                     if(((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))&&!((str[i-1]>='a'&&str[i-1]<='z')||(str[i-1]>='A'&&str[i-1]<='Z')))
                     {
                            count_w++;
                     }
              }
              printf("%d\n",count_w);
       }
       return 0;
}
