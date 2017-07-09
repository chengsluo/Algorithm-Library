#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int num[1000001];
int main(int argc, char const *argv[]) {
  int n, c;
  int ct;
  while (scanf("%d%d", &n, &c) == 2) {
    for (int i = 0; i < n; i++) {
      scanf("%d", num + i);
    }
    ct = 1;
    for (int i = 1; i < n; i++) {
      if (num[i] - num[i - 1] <= c)
        ct++;
      else
        ct = 1;
    }
    printf("%d\n", ct);
  }
  return 0;
}
