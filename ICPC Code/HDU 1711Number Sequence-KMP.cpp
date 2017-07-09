#include<iostream>
#include<cstdio>
using namespace std;
int n,m,s[1000010],p[10010],nnext[10010];

void getNext(){
	int i=0,k=-1;
	nnext[0]=-1;
	while(i<m-1){
		if(k==-1||p[i]==p[k]){
			i++;k++;
			if(p[i]==p[k]) nnext[i]=nnext[k];
			else nnext[i]=k;
		}
		else k=nnext[k];
	}
}
int kmp(){
	getNext();
	int i=0,j=0;
	while(i<n&&j<m){
		if(s[i]==p[j]||j==-1){
			i++;j++;
		}
		else{
			j=nnext[j];
		}
		if(j==m) return i+1-j;
	}
	return -1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%d",s+i);
		for(int i=0;i<m;i++) scanf("%d",p+i);
		printf("%d\n",kmp());
	}
	return 0;
}
