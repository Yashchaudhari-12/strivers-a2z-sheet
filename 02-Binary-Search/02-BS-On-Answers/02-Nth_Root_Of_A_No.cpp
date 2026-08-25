#include <bits/stdc++.h>
using namespace std;

long long power_exp(int mid, int n)
{
    long long ans = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans *= mid;
            n--;
        }
        else
        {
            mid = 1LL * mid * mid;
            n = n / 2;
        }
    }
    return ans;
}

int nth_root(int n, int m)
{
    int low = 1;
    int high = m, ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        long long power = power_exp(mid, n);

        if (power == m)
        {
            return mid;
        }
        else if (power < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n, m, k;

    cout << "Enter Root No : ";
    cin >> n;

    cout << "Enter No : ";
    cin >> m;

    k = nth_root(n, m);

    cout << "The Root Of Given Element is : " << k << "\n";
    return 0;
}