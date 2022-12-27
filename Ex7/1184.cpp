#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;
struct NODE
{
    string s;
    int step;
};
string ed, chg;
queue<NODE> q;
map<string, bool> mp;

int BFS(NODE st)
{
    q.push(st);
    while (!q.empty())
    {
        NODE cur = q.front(), nxt;
        q.pop();
        bool flag = true;
        for (int i = 0; i < 6; i++)
        {
            if (cur.s[i] != ed[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return cur.step;
        chg = cur.s;
        int idx = cur.s[6];
        if (idx != 0)
        {
            swap(chg[0], chg[idx]);
            if (!mp.count(chg))
            {
                nxt.s = chg;
                nxt.step = cur.step + 1;
                q.push(nxt);
                mp[nxt.s] = true;
            }
        }
        chg = cur.s;
        idx = cur.s[6];
        if (idx != 5)
        {
            swap(chg[5], chg[idx]);
            if (!mp.count(chg))
            {
                nxt.s = chg;
                nxt.step = cur.step + 1;
                q.push(nxt);
                mp[nxt.s] = true;
            }
        }

        chg = cur.s;
        idx = cur.s[6];
        if (chg[idx] != '9' && chg[idx] != ed[idx])
        {
            chg[idx] += 1;
            if (!mp.count(chg))
            {
                nxt.s = chg;
                nxt.step = cur.step + 1;
                q.push(nxt);
                mp[nxt.s] = true;
            }
        }

        chg = cur.s;
        idx = cur.s[6];
        if (chg[idx] != '0' && chg[idx] != ed[idx])
        {
            chg[idx] -= 1;
            if (!mp.count(chg))
            {
                nxt.s = chg;
                nxt.step = cur.step + 1;
                q.push(nxt);
                mp[nxt.s] = true;
            }
        }
        chg = cur.s;
        idx = cur.s[6];
        if (idx != 0)
        {
            if (idx == 5)
                chg[6] -= 1;
            else if (chg[idx] == ed[idx])
                chg[6] -= 1;
            if (!mp.count(chg))
            {
                nxt.s = chg;
                nxt.step = cur.step + 1;
                q.push(nxt);
                mp[nxt.s] = true;
            }
        }
        chg = cur.s;
        idx = cur.s[6];
        if (idx != 5)
        {
            if (idx == 0)
                chg[6] += 1;
            else if (chg[idx] == ed[idx])
                chg[6] += 1;
            if (!mp.count(chg))
            {
                nxt.s = chg;
                nxt.step = cur.step + 1;
                q.push(nxt);
                mp[nxt.s] = true;
            }
        }
    }
    return 0;
}

int main()
{
    NODE st;
    puts("Input:");
    while (cin >> st.s >> ed)
    {
        while (!q.empty())
            q.pop();
        mp.clear();
        st.s += '\0';
        st.step = 0;
        mp[st.s] = true;
        int ans = BFS(st);
        puts("Output:");
        printf("%d\n", ans);
    }
}