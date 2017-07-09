#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int p[22];
long long m[22][22];
int s[22][22];


void print(int i,int j){
	if(i==j) {cout<<'A'<<i;}
	else if(i+1==j) cout<<'('<<'A'<<i<<'A'<<j<<')';
	else{
		cout<<'(';
		print(i,s[i][j]);
		print(s[i][j]+1,j);
		cout<<')';
	}
}

void output(int i,int j){
	if(i==j) {cout<<'A'<<i;}//注意超级边界，不用乘的情况 
	else if(i+1==j) cout<<'A'<<i<<'A'<<j;
	else{
		print(i,s[i][j]);
		print(s[i][j]+1,j);
	}
	cout<<endl;
}

int main(){
	int n,ct=1;
	while(cin>>n){
		
		for(int i=0;i<n+1;i++) cin>>p[i];
		for(int i=0;i<=n;i++) m[i][i]=0;//注意m[n][n]=0; 
		for(int d=1;d<n;d++){
			for(int i=1;i<=n-d;i++){
				int j=i+d;
				m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
				s[i][j]=i;
				for(int k=i+1;k<j;k++){
					int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
					if(t<m[i][j]) {
						m[i][j]=t;s[i][j]=k;
					}
				}
			}
		}
		cout<<"Case "<<ct++<<endl<<m[1][n]<<" ";
		output(1,n);
	} 
	return 0;
}

/*

*/

