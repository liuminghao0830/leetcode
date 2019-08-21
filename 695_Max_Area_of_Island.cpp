#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& vis){
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y] || vis[x][y]) return 0;
        int area = 1; vis[x][y] = 1;
        area += dfs(grid, x + 1, y, vis);
        area += dfs(grid, x, y + 1, vis);
        area += dfs(grid, x, y - 1, vis);
        area += dfs(grid, x - 1, y, vis);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        /* DFS O(n*m) : 67% */
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int max_area = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] && !vis[i][j]){
                    max_area = max(max_area, dfs(grid, i, j, vis));
                }
            }
        }
        return max_area;
    }
    int maxAreaOfIsland_BFS(vector<vector<int>>& grid) {
        /* BFS O(n*m) : 6% */
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int max_area = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (!grid[i][j] || vis[i][j]) continue;
                queue<vector<int>> q; q.push({i, j});
                int area = 0;
                while (!q.empty()){
                    auto t = q.front(); q.pop();
                    int x = t[0], y = t[1];
                    vis[x][y] = 1; area++;
                    for (auto dir : dirs){
                        int _x = x + dir[0], _y = y + dir[1];
                        if (_x < 0 || _x >= m || _y < 0 || _y >= n || !grid[_x][_y] || vis[_x][_y]) continue;
                        q.push({_x, _y});
                        vis[_x][_y] = 1;
                    }
                }
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};

int main(){
    vector<vector<int>> grid;
    grid.push_back({1, 1, 0, 0, 0});
    grid.push_back({1, 1, 0, 0, 0});
    grid.push_back({0, 0, 0, 1, 1});
    grid.push_back({0, 0, 0, 1, 1});
    Solution* solution = new Solution();
    cout << solution->maxAreaOfIsland_BFS(grid) << endl;
    return 0;
}