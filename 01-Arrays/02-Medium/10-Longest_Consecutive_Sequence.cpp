#include<bits/stdc++.h>
using namespace std;

int longest_seq(vector<int> arr)
{
    int longest = 1;
    unordered_set <int> a;
    int n= arr.size();

    for(int i=0;i<n;i++)
    {
        a.insert(arr[i]);
    }

    for(auto it : a)
    {
        if(a.find(it-1) == a.end())
        {
            int x = it;
            int count = 1;
            while(a.find(x+1) != a.end())
            {
                count++;
                x = x+1;
            }
            longest = max(longest,count);
        }
    }
    return longest;
}

int main()
{
    int n,m;
    cout << "Enter Array Size : ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    m = longest_seq(arr);

    cout << "The Longest Sequence Of Consecutive Elements Is : " << m << "\n";
    return 0;
}
