#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
       int n=0;
       char ch;
       while(scanf("%c",&ch)==1){
                    if(ch>='0'&&ch<='9')
                            n=n+ch-'0';
                     else{
                            if(ch=='!'||ch=='\n'){
                                   printf("\n");
                            }
                            else{
                                   if(ch=='b') ch=' ';
                                   for(int i=0;i<n;i++)
                                          printf("%c",ch);
                            }
                            n=0;
                     }
       }
       return 0;
}
