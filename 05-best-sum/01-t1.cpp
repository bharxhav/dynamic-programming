/*
* Same as how Sum, but we give best sum, that is the shortest possible one.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> bestSumHelper(vector<int> &lst, int target, vector<int> stk)
{
    if (target < 0)
        return vector<int>{};

    if (target == 0)
        return stk;

    vector<int> ret;
    int le = INT32_MAX;

    for (auto num : lst)
    {
        stk.push_back(num);
        vector<int> ans = bestSumHelper(lst, target - num, stk);
        if (ans.size() != 0 && ans.size() < le)
        {
            ret = ans;
            le = ret.size();
        }

        stk.pop_back();
    }

    return ret;
}

void bestSum(vector<int> lst, int target)
{
    vector<int> ret = bestSumHelper(lst, target, vector<int>{});

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