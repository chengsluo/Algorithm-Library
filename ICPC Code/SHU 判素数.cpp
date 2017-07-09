#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int num;
	cin >> num;
	if (num <= 1) cout << "mistake!" << endl;
	else {
		int temp = sqrt(num);
		int i;
		for (i = 2;i <=num;i++){
			if (num%i == 0)
				break;
		}
		if (i <= temp) cout << num << " is prime." << endl;
		else cout << num<< " isn't prime." << endl;
	}
	return 0;
}