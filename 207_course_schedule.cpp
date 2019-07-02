#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> vis(numCourses, 0);
        
        for (auto pre : prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }
        
        for (int i = 0; i < numCourses; ++i){
            if (!dfs(graph, vis, i)) return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<int>> &graph, vector<int> &vis, int s){
        if (vis[s] == 1) return true;
        if (vis[s] == -1) return false;
        
        vis[s] = -1;
        
        for (auto t : graph[s]){
            if (!dfs(graph, vis, t)) return false;
        }
        
        vis[s] = 1;
        return true;
    }
}; Solution solution;

int main(){
    vector<vector<int>> prerequisites{{1,0}, {2,0}, {3,1}, {3,2}};
    auto res = solution.canFinish(4, prerequisites);
    
    cout << res << endl;

    return 0;
}
