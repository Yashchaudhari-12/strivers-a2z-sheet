#include<iostream>
using namespace std;

void move_zeros(int arr[],int n)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            arr[j]=arr[i];
            j++;
        }
    }
    for(;j<n;j++)
    {
        arr[j]=0;
    }
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
    move_zeros(arr,n);

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}