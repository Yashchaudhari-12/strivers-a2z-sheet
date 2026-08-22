#include <bits/stdc++.h>
using namespace std;

int min_elem(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[low] <= nums[high])
        {
            ans = min(ans, nums[low]);
            break;
        }
        if (nums[mid] > nums[low])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n, ans;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    ans = min_elem(nums);

    cout << "The Minimum Element In The Given Array Is : " << ans << "\n";
    return 0;
}