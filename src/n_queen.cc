#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int n;
int c[14];
int result;

void solve(const int &cur)
{
    if (cur > n) result++;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            bool ok = true;
            c[cur] = i;
            for (int j = 1; j < cur; j++)
            {
                if (c[cur] == c[j] ||
                        cur + c[cur] == j + c[j] ||
                        cur - c[cur] == j - c[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                solve(cur + 1);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        result = 0;
        solve(1);
        printf("%d\n", result);
    }
    return 0;
}
