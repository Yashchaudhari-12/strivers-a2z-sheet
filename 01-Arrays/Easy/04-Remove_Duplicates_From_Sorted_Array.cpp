#include<iostream>
#include<climits>
using namespace std;

int remove_duplicates(int arr[],int n)
{
    int count = 1;
    for(int i=0,j=1;i<n-1;i++)
    {
        if(arr[i]!=arr[i+1])
        {
            arr[j]=arr[i+1];
            j++;
            count++;
        }
    }
    return count;
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
    int count = remove_duplicates(arr,n);

    cout << "The Modified Array Has " << count << " Elements" << endl;
    
    for(int i=0;i<count;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}