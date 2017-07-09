#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1010],p[1010];
int next[1010],n,m;

void getNext(){
	int i=0,k=-1;
	next[0]=-1;
	while(i<m-1){
		if(k==-1||p[i]==p[k]){
			i++;k++;
			if(p[i]==p[k]) next[i]=next[k];
			else next[i]=k;
		}
		else k=next[k];
	}
}
int kmp(){
	getNext();
	int i=0,j=0,ct=0;
	while(i<n&&j<m){
		if(j==-1||s[i]==p[j]){
			i++;j++;
		}
		else j=next[j];
		if(j==m){
			ct++;//i,j此时已经变成下一位了 
			j=0;
		}
	}
	return ct;
}
int main(){
	while(scanf("%s%s",s,p)==2){
		if(s[0]=='#') break;
		n=strlen(s);m=strlen(p);
		printf("%d\n",kmp());
	}
	return 0;
}
