#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    int cnt = 0;
public:
    void backtracking(int m, int n, int N, int i, int j){
        if (i < 0 || i >= m || j < 0 || j >= n){
            cout << i << " " << j << endl;
            cnt++; return;
        }
        else if (N <= 0) return;
        
        backtracking(m, n, N - 1, i + 1, j);
        backtracking(m, n, N - 1, i - 1, j);
        backtracking(m, n, N - 1, i, j + 1);
        backtracking(m, n, N - 1, i, j - 1);
    }
    
    int findPaths_backtracking(int m, int n, int N, int i, int j) {
        backtracking(m, n, N, i, j);
        return cnt;
    }

    int findPaths_dp(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        for (int k = 1; k <= N; ++k){
            for (int x = 0; x < m; ++x){
                for (int y = 0; y < n; ++y){
                    long int left = x == 0 ? 1 : dp[k - 1][x - 1][y];
                    long int right = x == m - 1 ? 1 : dp[k - 1][x + 1][y];
                    long int bottom = y == 0 ? 1 : dp[k - 1][x][y - 1];
                    long int up = y == n - 1 ? 1 : dp[k - 1][x][y + 1];
                    dp[k][x][y] = (left + right + up + bottom) % 1000000007;
                }
            }
        }
        return dp[N][i][j];
    }

};

int main(){
    Solution* solution = new Solution();
    cout << solution->findPaths_dp(1, 3, 3, 0, 1) << endl;
    return 0;
}