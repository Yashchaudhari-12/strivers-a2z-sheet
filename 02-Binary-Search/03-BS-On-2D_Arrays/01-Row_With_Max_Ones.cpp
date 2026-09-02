#include <bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] >= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int Max_Ones(vector<vector<int>> &nums, int n, int m)
{
    int cnt_ones = 0;
    int index = -1;
    int max_ones = -1;

    for (int i = 0; i < n; i++)
    {
        cnt_ones = m - lowerbound(nums[i], 1);

        if (cnt_ones > max_ones)
        {
            index = i;
            max_ones = cnt_ones;
        }
    }
    return index;
}

int main()
{
    int n, m;

    cout << "How Many Matrix Rows : ";
    cin >> n;

    cout << "How Many Matrix Columns : ";
    cin >> m;

    vector<vector<int>> nums(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }

    int ans = Max_Ones(nums, n, m);

    cout << "The Row With Max Ones Is : " << ans << "\n";
    return 0;
}