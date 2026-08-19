#include <bits/stdc++.h>
using namespace std;

int floor_arr(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] <= k)
        {
            ans = nums[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int ceil_arr(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] >= k)
        {
            ans = nums[mid];
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
    int n, target, floor, ceil;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter Target : ";
    cin >> target;

    floor = floor_arr(nums, target);
    ceil = ceil_arr(nums, target);

    cout << "The Floor Is : " << floor << "\n";
    cout << "The Ceiling Is : " << ceil << "\n";

    return 0;
}