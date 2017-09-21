#include<iostream>
#include<cstring>
#include<functional>
#include<queue>
#include<cstdio>
using namespace std;

int G[510][510];//G[i][j]=1,����i��Ӯ��j�ӡ�
int m,n;
int dir[510];
int deg[510];///ÿ��������
//�����޷�������������������:
/*

4 2
4 1
3 2

��ȷ���:
3 2 4 1
�����˽��:
4 1 3 2
*/
bool retoposort()
{
      int k=0;
      priority_queue<int,vector<int>,less<int> >qu;
      ///����Ҿ����е�һ����
      for(int i=n;i>0;i--){
             deg[i]=0;
             for(int j=1;j<=n;j++){
                    if(G[i][j]) deg[i]++;
             }
             //��û��ʤ���������
             if(deg[i]==0) qu.push(i);
      }
      while(!qu.empty()){
            //ȡ�����������
             int v=qu.top();qu.pop();
             dir[k++]=v;
             for(int i=n;i>0;i--){
                    if(G[i][v]){
                           deg[i]--;
                           G[i][v]=0;
                           if(deg[i]==0) qu.push(i);
                    }
             }
      }
      if(k<n) return false;
      return true;
}

bool toposort()
{
       int k=0;
       //����Ҫ�����ȶ��д���������С�����ȣ�
       priority_queue<int,vector<int>,greater<int> >qu;
       //����Ҿ����е�һ����
       for(int i=1;i<=n;i++){
              deg[i]=0;
              for(int j=1;j<=n;j++){
                     if(G[j][i]) deg[i]++;
              }
              //���Ϊ0�ĵ������,��������սʤ����,С����ǰ
              if(deg[i]==0) qu.push(i);
       }
       while(!qu.empty()){
              int v=qu.top();
              qu.pop();
              dir[k++]=v;
              for(int i=1;i<=n;i++){
                     if(G[v][i]){
                            deg[i]--;
                            if(deg[i]==0) qu.push(i);
                     }
              }
       }
       if(k<n) return false;
       return true;
}

int main()
{
       int t1,t2;
       while(scanf("%d%d",&n,&m)==2){
              memset(G,0,sizeof(G));
              for(int i=0;i<m;i++){
                     scanf("%d%d",&t1,&t2);
                     G[t1][t2]=1;
              }
            //   retoposort();
            //   for(int i=n-1;i>=0;i--){
            //          printf("%d%c",dir[i],i==0?'\n':' ');
            //   }
              toposort();
              for(int i=0;i<n;i++){
                     printf("%d%c",dir[i],i==n-1?'\n':' ');
              }
       }
       return 0;
}

