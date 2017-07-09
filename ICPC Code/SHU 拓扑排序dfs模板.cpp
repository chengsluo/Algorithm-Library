#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;



const int maxn=100;
int t;
int c[maxn];
int Ans[maxn];
int G[maxn][maxn];
int n,m;

bool dfs(int v){
	c[v]=-1;
	for(int i=0;i<n;++i)
              if(G[v][i]){
                     if(c[i]==-1)return false;///ÓÐ»·
                     if(c[i]==0&& !dfs(i))return false;///
              }
	c[v]=1;
	Ans[--t]=v+1;
	return 1;
}
bool toposort(int n){
	t=n;
	memset(c,0,sizeof(c));
	for(int i=0;i<n;++i)
              if(c[i]!=0&&dfs(i)!=0) return false;
	return true;
}
int main()
{
	cin>>n>>m;
	memset(G,0,sizeof(G));
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a][b]=1;
	}
	if(toposort(n)){
		cout<<"ÄÜÍØÆËÅÅÐò"<<endl;
	 	for(int i=0;i<n;++i){
		 	cout<<Ans[i]<<" ";
		 }
		 cout<<endl;
	}else{
		cout<<"²»ÄÜÍØÆËÅÅÐò"<<endl;
	}

	return 0;
}








