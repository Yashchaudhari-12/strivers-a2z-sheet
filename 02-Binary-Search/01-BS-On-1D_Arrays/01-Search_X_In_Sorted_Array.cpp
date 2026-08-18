#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
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
    int n, m, k;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter A Target To Find : ";
    cin >> k;
    sort(nums.begin(), nums.end());

    m = search(nums, k);

    if (m == -1)
    {
        cout << "Element Not Found" << "\n";
    }
    else
    {
        cout << "Element Found At Index No : " << m << "\n";
    }
    return 0;
}
