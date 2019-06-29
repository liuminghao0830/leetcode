#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int dp_wiggleMaxLength(vector<int>& nums){
        if (nums.empty()) return 0;

        vector<int> up(nums.size(), 1);
        vector<int> dn(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i){
            for (int j = 0; j < i; ++j){
                if (nums[i] - nums[j] > 0) up[i] = max(up[i], dn[j] + 1);
                else if (nums[i] - nums[j] < 0) dn[i] = max(dn[i], up[j] + 1);
            }
        }

        return max(up.back(), dn.back());
    }

    int greedy_wiggleMaxLength(vector<int>& nums){
        int n = nums.size();
        if (n <= 1) return n;

        int up = 1; int dn = 1;

        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] - nums[i - 1] < 0) up = dn + 1;
            if (nums[i] - nums[i - 1] > 0) dn = up + 1;
        }

        return max(up, dn);
    }
}; Solution solution;


int main(){
    vector<int> nums{1,17,5,10,13,15,10,5,16,8};
    int res = solution.greedy_wiggleMaxLength(nums);

    cout << res << endl;

    return 0;
}
