#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        /*DP O(m * n) : 30% */
        int m = A.size(), n = B.size(); int max_len = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; --i){
            for (int j = n - 1; j >= 0; --j){
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
                max_len = max(dp[i][j], max_len);
            }
        }
        return max_len;
    }
};

int main(){
    vector<int> A{1, 2, 3, 2, 1};
    vector<int> B{3, 2, 1, 4, 7};
    Solution* solution = new Solution();
    cout << solution->findLength(A, B) << endl;
    return 0;
}