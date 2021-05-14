#include <iostream>
#include <map>

#define ll long long int

using namespace std;

ll fib_helper(int n, map<int, ll> &f)
{
    if (f[n] != 0)
        return f[n];

    if (n < 2)
        return n;

    f[n] = fib_helper(n - 1, f) + fib_helper(n - 2, f);
    return f[n];
}

ll fib(int n)
{
    map<int, ll> f;

    return fib_helper(n, f);
}

int main()
{

    cout << fib(6) << endl;
    cout << fib(7) << endl;
    cout << fib(8) << endl;
    cout << fib(50) << endl;

    return 0;
}