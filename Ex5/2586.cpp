
#include <cstdio>
#include <iostream>
typedef long long ll;
using namespace std;
int main()
{ /**/
    ll s, d, ans;
    while (cin >> s >> d)
    {
        if (d > 4 * s)
            ans = 10 * s - 2 * d;
        else if (2 * d > 3 * s)
            ans = 8 * s - 4 * d;
        else if (3 * d > 2 * s)
            ans = 6 * s - 6 * d;
        else if (4 * d > s)
            ans = 3 * s - 9 * d;
        else
            ans = -1;
        if (ans > 0)
            printf("%lld\n", ans);
        else
            puts("Deficit");
    }
    return 0;
}