#include <bits/stdc++.h>
using namespace std;

string rev_string(string s)
{
    string result = "";
    int i = s.size() - 1;

    while (i >= 0)
    {
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        if (i < 0)
            break;

        int end = i;

        while (i >= 0 && s[i] != ' ')
        {
            i--;
        }

        string word = s.substr(i + 1, end - i);

        if (!result.empty())
        {
            result += " ";
        }
        result += word;
    }
    return result;
}

int main()
{
    string s;

    cout << "Enter A String : ";
    getline(cin, s);

    string ans = rev_string(s);

    cout << "Reversed String Is : " << ans << "\n";
    return 0;
}