#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    /* DFS O(n^2) : 94% */
    void dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& vis){
        int m = matrix.size(), n = matrix[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j]) return;
        vis[i][j] = 1;
        if (i < m - 1 && matrix[i][j] <= matrix[i + 1][j]) dfs(i + 1, j, matrix, vis);
        if (i > 0 && matrix[i][j] <= matrix[i - 1][j]) dfs(i - 1, j, matrix, vis);
        if (j < n - 1 && matrix[i][j] <= matrix[i][j + 1]) dfs(i, j + 1, matrix, vis);
        if (j > 0 && matrix[i][j] <= matrix[i][j - 1]) dfs(i, j - 1, matrix, vis);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        for (int j = 0; j < n; ++j){
            dfs(0, j, matrix, pacific);
            dfs(m - 1, j, matrix, atlantic);
        }

        for (int i = 0; i < m; ++i){
            dfs(i, 0, matrix, pacific);
            dfs(i, n - 1, matrix, atlantic);
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }

        return res;
    }
};

int main(){
    vector<vector<int>> matrix;
    matrix.push_back({1, 2, 2, 3, 5});
    matrix.push_back({3, 2, 3, 4, 4});
    matrix.push_back({2, 4, 5, 3, 1});
    matrix.push_back({6, 7, 1, 4, 5});
    matrix.push_back({5, 1, 1, 2, 4});
    
    Solution* solution = new Solution();
    auto res = solution->pacificAtlantic(matrix);

    for (auto m : res) {
        cout << m[0] << " " << m[1] << endl;
    }

    return 0;
}