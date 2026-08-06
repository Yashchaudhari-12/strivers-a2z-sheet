#include<iostream>
using namespace std;

int union_sorted(int arr1[],int arr2[],int temp[],int n,int m)
{
    int k = 0,i=0,j=0;

    while(i < n && j < m)
    {
        if(arr1[i]<arr2[j])
        {
            if(k==0 || temp[k-1]!=arr1[i])
            {
                temp[k]=arr1[i];
                k++;
            }
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            if(k == 0 || temp[k-1]!=arr2[j])
            {
                temp[k]=arr2[j];
                k++;
            }
            j++;
        }
        else
        {
            if(k==0 || temp[k-1]!=arr1[i])
            {
                temp[k]=arr1[i];
                k++;
            }
            i++;
            j++;
        }
    }
    while(i<n)
    {
        if(k==0 || temp[k-1]!=arr1[i])
        {
            temp[k]=arr1[i];
            k++;
        }
        i++;
    }
    while(j<m)
    {
        if(k==0 || temp[k-1]!=arr2[j])
        {
            temp[k]=arr2[j];
            k++;
        }
        j++;
    }
    return k;
}

int main()
{
    int n,m;
    cout << "Enter Both Array Sizes : ";
    cin >> n >> m;

    int arr1[n],arr2[m],temp[n+m];

    cout << "Enter Array Elements For 1st Array : ";
    for(int i=0;i<n;i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter Array Elements for 2nd Array : ";
    for(int i=0;i<m;i++)
    {
        cin >> arr2[i];
    }

    int k = union_sorted(arr1,arr2,temp,n,m);

    for(int i=0;i<k;i++)
    {
        cout << temp[i] << " ";
    }
}