#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool canConstructHelper(vector<string> &elements, string target, map<string, int> &f)
{
    if (target == "")
        return true;

    if (f[target] != 0)
        return f[target] - 1;

    for (auto st : elements)
    {
        if (st.size() > target.size())
            continue;

        bool match = true;
        for (int i = 0; i < st.size(); ++i)
        {
            if (st[i] != target[i])
            {
                match = false;
                break;
            }
        }

        if (!match)
            continue;

        if (canConstructHelper(elements, target.substr(st.size(), target.size() - st.size()), f))
        {
            f[target] = 2;
            return true;
        }
    }

    f[target] = 1;
    return false;
}

bool canConstruct(vector<string> elements, string target)
{
    map<string, int> f;
    return canConstructHelper(elements, target, f);
}

int main()
{
    cout << canConstruct(vector<string>{"ab", "abc", "cd", "def", "abcd"}, "abcdef") << endl;
    cout << canConstruct(vector<string>{"bo", "rd", "ate", "t", "ska", "sk", "boar"}, "skateboard") << endl;
    cout << canConstruct(vector<string>{"a", "p", "ent", "enter", "ot", "o", "t"}, "enterapotentpot") << endl;
    cout << canConstruct(vector<string>{"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}, "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef") << endl;

    return 0;
}