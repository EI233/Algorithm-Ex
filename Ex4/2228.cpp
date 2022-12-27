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
int f[2][MAXN][2], w[MAXN], ans = 0; // f[i][j][0]����ĳ��ǰiСʱ˯��jСʱ���ҵ�iСʱ���ţ�
// f[i][j][1]��ʾǰiСʱ˯��jСʱ���ҵ�iСʱ������˯��
//����һ������������Ż���
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
    f[1][0][0] = 0; //��ʼ����
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i & 1][j][0] = max(f[(i - 1) & 1][j][1], f[(i - 1) & 1][j][0]); //����û��˯��ת��
            if (j >= 1)
                f[i & 1][j][1] = max(f[(i - 1) & 1][j - 1][0], f[(i - 1) & 1][j - 1][1] + w[i]); //��˯�˵�ת��
        }
    }
    ans = max(f[n & 1][m][1], f[n & 1][m][0]);
    memset(f, -0x3f, sizeof(f));
    f[1][1][1] = w[1]; //ǿ����ţ�ڵ�һ��Сʱ����˯������ǰ�Ĺ滮��û�еĲ��֣�
    for (int i = 2; i <= n; i++)
    { //ִ�е�2��dp���������Ѿ�ִ�й���dp�����䣡
        for (int j = 0; j <= m; j++)
        {
            f[i & 1][j][0] = max(f[(i - 1) & 1][j][1], f[(i - 1) & 1][j][0]);
            if (j >= 1)
                f[i & 1][j][1] = max(f[(i - 1) & 1][j - 1][0], f[(i - 1) & 1][j - 1][1] + w[i]);
        }
    }
    ans = max(ans, f[n & 1][m][1]); //����ȡ���ţ�
    puts("Output:");
    printf("%d", ans);
    puts("");
    return 0;
}