#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int findMaxForm(vector<string>& strs, int m, int n){
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto str : strs){
            int ones = 0; int zeros = 0;
            for (char c : str) c == '1' ? ones++ : zeros++;
            for (int i = m; i >= zeros; --i ){
                for (int j = n; j >= ones; --j){
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp.back().back();
    }
};

int main(){
    Solution* solution = new Solution();
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    int m = 5; int n = 3;
    cout << solution->findMaxForm(strs, m, n) << endl;

    return 0;
}