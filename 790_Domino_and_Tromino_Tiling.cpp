#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int numTilings(int N) {
        /* dp O(n) : 100%*/
        if (N == 1) return 1;
        else if (N == 2) return 2;
        vector<long> dp(N + 1);
        dp[1] = 1; dp[2] = 2; dp[3] = 5;
        for (int i = 4; i <= N; ++i){
            dp[i] = (2*dp[i - 1] + dp[i - 3]) % int(1e9 + 7);
        }
        return dp.back();
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->numTilings(10) << endl;
    return 0;
}