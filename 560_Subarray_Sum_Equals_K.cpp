#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0; int sum = 0;
        unordered_map<int, int> m; m[0] = 1;
        
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if (m.count(sum - k)) cnt += m[sum - k];
            m[sum]++;
        }
        
        return cnt;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> nums{1, 1, 1};
    
    cout << solution->subarraySum(nums, 2) << endl;

    return 0;
}