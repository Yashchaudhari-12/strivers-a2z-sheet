#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> four_sum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    k++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n, target;

    cout << "Enter Array Size : ";
    cin >> n;

    vector<vector<int>> ans;
    vector<int> nums(n);

    cout << "Enter Elements Of Array : ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter A Target : ";
    cin >> target;

    ans = four_sum(nums, target);

    for (auto x : ans)
    {
        for (int it : x)
        {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}