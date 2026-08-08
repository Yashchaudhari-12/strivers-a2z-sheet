#include<iostream>
using namespace std;

void rev_array(int arr[],int start,int end)
{
    while(start<end)
    {
    int temp = arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    start++; 
    end--;
    }
}
void left_rotate(int arr[],int n,int k)
{
    k = k % n;

    rev_array(arr,0,k-1);
    rev_array(arr,k,n-1);
    rev_array(arr,0,n-1);
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

    cout << "Enter Places You Want To Rotate Left To : ";
    cin >> k;
    left_rotate(arr,n,k);

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}