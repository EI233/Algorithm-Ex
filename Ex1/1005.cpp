#include <cmath>
#include <cstdio>
using namespace std;
struct point
{
    double x, y;
};
point p[20001];
double res;
int main()
{
    int num, resp;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%lf %lf", &p[i].x, &p[i].y);
        res = (p[i].x * p[i].x + p[i].y * p[i].y) * (atan(1.0) * 4) / 100;
        resp = ceil(res);
        printf("Property %d: This property will begin eroding in year %d.\n", i + 1, (int)resp);
    }
    printf("END OF OUTPUT.");
}