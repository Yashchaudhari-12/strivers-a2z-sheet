#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[],int n,int temp[])
{
    int even_count = 0,odd_count = 1;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            temp[even_count] = arr[i];
            even_count += 2;
        }
        else
        {
            temp[odd_count] = arr[i];
            odd_count += 2;
        }
    }
}

int main()
{
    int n;
    cout << "Enter Array Size : ";
    cin >> n;
    int arr[n],temp[n];

    cout << "Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }    
    
    rearrange(arr,n,temp);

    for(int i=0;i<n;i++)
    {
        cout << temp[i] << " ";
    }
    cout << "\n";
    return 0;


}