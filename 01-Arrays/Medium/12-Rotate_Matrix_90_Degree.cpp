#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector <int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            swap(matrix[j][i],matrix[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}
int main()
{
    int n;
    int m;

    cout << "Enter No Of Rows : ";
    cin >> n;
    cout << "Enter No Of Columns : ";
    cin >> m;

    vector<vector <int>> matrix(n, vector<int>(m));

    cout << "Enter Matrix Elements : " << "\n";
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matrix[i][j];
        }
    }

    rotate(matrix);

    cout << "The Clockwise 90 Degree Rotated Matrix Is : " << "\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}