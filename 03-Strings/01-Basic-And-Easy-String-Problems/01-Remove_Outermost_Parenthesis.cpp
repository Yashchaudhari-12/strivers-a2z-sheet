#include <bits/stdc++.h>
using namespace std;

string remove_outer_parenthesis(string s)
{
    string result;
    int depth = 0;

    for (char c : s)
    {

        if (c == '(')
        {
            depth++;

            if (depth > 1)
            {
                result += c;
            }
        }
        else
        {
            if (depth > 1)
            {
                result += c;
            }
            depth--;
        }
    }
    return result;
}

int main()
{
    string s;

    cout << "Enter A String : ";
    cin >> s;

    string ans = remove_outer_parenthesis(s);

    cout << "After Removing : " << ans << "\n";
    return 0;
}