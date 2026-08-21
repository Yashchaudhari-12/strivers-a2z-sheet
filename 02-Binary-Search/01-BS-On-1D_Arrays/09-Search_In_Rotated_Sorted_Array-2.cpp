#include <bits/stdc++.h>
using namespace std;

bool search_elem(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[mid] == nums[low] && nums[mid] == nums[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }
        if (nums[low] <= nums[mid])
        {
            if (target >= nums[low] && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (nums[mid] <= nums[high])
        {
            if (target >= nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    int n, target;
    bool k;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter Target Value : ";
    cin >> target;

    k = search_elem(nums, target);

    if (k == true)
    {
        cout << "The Element Is Present" << "\n";
    }
    else
    {
        cout << "The Element Is Not Present" << "\n";
    }
    return 0;
}