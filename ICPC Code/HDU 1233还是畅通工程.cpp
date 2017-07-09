#include<iostream>
#include<cstdio>
#include<cstring >
#include<algorithm>
using namespace std;

struct R{
    int r1;
    int r2;
    int cost;
};
int city[101];
R road[5051];//注意结构
bool myCompare(R a,R b){
    return a.cost<b.cost;
}
int find(int x)
{
    if(city[x]==0) {
        city[x]=x;
        return x;
    }
    int r=x;
    while(city[r]!=r){
        r=city[r];
    }
    int t=x,temp;
    while(city[t]!=r){
        temp=city[t];
        city[t]=r;
        t=temp;
    }
    return r;
}
bool merge(int a,int b)
{
    int t1=find(a),t2=find(b);
    if(t1==t2) return 0;
    else{
        city[t2]=t1;
        return 1;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n){
        long long ans=0,ct=0;
        memset(city,0,sizeof(city));
        int m=n*(n-1)/2;//注意数量关系
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&road[i].r1,&road[i].r2,&road[i].cost);
        }
        sort(road,road+m,myCompare);
        for(int i=0;i<m;i++){
            if(merge(road[i].r1,road[i].r2)){//注意比较方法
                ans+=road[i].cost;
                ct++;
            }
            if(ct==n-1) break;//注意数量关系
        }
        printf("%lld\n",ans);
    }
    return 0;
}
