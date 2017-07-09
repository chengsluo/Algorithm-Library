#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int num[10010];

int main()
{
	int t,n,a,b,c,ct,ans;
	while (cin>>n>>a>>b>>c) {
		ct=0;
		ans=0;
		for(int i=0;i<n;i++){
			cin>>num[i];
			ct+=num[i];
			if(ct>=a&&ct<b) {ans+=2;ct=0;}
			else if(ct>=b&&ct<c){ans+=3;ct=0;}
			else if(ct>=c) {ans+=4;ct=0;}
		}
		cout<<ans<<endl;
	}
	return 0;
}