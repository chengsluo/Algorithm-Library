#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	long long L,R,ct;
	while(scanf("%lld%lld",&L,&R)==2){
		if(L==0){
			L=1;
		}
		if(R<=1){
			ct=0;
		}else if(R<=2){
			ct=1; 
		}else if(R-L<=3){
			ct=2;
		}else if(R-L>3){
			if((R-L-3)%2){
				ct=2+(R-L-3)/2+1;
			}else{
				ct=2+(R-L-3)/2;
			}
		}
		printf("%lld\n",ct);
	}
	return 0;
}