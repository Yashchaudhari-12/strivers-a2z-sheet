#include <bits/stdc++.h>
using namespace std;

int count_sub(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0, xor1 = 0;
    map<int, int> mp;
    mp[xor1]++;

    for (int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ nums[i];
        int x = xor1 ^ k;
        count += mp[x];
        mp[xor1]++;
    }
    return count;
}

int main()
{
    int n, k, m;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter A Target : ";
    cin >> k;

    m = count_sub(arr, k);

    cout << "The Amount Of Times The Given Xor Value Appears Is : " << m << "\n";
    return 0;
}