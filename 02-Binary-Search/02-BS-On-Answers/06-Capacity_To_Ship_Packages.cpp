#include <bits/stdc++.h>
using namespace std;

bool min_days(vector<int> &nums, int k, int days)
{
    int n = nums.size(), curr_sum = 0;

    int days_taken = 1;

    for (int i = 0; i < n; i++)
    {
        if (curr_sum + nums[i] > k)
        {
            days_taken++;
            curr_sum = nums[i];
        }
        else
        {
            curr_sum += nums[i];
        }
    }
    if (days_taken <= days)
    {
        return true;
    }
    return false;
}

int min_cap(vector<int> &nums, int days)
{
    auto it = max_element(nums.begin(), nums.end());
    int low = *it;

    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (min_days(nums, mid, days) == true)
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
    int n, days;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter Max Days : ";
    cin >> days;

    int m = min_cap(nums, days);

    cout << "The Minimum Capacity To Ship Packages In Given Days Is : " << m << "\n";
    return 0;
}