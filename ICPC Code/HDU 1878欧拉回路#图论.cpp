#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int M=1010;
bool G[M][M];
int ra[M],root[M];
int deg[M];
int n,m;
void init_set()
{
    for(int i=0;i<n;i++){
        root[i]=i;
        ra[i]=0;
    }
}
int find_set(int x)
{
    if(root[x]!=x) root[x]=find_set(root[x]);
    return root[x];
}
void union_set(int a,int b)
{
    int x=find_set(a),y=find_set(b);
    if(x==y){
        return;
    }else{
        if(ra[x]<ra[y]){
            root[x]=y;
        }else{
            root[y]=x;
            if(ra[x]==ra[y]) ra[x]++;
        }
    }
}
bool check_connected()
{
    for(int i=1;i<n;i++){
        if(root[i]!=root[0]){
            return false;
        }
    }
    return true;
}
int main()
{
       while(scanf("%d%d",&n,&m)&&n!=0){
              memset(deg,0,sizeof(deg));
              memset(G,0,sizeof(G));
              init_set();
              for(int i=0;i<m;i++){
                     int t1,t2;
                     scanf("%d%d",&t1,&t2);
                     t1--;t2--;
                     if(t1==t2) continue;
                     if(G[t1][t2]==0) {
                                   deg[t1]++;
                                   deg[t2]++;
                     }
                     union_set(t1,t2);
                     G[t1][t2]=G[t2][t1]=1;
              }
              if(check_connected()==false){
                printf("0\n");
                continue;
              }
              int i;
              for(i=0;i<n;i++){
                     if(deg[i]%2){
                            break;
                     }
              }
              if(i<n){
                     printf("0\n");
              }
              else{
                     printf("1\n");
              }
       }
       return 0;
}