#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char str1[100];
char str2[100];

int main()
{
       int t,key;
       int num[2];
       scanf("%d",&t);
       getchar();
       while(t--){
              num[0]=0;num[1]=0;
              gets(str1);
              num[0]++;
              key=0;
              while(gets(str2)){
                     if(strcmp(str2,"END")==0){
                            break;
                     }
                     else if(strcmp(str2,str1)!=0){
                            num[key]++;
                            strcpy(str1,str2);
                     }
                     else{
                            key=1-key;
                            num[key]++;
                            strcpy(str1,str2);
                     }
              }
              printf("%d\n",num[0]*num[1]);
       }
       return 0;
}
