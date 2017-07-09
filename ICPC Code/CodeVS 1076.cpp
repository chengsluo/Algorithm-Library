#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[100010];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n);
	cout<<num[0];
	for(int i=1;i<n;i++){
		cout<<" "<<num[i];
	}
	cout<<endl;
	return 0;
}