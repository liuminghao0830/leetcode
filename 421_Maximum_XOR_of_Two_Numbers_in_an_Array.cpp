#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaximumXOR_brute_force(vector<int>& nums) {
        /* Brute foce O(N^2): TLE */
        int n = nums.size(); int max_xor = 0;
        for (int i = 0; i < n - 1; ++i){
            for (int j =  i + 1; j < n; ++j){
                max_xor = max(max_xor, nums[i] ^ nums[j]);
            }
        }
        return max_xor;
    }

    int findMaximumXOR(vector<int>& nums) {
        int mask = 0; int res = 0;
        for (int i = 31; i >= 0; --i){
            unordered_set<int> s;
            mask |= 1 << i;
            for (int n : nums) s.insert(n & mask);
            
            int g = res | (1 << i);
            for (int p : s){
                if (s.count(p ^ g)) {
                    res = g;
                    break;
                }
            }
        }
        return res;
    }
};


int main(){
    vector<int> nums{15, 15, 9, 3, 2};
    Solution* solution = new Solution();
    cout << solution->findMaximumXOR(nums) << endl;
    return 0;
}