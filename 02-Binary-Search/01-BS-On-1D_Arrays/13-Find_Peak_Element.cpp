#include <bits/stdc++.h>
using namespace std;

int peak_elem(vector<int> &nums)
{
    int n = nums.size();
    int low = 1;
    int high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[0] > nums[1])
        {
            return nums[0];
        }
        if (nums[n - 1] > nums[n - 2])
        {
            return nums[n - 1];
        }

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            return nums[mid];
        }
        else if (nums[mid] > nums[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
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

    ans = peak_elem(nums);

    cout << "Peak Element Is : " << ans << "\n";
    return 0;
}