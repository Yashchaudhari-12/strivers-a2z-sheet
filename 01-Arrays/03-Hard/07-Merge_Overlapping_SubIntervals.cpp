#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge_interval(vector<vector<int>> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || nums[i][0] > ans.back()[1])
        {
            ans.push_back(nums[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], nums[i][1]);
        }
    }
    return ans;
}

int main()
{
    int n;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));

    cout << "Enter Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    vector<vector<int>> ans = merge_interval(arr);

    for (auto it : ans)
    {
        for (int x : it)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}