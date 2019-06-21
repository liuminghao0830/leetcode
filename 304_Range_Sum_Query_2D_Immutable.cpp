#include<bits/stdc++.h>

using namespace std;

/*
Given a 2D matrix matrix, find the sum of the elements inside 
the rectangle defined by its upper left corner (row1, col1) 
and lower right corner (row2, col2).
*/


class NumMatrix {
public:
    vector<vector<int>> sum_array;

    NumMatrix(vector<vector<int>>& matrix) {
        sum_array = matrix;
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[0].size(); ++j){
                if (j == 0) continue;
                else sum_array[i][j] += sum_array[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i){
            if (col1 == 0) sum += sum_array[i][col2];
            else {
                sum += sum_array[i][col2] - sum_array[i][col1 - 1];
            }
        }

        return sum;
    }
};


int main(){
    vector<vector<int>> matrix;
    matrix.push_back({3, 0, 1, 4, 2});
    matrix.push_back({5, 6, 3, 2, 1});
    matrix.push_back({1, 2, 0, 1, 5});
    matrix.push_back({4, 1, 0, 1, 7});
    matrix.push_back({1, 0, 3, 0, 5});

    NumMatrix* obj = new NumMatrix(matrix);
    int param_1 = obj->sumRegion(2, 1, 4, 3);

    cout << param_1 << endl;
    
    return 0;
}
