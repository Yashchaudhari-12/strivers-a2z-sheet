#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void two_sum(int arr[],int n,int k)
{
    unordered_map<long long, int> mp;

    for(int i=0;i<n;i++)
    {
        int curr_elem = arr[i];
        int required_sum = k - curr_elem;

        if(mp.find(required_sum) != mp.end())
        {
            cout << mp[required_sum] << " " << i << "\n";
            return;
        }
        if(mp.find(curr_elem) == mp.end())
        {
            mp[curr_elem] = i;
        }
    }
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
    
    cout << "Enter Target Sum : ";
    cin >> k;

    two_sum(arr,n,k);

    return 0;

}