#include<iostream>
#include<climits>
using namespace std;

int LargestElement(int arr[],int n)
{
    int largest = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[n]>largest)
        {
            largest = arr[i];       
        }
    }
    return largest;
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

    int largest = LargestElement(arr,n);
    cout << "Largest Element In The Given Array Is : " << largest << endl;
    return 0;
}
/*
Time Complexity : O(n)
Reason : Runs n+n Times constants Ignored

Space Complexity : O(1)
Reason : Only Three Extra Variables Used 

Status : Solved Without Help
*/