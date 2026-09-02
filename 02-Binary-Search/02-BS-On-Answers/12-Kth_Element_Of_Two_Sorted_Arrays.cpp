#include <bits/stdc++.h>
using namespace std;

int kth_elem(vector<int> &a, vector<int> &b, int k)
{
    int n1 = a.size();
    int n2 = b.size();
    int low = max(0, k - n2), high = min(k, n1);
    int left = k;

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l2 > r1)
        {
            low = mid1 + 1;
        }
        else
        {
            high = mid1 - 1;
        }
    }
    return 0;
}

int main()
{
    int n1, n2, k;

    cout << "Enter Array Size : ";
    cin >> n1 >> n2;

    vector<int> a(n1), b(n2);

    cout << "Enter Array Elements for A array : ";
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }

    cout << "Enter Array Elements for B array : ";
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    cout << "Enter Elements Position : ";
    cin >> k;

    int m = kth_elem(a, b, k);

    cout << "The Kth Element In Sorted Arrays Is : " << m << "\n";
    return 0;
}