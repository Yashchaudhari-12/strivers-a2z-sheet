#include <bits/stdc++.h>
using namespace std;

bool can_we_place(vector<int> &nums, int dist, int no)
{
    int n = nums.size();
    int cnt_cows = 1, last_cp = nums[0];

    for (int i = 1; i <= n - 1; i++)
    {
        if (nums[i] - last_cp >= dist)
        {
            cnt_cows++;
            last_cp = nums[i];
        }
        if (cnt_cows >= no)
        {
            return true;
        }
    }

    return false;
}

int min_dist_max(vector<int> &nums, int n)
{
    sort(nums.begin(), nums.end());
    int low = 1;
    int high = nums[n - 1] - nums[0];

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (can_we_place(nums, mid, n) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
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

    cout << "No Of Cows To Be Placed : ";
    cin >> k;

    m = min_dist_max(nums, k);

    cout << "The Maximized Minimum Distance Between Cows Is : " << m << "\n";
    return 0;
}