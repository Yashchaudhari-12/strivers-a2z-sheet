#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_continuous_ones(int arr[],int n)
{
    int current_max=0;
    int final_max=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i] == 1)
        {
            current_max++;
        }
        else
        {
            current_max = 0;
        }
        final_max = max(final_max,current_max);
    }
    return final_max;
}

int main()
{
    int n,k;

    cout << "Enter Array Size : ";
    cin >> n;
    int arr[n];
    cout << "Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    k = max_continuous_ones(arr,n);

    if(k==0)
    {
        cout << "No Continuous One's Present" << "\n";
    }
    else
    {
    cout << "The Max Continuous 1s In The Given Array Are : " << k << "\n";
    }
    return 0;
    
}