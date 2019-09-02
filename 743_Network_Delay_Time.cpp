#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        /* Dijkstra : O(N^2) : 75% */
        vector<int> d(N + 1, INT_MAX); d[K] = 0; // distance from K to v
        vector<vector<int>> edges(N + 1, vector<int>(N + 1, -1));
        for (auto time : times) edges[time[0]][time[1]] = time[2];
        queue<int> q; q.push(K);
        while (!q.empty()){
            vector<bool> vis(N + 1, false);
            int n = q.size();
            for (int i = 0; i < n; ++i){
                int u = q.front(); q.pop();
                for (int v = 1; v <= N; ++v){
                    if (edges[u][v] != -1 && d[u] + edges[u][v] < d[v]){
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                        d[v] = d[u] + edges[u][v];
                    }
                }
            }
        }
        int tot_time = 0;
        for (int i = 1; i <= N; ++i){
            tot_time = max(tot_time, d[i]);
        }
        return tot_time == INT_MAX ? -1 : tot_time;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<vector<int>> times{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << solution->networkDelayTime(times, 4, 2) << endl;
    return 0;
}