#include <iostream>

#define ll long long int

using namespace std;

ll getWays(int x, int y)
{
    if (x <= 0 || y <= 0)
        return 0;

    if (x == 1 && y == 1)
        return 1;

    ll ways = 0;
    ways += getWays(x - 1, y);
    ways += getWays(x, y - 1);

    return ways;
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