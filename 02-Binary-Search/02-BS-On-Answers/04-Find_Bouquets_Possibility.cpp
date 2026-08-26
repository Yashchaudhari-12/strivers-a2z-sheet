#include <bits/stdc++.h>
using namespace std;

bool is_possible(vector<int> &nums, int day, int k, int m)
{
    int n = nums.size();
    int cnt = 0;
    int no_of_bou = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= day)
        {
            cnt++;
        }
        else
        {
            no_of_bou += (cnt / k);
            cnt = 0;
        }
    }
    no_of_bou += cnt / k;

    if (no_of_bou >= m)
    {
        return true;
    }
    return false;
}

int blooming_day(vector<int> &nums, int m, int k)
{
    int n = nums.size(), ans = 0;
    auto it = min_element(nums.begin(), nums.end());
    int low = *it;

    auto itt = max_element(nums.begin(), nums.end());
    int high = *itt;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (m * k > n)
            return -1;

        if (is_possible(nums, mid, k, m) == true)
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
    int n, m, k, t;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter No Of Bouquets : ";
    cin >> m;

    cout << "Enter No Of Roses : ";
    cin >> k;

    t = blooming_day(nums, m, k);

    cout << "The Minimum No Of Days To Make Given No Of Bouquets Is : " << t << "\n";
    return 0;
}