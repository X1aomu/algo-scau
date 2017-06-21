#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int k_max = 200000;

int main()
{
    int man[k_max];
    int dragon[k_max];
    int pm, pd, result;
    int m, d;
    scanf("%d%d", &d, &m);
    while (!(m == 0 && d == 0))
    {
        for (int i = 0; i < d; i++)
        {
            scanf("%d", dragon + i);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", man + i);
        }
        sort(man, man + m);
        sort(dragon, dragon + d);
        pm = 0, pd = 0;
        result = 0;
        while (pm < m && pd < d)
        {
            if (man[pm] >= dragon[pd])
            {
                result += man[pm];
                pm++; pd++;
            }
            else pm++;
        }
        if (pd == d) printf("%d\n", result);
        else printf("Loowater is doomed!\n");

        scanf("%d%d", &d, &m);
    }
    return 0;
}
