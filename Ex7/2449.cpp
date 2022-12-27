#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int maxn = 1005;
const int maxe = 100005;

struct State
{
    int f;
    int g;
    int u;
    bool operator<(const State b) const
    {
        if (f == b.f)
            return g > b.g;
        return f > b.f;
    }
};
struct Edge
{
    int v;
    int w;
    int ne;
} edge[maxe], reedge[maxe];
int head[maxn], rehead[maxn];
int dis[maxn], vis[maxn];
int n, m;
int cot;
int s, t, k;

void init()
{
    cot = 0;
    memset(head, -1, sizeof(head));
    memset(rehead, -1, sizeof(rehead));
}

void addedge(int u, int v, int w)
{
    edge[cot].v = v;
    edge[cot].w = w;
    edge[cot].ne = head[u];
    head[u] = cot;
    reedge[cot].v = u;
    reedge[cot].w = w;
    reedge[cot].ne = rehead[v];
    rehead[v] = cot++;
}

void SPFA()
{
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    int u, v;
    q.push(t);
    vis[t] = true;
    dis[t] = 0;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int i = rehead[u]; ~i; i = reedge[i].ne)
        {
            v = reedge[i].v;
            if (dis[v] > dis[u] + reedge[i].w || dis[v] == -1)
            {
                dis[v] = dis[u] + reedge[i].w;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        vis[u] = false;
    }
}

int Astart()
{
    if (s == t)
        k++;
    if (dis[s] == -1)
        return -1;
    int cnt = 0;
    priority_queue<State> q;
    State a, b;
    a.g = 0;
    a.u = s;
    a.f = a.g + dis[a.u];
    q.push(a);
    while (!q.empty())
    {
        b = q.top();
        q.pop();
        if (b.u == t)
        {
            cnt++;
            if (cnt == k)
                return b.g;
        }
        for (int i = head[b.u]; ~i; i = edge[i].ne)
        {
            a.g = b.g + edge[i].w;
            a.u = edge[i].v;
            a.f = a.g + dis[a.u];
            q.push(a);
        }
    }
    return -1;
}

int main()
{
    int u, v, w;
    while (scanf("%d %d", &n, &m) == 2)
    {
        init();
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
        }
        scanf("%d %d %d", &s, &t, &k);
        SPFA();
        printf("%d\n", Astart());
    }
    return 0;
}