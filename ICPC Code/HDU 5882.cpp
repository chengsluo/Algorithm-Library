#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int n,k;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		if(k%2){//要求每个人面对其他所有人，有一半的对手会赢，有一半的对手会输，所以只有当为奇数时，可以满足条件，比如n=5,有两个对手会赢，有两个对手会输;当n=4,有一个对手会赢，便有两个对手会输...看清题意即可！
			printf("Balanced\n");
		}else{
			printf("Bad\n");
		}
	}
	return 0;
}
