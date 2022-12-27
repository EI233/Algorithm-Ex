#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int c[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
char D[4] = {'r', 'd', 'u', 'l'};
int book[3700000];
int C[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

struct node
{
    int pos;
    int step;
    int state[10];
    int HMD;
    int cantor;
    bool operator<(const node h) const
    {
        return step + HMD > h.step + h.HMD;
    }
};

struct yun
{
    int Node;
    int dis;
} path[3700000];

int is_solve(int a[])
{
    int i, j, ans = 0;
    for (i = 0; i < 8; i++)
        for (j = i + 1; j < 9; j++)
        {
            if (a[i] == 9 || a[j] == 9)
                continue;
            if (a[j] < a[i])
                ans++;
        }

    if (ans & 1)
        return 1;
    else
        return 0;
}

int hmd(int ma[])
{
    int ans = 0, i;
    for (i = 0; i < 9; i++)
    {
        if (ma[i] == 9)
            continue;
        ans += fabs((int)((ma[i] - 1) / 3 - i / 3)) + fabs((int)(ma[i] - 1) % 3 - i % 3);
    }
    return ans;
}

int Cantor(int a[])
{
    int i, j, l, ans = 0;
    for (i = 0; i < 8; i++)
    {
        l = 0;
        for (j = i + 1; j < 9; j++)
            if (a[j] < a[i])
                l++;
        ans += C[8 - i] * l;
    }
    return ans;
}

void A_star(int pos, int a[])
{
    int i;
    priority_queue<node> Q;
    node st, en;
    for (i = 0; i < 9; i++)
        st.state[i] = a[i];
    st.pos = pos;
    st.HMD = hmd(st.state);
    st.cantor = Cantor(st.state);
    st.step = 0;
    Q.push(st);
    while (Q.size())
    {
        st = Q.top();
        Q.pop();
        if (st.cantor == 0)
        {
            int k = 0;
            int p[10000];
            for (i = 1; i <= st.step; i++)
            {
                p[i] = path[k].dis;
                k = path[k].Node;
            }
            for (i = st.step; i >= 1; i--)
                printf("%c", D[p[i]]);
            printf("\n");
            return;
        }
        int x = st.pos / 3;
        int y = st.pos % 3;
        for (i = 0; i < 4; i++)
        {
            int dx = x + c[i][0];
            int dy = y + c[i][1];
            int dz = dx * 3 + dy;
            if (dx < 0 || dy < 0 || dx > 2 || dy > 2)
                continue;

            for (int j = 0; j < 9; j++)
                en.state[j] = st.state[j];
            swap(en.state[dz], en.state[st.pos]);

            int kk = Cantor(en.state);

            if (book[kk])
                continue;

            book[kk] = 1;
            en.cantor = kk;
            en.pos = dz;

            en.step = st.step + 1;

            en.HMD = hmd(en.state);
            path[kk].dis = i;
            path[kk].Node = st.cantor;

            Q.push(en);
        }
    }
}

int main()
{
    char str[100];
    gets_s(str, 100);
    int puzzle[10], pos;
    int k = 0, i;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            if (str[i] == 'x')
            {
                puzzle[k++] = 9;
                pos = k - 1;
            }
            else
                puzzle[k++] = str[i] - '0';
        }
    }
    if (is_solve(puzzle))
        printf("unsolvable\n");
    else
        A_star(pos, puzzle);
}