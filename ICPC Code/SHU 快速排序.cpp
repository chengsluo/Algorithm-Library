#include<iostream>
using namespace std;
#define TEST 0
inline void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void qsort(int a[], int left,int right)//µ›πÈ–Œ Ω
{
	int pivot = a[right], l = left, r = right;
	while (l < r) {
		swap(a[l], a[r]);
		while (l<r&&a[r]>pivot) --r;
		while (l < r&&a[l] <= pivot) ++l;
	}
	swap(a[left], a[r]);
	if (left < r - l) qsort(a, left, r - l);
	if (r + l < right) qsort(a, r + 1, right);

	//if ((left + right) % 2 ) {
	//	int mid = (left + right) / 2;
	//	for (int i = left;i <=right;i++) {
	//		if (a[i] > a[mid]) swap(a[i], a[mid + 1 + i - left]);
	//	}
	//	if (right - left > 0) {
	//		qsort(a, left, mid);
	//		qsort(a, mid + 1, right);
	//	}
	//}
	//else {
	//	int mid = (left + right) / 2;
	//	for (int i = left;i <mid;i++) {
	//		if (a[i] > a[mid + 1 + i - left]) swap(a[i], a[mid + 1 + i - left]);
	//	}
	//	if (right - left > 0) {
	//		qsort(a, left, mid);
	//		qsort(a, mid + 1, right);
	//	}
	//}
}

int main()
{
	int array[] = { 9,7,2,5,7,19,3,5,8,43242,234,1,45,23 };
	int size = sizeof(array) / sizeof(int);
	qsort(array, 0,size-1);
	for (int i = 0;i < size;i++) {
		if (i) cout << " ";
		cout << array[i];
	}
	cout << endl;
	return 0;
}

#if TEST 
for (int i = 0;i < size;i++) {
	if (i) cout << " ";
	cout << a[i];
}
cout << endl;
#endif