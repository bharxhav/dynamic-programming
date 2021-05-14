#include <iostream>
#include <vector>

using namespace std;

bool canSumHelper(vector<int> &lst, int target, int i)
{
    if (target < 0)
        return false;

    if (target == 0)
        return true;

    if (i >= lst.size())
        return false;

    return canSumHelper(lst, target, i + 1) || canSumHelper(lst, target - lst[i], i + 1) || canSumHelper(lst, target - lst[i], i);
}

bool canSum(vector<int> lst, int target)
{
    return canSumHelper(lst, target, 0);
}

int main()
{
    cout << canSum(vector<int>{2, 3}, 7) << endl;
    cout << canSum(vector<int>{5, 3, 4, 7}, 7) << endl;
    cout << canSum(vector<int>{2, 4}, 7) << endl;
    cout << canSum(vector<int>{2, 3, 5}, 8) << endl;
    cout << canSum(vector<int>{7, 14}, 300) << endl;

    // true, true, false, true, false

    return 0;
}