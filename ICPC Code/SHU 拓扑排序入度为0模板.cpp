#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100;

int Ans[maxn];
int G[maxn][maxn];
int n,m;
int deg[maxn];

bool toposort(int n){
	int t=0;
	queue<int >que;
	for(int i=0;i<n;++i){
		if(deg[i]==0)que.push(i);
	}
	while(!que.empty()){
		int v=que.front();que.pop();
		Ans[t++]=v+1;
		for(int i=0;i<n;++i){
			if(G[v][i]==1){
				deg[i]--;
				if(deg[i]==0)que.push(i);
			}
		}
	}
	if(t<n)return false;
	return true;
}
int main()
{
	cin>>n>>m;
	memset(G,0,sizeof(G));
	memset(deg,0,sizeof(deg));
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a][b]=1;
		deg[b]++;
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
	int a=1/0;
	return 0;
}



/*
	4 3
	1 2
	3 2
	4 3
*/

/*
	4 4
	1 2
	2 3
	3 4
	4 1
*/









