#include <bits/stdc++.h>
using namespace std;

int rotate_count(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX, index = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[low] <= nums[high])
        {
            if (nums[low] < ans)
            {
                index = low;
                ans = nums[low];
                break;
            }
        }
        if (nums[mid] > nums[low])
        {
            if (nums[low] < ans)
            {
                index = low;
                ans = nums[low];
            }
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            if (nums[mid] < ans)
            {
                index = mid;
                ans = nums[mid];
            }
        }
    }
    return index;
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

    ans = rotate_count(nums);

    cout << "The Amount Of Times The Given Array Is Rotated Is : " << ans << "\n";
    return 0;
}