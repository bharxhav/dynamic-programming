#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct vector_bool
{
    bool c = false;
    vector<int> v;
};

vector<int> howSumHelper(vector<int> &lst, int target, vector<int> &stk, map<int, vector_bool> &f)
{

    if (target < 0)
        return vector<int>{};

    if (target == 0)
        return stk;

    if (f[target].c)
        return f[target].v;

    for (auto num : lst)
    {
        stk.push_back(num);
        vector<int> ans = howSumHelper(lst, target - num, stk, f);
        if (ans.size() != 0)
        {
            f[target].c = true;
            f[target].v = ans;
            return ans;
        }

        stk.pop_back();
    }

    f[target].c = true;
    f[target].v = vector<int>{};
    return f[target].v;
}

void howSum(vector<int> lst, int target)
{
    cout << endl;

    map<int, vector_bool> f;
    vector<int> stk;
    vector<int> ret = howSumHelper(lst, target, stk, f);

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