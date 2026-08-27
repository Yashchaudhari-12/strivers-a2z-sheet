#include <bits/stdc++.h>
using namespace std;

bool division_sum(vector<int> &nums, int k, int m)
{
    int div_sum = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {

        int sum = ceil((float)nums[i] / (float)k);

        div_sum += sum;
    }
    if (div_sum <= m)
    {
        return true;
    }
    return false;
}

int min_div(vector<int> &nums, int t)
{
    int low = 1;
    auto it = max_element(nums.begin(), nums.end());
    int high = *it;
    int ans = 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (division_sum(nums, mid, t) == true)
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
    int n, threshold, m;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter Threshold : ";
    cin >> threshold;

    m = min_div(nums, threshold);

    cout << "The Minimum Divisor Of The Given Array Is : " << m << "\n";
    return 0;
}