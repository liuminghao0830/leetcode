#include<bits/stdc++.h>

using namespace std;

class Solution{
private:
    bool hasCycle(unordered_map<int, unordered_set<int>>& m, 
                                    int s, int e, int pre){
        if (m[s].count(e)) return true;
        for (auto t : m[s]){
            if (t == pre) continue;
            if (hasCycle(m, e, t, s)) return true;
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> m;
        for (auto edge : edges){
            if (hasCycle(m, edge[0], edge[1], -1)) return edge;
            m[edge[0]].insert(edge[1]);
            m[edge[1]].insert(edge[0]);
        }
        return {};
    }
};

int main(){
    Solution* solution = new Solution();
    vector<vector<int>> edges{{1, 2}, {1, 3}, {2, 3}};
    auto res = solution->findRedundantConnection(edges);
    for (auto n : res) cout << n << " ";
    cout << "\n";
    return 0;
}