#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

//char str1[1010],str2[1010],str[1010],aa[1010],bb[1010];

void inversion(char *ch){
       int len=strlen(ch);
       for(int i=0;i<len/2;i++){
              char t=ch[i];ch[i]=ch[len-1-i];ch[len-1-i]=t;
       }
}
//
//void add(char *a,char *b,char *ans)
/////加法模板，加树，被加数，以及和都被倒置了
//{
//       inversion(a);inversion(b);
//       int i;
//       int temp=0;
//       for(i=0;a[i]!='\0'&&b[i]!='\0';i++){///调过的Bug证明，人傻的时候，无处不傻
//              if(temp+a[i]+b[i]>'9'+'0'){
//                     ans[i]=temp+a[i]+b[i]-'0'-10;
//                     temp=1;
//              }
//              else{
//                     ans[i]=temp+a[i]+b[i]-'0';
//                     temp=0;
//              }
//       }
//       int k=i;
//       while(a[i]!='\0'){
//              if(temp+a[i]>'9'){
//                     ans[i]=temp+a[i]-10;
//                     temp=1;
//              }
//              else{
//                     ans[i]=temp+a[i];
//                     temp=0;
//              }
//              i++;
//
//       }
//       while(b[k]!='\0'){
//              if(temp+b[k]>'9'){
//                     ans[i]=temp+b[k]-10;
//                     temp=1;
//              }
//              else{
//                     ans[i]=temp+b[k];
//                     temp=0;
//              }
//              i++;
//              k++;
//       }
//
//       if(temp) ans[i++]='1';
//       ans[i]='\0';
//       inversion(ans);
//
//}
char str1[1010],str2[1010],str[1010];

int main()
{
       int t;
       scanf("%d",&t);
       for(int i=1;i<=t;i++){
              getchar();
              memset(str,0,sizeof(str));
              memset(str1,0,sizeof(str1));
              memset(str2,0,sizeof(str2));

              scanf("%s %s",str1,str2);
              if(i!=1) printf("\n");
              printf("Case %d:\n",i);
              printf("%s + %s = ",str1,str2);
              inversion(str1);
              inversion(str2);
              int len1=strlen(str1);
              int len2=strlen(str2);
              for(int i=0;i<len1;i++) str1[i]-='0';///'\0'==0'
              for(int i=0;i<len2;i++) str2[i]-='0';
              for(int i=0;i<1010;i++){
                     int temp=str[i]+str1[i]+str2[i];///注意更新效果
                     str[i]=temp%10;
                     str[i+1]=temp/10;
              }
              bool key=0;
              for(int i=1009;i>=0;i--){
                     if(str[i]) {
                            for(;i>=0;i--)
                                   printf("%d",str[i]);
                            key=1;
                            break;
                     }
              }
              if(key==0) printf("0");
              printf("\n");
       }
       return 0;
}
