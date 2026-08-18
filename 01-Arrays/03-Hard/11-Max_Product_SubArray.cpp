#include <bits/stdc++.h>
using namespace std;

int max_product(vector<int> &nums)
{
    int n = nums.size();
    int max_prod = INT_MIN;
    int prefix = 1, suffix = 1;

    for (int i = 0; i < n - 1; i++)
    {
        if (prefix == 0)
        {
            prefix = 1;
        }
        if (suffix == 0)
        {
            suffix = 1;
        }

        prefix *= nums[i];
        suffix *= nums[n - i - 1];

        max_prod = max(max_prod, max(prefix, suffix));
    }
    return max_prod;
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

    m = max_product(arr);

    cout << "The Max Product In The Given Array is : " << m << "\n";
    return 0;
}