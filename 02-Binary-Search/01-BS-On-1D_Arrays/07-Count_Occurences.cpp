#include <bits/stdc++.h>
using namespace std;

int first_occur(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int first = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int last_occur(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int last = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

int main()
{
    int n, k, first, last;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter Target Value : ";
    cin >> k;

    first = first_occur(nums, k);
    last = last_occur(nums, k);

    cout << "The Amount Of Times The Element Has Occured Is : " << last - first + 1 << "\n";
    return 0;
}