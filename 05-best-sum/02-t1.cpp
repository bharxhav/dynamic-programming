/*
* Same as how Sum, but we give best sum, that is the shortest possible one.
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct table
{
    bool c = false;
    vector<int> v;
};

table bestSumHelper(vector<int> &lst, int target, map<int, table> &f)
{
    if (f[target].c)
        return f[target];

    table ret;

    if (target < 0)
    {
        ret.c = false;
        return ret;
    }

    if (target == 0)
    {
        ret.c = true;
        ret.v = {};
        return ret;
    }

    table re;

    for (auto num : lst)
    {
        ret = bestSumHelper(lst, target - num, f);

        if (ret.c)
        {
            if (re.v.size() == 0 || re.v.size() > ret.v.size())
            {
                re = ret;
                re.c = true;
                re.v.push_back(num);
            }
        }
    }

    f[target] = re;
    return re;
}

void bestSum(vector<int> lst, int target)
{
    map<int, table> f;
    table ret = bestSumHelper(lst, target, f);

    if (ret.v.size() == 0)
    {
        cout << "No Possible Combination" << endl;
        return;
    }

    cout << "Shortest Possible Combination is:" << endl;
    for (auto num : ret.v)
        cout << num << " ";
    cout << endl;
}

int main()
{
    bestSum(vector<int>{5, 3, 4, 7}, 7);    // 7
    bestSum(vector<int>{2, 3, 5}, 8);       // 3, 5
    bestSum(vector<int>{1, 4, 5}, 8);       // 4, 4
    bestSum(vector<int>{1, 2, 5, 25}, 100); // 25, 25 ,25 ,25
    bestSum(vector<int>{25, 5, 2, 1}, 100); // 25, 25 ,25 ,25

    return 0;
}