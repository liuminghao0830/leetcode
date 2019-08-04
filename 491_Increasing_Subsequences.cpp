#include<bits/stdc++.h>

using namespace std;

class Solution{
private:
    set<vector<int>> dup_set;

    void dfs(vector<vector<int>>& res, vector<int>& nums, int i){
        if (i >= nums.size()) return;
        if (res.empty()) {
            res.push_back({nums[i]});
            dfs(res, nums, i + 1);
        }
        else {
            int n = res.size();
            for (int j = 0; j < n; ++j) {
                if (res[j].back() <= nums[i]) {
                    res.push_back(res[j]);
                    res[j].push_back(nums[i]);
                }
                if (res[j].size() > 1) dup_set.insert(res[j]);
            }
            res.push_back({nums[i]});
            dfs(res, nums, i + 1);
        }
    }

public:
    vector<vector<int>> findSubsequences_recursion(vector<int>& nums){
        if (nums.size() < 2) return {};
        vector<vector<int>> temp;
        
        dfs(temp, nums, 0);
        
        return vector<vector<int>> (dup_set.begin(), dup_set.end());
    }

    vector<vector<int>> findSubsequences_iteration(vector<int>& nums){
        if (nums.size() < 2) return {};
        set<vector<int>> res;
        vector<vector<int>> temp;
        for (int i = 0; i < nums.size(); ++i){
            if (temp.empty()) {
                temp.push_back({nums[i]});
                continue;
            }
            int n = temp.size();
            for (int j = 0; j < n; ++j){
                if (temp[j].back() <= nums[i]) {
                    temp.push_back(temp[j]);
                    temp[j].push_back(nums[i]);
                }
                if (temp[j].size() > 1) res.insert(temp[j]);
            }
            temp.push_back({nums[i]});
        }

        return vector<vector<int>> (res.begin(), res.end());
    }
};

int main(){
    Solution solution;
    vector<int> nums{4, 6, 7, 7};
    auto res = solution.findSubsequences_iteration(nums);

    for (auto s : res) {
        for (int n : s) cout << n << " ";
        cout << "\n";
    }

    return 0;
}