#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& M, int j, vector<bool>& vis){
        vis[j] = true;
        for (int i = 0; i < M.size(); ++i){
            if (vis[i] || !M[j][i]) continue;
            dfs(M, i, vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        /*DFS O(n^2) : 50% */
        if (M.empty() || M[0].empty()) return 0;
        int n = M.size(); int cnt = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; ++i){
            if (vis[i]) continue;
            dfs(M, i, vis);
            cnt++;
        }
        return cnt;
    }
};

int main(){
    vector<vector<int>> M;
    M.push_back({1, 1, 0});
    M.push_back({1, 1, 0});
    M.push_back({0, 0, 1});
    Solution* solution = new Solution();
    cout << solution->findCircleNum(M) << endl;
    return 0;
}