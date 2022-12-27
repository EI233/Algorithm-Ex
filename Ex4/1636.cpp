#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define N 205
using namespace std;
int t;
int n, m;
int anum, bnum;
int map[N][N];
int dp[N][N];
int vis[2][N];
void DFS(int side, int temp)
{
    vis[side][temp] = 1;
    if (side == 0)
    {
        anum++;
        for (int i = 1; i <= n; i++)
        {
            if (map[temp][i] && !vis[1][i])
            {
                DFS(1, i);
            }
        }
    }
    else
    {
        bnum++;
        for (int i = 1; i <= n; i++)
        {
            if (map[i][temp] && !vis[0][i])
            {
                DFS(0, i);
            }
        }
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(map, 0, sizeof(map));
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            map[x][y] = 1;
        }
        int a[N], b[N];
        int k = 0;

        for (int i = 1; i <= n; i++)
        {
            if (vis[0][i])
                continue;
            anum = 0;
            bnum = 0;
            DFS(0, i);
            a[k] = anum;
            b[k++] = bnum;
        }
        for (int i = 1; i <= n; i++)
        {

            if (vis[1][i])
                continue;
            anum = 0;
            bnum = 0;
            DFS(1, i);
            a[k] = anum;
            b[k++] = bnum;
        }
        dp[0][0] = 1;
        for (int i = 0; i < k; i++)
        {
            for (int j = n / 2; j >= a[i]; j--)
            {
                for (int h = n / 2; h >= b[i]; h--)
                {
                    if (dp[j][h] || dp[j - a[i]][h - b[i]] == 1)
                        dp[j][h] = 1;
                }
            }
        }
        for (int i = n / 2; i >= 0; i--)
        {
            if (dp[i][i] == 1)
            {
                cout << i << endl;
                break;
            }
        }
    }
}