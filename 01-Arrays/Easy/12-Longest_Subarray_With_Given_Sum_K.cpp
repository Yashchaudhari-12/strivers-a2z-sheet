#include<iostream>
using namespace std;

int max_length(int arr[],int n,int k)
{
    int max_len=0;
    int curr_sum=0,j=0;

    for(int i=0;i<n;i++)
    {
        curr_sum += arr[i];

        while(curr_sum>k)
        {
            curr_sum = curr_sum - arr[j];
            j++;
        }

        if(curr_sum==k)
        {
            max_len = max(max_len,i-j+1);
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
    cout << "Enter Max Sum : ";
    cin >> k;

    m = max_length(arr,n,k);

    cout << "The Max Length Of SubArray With Given Sum Is : " << m << "\n";
    return 0;
}