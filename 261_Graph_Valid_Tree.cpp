#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution{
public:
    bool validTree_bfs(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        unordered_set<int> seen;
        for (vector<int> edge : edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        queue<int> q;
        q.push(0); seen.insert(0);
        while (!q.empty()){
            int t = q.front(); q.pop();
            seen.insert(t);
            for (auto p : graph[t]){
                if (seen.count(p)) return false;
                q.push(p);
                graph[p].erase(t);
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        vector<int> seen(n, 0);
        for (vector<int> edge : edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        auto res = dfs_search(graph, seen, 0);
        if (!res) return false;
        int s = 0;
        for (int i : seen) s += i;
        return s == n;
    }
    bool dfs_search(vector<unordered_set<int>>& g, vector<int>& seen, int s){
        if (seen[s]) return false;
        seen[s] = true;
        for (int nxt : g[s]){
            g[nxt].erase(s);
            if (!dfs_search(g, seen, nxt)) return false;
        }
        return true;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<vector<int>> edges{{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout << solution->validTree(5, edges) << "\n";
    vector<vector<int>> edges2{{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    cout << solution->validTree(5, edges2) << "\n";
    return 0;
}