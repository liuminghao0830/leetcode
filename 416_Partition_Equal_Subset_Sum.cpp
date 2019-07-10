#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (n <=1 || sum % 2 != 0) return false;
        int t = sum / 2;
        
        vector<bool> dp(t + 1, false); dp[0] = true;
        
        for (int num : nums){
            for (int j = t; j >= num; --j){
                dp[j] = dp[j - num] || dp[j];
            }
        }
        
        return dp[t];
    }
};

int main(){
    vector<int> nums{5, 1, 5, 11};
    Solution* solution = new Solution();
    cout << solution->canPartition(nums) << endl;
    return 0;
}