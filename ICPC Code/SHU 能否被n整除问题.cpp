#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

char str[90];
int main(){
	int t;
	cin>>t;
	getchar();
	while(t--){
		gets(str);
		int s=0;
		int len=strlen(str);
		for(int i=0;i<len;i++){
			s=str[i]-'0'+s*10;
			if(s>=11){//将11改成n即可判断能否被n整除 
				s=s%11;
			}
		}
		if(s==0){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	} 
	return 0;
}

/*

*/

