#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int k_power = 2000;
const int k_n = 50;
int d[k_n];
int p[k_n];
int dp[k_power + 1];

inline void solve(const int &a, const int &b)
{
    for (int j = k_power; j >= b; j--)
    {
        dp[j] = max(dp[j], dp[j - b] + a);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", d + i);
    for (int i = 0; i < n; i++)
        scanf("%d", p + i);

    for (int i = 0; i < n; i++)
        solve(d[i], p[i]);

    printf("%d\n", dp[k_power - 1] + 1);
    return 0;
}
