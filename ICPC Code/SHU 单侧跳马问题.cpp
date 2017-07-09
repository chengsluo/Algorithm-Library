#include<iostream>
using namespace std;

const int n = 8;
JumpHorseSingle(int a, int b)
{
	
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		int ans=JumpHorseSingle(a, b);
		if (ans == -1) cout << "Impossible" << endl;
		else cout << ans << endl;
	}
	return 0;
}