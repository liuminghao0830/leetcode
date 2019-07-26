#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool find132pattern_brute_force(vector<int>& nums) {
        int n = nums.size(); int mn = INT_MAX;
        for (int i = 0; i < n; ++i){
            mn = min(mn, nums[i]);
            if (mn == nums[i]) continue;
            for (int j = i + 1; j < n; ++j){
                if (mn < nums[j] && nums[i] > nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool find132pattern_stack(vector<int>& nums){
        stack<int> stk; int third = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i){
            if (nums[i] < third) return true;
            while(!stk.empty() && nums[i] > stk.top()){
                third = stk.top(); stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};

int main(){
    vector<int> nums{3, 1, 4, 2};
    Solution* solution = new Solution();
    cout << solution->find132pattern_stack(nums) << endl;
    return 0;
}