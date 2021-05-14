#include <iostream>
#include <vector>

#define ll long long int

using namespace std;

ll getWays(int x, int y)
{
    vector<vector<ll>> table(x);

    for (int i = 0; i < x; ++i)
    {
        vector<ll> tmp(y);
        table[i] = tmp;
    }

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            if (i == 0 || j == 0)
                table[i][j] = 1;
            else
                table[i][j] = table[i - 1][j] + table[i][j - 1];
        }
    }

    return table[x - 1][y - 1];
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