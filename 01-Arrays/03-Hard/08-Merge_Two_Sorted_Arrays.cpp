#include <bits/stdc++.h>
using namespace std;

void merge_array(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = 0;

    while (i >= 0 && j < n)
    {
        if (nums1[i] > nums2[j])
        {
            swap(nums1[i], nums2[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }
    sort(nums1.begin(), nums1.begin() + m);
    sort(nums2.begin(), nums2.end());

    for (int i = 0; i < n; i++)
    {
        nums1[m + i] = nums2[i];
    }
}

int main()
{
    int n, m;

    cout << "Enter Size Of Nums1 : ";
    cin >> m;

    cout << "Enter Size Of Nums2 : ";
    cin >> n;

    vector<int> nums1(m + n, 0);
    vector<int> nums2(n);

    cout << "Enter Nums1 : ";

    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    cout << "Enter Nums2 : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    merge_array(nums1, m, nums2, n);

    for (int x : nums1)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}