#include <bits/stdc++.h>
using namespace std;

vector<int> maj_elem(vector<int> &arr)
{
    int n = arr.size();
    int cnt1 = 0, cnt2 = 0;
    int candidate1 = 0, candidate2 = 0;
    vector<int> ans;

    for (int num : arr)
    {
        if (cnt1 == 0 && num != candidate2)
        {
            cnt1 = 1;
            candidate1 = num;
        }
        else if (cnt2 == 0 && num != candidate1)
        {
            cnt2 = 1;
            candidate2 = num;
        }
        else if (candidate1 == num)
        {
            cnt1++;
        }
        else if (candidate2 == num)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate1)
        {
            cnt1++;
        }
        else if (arr[i] == candidate2)
        {
            cnt2++;
        }
    }
    if (cnt1 > n / 3)
    {
        ans.push_back(candidate1);
    }
    if (cnt2 > n / 3)
    {
        ans.push_back(candidate2);
    }
    return ans;
}

int main()
{
    int n;

    cout << "Enter Array Size : ";
    cin >> n;
    vector<int> arr(n);
    vector<int> ans;

    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ans = maj_elem(arr);

    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}