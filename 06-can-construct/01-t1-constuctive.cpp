/*
*   From a given wordBank, we have to construct a target sequence.
*   Return a bool.
*   word bank is reusable.

Example:
    target = "abcdef"
    elements = [ab, abc, cd, def, abcd]

    Ans = True
*/

#include <iostream>
#include <vector>

using namespace std;

bool canConstructHelper(vector<string> &elements, string target, string seq)
{
    if (target == seq)
        return true;

    if (seq.size() > target.size())
        return false;

    for (auto str : elements)
    {
        if (canConstructHelper(elements, target, seq + str))
            return true;
    }

    return false;
}

bool canConstruct(vector<string> elements, string target)
{
    return canConstructHelper(elements, target, "");
}

int main()
{
    cout << canConstruct(vector<string>{"ab", "abc", "cd", "def", "abcd"}, "abcdef") << endl;
    cout << canConstruct(vector<string>{"bo", "rd", "ate", "t", "ska", "sk", "boar"}, "skateboard") << endl;
    cout << canConstruct(vector<string>{"a", "p", "ent", "enter", "ot", "o", "t"}, "enterapotentpot") << endl;
    cout << canConstruct(vector<string>{"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}, "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef") << endl;

    return 0;
}
