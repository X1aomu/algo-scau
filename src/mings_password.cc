#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int k_max = 12;
int c[k_max];
int n, m;
int result;

int prime[] =
{
    0,
    0, 1, 1, 0, 1, 0, 1, 0, 0, 0,
    1, 0, 1, 0, 0, 0, 1, 0, 1, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
    1, 0, 0, 0, 0, 0
};

void solve(const int &p)
{
    if (p == n) result++;
    else if (p < m - 1)
    {
        for (int i = 0; i <= 9; i++)
        {
            c[p] = i;
            solve(p + 1);
        }
    }
    else
    {
        int sum = 0;
        for (int  i = p - 1; i > p - m; i--)
            sum += c[i];
        for (int i = 0; i <= 9; i++)
        {
            if (prime[sum + i])
            {
                c[p] = i;
                solve(p + 1);
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        result = 0;
        solve(0);
        printf("%d\n", result);
    }
    return 0;
}
