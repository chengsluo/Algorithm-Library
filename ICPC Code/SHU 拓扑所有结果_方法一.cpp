#include<iostream>
#include<cstdio>
#include<cstring>
#include <ctime>
using namespace std;

int G[50][50];
int m,n;
int dir[50];///路径
int deg[50];///每个点的入度
int num[50];///入度为零的点构成的数组
int f;///仅在记录路径时使用

void dfs(int v,int k)
{
       int tt[50];///记录此层中，更改过的度的编号
       int t=0;
       dir[f++]=v;
       int temp=k;///记录原本入度为零的点数
       for(int i=1;i<=n;i++){
              if(G[v][i]){
                     if(deg[i]!=0) {
                            deg[i]--;
                            tt[t++]=i;///记录更改
                            if(deg[i]==0){
                                   num[k]=i;
                                   k++;
                            }
                     }
              }
       }
       if(k==0){
              for(int i=0;i<n;i++){
                     printf("%d%c",dir[i],i==n-1?'\n':' ');
              }
       }
       for(int i=0;i<k;i++){
              int t1=num[i];
              int t2=num[k-1];
              num[i]=num[k-1];///将数组的最后一个元素删除
              dfs(t1,k-1);
              num[i]=t1;
              num[k-1]=t2;
       }
       for(int i=0;i<t;i++){
              deg[tt[i]]++;
       }
       k=temp;
       f--;
}

void toposort()
{
       int k=0;
       f=0;
       for(int i=1;i<=n;i++){
              deg[i]=0;
              for(int j=1;j<=n;j++){
                     if(G[j][i]) deg[i]++;
              }
              if(deg[i]==0) num[k++]=i;
       }
       for(int i=0;i<k;i++){
              int t1=num[i];
              int t2=num[k-1];
              num[i]=num[k-1];
              dfs(t1,k-1);
              num[i]=t1;
              num[k-1]=t2;
       }
}
int main()
{
       int t1,t2;
       while(scanf("%d%d",&n,&m)==2){///n为顶点数，m为边数
             // int iii=clock();
              memset(G,0,sizeof(G));
              for(int i=0;i<m;i++){
                     scanf("%d%d",&t1,&t2);///这里t1,t2>0;
                     G[t1][t2]=1;
              }
              toposort();///若有环，将不输出任何结果！
              //cout<<clock()-iii;
       }
       return 0;
}

//书上测试数据之一：
//6 9
//
//2 1
//2 5
//5 1
//1 4
//1 3
//3 4
//6 3
//6 4
//6 5

