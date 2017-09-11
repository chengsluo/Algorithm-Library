#include <iostream>
#include <cstdio>
using namespace std;
int num[30000],father[30000],m,n;

void InitSet()
{
    for(int i=0;i<n;i++){
        father[i]=i;
        num[i]=1;
    }
}
int findSet(int a)
{
    if(father[a]!=a){
        return findSet(father[a]);
    }else{
        return a;
    }
}
void UnionSet(int a,int b)
{
    int x=findSet(a),y=findSet(b);
    if(x==y){
        return;
    }else if(x>y){
        father[x]=y;
        num[y]=num[x]+num[y];
    }else{
        father[y]=x;
        num[x]=num[y]+num[x];
    }
}
int main()
{
    int t,first,tmp;
    while(scanf("%d%d",&n,&m)==2&&!(n==0&&m==0)){
        InitSet();
        for(int i=0;i<m;i++){
            scanf("%d%d",&t,&first);
            for(int i=1;i<t;i++){
                scanf("%d",&tmp);
                UnionSet(first,tmp);
            }
        }
        printf("%d\n",num[findSet(0)]);
    }
    return 0;
}