#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int male = 1, female = 0;

long long solve(const int &m, const int &f, const int &pp, const int &p)
{
    if (m < 0 || f < 0) return 0;
    else if (f == 0) return 1;
    else if (m == 0) // f != 0
    {
        if (f > 1) return 0;
        else
        {
            if (p == female) return 0;
            else return 1;
        }
    }
    else
    {
        if (pp == female && p == female)
            return solve(m - 1, f, p, male);
        else
            return solve(m, f - 1, p, female) + solve(m - 1, f, p, male);
    }
}

long long A(const int &n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int m, f;
        scanf("%d %d", &m, &f);
        if (f > m * 2) printf("0\n");
        else printf("%lld\n", (solve(m - 1, f, -1, male) + solve(m, f - 1, female, female)) * A(m) * A(f));
    }
    return 0;
}
