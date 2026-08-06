#include<iostream>
#include<climits>
using namespace std;

int second_Largest(int arr[],int n)
{
    int largest = arr[0];
    int second_largest = INT_MIN;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>second_largest)
        {
            second_largest = arr[i];
        }
    }
    return second_largest;
}

int main()
{
    int n;
    cout << "Enter Array Size : ";
    cin >> n;

    cout << "Enter Array Elements : ";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int second_largest = second_Largest(arr,n);

    if(second_largest==INT_MIN)
    {
        cout << "No Second Largest Element" << endl;
    }
    else
    {
        cout << "The Second Largest Element In The Given Array Is : " << second_largest << endl;
    }
    return 0;

}