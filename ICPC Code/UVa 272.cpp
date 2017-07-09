#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	bool key=1;
	char c;
	while((c=getchar())!=EOF){//  must have () before !=EOF
		if(c=='"'&&key){
			printf("``");
			key=0;
		}else if(c=='"'&&!key){
			printf("''");
			key=1;
		}else{
			printf("%c",c);
		}
	}
	return 0;
}