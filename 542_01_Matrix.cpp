#include<bits/stdc++.h>

using namespace std;

class Solution{
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& d, int i, int j){
        int m = matrix.size(), n = matrix[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return INT_MAX;
        if (d[i][j] >= 0) return d[i][j];
        if (matrix[i][j] == 0) { d[i][j] = 0; return 0; }
        
        d[i][j] = INT_MAX;
        int left = dfs(matrix, d, i + 1, j);
        int right = dfs(matrix, d, i - 1, j);
        int up = dfs(matrix, d, i, j + 1);
        int down = dfs(matrix, d, i, j - 1);
        
        d[i][j] = min(min(left, right), min(up, down));
        if (d[i][j] != INT_MAX) d[i][j]++;

        return d[i][j];
    }
public:
    vector<vector<int>> updateMatrix_dfs(vector<vector<int>>& matrix){
        if (matrix.empty() || matrix[0].empty()) return matrix;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> distance(m, vector<int>(n, -1));

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                distance[i][j] = dfs(matrix, distance, i, j);
            }
        }

        return distance;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix){
        /*BST O(2n) : 6% */
        if (matrix.empty() || matrix[0].empty()) return matrix;
        int m = matrix.size(), n = matrix[0].size();
        queue<vector<int>> q;

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (matrix[i][j] == 0) q.push({i, j});
                else matrix[i][j] = INT_MAX;
            }
        }
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()){
            auto t = q.front(); q.pop();
            for (auto dir : dirs){
                int x = t[0] + dir[0], y = t[1] + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[t[0]][t[1]] + 1) continue;
                matrix[x][y] = matrix[t[0]][t[1]] + 1;
                q.push({x, y});
            }
        }

        return matrix;
    }
};

int main(){
    vector<vector<int>> matrix;
    matrix.push_back({0, 0, 0});
    matrix.push_back({0, 1, 0});
    matrix.push_back({1, 1, 1});
    Solution* solution = new Solution();
    auto res = solution->updateMatrix(matrix);

    for (auto s : res) {
        for (int n : s) cout << n << " ";
        cout << "\n";
    }

    return 0;
}