#include <iostream>
#include <cmath>

using namespace std;

int square(int a) {
    return a * a;
}

void solve(int a) {
    int big;
    double another;
    big = a * a;
    while (big > a)
    {
        another = sqrt(big * big - a * a);
        if ((int)another == another)
            cout << big << "," << another << "\n";
        big--;
    }
    int small = (int)sqrt(a) - 1;
    big = a - 1;
    while (big > small)
    {
        another = sqrt(a*a - big*big);
        if ((int)another == another && big > another)
            cout << big << "," << another << "\n";
        big--;
    }
}

int main() {
    int n;
    cin >> n;
    static int a = 0;
    cin >> a;
    solve(a);
    n--;
    while(n--) {
        cout << "\n";
        cin >> a;
        solve(a);
    }
    return 0;
}
