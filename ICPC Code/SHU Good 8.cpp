#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef  long long int  ll ;
///����������������������������������������������������������������������///
///�������������������� �������á�������������������������///
///����������������������������������������������������������������������///

char num[20];
int main()
{
       int t,n;
       scanf("%d",&t);
       while(t--){
              scanf("%s",num);
              int len=strlen(num);
              if(len<3) {printf("888\n");continue;}///����С��3ֱ�����
              int ct=0;
              for(int i=0;i<len;i++){
                     if(num[i]=='8') ct++;
                     if(ct>3){
                            num[i]='9';
                            for(int j=i+1;j<len;j++){
                                   if(num[j]=='8'){
                                          num[j]='0';
                                   }
                            }
                            break;
                     }
              }
              if(ct==4){puts(num); continue;}

              int k=0;
              for(int i=len-1;i>=0;i--){///8�ĸ���С��3
                     if(ct==3){
                            if(k==1){
                                   for(int j=i;j>=0;j--){
                                          if(num[j]<'8'){
                                                 num[j]++;k=0;break;
                                          }
                                          else if(num[j]=='9'){
                                                 num[j]='0';
                                          }
                                   }
                                   break;
                            }
                            else break;
                     }
                     if(k){///��λ������
                            if(num[i]<'8'){
                                   num[i]='8';
                                   ct++;
                                   k=0;
                            }
                            else if(num[i]=='9'){
                                   num[i]='8';
                                   ct++;
                                   k=1;
                            }
                     }
                     else{///��λδ����
                            if(num[i]<'8'){
                                   num[i]='8';
                                   ct++;
                            }
                            else if(num[i]=='9'){
                                   num[i]='8';
                                   ct++;
                                   k=1;
                            }
                     }
              }
              if(k) printf("1");
              puts(num);
       }
       return 0;
}
