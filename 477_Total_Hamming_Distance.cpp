#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalHammingDistance_brute_force(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int n = nums.size(); int cnt = 0;
        
        for (int i = 0; i < n - 1; ++i){
            for (int j = i + 1; j < n; ++j){
                int XOR = nums[i] ^ nums[j];
                while (XOR > 0) {
                    if (XOR % 2) cnt++;
                    XOR /= 2;
                }
            }
        }
        return cnt;
    }

    int totalHammingDistance(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int n = nums.size(), res = 0;
        for (int i = 0; i < 32; ++i){
            int cnt = 0;
            for (int num : nums){
                if (num & (1 << i)) cnt++;
            }
            res += (n - cnt) * cnt;
        }
        return res;
    }
};

int main(){
    vector<int> nums{4, 14, 2};
    Solution* solution = new Solution();
    cout << solution->totalHammingDistance(nums) << endl;
    return 0;
}