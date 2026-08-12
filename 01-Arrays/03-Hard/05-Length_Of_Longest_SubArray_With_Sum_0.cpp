#include <bits/stdc++.h>
using namespace std;

int longest_suba(vector<int> &nums)
{
    int n = nums.size();
    int curr_sum = 0, max_len = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        curr_sum += nums[i];

        if (curr_sum == 0)
        {
            max_len = max(max_len, i + 1);
        }
        int rem = curr_sum - 0;
        if (mp.find(rem) != mp.end())
        {
            int len = i - mp[rem];
            max_len = max(len, max_len);
        }
        if (mp.find(curr_sum) == mp.end())
        {
            mp[curr_sum] = i;
        }
    }
    return max_len;
}

int main()
{
    int n, m;

    cout << "Enter Array Size : ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    m = longest_suba(arr);

    cout << "The Longest Subarray With Sum K Is : " << m << "\n";

    return 0;
}