#include<bits/stdc++.h>

using namespace std;

class Solution{
private:
    int min_price = INT_MAX;
    void recursion(unordered_map<int, vector<vector<int>>>& m, vector<vector<int>>& flights, 
                                        vector<bool>& vis, int src, int dst, int K, int p){
        if (src == dst) { min_price = p; return; }
        if (K < 0) return;

        for (auto flight : m[src]){
            if (vis[flight[0]] || p + flight[1] > min_price) continue;
            vis[flight[0]] = true;
            recursion(m, flights, vis, flight[0], dst, K - 1, p + flight[1]);
            vis[flight[0]] = false;
        }
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        /* DFS O(m^K) : 5% */
        unordered_map<int, vector<vector<int>>> m;
        for (auto flight : flights) m[flight[0]].push_back({flight[1], flight[2]});

        vector<bool> vis(n, false);
        recursion(m, flights, vis, src, dst, K, 0);
        return min_price == INT_MAX ? -1 : min_price;
    }

    int findCheapestPrice_dp(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        /* dp O(m * K) : 20% */
        vector<vector<int>> dp(K + 2, vector<int>(n, 1e9));
        dp[0][src] = 0;
        for (int i = 1; i <= K + 1; ++i){
            dp[i][src] = 0;
            for (auto flight : flights){
                dp[i][flight[1]] = min(dp[i][flight[1]], dp[i - 1][flight[0]] + flight[2]);
            }
        }
        return dp[K + 1][dst] > 1e9 ? -1 : dp[K + 1][dst];
    }
};

int main(){
    Solution* solution = new Solution();
    vector<vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << solution->findCheapestPrice_dp(3, flights, 0, 2, 1) << endl;
    return 0;
}