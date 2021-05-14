#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    int val = -1;
};

bool canSumHelper(vector<int> &lst, int target, map<int, Node> &table)
{
    if (target < 0)
        return false;

    if (target == 0)
        return true;

    if (table[target].val != -1)
        return table[target].val;

    for (auto num : lst)
        if (canSumHelper(lst, target - num, table))
        {
            table[target].val = true;
            return true;
        }

    table[target].val = false;
    return false;
}

bool canSum(vector<int> lst, int target)
{
    map<int, Node> f;
    return canSumHelper(lst, target, f);
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