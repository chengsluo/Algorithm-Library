#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;
char num[2000];
int main(){
	int a,temp;
	while(scanf("%s",num)==1&&num[0]!='0'){
		int len=strlen(num);
		int sum=0;
		while(len--){
			sum+=(num[len]-'0');
		}
		a=sum;
		while(1){
			temp=0;
			while(a>=10){
				temp+=a%10;
				a=a/10;
			}
			temp+=a;
			if(temp<10){
				printf("%d\n",temp);
				break;
			}
			a=temp;
		}
	}
	return 0;
}
