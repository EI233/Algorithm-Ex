#include <algorithm>
#include <cstdio>
#include <cstring>
#define me(a) memset(a, 0, sizeof(a))
using namespace std;
int dp[115][70][70], maze[105], status[70], num[70], m, n, len;
char str[111];
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        me(dp);
        me(num);
        me(maze);
        me(status);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", str);
            for (int j = 0; j < m; j++)
            {
                if (str[j] == 'H')
                {
                    maze[i] += (1 << j);
                }
            }
        }
        len = 1;
        for (int i = 0; i < (1 << m); i++)
        {
            if (!(i & (i << 1)) && !(i & (i << 2)))
            {
                int k = i, sum = 0;
                while (k)
                {
                    if (k & 1)
                        sum++;
                    k >>= 1;
                }
                num[len] = sum;
                status[len++] = i;
            }
        }

        for (int i = 1; i < len; i++)
        {
            if (!(maze[1] & status[i]))
            {
                dp[1][i][1] = num[i];
            }
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < len; j++)
            {
                if (status[j] & maze[i])
                    continue;
                for (int k = 1; k < len; k++)
                {
                    if (status[j] & status[k])
                        continue;
                    if (status[k] & maze[i - 1])
                        continue;
                    for (int t = 1; t < len; t++)
                    {
                        if (status[t] & status[j])
                            continue;
                        if (status[t] & status[k])
                            continue;
                        if (status[t] & maze[i - 2])
                            continue;
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][t] + num[j]);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < len; i++)
            for (int j = 1; j < len; j++)
                ans = max(ans, dp[n][i][j]);
        printf("%d\n", ans);
    }
    return 0;
}