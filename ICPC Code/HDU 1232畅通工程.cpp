#include<iostream>
#include<cstdio>
using namespace std;

int num[1001];
int find(int x)
{
    int r=x;
    while(r!=num[r]) r=num[r];
    int p=x,t;
    while(p!=num[r]){
            t=num[p];
            num[p]=r;
            p=t;
    }
    return r;
}
void merge(int a,int b)
{
    int t1=find(a);
    int t2=find(b);
    if(t1!=t2){
        num[t2]=t1;
    }
}
int main()
{
    int n,m,t1,t2;
    while(scanf("%d%d",&n,&m)==2){
        for(int i=1;i<=n;i++) num[i]=i;
        for(int i=0;i<m;i++){
            scanf("%d%d",&t1,&t2);
            merge(t1,t2);
        }
        int count=0;
        for(int i=1;i<=n;i++){
                if(num[i]==i)count++; //不用if(find[i]==i)，因为只需要统计树根的个数
        }
        printf("%d\n",count-1);
    }
    return 0;
}

