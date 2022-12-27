#include <cstdio>
#include <cstring>
using namespace std;
int n, m, s, num;
const int maxn = 110;
double V, dis[maxn];
struct edge
{
    int u, v;
    double cost, w;
} e[220];
void addv(int a, int b, double ra, double ca)
{
    e[num].u = a;
    e[num].v = b;
    e[num].cost = ca;
    e[num++].w = ra;
}
bool bellman()
{
    dis[s] = V;
    for (int i = 1; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < num; j++)
        {
            int u = e[j].u;
            int v = e[j].v;
            if (dis[v] < (dis[u] - e[j].cost) * e[j].w)
            {
                dis[v] = (dis[u] - e[j].cost) * e[j].w;
                flag = true;
            }
        }
        if (!flag)
            return false;
    }
    for (int i = 0; i < num; i++)
    {
        if (dis[e[i].v] < (dis[e[i].u] - e[i].cost) * e[i].w)
            return true;
    }
    return false;
}
int main()
{
    while (~scanf("%d%d%d%lf", &n, &m, &s, &V))
    {
        num = 0;
        memset(dis, 0, sizeof(dis));
        while (m--)
        {
            int a, b;
            double ra, ca, rb, cb;
            scanf("%d%d%lf%lf%lf%lf", &a, &b, &ra, &ca, &rb, &cb);
            addv(a, b, ra, ca);
            addv(b, a, rb, cb);
        }
        if (bellman())
            printf("YES\n");
        else
            printf("NO\n");
    }
}