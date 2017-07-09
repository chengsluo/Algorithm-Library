#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int num[10000];

int main()
{
	int t;
	double a;
	cin>>t;
	while(t--){
		cin>>a;
		if(a<=4) {cout<<4<<endl;continue;}
		long long temp=sqrt(a)/1;
		int i,ii,j;
		for(i=temp;;i++){
			for(j=2;j<i;j++){
				if(i%j==0) break;
			}
			if(j>=i) break;
		}
		for(ii=temp;;ii--){
			for(j=2;j<ii;j++){
				if(ii%j==0) break;
			}
			if(j>=ii) break;
		}
		if(i*i-a<a-ii*ii){
			cout<<i*i<<endl;
		}
		else{
			cout<<ii*ii<<endl;
		}
	}
	return 0;
}