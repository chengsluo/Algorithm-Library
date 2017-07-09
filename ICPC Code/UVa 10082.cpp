#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
	int i,c;
	while((c=getchar())!=EOF){
		for(i=1;s[i]&&s[i]!=c;i++);//find move char ,and s[i]=='\0' is equired s[i]==0;
		if(s[i]) putchar(s[i-1]); //if find,output the pre char;
		else putchar(c);
	}
	return 0;
}