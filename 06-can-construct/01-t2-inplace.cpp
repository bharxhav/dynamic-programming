#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canConstructHelper(vector<string> &elements, string target)
{
    if (target == "")
        return true;

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

        if (canConstructHelper(elements, target.substr(st.size(), target.size() - st.size())))
            return true;
    }

    return false;
}

bool canConstruct(vector<string> elements, string target)
{
    return canConstructHelper(elements, target);
}

int main()
{
    cout << canConstruct(vector<string>{"ab", "abc", "cd", "def", "abcd"}, "abcdef") << endl;
    cout << canConstruct(vector<string>{"bo", "rd", "ate", "t", "ska", "sk", "boar"}, "skateboard") << endl;
    cout << canConstruct(vector<string>{"a", "p", "ent", "enter", "ot", "o", "t"}, "enterapotentpot") << endl;
    cout << canConstruct(vector<string>{"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}, "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef") << endl;

    return 0;
}