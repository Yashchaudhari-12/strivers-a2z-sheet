#include <bits/stdc++.h>
using namespace std;

int count_sub(vector<int> &arr, int k)
{
    int n = arr.size();
    int curr_sum = 0;
    int count = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        int rem = curr_sum - k;

        if (mp.find(rem) != mp.end())
        {
            count += mp[rem];
        }
        mp[curr_sum]++;
    }
    return count;
}

int main()
{
    int n, answer, k;

    cout << "Enter Array Size : ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter Sum : ";
    cin >> k;

    answer = count_sub(arr, k);

    cout << "The Frequency Of Subarrays with Sum Equal To Given K Is : " << answer << "\n";
    return 0;
}