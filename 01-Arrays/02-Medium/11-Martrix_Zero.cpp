#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                if(j != 0){
                    matrix[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i=0;i<n;i++){
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    int n,m;

    cout << "Enter No Of Rows : ";
    cin >> n;

    cout << "Enter No Of Columns : ";
    cin >> m;

    vector<vector<int>> matrix(n,vector<int>(m));

    cout << "Enter Matrix Elements : " << "\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    cout << "After Setting Zeroes : " << "\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;

}