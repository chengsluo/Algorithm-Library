#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int num[10001];
int tmp[10001];
int c1[10];
int c2[10];

void init()
{
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
}
int main()
{
	int tc=1;
	int n;
	while(scanf("%d",&n)==1&&n!=0){
		for(int i=0;i<n;i++){
			scanf("%d",num+i);
		}
		printf("Game %d:\n",tc++);
		while(true){
			init();
			int key=0;
			for(int i=0;i<n;i++){
				scanf("%d",tmp+i);
				if(tmp[i]!=0) key=1;
			}
			if(key){
				int a=0,b=0;
				for(int i=0;i<n;i++){
					if(num[i]==tmp[i]) a++;
					c1[num[i]]++;
					c2[tmp[i]]++;
				}
				for(int i=0;i<10;i++){
					b+=min(c1[i],c2[i]);
				}
				b=b-a;
				printf("    (%d,%d)\n",a,b);//notice the number of spaces!				
			}else{
				break;
			}
		}
	}
	return 0;
}