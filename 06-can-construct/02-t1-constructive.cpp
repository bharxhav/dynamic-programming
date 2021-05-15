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
#include <map>

using namespace std;

bool canConstructHelper(vector<string> &elements, string target, string seq, map<string, int> &f)
{
    if (target == seq)
        return true;

    if (seq.size() > target.size())
        return false;

    if (f[seq] != 0)
        return f[seq] - 1;

    for (auto str : elements)
    {
        if (canConstructHelper(elements, target, seq + str, f))
        {
            f[seq] = 2;
            return true;
        }
    }

    f[seq] = 1;
    return false;
}

bool canConstruct(vector<string> elements, string target)
{
    map<string, int> f;
    return canConstructHelper(elements, target, "", f);
}

int main()
{
    cout << canConstruct(vector<string>{"ab", "abc", "cd", "def", "abcd"}, "abcdef") << endl;
    cout << canConstruct(vector<string>{"bo", "rd", "ate", "t", "ska", "sk", "boar"}, "skateboard") << endl;

    // This case passes, ONLY because the letters are mostly comprised of `e`.
    cout << canConstruct(vector<string>{"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}, "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef") << endl;

    // This case STILL fails, since the combinations are so diverse
    cout << canConstruct(vector<string>{"a", "p", "ent", "enter", "ot", "o", "t"}, "enterapotentpot") << endl;

    return 0;
}