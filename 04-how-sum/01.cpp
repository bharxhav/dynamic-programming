#include <iostream>
#include <vector>

using namespace std;

vector<int> howSumHelper(vector<int> &lst, int target, vector<int> stk)
{
    if (target < 0)
        return vector<int>{};

    if (target == 0)
        return stk;

    for (auto num : lst)
    {
        stk.push_back(num);
        vector<int> ans = howSumHelper(lst, target - num, stk);
        if (ans.size() != 0)
            return ans;

        stk.pop_back();
    }

    return vector<int>{};
}

void howSum(vector<int> lst, int target)
{
    vector<int> ret = howSumHelper(lst, target, vector<int>{});

    if (ret.size() == 0)
    {
        cout << "No Possible Combination" << endl;
        return;
    }

    cout << "One Possible Combination is:" << endl;
    for (auto num : ret)
        cout << num << " ";
    cout << endl;
}

int main()
{
    howSum(vector<int>{2, 3}, 7);
    howSum(vector<int>{5, 3, 4, 7}, 7);
    howSum(vector<int>{2, 4}, 7);
    howSum(vector<int>{2, 3, 5}, 8);
    howSum(vector<int>{7, 14}, 300);

    return 0;
}