#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool checkSubarraySum(vector<int>& nums, int k){
        if (nums.size() < 2) return false;
        for (int i = 0; i < nums.size(); ++i){
            int sum = nums[i];
            for (int j = i + 1; j < nums.size(); j++){
                sum += nums[j];
                if ((sum == k) || (k != 0 && sum % k == 0)) return true;
            }
        }
        return false;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> nums{23, 2, 4, 6, 7}; int k = 6;
    bool res = solution->checkSubarraySum(nums, k);
    cout << res << endl;
    return 0;
}