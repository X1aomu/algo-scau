#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

typedef struct comp {
    int order;
    int passes;
    int time;
    char name[21];
} comp;

comp c[500000];

bool cmp(const comp &a, const comp &b)
{
    if (a.passes != b.passes) return a.passes > b.passes;
    else if (a.time != b.time) return a.time < b.time;
    else return a.order < b.order;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        c[i].order = i;
        scanf("%d %d %s", &c[i].passes, &c[i].time, c[i].name);
    }
    sort(c, c + n, cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", c[i].name);
    }
    return 0;
}
