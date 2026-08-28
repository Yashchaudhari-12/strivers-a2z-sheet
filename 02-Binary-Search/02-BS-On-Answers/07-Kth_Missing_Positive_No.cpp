#include <bits/stdc++.h>
using namespace std;

int miss_no(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int missing = nums[mid] - (mid + 1);

        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low + k;
}

int main()
{
    int n, m, k;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter Position Of Missing No : ";
    cin >> k;

    m = miss_no(nums, k);

    cout << "The Missing No Is : " << m << "\n";
    return 0;
}