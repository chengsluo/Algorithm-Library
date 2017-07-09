#include <iostream>
#include   <stdlib.h>      
#include   <time.h> 
using namespace std;

int main()
{
	int n;
	cin>>n;
	srand((unsigned)time(0));
	for(int i=0;i<n;i++){
		cout<<int(rand()%15+80)<<" ";
	}
	return 0;	
}
