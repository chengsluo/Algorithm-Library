#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef push_back pb;
typedef push_back pb;
typedef int Elem;

vector<Elem> vec;
vec.push_back(Elem);
vec[i];

queue<Elem>que;
q.emtry();
q.front();
q.push(Elem);
q.pop();

stack<Elem>sta;
sta.emtry();
sta.top();
sta.push(Elem);
sta.pop();

sort - ������
int a[100];
sort(a, a+n);
vector<int> v;
sort(v.begin(), v.end(),cmp);//1

bool cmp(int  a, int b) {//2
    return a > b; //��������
}
sort(a, a+n, cmp);

unique - ȥ���ظ�Ԫ�أ�����֮��
int a[..];//1
sort(a, a+n);
int cnt = unique(a, a+n) - a;
vector<int> v;//2
sort(v.begin(), v.end());
v.erase(unique(v.begin(),v.end()), v.end());

reverse - ��ת����
int a[..];//1
reverse(a, a+n);
string s;//2
reverse(s.begin(), s.end());

lower_bound - �������������һ�� >=x ������λ��
int a[4] = {1,3,3,4};
int* p = lower_bound(a, a+4, x);
//���x > 4 (û�ҵ�) , ���� p ������ a+4

��Ӧ�ģ�����һ��upper_bound�ĺ�����
���ҵ�һ�� > x ������λ��

����������������������ã�


