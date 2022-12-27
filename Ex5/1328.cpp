#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef struct
{
    double left;
    double right;
} Node;
Node s[1001];
bool cmp(Node s1, Node s2)
{
    return s1.right < s2.right;
}
int main()
{
    int i, n, d, x, y, sum, num = 1;
    double le;
    while (true)
    {
        sum = 1;
        cin >> n >> d;
        if (n == 0 && d == 0)
            break;
        for (i = 0; i < n; i++)
        {
            cin >> x >> y;
            if (y > d)
                sum = -1;
            le = sqrt(pow((float)d, 2) - pow((float)y, 2));
            s[i].left = x - le;
            s[i].right = x + le;
        }
        if (sum == -1)
        {
            cout << "Case " << num++ << ": " << sum << endl;
            continue;
        }
        sort(s, s + n, cmp);     // s已经按照线段右侧进行了排序
        double tmp = s[0].right; // 初始设置一个雷达
        for (i = 1; i < n; i++)
        {
            if (tmp >= s[i].left)
            {
                continue;
            }
            else
            {
                sum++;
                tmp = s[i].right;
            }
        }
        cout << "Case " << num++ << ": " << sum << endl;
    }
}
