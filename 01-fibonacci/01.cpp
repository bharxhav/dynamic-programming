#include <iostream>

using namespace std;

int fib(int n)
{
    if (n < 2)
        return n;

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << fib(6) << endl;
    cout << fib(7) << endl;
    cout << fib(8) << endl;
    cout << fib(50) << endl;

    return 0;
}