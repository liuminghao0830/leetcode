#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int minSteps_dp(int n){
        /* O(n^2) : 23% */
        if (n <= 1) return 0;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i){
            dp[i] = i;
            for (int j = 1; j < i; ++j){
                if (i % j != 0) continue;
                dp[i] = min(dp[i], i / j + dp[j]);
            }
        }
        return dp[n];
    }
    
    int minSteps(int n){
        if (n <= 1) return 0;
        int res = n;
        for (int i = 2; i < n; ++i){
            if (n % i != 0) continue;
            res = min(res, minSteps(n / i) + i);
        }
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->minSteps(18) << endl;
    return 0;
}