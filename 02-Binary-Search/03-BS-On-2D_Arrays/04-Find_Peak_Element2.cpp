#include <bits/stdc++.h>
using namespace std;

int max_elem_idx(vector<vector<int>> &mat, int n, int col)
{
    int max_value = -1;
    int max_idx = -1;

    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > max_value)
        {
            max_value = mat[i][col];
            max_idx = i;
        }
    }
    return max_idx;
}

vector<int> peak_index(vector<vector<int>> &mat, int n, int m)
{

    int low = 0, high = m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int largest_idx = max_elem_idx(mat, n, mid);

        int left = mid - 1 >= 0 ? mat[largest_idx][mid - 1] : -1;
        int right = mid + 1 < m ? mat[largest_idx][mid + 1] : -1;

        if (mat[largest_idx][mid] > left && mat[largest_idx][mid] > right)
        {
            return {largest_idx, mid};
        }
        else if (mat[largest_idx][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}

int main()
{
    int n, m;

    cout << "Enter No Of Rows : ";
    cin >> n;
    cout << "Enter No Of Columns : ";
    cin >> m;

    vector<vector<int>> nums(n, vector<int>(m));

    cout << "Enter Matrix Elements : ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }

    vector<int> ans = peak_index(nums, n, m);

    cout << "Peak Element Index Is : ";

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}
