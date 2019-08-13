#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool dfs(vector<int>& nums, vector<int>& s, int p, int target){
        if (p == nums.size()) {
            return s[0] == target && s[1] == target && s[2] == target;
        }
        
        for (int i = 0; i < 4; ++i){
            if (s[i] + nums[p] > target) continue;
            s[i] += nums[p];
            if (dfs(nums, s, p + 1, target)) return true;
            s[i] -= nums[p];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;

        sort(nums.rbegin(), nums.rend());
        vector<int> s(4, 0);
        auto res = dfs(nums, s, 0, sum / 4);
        return res;
    }
};
int main(){
    vector<int> nums{3, 1, 3, 3, 7, 10, 10, 3, 6, 9, 10, 3, 7, 6, 7};
    Solution* solution = new Solution();
    cout << solution->makesquare(nums) << endl;
    return 0;
}