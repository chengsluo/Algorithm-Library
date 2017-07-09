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

sort - 排序函数
int a[100];
sort(a, a+n);
vector<int> v;
sort(v.begin(), v.end(),cmp);//1

bool cmp(int  a, int b) {//2
    return a > b; //降序排序
}
sort(a, a+n, cmp);

unique - 去除重复元素（排序之后）
int a[..];//1
sort(a, a+n);
int cnt = unique(a, a+n) - a;
vector<int> v;//2
sort(v.begin(), v.end());
v.erase(unique(v.begin(),v.end()), v.end());

reverse - 翻转数组
int a[..];//1
reverse(a, a+n);
string s;//2
reverse(s.begin(), s.end());

lower_bound - 查找有序数组第一个 >=x 的数的位置
int a[4] = {1,3,3,4};
int* p = lower_bound(a, a+4, x);
//如果x > 4 (没找到) , 返回 p 将等于 a+4

相应的，还有一个upper_bound的函数。
查找第一个 > x 的数的位置

如何区分这两个函数的作用？


