#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int p=(int)pow((n-1)*2,0.5);
		if(p*(p+1)==(n-1)*2) printf("2\n");
		else printf("3\n");
	}
	return 0;
}

/*

*/

