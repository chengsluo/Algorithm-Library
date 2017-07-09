#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int temp[2500];

void multiply(char* a,char* b,char* c)
{
    int i,j,ca,cb,* s;
    ca=strlen(a);
    cb=strlen(b);
    s=new int [ca+cb];
    for (i=0;i<ca+cb;i++)
        s[i]=0;
    for (i=0;i<ca;i++)
        for (j=0;j<cb;j++)
            s[i+j+1]+=(a[i]-'0')*(b[j]-'0');//i+j+1的目的就是为了防止最高位进位而产生错误
    for (i=ca+cb-1;i>=0;i--)
        if (s[i]>=10)
        {
            s[i-1]+=s[i]/10;
            s[i]%=10;
        }
    i=0;
    while (s[i]==0)
        i++;//去除前导0
       for (j=0;i<ca+cb;i++,j++)
           c[j]=s[i]+'0';
    c[j]='/0';//将结果存储到字符数组
   delete []s;
}
void mul( char *a, char *b, char *sum )
{
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
char ch1[30],ch2[30],ans[30];

int main()
{
    int t;
    int n;
    scanf("%d",&t);
    while(t--){
        scanf("%d %s",&n,ch1);
        strcpy(ch2,ch1);
        multiply(ch1,ch2,ans);
        for(int i=0;i<n;i++){
            printf("%c",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
