#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] >= k)
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
    int n, k, m;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    cout << "Enter A Target : ";
    cin >> k;

    m = lower_bound(nums, k);

    cout << "The Lower Bound Is : " << m << "\n";
    return 0;
}