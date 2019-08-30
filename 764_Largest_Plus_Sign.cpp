#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        /*brute force O(n^3) : 7%*/
        vector<vector<int>> grid(N, vector<int>(N, 1));
        for (auto m : mines) grid[m[0]][m[1]] = 0;
        int mo = 0;
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j){
                if (!grid[i][j]) continue;
                for (int cnt = 1; cnt < N; ++cnt){
                    if (i - cnt < 0 || i + cnt >= N || j - cnt < 0 || j + cnt >= N) { mo = max(mo, cnt); break; }
                    if (!grid[i + cnt][j]) { mo = max(mo, cnt); break; }
                    if (!grid[i - cnt][j]) { mo = max(mo, cnt); break; }
                    if (!grid[i][j + cnt]) { mo = max(mo, cnt); break; }
                    if (!grid[i][j - cnt]) { mo = max(mo, cnt); break; }
                }
            }
        }
        return mo;
    }
    int orderOfLargestPlusSign_dp(int N, vector<vector<int>>& mines) {
        /* DP O(n^2) : 54%*/
        vector<vector<int>> grid(N, vector<int>(N, 1));
        for (auto m : mines) grid[m[0]][m[1]] = 0;
        vector<vector<int>> left(N, vector<int>(N, 1));
        vector<vector<int>> right(N, vector<int>(N, 1));
        vector<vector<int>> up(N, vector<int>(N, 1));
        vector<vector<int>> down(N, vector<int>(N, 1));
        for (int i = 0; i < N; ++i){
            if (!grid[i][0]) left[i][0] = 0;
            if (!grid[i][N - 1]) right[i][N - 1] = 0;
            if (!grid[N - 1][i]) down[N - 1][i] = 0;
            if (!grid[0][i]) up[0][i] = 0;
        }
        for (int i = 0; i < N; ++i){
            for (int j = 1; j < N; ++j){
                if (!grid[i][j]) {left[i][j] = 0; continue;}
                left[i][j] += left[i][j - 1];
            }
        }
        for (int i = 0; i < N; ++i){
            for (int j = N - 2; j >= 0; --j){
                if (!grid[i][j]) {right[i][j] = 0; continue;}
                right[i][j] += right[i][j + 1];
            }
        }
        for (int i = 1; i < N; ++i){
            for (int j = 0; j < N; ++j){
                if (!grid[i][j]) {up[i][j] = 0; continue;}
                up[i][j] += up[i - 1][j];
            }
        }
        for (int i = N - 2; i >= 0; --i){
            for (int j = 0; j < N; ++j){
                if (!grid[i][j]) {down[i][j] = 0; continue;}
                down[i][j] += down[i + 1][j];
            }
        }
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j){
                cout << down[i][j] << " ";
            }
            cout << "\n";
        }
        int order, max_order = 0;
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j){
                order = min(down[i][j], min(up[i][j], min(left[i][j], right[i][j])));
                max_order = max(order, max_order);
            }
        }
        return max_order;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<vector<int>> mines{{4, 2}};
    cout << solution->orderOfLargestPlusSign_dp(5, mines) << endl;
    return 0;
}