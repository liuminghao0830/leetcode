#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 1) return {0};
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        
        for (auto edge : edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i){
            if (graph[i].size() == 1) q.push(i);
        }
        
        while (n > 2){
            int s = q.size(); n -= s;            
            for (int i = 0; i < s; ++i){
                int t = q.front(); q.pop();
                for (int a : graph[t]){
                    graph[a].erase(t);
                    if (graph[a].size() == 1) q.push(a);
                }
            }
        }
        
        vector<int> res; int s = q.size();
        for (int i = 0; i < s; ++i){
            res.push_back(q.front()); q.pop();
        }
        
        return res;
    }
}; Solution solution;


int main(){
	vector<vector<int>> edges;
	edges.push_back({0, 3});
	edges.push_back({1, 3});
	edges.push_back({2, 3});
	edges.push_back({4, 3});
	edges.push_back({5, 4});
	auto res = solution.findMinHeightTrees(6, edges);

	for (auto n : res) cout << n << " ";
	cout << "\n";
    return 0;
}
