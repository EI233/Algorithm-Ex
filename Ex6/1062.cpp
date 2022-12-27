#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 102;
const int INF = 0X3F3F3F3F;
int m, n;
int price[maxn];
int level[maxn];
int map[maxn][maxn];
bool vis[maxn];
int d[maxn];
void dijkstra()
{
    memset(d, INF, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int v = -1;
        int mins = INF;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && mins > d[j])
            {
                v = j;
                mins = d[j];
            }
        }
        if (v == -1)
            break;
        vis[v] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && d[j] > d[v] + map[v][j])
            {
                d[j] = d[v] + map[v][j];
            }
        }
    }
}
int main()
{
    puts("Input:");
    while (cin >> m >> n)
    {
        memset(map, INF, sizeof(map));
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> price[i] >> level[i] >> x;
            for (int j = 0; j < x; j++)
            {
                int num, discount;
                cin >> num >> discount;
                map[i][num] = discount;
            }
        }
        int mins = INF;
        for (int i = 0; i <= m; i++)
        {
            memset(vis, 0, sizeof(vis));
            for (int j = 1; j <= n; j++)
                if (level[1] - m + i > level[j] || level[1] + i < level[j])
                    vis[j] = true;
            dijkstra();
            for (int j = 1; j <= n; j++)
                mins = min(mins, price[j] + d[j]);
        }
        puts("Output:");
        cout << mins << endl;
    }
    return 0;
}
