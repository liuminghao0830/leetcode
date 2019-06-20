#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int basic_rob(vector<int>& nums, int start, int end){
        int n = end - start + 1;
        vector<int> dp(n, 0);
        dp[0] = nums[start]; dp[1] = max(dp[0], nums[start + 1]);

        for (int i = 2; i < n; i++){
            dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]);
        }

        return dp.back();
    }
    int rob(vector<int>& nums){
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int n = nums.size();

        return max(basic_rob(nums, 0, n - 2), basic_rob(nums, 1, n - 1));
    }   
}; Solution solution;

int main(){
    vector<int> nums{1, 2, 3, 1};
    int res = solution.rob(nums);

    cout << res << endl;

    return 0;
}
