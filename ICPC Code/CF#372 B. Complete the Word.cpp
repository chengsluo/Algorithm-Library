#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

char str[1000001];
int ct[26];
int ctq;
bool judge()
{
	int tmp=0;
	for(int i=0;i<26;i++){
		if(ct[i]!=-1) tmp++;
	}
	//cout<<tmp<< "  "<<ctq<<endl;
	if(tmp+ctq==26){
		return 1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	while(scanf("%s",str)!=EOF){
		memset(ct,-1,sizeof(ct));///
		ctq=0;
		int len=strlen(str);
		int i;
		for(i=0;i<len;i++){
			if(str[i]=='?'){
				ctq++;
				if(judge()){
					for(int j=0;j<i-25;j++){
						if(str[j]!='?') printf("%c",str[j]);
						else{
							printf("T");
						}
					}
					for(int j=i-25;j<=i;j++){
						if(str[j]!='?') printf("%c",str[j]);
						else{
							for(int k=0;k<26;k++){
								if(ct[k]==-1){
									printf("%c",(k+'A'));
									ct[k]=1;
									break;
								}
							}
						}
					}
					for(int j=i+1;j<len;j++){
						if(str[j]!='?') printf("%c",str[j]);
						else{
							printf("T");
						}
					}
					cout<<endl;
					break;
				}
			}else{
				if(ct[str[i]-'A']==-1){
					ct[str[i]-'A']=i;
					if(judge()){
						for(int j=0;j<i-25;j++){
							if(str[j]!='?') printf("%c",str[j]);
							else{
								printf("T");
							}
						}
						for(int j=i-25;j<=i;j++){
							if(str[j]!='?') printf("%c",str[j]);
							else{
								for(int k=0;k<26;k++){
									if(ct[k]==-1){
										printf("%c",(k+'A'));
										ct[k]=1;
										break;
									}
								}
							}
						}
						for(int j=i+1;j<len;j++){
							if(str[j]!='?') printf("%c",str[j]);
							else{
							printf("T");
							}
						}
						cout<<endl;
						break;
					}
				}else if(ct[str[i]-'A']!=-1){
					i=ct[str[i]-'A'];
					memset(ct,-1,sizeof(ct));
					ctq=0;
				}
			}
		}
		if(i==len) printf("-1\n");
	}
	return 0;
}