#include <iostream>
#include <vector>

#define ll long long int

using namespace std;

ll fib(int n)
{
    vector<ll> table = {0, 1};

    for (int i = 2; i <= n; ++i)
        table.push_back(table[i - 1] + table[i - 2]);

    return table.back();
}

int main()
{

    cout << fib(6) << endl;
    cout << fib(7) << endl;
    cout << fib(8) << endl;
    cout << fib(50) << endl;

    return 0;
}