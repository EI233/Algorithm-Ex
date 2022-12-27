#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, m;
int f[30], d[30], LeftY[30], t[30], wait[30], tmp[30], maxz, max1;

void UpdateFunc()
{
    for (int i = 0; i < n; i++)
        wait[i] = tmp[i];
}
void FishFunc()
{
    memset(wait, 0, sizeof(wait));
    maxz = -1;
    int LTime = 0;
    int YTime;
    for (int i = 0; i < n; i++) // ��iΪ���һ������
    {
        max1 = 0;
        memset(tmp, 0, sizeof(tmp));
        YTime = m - LTime;
        for (int j = 0; j < n; j++)
            LeftY[j] = f[j];
        while (true) // ÿ�ζ���ʣ�������ĳ������в���
        {
            if (YTime < 5)
                break;
            int Max = -1;
            int Lake_id;
            for (int j = 0; j <= i; j++)
            {
                if (LeftY[j] > Max)
                {
                    Max = LeftY[j];
                    Lake_id = j;
                }
            }
            if (Max == 0)
            {
                tmp[0] += YTime / 5 * 5;
                break;
            }
            tmp[Lake_id] += 5;
            max1 += LeftY[Lake_id];
            LeftY[Lake_id] -= d[Lake_id];
            if (LeftY[Lake_id] < 0)
                LeftY[Lake_id] = 0;
            YTime -= 5;
        }
        if (max1 > maxz) // �����iΪ���ĳ������������i-1Ϊ���ĳ�������Ҫ�࣬�������ÿ������ͣ����ʱ��
        {
            maxz = max1;
            UpdateFunc();
        }
        else if (max1 == maxz) // ���������ͬ��
        {
            for (int j = 0; j < n; j++)
            {
                if (tmp[j] < wait[j])
                    break;
                if (tmp[j] > wait[j])
                    UpdateFunc();
            }
        }
        LTime += t[i]; // ��·�ϻ��ѵ�ʱ���t[i]
        if (LTime > m)
            break;
    }
    cout << wait[0];
    for (int i = 1; i < n; i++)
        cout << ", " << wait[i];
    cout << endl << "Number of fish expected: " << maxz << endl << endl;
}
int main()
{
    while (~scanf("%d", &n) && n)
    {
        scanf("%d", &m);
        m *= 60;
        for (int i = 0; i < n; i++)
            scanf("%d", &f[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &d[i]);
        for (int i = 0; i < n - 1; i++)
        {
            scanf("%d", &t[i]);
            t[i] *= 5;
        }
        FishFunc();
    }
    return 0;
}