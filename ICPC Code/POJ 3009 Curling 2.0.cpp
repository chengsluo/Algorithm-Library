#include<iostream>
#include<cstdio>
using namespace std;

int m,n;
int a,b;
int G[30][30];
int v[4][2]={0,1,1,0,-1,0,0,-1};
int ans;

void dfs(int i,int j,int ct)
{
       if(ct>9) return;
       for(int k=0;k<4;k++){
              int key=0;
              int p=i+v[k][0],q=j+v[k][1];
              if(p<0||q<0||p>n-1||q>m-1){continue;}
              if(G[p][q]==1) continue;
              do{
                     if(G[p][q]==3){
                            if(ct+1<ans)
                                   ans=ct+1;
                            return;
                     }
                     p+=v[k][0];
                     q+=v[k][1];
                     if(p<0||q<0||p>n-1||q>m-1){key=1;break;}
                      if(G[p][q]==1){
                            G[p][q]=0;
                            p-=v[k][0];
                            q-=v[k][1];
                            break;
                     }
              }while(1);
              if(key==0){
                     dfs(p,q,ct+1);
                     G[p+v[k][0]][q+v[k][1]]=1;
              }
       }
       return;
}

int main()
{
       while(scanf("%d%d",&m,&n)==2){
              if(m==0&&n==0) return 0;
              for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++){
                            scanf("%d",&G[i][j]);
                            if(G[i][j]==2){
                                   G[i][j]=0;
                                   a=i;b=j;
                            }
                     }
              }
              ans=11;//题意
              dfs(a,b,0);
              if(ans==11){ans=-1;}
              cout<<ans<<endl;
       }
       return 0;
}
