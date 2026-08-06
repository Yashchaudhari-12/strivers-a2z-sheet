#include<bits/stdc++.h>
using namespace std;

vector<int> Leader(vector <int> arr)
{
    int n = arr.size(),j=1;

    vector<int> leader;
    int max_right = arr[n-1];
    leader.push_back(max_right);

    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>max_right)
        {
            leader.push_back(arr[i]);
            max_right = arr[i];
            j++;
        }
    }
    reverse(leader.begin(),leader.end());
    return leader;
}

int main()
{
    int n;
    cout << "Enter Array Size : ";
    cin >> n;

    vector<int> arr(n);
    vector<int> leader(n);

    cout << "Enter Array Elements : ";

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    leader = Leader(arr);

    for(int i=0;i<leader.size();i++)
    {
        cout << leader[i] << " ";
    }
    cout << "\n";
    return 0;
}