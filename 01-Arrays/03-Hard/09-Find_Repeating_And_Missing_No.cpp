#include <bits/stdc++.h>
using namespace std;

vector<int> repeating_missing(vector<int> &nums)
{
    int n = nums.size();
    int xr = 0;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ nums[i];
        xr = xr ^ (i + 1);
    }
    int bit_no = 0;

    while (1)
    {
        if ((xr & (1 << bit_no)) != 0)
        {
            break;
        }
        bit_no++;
    }
    int one = 0;
    int zero = 0;

    for (int i = 0; i < n; i++)
    {
        if ((nums[i] & (1 << bit_no)) != 0)
        {
            one = one ^ nums[i];
        }
        else
        {
            zero = zero ^ nums[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if ((i & (1 << bit_no)) != 0)
        {
            one = one ^ i;
        }
        else
        {
            zero = zero ^ i;
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == zero)
        {
            cnt++;
        }
    }
    if (cnt == 2)
    {
        return {zero, one};
    }
    else
    {
        return {one, zero};
    }
}

int main()
{
    int n;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = repeating_missing(arr);

    cout << "The Missing Elements Are : ";

    for (int it : ans)
    {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}