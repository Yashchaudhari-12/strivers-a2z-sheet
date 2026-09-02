#include <bits/stdc++.h>
using namespace std;

int help_func(vector<int> &nums, int m)
{
    int n = nums.size();
    int curr_sum = 0, cnt = 1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] + curr_sum < m)
        {
            curr_sum += nums[i];
        }
        else
        {
            cnt++;
            curr_sum = 0;
        }
    }
    return cnt;
}

int largest_min_sum(vector<int> &nums, int n)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = help_func(nums, mid);

        if (cnt > n)
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
    int n, k;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter No Os Subarrays : ";
    cin >> k;

    int m = largest_min_sum(nums, k);

    cout << "The Largest Minimized Sum Is : " << m << "\n";
    return 0;
}