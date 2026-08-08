#include<bits/stdc++.h>
using namespace std;

vector<int> Next_permutation(vector<int> arr,int n)
{
    int index = -1;

    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        reverse(arr.begin(),arr.end());
        return arr;
    }

    for(int i=n-1;i>index;i--)
    {
        if(arr[i]>arr[index])
        {
            swap(arr[index],arr[i]);
            break;
        }
    }

    reverse(arr.begin() + index + 1,arr.end());
    return arr;
}
int main()
{
    int n;
    
    cout << "Enter Array Size : ";
    cin >> n;

    vector <int> arr(n);

    cout << "Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    cout << "The Next Permutation Is : ";
    arr = Next_permutation(arr,n);

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}