#include <bits/stdc++.h>
using namespace std;

vector<int> generate_row(int row)
{
    long long ans = 1;
    vector<int> ansRow;

    ansRow.push_back(1);
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascal_triangle(int n)
{
    vector<vector<int>> ans;

    for (int i = 1; i <= n; i++)
    {
        ans.push_back(generate_row(i));
    }
    return ans;
}

int main()
{
    int n;

    cout << "Enter No Of Rows : ";
    cin >> n;

    vector<vector<int>> ans;

    ans = pascal_triangle(n);

    for (auto it : ans)
    {
        for (auto itt : it)
        {
            cout << itt << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}
