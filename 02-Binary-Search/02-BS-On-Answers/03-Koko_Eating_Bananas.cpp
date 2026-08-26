#include <bits/stdc++.h>
using namespace std;

int total_hrs(vector<int> &nums, int hour)
{
    int t_hr = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        t_hr += ceil((double)nums[i] / (double)hour);
    }
    return t_hr;
}

int total_banana(vector<int> &nums, int limit)
{
    int low = 0, ans = INT_MAX;
    auto it = max_element(nums.begin(), nums.end());
    int high = *it;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int req_time = total_hrs(nums, mid);

        if (req_time <= limit)
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

int main()
{
    int n, m, limit;

    cout << "Enter Array size : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter Hour Limit : ";
    cin >> limit;

    m = total_banana(nums, limit);

    cout << "The Banana Per Hour Rate Is : " << m << "\n";
    return 0;
}