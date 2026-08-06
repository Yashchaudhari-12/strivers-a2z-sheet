#include<iostream>
#include<climits>
using namespace std;

bool sorted_array(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            return false;
        }
    }
    return true;
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

    bool Sorted_Array = sorted_array(arr,n);

    if(Sorted_Array==true)
    {
        cout << "The Given Array Is Sorted" << endl;
    }
    else
    {
        cout << "The Given Array Is Not Sorted" << endl;
    }
    return 0;
}