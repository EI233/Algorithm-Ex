#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;
int mp[1020][1020];
int dis[1010];
int vis[1010];
int n, m;
void init()
{
    memset(vis, 0, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    memset(mp, inf, sizeof(mp));
}
void Dijkstra(int s, int e)
{
    dis[s] = 0;
    for (int k = 1; k <= n; k++)
    {
        int minw = inf;
        int minv;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] < minw && vis[i] == 0)
            {
                minw = dis[i];
                minv = i;
            }
        }
        vis[minv] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 1)
                continue;
            dis[i] = min(dis[i], dis[minv] + mp[minv][i]);
        }
    }
    cout << dis[e] << endl;
}
int main()
{
    cin >> m >> n;
    init();
    int a, b, w;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        if (w < mp[a][b])
        {
            mp[a][b] = w;
            mp[b][a] = w;
        }
    }
    Dijkstra(1, n);
    return 0;
}
