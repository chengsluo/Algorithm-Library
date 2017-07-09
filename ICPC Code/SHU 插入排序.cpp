#include<iostream>
using namespace std;
#define TEST 0

inline void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void isort(int a[], int size)
{
	int i, j, temp;
	if (size <= 1) return;
	if (a[0] > a[1]) swap(a[0], a[1]);
	for (i = 2;i < size;i++) {
		temp = a[i];
		for (j = i - 1;j >= 0;j--) {
			if (a[j] < temp) {
				a[j + 1] =temp;
				break;
			}
			a[j + 1] = a[j];
		}
		if (j == -1) a[0] = temp;
#if TEST 
		for (int i = 0;i < size;i++) {
			if (i) cout << " ";
			cout << a[i];
		}
		cout << endl;
#endif
	}
}

int main()
{
	int array[] = { 9,7,2,5,7,19,3,5,8,43242,234,1,45,23 };
	int size = sizeof(array) / sizeof(int);
	isort(array, size);
	for (int i = 0;i < size;i++) {
		if (i) cout << " ";
		cout << array[i];
	}
	cout << endl;
	return 0;
}