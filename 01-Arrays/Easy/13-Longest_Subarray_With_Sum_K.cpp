#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestsub(int arr[],int n,int k)
{
    unordered_map<long long, int> prefix_sum;
    long long sum = 0;
    int max_len = 0;

    for(int i=0;i<n;i++)
    {
        sum += arr[i];

        if(sum==k)
        {
            max_len = max(max_len,i+1);
        }

        long long rem = sum - k;

        if(prefix_sum.find(rem) != prefix_sum.end())
        {
            int len = i - prefix_sum[rem];
            max_len = max(max_len,len);
        }

        if(prefix_sum.find(sum) == prefix_sum.end())
        {
            prefix_sum[sum] = i;
        }
    }
    return max_len;
}

int main()
{
    int n,k,m;

    cout << "Enter Array Size : ";
    cin >> n;
    int arr[n];

    cout << "Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout << "Enter Subarray Sum : ";
    cin >> k;

    m = longestsub(arr,n,k);

    cout << "The Longest Subarray With Sum K Is : " << m << "\n";

    return 0;

}

