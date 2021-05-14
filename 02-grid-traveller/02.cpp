#include <iostream>
#include <map>

#define ll long long int

using namespace std;

ll getWaysHelper(int x, int y, map<pair<int, int>, ll> &f)
{
    if (x <= 0 || y <= 0)
        return 0;

    pair<int, int> p = make_pair(x, y);

    if (f[p] != 0)
        return f[p];

    if (x == 1 && y == 1)
        return 1;

    ll ways = 0;
    ways += getWaysHelper(x - 1, y, f);
    ways += getWaysHelper(x, y - 1, f);

    f[p] = ways;
    return ways;
}

ll getWays(int x, int y)
{
    map<pair<int, int>, ll> f;

    if (x > y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }

    return getWaysHelper(x, y, f);
}

int main()
{

    cout << getWays(1, 1) << endl;
    cout << getWays(2, 3) << endl;
    cout << getWays(3, 2) << endl;
    cout << getWays(3, 3) << endl;
    cout << getWays(18, 18) << endl;

    return 0;
}