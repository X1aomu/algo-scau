#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int k_ugly = 1400;
const int k_max = 100000000;
unsigned long r[k_max];
unsigned long ugly[k_ugly];

typedef pair<int, int> mypair;

int main()
{
    priority_queue<mypair, vector<mypair>, greater<mypair> > q;
    q.push(make_pair(1, 2));
    for (int i = 0; i < k_ugly; i++)
    {
        switch(q.top().second)
        {
            case 2: q.push(make_pair(q.top().first * 2, 2));
            case 3: q.push(make_pair(q.top().first * 3, 3));
            case 5: q.push(make_pair(q.top().first * 5, 5));
        }
        ugly[i] = q.top().first;
        q.pop();
    }

    int count = 0;
    for (int i = 0; i < k_ugly; i++)
    {
        for (unsigned long j = ugly[i] + 1; j < ugly[i+1]; j++)
        {
            if (count < k_max)
                r[count++] = j;
            else break;
        }
    }

    int t;
    int n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%lu\n", r[n - 1]);
    }
    return 0;
}
