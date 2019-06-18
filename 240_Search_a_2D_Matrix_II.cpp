#include<bits/stdc++.h>

using namespace std;

/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if (matrix.empty() || matrix[0].empty()) return false;
        if (matrix[0][0] > target || matrix.back().back() < target) return false;
        int x = matrix.size() - 1, y = 0;

        while (true){
            if (matrix[x][y] < target) ++y;
            else if (matrix[x][y] > target) --x;
            else return true;
            if (y >= matrix[0].size() || x < 0) break;
        }

        return false;
    }
}; Solution solution;


int main(){
    vector<vector<int>> matrix;
    matrix.push_back({1, 4, 7, 11, 15});
    matrix.push_back({2, 5, 8, 12, 19});
    matrix.push_back({3, 6, 9, 16, 22});
    matrix.push_back({10, 13, 14, 17, 24});
    matrix.push_back({18, 21, 23, 26, 30});
    int target = 20;

    bool res = solution.searchMatrix(matrix, target);

    cout << res << endl;

    return 0;
}
