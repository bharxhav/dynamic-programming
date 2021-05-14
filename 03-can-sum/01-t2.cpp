#include <iostream>
#include <vector>

using namespace std;

bool canSumHelper(vector<int> &lst, int target)
{
    if (target < 0)
        return false;

    if (target == 0)
        return true;

    for (auto num : lst)
        if (canSumHelper(lst, target - num))
            return true;

    return false;
}

bool canSum(vector<int> lst, int target)
{
    return canSumHelper(lst, target);
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