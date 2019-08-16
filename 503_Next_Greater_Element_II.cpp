#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements_binary_search(vector<int>& nums) {
        int n = nums.size(); vector<int> res(n);
        vector<int> sort_nums = nums; 
        sort(sort_nums.begin(), sort_nums.end());
        
        for (int i = 0; i < n; ++i){
            auto it = upper_bound(sort_nums.begin(), sort_nums.end(), nums[i]);
            if (it != sort_nums.end()) res[i] = *it;
            else res[i] = -1;
        }
        
        return res;
    }

    vector<int> nextGreaterElements_brute_force(vector<int>& nums) {
        int n = nums.size(); vector<int> res(n, -1);
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n + i; ++j){
                if (nums[j % n] > nums[i]) {
                    res[i] = nums[j % n];
                    break;
                }
            }
        }

        return res;
    }

    vector<int> nextGreaterElements_stack(vector<int>& nums) {
        int n = nums.size(); vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 0; i < 2 * n; ++i){
            int num = nums[i % n];
            while (!stk.empty() && nums[stk.top()] > num){
                res[stk.top()] = num; stk.pop();
            }
            if (i < n) stk.push(i);
        }

        return res;
    }
};

int main(){
    vector<int> nums{1, 2, 3, 4, 3};
    Solution* solution = new Solution();
    
    auto res = solution->nextGreaterElements_binary_search(nums);
    
    for (auto n : res) cout << n << " ";
    cout << "\n";
    
    return 0;
}