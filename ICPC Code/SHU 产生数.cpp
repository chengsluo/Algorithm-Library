#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

char ch[40];
int num[10][10];
int p[10];
long long  ct;
char ans[50];
char ans2[50];
char temp[50];
void statics(int a){
    if(p[a]==1) return ;
    else{
            p[a]=1;
            ct++;
    }
    for(int i=1;i<=9;i++){
        if(num[a][i]!=0){
            statics(i);
        }
    }
    return;
}
void mul( char *a, char *b, char *sum )
{
    int temp[2500];
    int i,j,la,lb,l;
    la=strlen(a);
    lb=strlen(b);

    for ( i=0;i<la+lb;i++ )
        temp[i]=0;
    for ( i=la-1;i>=0;i-- ) {
        l=la-1-i;
        for ( j=lb-1;j>=0;j-- ) {
            temp[l]=(b[j]-'0')*(a[i]-'0')+temp[l];
            l++;
        }
    }

    while ( temp[l]==0 )
        l--;
    for ( i=0;i<=l;i++ ) {
        temp[i+1]+=temp[i]/10;
        temp[i]=temp[i]%10;
    }
    if ( temp[l+1]!=0 )
        l++;

    while ( temp[l]/10!=0 ) {
        temp[l+1]+=temp[l]/10;
        temp[l]=temp[l]%10;
        l++;
    }
    if ( temp[l]==0 )
        l--;
    i=0;
    while ( l>=0 ) {
        sum[i]=temp[l]+'0';
        i++;
        l--;
    }
    sum[i]='\0';
}
int main()
{
    int n,t1,t2;
    while(scanf("%s %d",ch,&n)==2){
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            scanf("%d%d",&t1,&t2);
            num[t1][t2]=1;
        }
        int len=strlen(ch);
        ans[0]='1';
        ans[1]='\0';
        for(int i=0;i<len;i++){
            ct=0;
            memset(p,0,sizeof(p));
            statics(ch[i]-'0');
            int key=0;
            while(ct){
                temp[key++]=ct%10+'0';
                ct/=10;
            }
            for(int i=0;i<key/2;i++){
                int tt=temp[i];temp[i]=temp[key-1-i];
                temp[key-1-i]=tt;
            }
            temp[key]='\0';
            mul(ans,temp,ans2);
//            puts(temp);
//            puts(ans2);
            strcpy(ans,ans2);
        }
        printf("%s\n",ans);
        getchar();
    }
    return 0;
}
