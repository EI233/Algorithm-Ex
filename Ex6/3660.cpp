#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[105][105];
int n;
void floyd()
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (j = 1; j <= n; j++)
            for (i = 1; i <= n; i++)
                if (a[i][k] && a[k][j] && i != j)
                    a[i][j] = 1;
}
int main()
{
    int m, i, j;
    scanf("%d%d", &n, &m);
    memset(a, 0, sizeof(a));
    int x, y;
    while (m--)
    {
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
    }
    floyd();
    int counte = 0, sum = 0;
    for (i = 1; i <= n; i++)
    {
        counte = 0;
        for (j = 1; j <= n; j++)
            if (a[i][j] || a[j][i])
                counte++;
        if (counte == n - 1)
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}