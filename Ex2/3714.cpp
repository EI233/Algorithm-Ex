//
// Created by zxc02 on 2022/11/14.
// Time is 19:25
#include "algorithm"
#include "cmath"
#include "cstdio"

using namespace std;

struct point {
  int x, y, f;
  bool operator<(const point &a) const { return x < a.x; }
} A[200005], temp[200005];

int num, loop;
const double inf = 1e9;

double dist(point a, point b) {
  if (a.f == b.f)
    return inf;
  double p = a.x - b.x, q = a.y - b.y;
  double ans = p * p + q * q;
  ans = pow(ans, 0.5);
  return ans;
}

double Func(int l, int r) {
  if (l >= r)
    return inf;
  int mid = (l + r) >> 1;
  double mid_x = A[mid].x;
  double res = min(Func(l, mid), Func(mid + 1, r));
  {
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
      temp[k++] = A[i++];
    while (i <= mid)
      temp[k++] = A[i++];
    while (j <= r)
      temp[k++] = A[j++];
    for (int p = 0, q = l; p < k; p++, q++)
      A[q] = temp[p];
  }
  int k = 0;
  for (int i = l; i <= r; i++)
    if (A[i].x >= mid_x - res && A[i].x <= mid_x + res)
      temp[k++] = A[i];
  for (int i = 0; i < k; i++)
    for (int j = i - 1; j >= 0 && temp[i].y - temp[j].y < res; j--)
      res = min(res, dist(temp[i], temp[j]));
  return res;
}

int main() {
  //	freopen("input.txt", "r", stdin);
  scanf("%d", &num);
  for (int i = 0; i < num; ++i) {
    scanf("%d", &loop);
    for (int j = 0; j < loop; ++j) {
      scanf("%d %d", &A[j].x, &A[j].y);
      A[j].f = 0;
    }
    for (int j = loop; j < 2 * loop; ++j) {
      scanf("%d %d", &A[j].x, &A[j].y);
      A[j].f = 1;
    }
    sort(A, A + 2 * loop);
    printf("%.3f\n", Func(0, 2 * loop - 1));
  }
  return 0;
}