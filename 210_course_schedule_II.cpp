#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res; vector<int> indeg(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());
        
        for (auto pre : prerequisites){
            graph[pre[1]].push_back(pre[0]);
            indeg[pre[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i){
            if (!indeg[i]) q.push(i);
        }
        
        while (!q.empty()){
            auto t = q.front(); q.pop();
            res.push_back(t);
            for (auto a : graph[t]){
                indeg[a]--;
                if (!indeg[a]) q.push(a); 
            }
        }
        
        if (res.size() != numCourses) return {};
        else return res;
    }
}; Solution solution;


int main(){
    vector<vector<int>> prerequisites{{1,0}, {2,0}, {3,1}, {3,2}};
    auto res = solution.findOrder(4, prerequisites);

    for (auto n : res) cout << n << " ";
    cout << "\n";

    return 0;
}
