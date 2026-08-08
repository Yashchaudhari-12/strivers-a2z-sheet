#include<iostream>
using namespace std;

int elem_once(int arr[],int n)
{
    int answer=0;
    for(int i=0;i<n;i++)
    {
        answer = answer ^ arr[i]; 
    }
    return answer;
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

    k = elem_once(arr,n);

    cout << "The Element Appearing Once Is : " << k << "\n";
    return 0;
}
