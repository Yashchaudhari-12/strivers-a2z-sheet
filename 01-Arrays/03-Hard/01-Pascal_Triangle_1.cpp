#include <bits/stdc++.h>
using namespace std;

vector<int> generate_row(int n)
{
    vector<int> row;
    row.push_back(1);
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        row.push_back(ans);
    }
    return row;
}

vector<vector<int>> pascal_triangle(int row)
{
    vector<vector<int>> pt;

    for (int i = 1; i <= row; i++)
    {
        pt.push_back(generate_row(i));
    }
    return pt;
}

int main()
{
    int n;

    cout << "Enter No Of Rows : ";
    cin >> n;

    vector<vector<int>> ans = pascal_triangle(n);

    for (auto it : ans)
    {
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}