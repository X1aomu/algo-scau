#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
//#include <cstdio>
#include <cstdlib>
#include <cmath>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

map<long long, long long> m;

long long solve(const long long &n)
{
    if (3 == n) return 1;
    if (3 > n) return 0;
    else
    {
        if (m.find(n) != m.end()) return m[n];
        else
        {
            return m[n] = solve(n/2) + solve((n+1)/2);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    while (n != 0)
    {
        cout << solve(n) << "\n";
        cin >> n;
    }
    return 0;
}
