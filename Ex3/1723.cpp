
//
// Created by zxc02 on 2022/11/21.
// Time is 20:46
#include "algorithm"
#include "cmath"
#include "cstdio"

using namespace std;

bool cmp(int a, int b) { return a < b; }

int main() {
  freopen("input.txt", "r", stdin);
  int n, i, x_mid, y_mid, count = 0;
  int *x, *y;
  scanf("%d", &n);
  x = new int[n];
  y = new int[n];
  for (i = 0; i < n; i++)
    scanf("%d %d", &x[i], &y[i]);
  sort(y, y + n, cmp);
  sort(x, x + n, cmp);
  for (i = 0; i < n; i++)
    x[i] -= i;
  sort(x, x + n, cmp);
  x_mid = x[n / 2];
  y_mid = y[n / 2];
  for (i = 0; i < n; i++)
    count += abs(x[i] - x_mid) + abs(y[i] - y_mid);
  printf("%d\n", count);
  delete[] x, delete[] y;
  return 0;
}