#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

using namespace std;

typedef struct custom
{
    int time;
    int vip;
    char name[21];
    friend bool operator < (const custom &pep1, const custom &pep2);
} custom;

bool operator < (const custom &pep1, const custom &pep2)
{
    return pep1.vip < pep2.vip;
}

const int k_max = 100000;

int main()
{
    custom  temp;
    queue<custom> q;
    priority_queue<custom, vector<custom> > pq;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %s", &temp.time, &temp.vip, temp.name);
        temp.vip = temp.vip * k_max - i;
        q.push(temp);
    }

    int time = 0;
    while (!q.empty())
    {
        while (!q.empty() && q.front().time <= time)
        {
            pq.push(q.front());
            q.pop();
        }
        if (!pq.empty())
            {printf("%s\n", pq.top().name); pq.pop();}
        time += 5;
    }
    while (!pq.empty())
    {
        printf("%s\n", pq.top().name); pq.pop();
    }
    return 0;
}
