/*
* Same as how Sum, but we give best sum, that is the shortest possible one.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> bestSumHelper(vector<int> &lst, int target, vector<int> stk, int i)
{
    if (target < 0)
        return vector<int>{};

    if (target == 0)
        return stk;

    if (i >= lst.size())
        return vector<int>{};

    vector<int> a, b, c;
    a = bestSumHelper(lst, target, stk, i + 1);
    stk.push_back(lst[i]);
    b = bestSumHelper(lst, target - lst[i], stk, i);
    c = bestSumHelper(lst, target - lst[i], stk, i + 1);
    stk.pop_back();

    int l, j, k;

    l = a.size() != 0 ? a.size() : INT32_MAX;
    j = b.size() != 0 ? b.size() : INT32_MAX;
    k = c.size() != 0 ? c.size() : INT32_MAX;

    return l < j ? k < l ? c : a : k < j ? c
                                         : b;
}

void bestSum(vector<int> lst, int target)
{
    vector<int> ret = bestSumHelper(lst, target, vector<int>{}, 0);

    if (ret.size() == 0)
    {
        cout << "No Possible Combination" << endl;
        return;
    }

    cout << "Shortest Possible Combination is:" << endl;
    for (auto num : ret)
        cout << num << " ";
    cout << endl;
}

int main()
{
    bestSum(vector<int>{5, 3, 4, 7}, 7);    // 7
    bestSum(vector<int>{2, 3, 5}, 8);       // 3, 5
    bestSum(vector<int>{1, 4, 5}, 8);       // 4, 4
    bestSum(vector<int>{1, 2, 5, 25}, 100); // 25, 25 ,25 ,25

    return 0;
}