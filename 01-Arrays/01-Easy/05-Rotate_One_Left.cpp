#include<iostream>
using namespace std;

void left_rotate(int arr[],int n)
{
    int temp = arr[0];
    for(int i=0;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
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
    
    left_rotate(arr,n);

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}