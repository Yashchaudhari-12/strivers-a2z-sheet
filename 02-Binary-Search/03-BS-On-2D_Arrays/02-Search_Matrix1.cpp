#include <bits/stdc++.h>
using namespace std;

bool search_mat(vector<vector<int>> &nums, int target)
{
    int n = nums.size();
    int m = nums[0].size();
    int low = 0, high = n * m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int row = mid / m, col = mid % m;
        // row is a multiple suppose 4 so row no are 0,4,8 so row = /m
        // for column remainder is taken so col = %m

        if (nums[row][col] == target)
        {
            return true;
        }
        else if (nums[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
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

    if (search_mat(nums, target) == true)
    {
        cout << "Element Exists\n";
    }
    else
    {
        cout << "Element Does Not Exist\n";
    }
}