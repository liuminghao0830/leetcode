#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> dirs{{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    double recursion(vector<vector<vector<double>>>& memo, int N, int k, int i, int j){
        if (k == 0) return 1.0;
        if (memo[k][i][j] != 0.0) return memo[k][i][j];
        for (auto dir : dirs){
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || x >= N || y < 0 || y >= N) continue;
            memo[k][i][j] += recursion(memo, N, k - 1, x, y);
        }
        return memo[k][i][j];
    }
public:
    double knightProbability_dp(int N, int K, int r, int c) {
        /* O(K*N*N) : 14% */
        if (K == 0) return 1;
        vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N, 0)));
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j){
                dp[0][i][j] = 1;
            }
        }
        for (int m = 1; m <= K; ++m){
            for (int i = 0; i < N; ++i){
                for (int j = 0; j < N; ++j){
                    for (auto dir : dirs){
                        int x = i + dir[0], y = j + dir[1];
                        if (x < 0 || x >= N || y < 0 || y >= N) continue;
                        dp[m][i][j] += dp[m - 1][x][y];
                    }
                }
            }
        }
        return dp[K][r][c] / pow(8, K);
    }
    double knightProbability(int N, int K, int r, int c) {
        /* O(K*N*N) : 20% */
        if (K == 0) return 1;
        vector<vector<vector<double>>> memo(K + 1, vector<vector<double>>(N, vector<double>(N, 0)));
        
        return recursion(memo, N, K, r, c) / pow(8, K);
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->knightProbability(8, 30, 6, 4) << endl;
    return 0;
}