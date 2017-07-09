#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[10000];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n);
	int a=1;
	for(int i=1;i<n;i++){
		if(num[i]!=num[i-1]){
			num[a++]=num[i];
		}
	}
	cout<<a<<endl;
	cout<<num[0];
	for(int i=1;i<a;i++){
		cout<<" "<<num[i];
	}
	cout<<endl;
	return 0;
}