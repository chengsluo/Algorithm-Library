#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[1000];
int main(){
	while(gets(str)!=NULL&&str[3]!='O'){
		gets(str);
		int len=strlen(str);
		for(int i=0;i<len;i++){
			if(!isalpha(str[i]))continue;
			str[i]-=5;
			if(str[i]<'A') str[i]+=26;
		}
		puts(str);
		gets(str);
	}
	return 0;
}

/*

*/

