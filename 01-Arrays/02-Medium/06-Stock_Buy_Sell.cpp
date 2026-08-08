#include<bits/stdc++.h>
using namespace std;

int maxprofit(int arr[],int n)
{
    int buying_price = arr[0];
    int max_profit = 0;

    for(int i=0;i<n-1;i++)
    {
      if(buying_price >= arr[i])
      {
        buying_price = arr[i];
      }
      max_profit = max(arr[i+1]-buying_price,max_profit);   
    }
    return max_profit;
}
int main()
{
    int n,m;
    cout << "Enter Array Size : ";
    cin >> n;
    int arr[n];

    cout << "Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    m = maxprofit(arr,n);

    cout << "The Max Profit Is : " << m << "\n";
    return 0;
}