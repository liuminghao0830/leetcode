#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 0); vector<int> parent(n, 0);
        int mx = 0; int mx_id;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (nums[j]%nums[i] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (mx < dp[i]){
                        mx = dp[i];
                        mx_id = i;
                    }
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < mx; ++i) {
            res.push_back(nums[mx_id]);
            mx_id = parent[mx_id];
        }

        return res;
    }

}; Solution solution;


int main(){
    vector<int> nums{1,2,4,8};

    auto res = solution.largestDivisibleSubset(nums);

    for (auto n : res) cout << n << " ";
    cout << "\n";

    return 0;
}
