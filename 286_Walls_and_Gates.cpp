#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    void dfs(vector<vector<int>>& rooms, vector<vector<bool>>& seen,
                                            int x, int y, int d){
        if (seen[x][y]) return;
        seen[x][y] = true;
        int m = rooms.size(), n = rooms[0].size();
        rooms[x][y] = min(rooms[x][y], d);
        if (x < m - 1 && rooms[x + 1][y] > d) dfs(rooms, seen, x + 1, y, d + 1);
        if (y < n - 1 && rooms[x][y + 1] > d) dfs(rooms, seen, x, y + 1, d + 1);
        if (x > 0 && rooms[x - 1][y] > d) dfs(rooms, seen, x - 1, y, d + 1);
        if (y > 0 && rooms[x][y - 1] > d) dfs(rooms, seen, x, y - 1, d + 1);
        seen[x][y] = false;
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        for (int x = 0; x < m; ++x){
            for (int y = 0; y < n; ++y){
                if (rooms[x][y] == 0) dfs(rooms, seen, x, y, 0);
            }
        }
    }
    void print_rooms(vector<vector<int>>& rooms);
};

void Solution::print_rooms(vector<vector<int>>& rooms){
    for (auto row : rooms) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }
};

int main(){
    Solution* solution = new Solution();
    vector<vector<int>> rooms;
    int INF = 2147483647;
    rooms.push_back({INF, -1, 0, INF});
    rooms.push_back({INF, INF, INF, -1});
    rooms.push_back({INF, -1, INF, -1});
    rooms.push_back({0, -1, INF, INF});
    solution->wallsAndGates(rooms);
    solution->print_rooms(rooms);
    return 0;
}