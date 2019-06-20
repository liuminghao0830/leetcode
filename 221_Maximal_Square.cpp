#include<bits/stdc++.h>

using namespace std;

/*
Given a 2D binary matrix filled with 0's and 1's, find the 
largest square containing only 1's and return its area.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int max_area = 0;
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 || j == 0) dp[i][j] = matrix[i][j] == '1' ? 1 : 0; 
                else if (matrix[i][j] == '1'){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
                max_area = max(max_area, dp[i][j]*dp[i][j]);
            }
        }
        
        return max_area;
    }
}; Solution solution;

int main(){
    vector<vector<char>> matrix;
    matrix.push_back({'0', '1', '1', '1'});
    matrix.push_back({'0', '1', '1', '1'});
    matrix.push_back({'0', '1', '1', '1'});
    matrix.push_back({'0', '1', '1', '1'});

    int res = solution.maximalSquare(matrix);

    cout << res << endl;

    return 0;
}
