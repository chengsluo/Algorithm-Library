#include <iostream>
#include <cstdio>
using namespace std;
int num[50000],father[50000],m,n,ct;

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
        return father[a]=findSet(father[a]);//路径压缩
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
        ct--;
    }else{
        father[y]=x;
        ct--;
    }
}
int main()
{
    int a,b,k=1;
    while(scanf("%d%d",&n,&m)==2&&!(n==0&&m==0)){
        ct=n;
        InitSet();
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            UnionSet(a,b);
        }
        printf("Case %d: %d\n",k++,ct);
    }
    return 0;
}