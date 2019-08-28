#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        /* O(n^2) : 70%*/
        int n = nums.size(), max_len = 0, max_cnt = 0;
        vector<int> dp(n, 1), cnt(n, 1);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (nums[j] >= nums[i]) continue;
                if (dp[i] == dp[j] + 1) cnt[i] += cnt[j];
                else if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
            }
            max_len = max(max_len, dp[i]);
        }
        for (int i = 0; i < n; ++i){
            if (dp[i] == max_len) max_cnt += cnt[i];
        }
        return max_cnt;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> nums{1, 3, 5, 4, 7};
    cout << solution->findNumberOfLIS(nums) << endl;
    return 0;
}