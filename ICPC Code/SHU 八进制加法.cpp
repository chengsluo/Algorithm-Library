#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str1[102];
char str2[102];
char str3[102];
int main(){
	while(scanf("%s%s",str1,str2)==2){
		int len1=strlen(str1);
		int len2=strlen(str2);
		printf("%s+%s=",str1,str2);
		for(int i=0;i<103;i++){
			 str3[i]='0';
		}
		int i=len1-1,j=len2-1,k=0;
		while(1){
			if(str3[k]+str1[i]+str2[j]<'8'+'0'+'0')
				str3[k]=str3[k]+str1[i]+str2[j]-'0'-'0';
			else{
				str3[k]=str3[k]+str1[i]+str2[j]-'8'-'0';
				str3[k+1]+=1;
			}
			k++;
			if(i==0&&j==0) break;
			if(i) i--;
			else str1[i]='0';
			if(j) j--;
			else str2[j]='0';		
		}
		int len3;
		if(str3[k]!='0') len3=k+1;
		else len3=k;
		for(int i=len3-1;i>=0;i--){
			printf("%c",str3[i]);
		}
		printf("\n");
	}
	return 0;
}

/*

*/

