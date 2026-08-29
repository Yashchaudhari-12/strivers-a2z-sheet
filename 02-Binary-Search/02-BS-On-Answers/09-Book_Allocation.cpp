#include <bits/stdc++.h>
using namespace std;

int min_pages(vector<int> &nums, int curr_p)
{
    int n = nums.size();
    int cnt_std = 1, pages = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] + pages <= curr_p)
        {
            pages += nums[i];
        }
        else
        {
            pages = nums[i];
            cnt_std++;
        }
    }
    return cnt_std;
}

int max_pages(vector<int> &nums, int students)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();

    if (students > n)
    {
        return -1;
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int student = min_pages(nums, mid);

        if (student > students)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int n, students;

    cout << "Enter Array Size : ";
    cin >> n;
    vector<int> nums(n);

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "The No Of Students : ";
    cin >> students;

    int m = max_pages(nums, students);

    cout << "The Max Pages Allocated to One Student Is : " << m << "\n";
    return 0;
}