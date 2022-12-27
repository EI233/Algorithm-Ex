#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
typedef struct node
{
    int state;
    int cost;
} NODE;

int change[16] = {0xC800, 0xE400, 0x7200, 0x3100, 0x8C80, 0x4E40, 0x2720, 0x1310,
                  0x08C8, 0x04E4, 0x0272, 0x0131, 0x008C, 0x004E, 0x0027, 0x0013};
bool visited[65536];

int BFS(int state)
{
    if (state == 0 || state == 0xFFFF)
        return 0;
    memset(visited, false, sizeof(visited));
    queue<NODE> q;
    NODE curr, next;
    curr.state = state, curr.cost = 0;
    q.push(curr);
    visited[state] = true;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        for (int i = 0; i < 16; ++i)
        {
            next.state = curr.state ^ change[i];
            next.cost = curr.cost + 1;
            if (visited[next.state])
                continue;
            if (next.state == 0 || next.state == 0xFFFF)
                return next.cost;
            q.push(next);
            visited[next.state] = true;
        }
    }
    return -1;
}
int main()
{
    char c;
    int state = 0, ans;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            state <<= 1;
            if ((c = getchar()) == 'b')
                state += 1;
        }
        getchar();
    }
    if ((ans = BFS(state)) == -1)
        printf("Impossible\n");
    else
        printf("%d\n", ans);
    return 0;
}
