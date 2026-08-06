#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxsum(int arr[],int n)
{
    int curr_sum = 0,start = 0;
    int max_sum = INT_MIN;
    int ans_start=0,ans_end=0;

    for(int i=0;i<n;i++)
    {
        curr_sum += arr[i];

        if(curr_sum>max_sum)
        {
            max_sum = curr_sum;
            ans_start = start;
            ans_end = i;
        }

        if(curr_sum<0)
        {
            curr_sum = 0;
            start = i+1;
        }
        
    }

    for(int i=ans_start;i<=ans_end;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
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
    
    m = maxsum(arr,n);

    cout << "The Max Sum Of The Longest Subarray Is : " << m << "\n";
    return 0;

}