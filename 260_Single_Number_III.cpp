#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber_set(vector<int>& nums) {
        unordered_set<int> s;
        for (auto n : nums){
            if (s.count(n)) s.erase(n);
            else s.insert(n);
        }

        vector<int> res(s.begin(), s.end());
        return res;
    }

    vector<int> singleNumber(vector<int>& nums) {
        int AXORB = 0;
        for (auto n : nums) AXORB ^= n;
        
        vector<int> res(2, 0);
        AXORB &= -AXORB;
        for (auto n : nums){
            if (n & AXORB) res[0] ^= n;
            else res[1] ^= n;
        }
        return res;
    }
};

int main(){
    vector<int> nums{1, 2, 1, 3, 2, 5};
    Solution* solution = new Solution();
    auto res = solution->singleNumber(nums);
    for (auto n : res) cout << n << " ";
    cout << "\n";
    return 0;
}