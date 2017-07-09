#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int num[1010];
int n;
bool inline cmp(int a,int b)
{
    return a>b;
}
bool havel()
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=num[i];
    if(sum&1) return 0;
    int ct=0;
    for(int i=0;i<n;i++){
        sort(num+ct,num+n,cmp);
        if(num[ct]==0) return 1;
        if(ct+num[ct]+1>n) return 0;
        for(int j=ct+1;j<ct+num[ct]+1;j++){
            if(--num[j]<0){
                return 0;
            }
        }
        ct++;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",num+i);
        }
        if(havel()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
