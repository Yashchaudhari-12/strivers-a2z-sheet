#include <bits/stdc++.h>
using namespace std;

int a_merge(vector<int> &nums, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    int count = 0;

    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
            count += mid - low + 1;
        }
    }
    return count;
}

int merge(vector<int> &nums, int low, int high)
{
    int count = 0;
    if (low == high)
        return count;
    int mid = (low + high) / 2;

    count += merge(nums, low, mid);
    count += merge(nums, mid + 1, high);
    count += a_merge(nums, low, mid, high);
    return count;
}

int count(vector<int> &nums)
{
    int n = nums.size();
    return merge(nums, 0, n - 1);
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

    m = count(arr);

    cout << "The Number Of Inversions Is : " << m << "\n";
    return 0;
}