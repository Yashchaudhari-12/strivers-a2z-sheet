#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int missingnumber(int arr[],int n)
{
    int xor1=0,xor2=0;

    for(int i=0;i<n;i++)
    {
        xor1 ^= arr[i];
    }
    for(int i=0;i<=n;i++)
    {
        xor2 ^= i;
    }
    return xor1^xor2;
}

int main()
{
    int n;
    cout << "Enter Array Size : ";
    cin >> n;
    int arr[n];

    cout << "Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int miss_no = missingnumber(arr,n);

    cout << "The Missing Number In The Given Range Of Array Is : " << miss_no << '\n';
    return 0;
}