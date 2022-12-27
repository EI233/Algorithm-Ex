#include <algorithm>
#include <cstdio>
using namespace std;
#define ms(x, n) memset(x, n, sizeof(x));
typedef long long LL;
const LL maxn = 1e5 + 10;

int n, x[maxn];
LL m;
int findi(int s, int r) {
  int l = 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (x[mid] >= s)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
bool check(int k) {
  LL sum = 0;
  for (int j = 1; j <= n; j++) {
    sum += (LL)j - findi(x[j] - k, j);
    if (sum >= m)
      return true;
  }
  return false;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++)
      scanf("%d", &x[i]);
    m = (LL)(n * (n - 1) / 2 + 1) / 2;
    sort(x + 1, x + 1 + n);
    int l = 0, r = x[n];
    while (l < r) {
      int mid = (l + r) >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%d\n", l);
  }
  return 0;
}