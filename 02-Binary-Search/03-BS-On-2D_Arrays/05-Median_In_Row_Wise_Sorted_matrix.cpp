#include <bits/stdc++.h>
using namespace std;

int upperbound(vector<int> &nums, int k)
{

    int n = nums.size(), low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] > k)
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

int no_of_elem(vector<vector<int>> &mat, int n, int mid)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cnt += upperbound(mat[i], mid);
    }
    return cnt;
}

int median_matrix(vector<vector<int>> &mat, int n, int m)
{
    int low = INT_MAX, high = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }

    int req = (n * m) / 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int small_equal = no_of_elem(mat, n, mid);

        if (small_equal <= req)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int n, m;

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

    int median = median_matrix(nums, n, m);

    cout << "The Median Is : " << median << "\n";
    return 0;
}
