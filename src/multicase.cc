#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

long long solve(int a, int b)
{
    long long r;
    while ((r = a % b) != 0)
    {
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    //ios::sync_with_stdio(false);
    int n;
    long long a, b;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", (a*b)/solve(a, b));
    }
    puts("group 1 done");

    scanf("%lld %lld", &a, &b);
    while (!(a == 0 && b == 0))
    {
        printf("%lld\n", (a*b)/solve(a, b));
        scanf("%lld %lld", &a, &b);
    }
    puts("group 2 done");

    while (scanf("%lld %lld", &a, &b) == 2)
    {
        printf("%lld\n", (a*b)/solve(a, b));
    }
    puts("group 3 done");
    return 0;
}
