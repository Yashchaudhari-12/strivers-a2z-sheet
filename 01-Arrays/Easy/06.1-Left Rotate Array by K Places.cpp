#include <iostream>
using namespace std;

void move_left(int arr[], int n, int k)
{
    int temp[k];
    k = k % n;
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];
    }
    for (int i = 0; i < k; i++)
    {
        arr[n - k + i] = temp[i];
    }
}
int main()
{
    int n, k;
    cout << "Enter Array Size : ";
    cin >> n;
    int arr[n];
    cout << "Enter Array Elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter Places To Be Rotated Left : ";
    cin >> k;

    move_left(arr, n, k);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}