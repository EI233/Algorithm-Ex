/**
 * @file 2228.cpp
 * @brief
 * @author Xincai Zhu (pygonebe@outlook.com)
 * @version 1.0
 * @date 2022-12-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 3835;
int f[2][MAXN][2], w[MAXN], ans = 0; // f[i][j][0]代表某天前i小时睡了j小时，且第i小时醒着；
// f[i][j][1]表示前i小时睡了j小时，且第i小时正在熟睡！
//加了一个滚动数组的优化！
int n, m, k;
int main()
{
    puts("Input:");
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    if (m == 0)
    {
        puts("0");
        return 0;
    }
    memset(f, -0x3f, sizeof(f));
    f[1][1][1] = 0;
    f[1][0][0] = 0; //初始化！
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i & 1][j][0] = max(f[(i - 1) & 1][j][1], f[(i - 1) & 1][j][0]); //对于没熟睡的转移
            if (j >= 1)
                f[i & 1][j][1] = max(f[(i - 1) & 1][j - 1][0], f[(i - 1) & 1][j - 1][1] + w[i]); //熟睡了的转移
        }
    }
    ans = max(f[n & 1][m][1], f[n & 1][m][0]);
    memset(f, -0x3f, sizeof(f));
    f[1][1][1] = w[1]; //强行让牛在第一个小时就熟睡！这是前文规划中没有的部分；
    for (int i = 2; i <= n; i++)
    { //执行第2次dp，对上面已经执行过的dp作补充！
        for (int j = 0; j <= m; j++)
        {
            f[i & 1][j][0] = max(f[(i - 1) & 1][j][1], f[(i - 1) & 1][j][0]);
            if (j >= 1)
                f[i & 1][j][1] = max(f[(i - 1) & 1][j - 1][0], f[(i - 1) & 1][j - 1][1] + w[i]);
        }
    }
    ans = max(ans, f[n & 1][m][1]); //两次取最优！
    puts("Output:");
    printf("%d", ans);
    puts("");
    return 0;
}