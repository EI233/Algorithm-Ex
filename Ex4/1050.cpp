#include <algorithm>
#include <cstdio>
#include <cstring>
#define Inf (1 << 29)
using namespace std;
int n;
int a[110][110];
int dp[110][110][110];
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        scanf("%d", &a[i][j]);
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = 0; k < n; k++) {
          int x = 0;
          for (int l = i; l <= j; l++)
            x += a[k][l];
          if (dp[i][j][k - 1] >= 0)
            dp[i][j][k] = dp[i][j][k - 1] + x;
          else
            dp[i][j][k] = x;
          ans = max(ans, dp[i][j][k]);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}