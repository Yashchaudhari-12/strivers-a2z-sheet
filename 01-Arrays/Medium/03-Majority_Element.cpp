#include<iostream>
using namespace std;

int majority(int arr[],int n)
{
    int count = 0;
    int candidate = 0;

    for(int i=0;i<n;i++)
    {
        if(count == 0)
        {
            candidate = arr[i];
            count = 1;
        }
        else if(candidate == arr[i])
        {
            count++;
        }
        else 
        {
            count--;
        }
    }

    count = 0;

    for(int i=0;i<n;i++)
    {
        if(arr[i] == candidate)
        {
            count++;
        }
    }

    if(count > n/2)
    {
        return candidate;
    }

    return -1;
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

    m = majority(arr,n);

    if(m == -1)
    {
        cout << "No Majority Element Exists" << "\n";
    }
    else
    {
    cout << "The Majority Element In This Array Is : " << m << "\n";
    }
    return 0;
}