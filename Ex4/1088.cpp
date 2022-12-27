#include <iostream>
using namespace std;
int to[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
int high[105][105];
int maxLen[105][105];
bool check(int x, int y)
{
    if (x >= 1 && y >= 1 && x <= n && y <= m)
        return 1;
    else
        return 0;
}

int dfs(int x, int y)
{
    if (maxLen[x][y] != 0) // �˳��߽� ��������Ѿ�������������������Ǳ߽�
        return maxLen[x][y];

    maxLen[x][y] = 1; // ��͵ĵ����1;
    for (int i = 0; i < 4; i++)
    { // ������������
        int x1 = x + to[i][0];
        int y1 = y + to[i][1];
        if (check(x1, y1) && high[x1][y1] < high[x][y])
        { // �ж��ܷ����»�
            maxLen[x][y] = max(dfs(x1, y1) + 1, maxLen[x][y]);
        }
    }
    return maxLen[x][y]; // �����������ĵ㣬��������������
}
int main()
{

    cin >> n >> m;

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> high[i][j];
            maxLen[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans = max(ans, dfs(i, j)); // ����ÿһ���㣬�����ҳ����ֵ
        }
    }
    cout << ans << endl;
    return 0;
}