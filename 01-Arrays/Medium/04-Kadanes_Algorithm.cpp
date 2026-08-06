#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_sum(int arr[],int n)
{
    int curr_sum = 0,j=0;
    int max_sum = INT_MIN;
    int temp[n];

    for(int i=0;i<n;i++)
    {
        
        curr_sum += arr[i];

        max_sum = max(max_sum,curr_sum);

        if(curr_sum<0)
        {
            curr_sum = 0;
        }

    }
    return max_sum;
}

int main()
{
    int n,m;

    cout << "Enter Array Size : ";
    cin >> n;

    int arr[n];

    cout << "Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    m = max_sum(arr,n);

    cout << "The Max Sum Of A Contiguous SubArray Is : " << m << "\n";
    return 0;

}