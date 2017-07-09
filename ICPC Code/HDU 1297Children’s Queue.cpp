#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

char f[1010][1000];
char t[1000];

void add(const char *a,const char *b,char * str)///大整数加法模板之一
{
       int lena=strlen(a);
       int lenb=strlen(b);
       int temp=0;
       int k=0;
       int i,j;
       for(i=lena-1,j=lenb-1;i>=0&&j>=0;i--,j--){
              if(a[i]+b[j]+temp>'9'+'0'){
                     str[k++]=a[i]+b[j]+temp-'0'-10;
                     temp=1;
              }
              else {
                     str[k++]=a[i]+b[j]+temp-'0';
                     temp=0;
              }
       }
       while(i>=0){
              if(temp+a[i]>'9'){
                     str[k++]=temp+a[i]-10;
                     temp=1;
              }
              else{
                     str[k++]=temp+a[i];
                     temp=0;
              }
              i--;
       }
       while(j>=0){
              if(temp+b[j]>'9'){
                     str[k++]=temp+b[j]-10;
                     temp=1;
              }
              else{
                     str[k++]=temp+b[j];
                     temp=0;
              }
              j--;
       }
       if(temp!=0) str[k++]='1';
       str[k]='\0';
       for(int i=0,j=k-1;i<k/2;i++){
              char tt=str[i];
              str[i]=str[k-1-i];
              str[k-1-i]=tt;
       }
}

int main()
{
       f[1][0]='1';
       f[2][0]='2';
       f[3][0]='4';
       f[4][0]='7';

//       char c[5]="9899",cd[5]="213";
//       add(c,cd,t);puts(t);

       for(int i=1;i<=4;i++) f[i][1]='\0';
       for(int i=5;i<=1000;i++){
              add(f[i-1],f[i-2],t);
              add(t,f[i-4],f[i]);
            //  puts(t);
       }
       int n;
       while(scanf("%d",&n)==1){
              puts(f[n]);
       }
       return 0;
}
