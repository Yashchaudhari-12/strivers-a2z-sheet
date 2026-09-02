#include <bits/stdc++.h>
using namespace std;

vector<int> index_elem(vector<vector<int>> &nums, int target)
{
    int n = nums.size();
    int m = nums[0].size();
    int row = 0, col = m - 1;

    while (row < n && m >= 0)
    {
        if (nums[row][col] == target)
        {
            return {row, col};
        }
        else if (nums[row][col] > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return {-1, -1};
}

int main()
{
    int n, m, target;

    cout << "Enter No Of Rows : ";
    cin >> n;
    cout << "Enter No Of Columns : ";
    cin >> m;

    vector<vector<int>> nums(n, vector<int>(m));

    cout << "Enter Matrix Elements : ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }

    cout << "Enter Target Element : ";
    cin >> target;

    vector<int> ans = index_elem(nums, target);

    cout << "The Index Is : ";

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}