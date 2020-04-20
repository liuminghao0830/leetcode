#include<iostream>
#include<vector>

using namespace std;

class Solution {
// DFS time complexity: O(n)
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& seen, int s){
        if (seen[s]) return;
        seen[s] = true;
        for (int i : graph[s]){
            dfs(graph, seen, i);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        for (auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int cnt = 0;
        vector<bool> seen(n, false);
        for (int i = 0; i < n; ++i){
            if (seen[i]) continue;
            dfs(graph, seen, i);
            cnt++;
        }
        return cnt;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<vector<int>> edges{{0, 1}, {1, 2}, {3, 4}};
    cout << solution->countComponents(5, edges) << "\n";
    return 0;
}