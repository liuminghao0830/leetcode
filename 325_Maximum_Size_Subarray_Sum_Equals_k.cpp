#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // time complexity: O(n)
        nums.insert(nums.begin(), 0);
        unordered_map<int, int> smap;
        smap[0] = 0; int max_len = 0;
        for (int i = 1; i < nums.size(); ++i){
            nums[i] += nums[i - 1];
            if (smap.count(nums[i] - k))
                max_len = max(max_len, i - smap[nums[i] - k]);
            if (smap.count(nums[i])) smap[nums[i]] = min(i, smap[nums[i]]);
            else smap[nums[i]] = i;
            
        }
        return max_len;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> nums{1, -1, 5, -2, 3};
    cout << solution->maxSubArrayLen(nums, 3) << "\n";
    vector<int> nums2{-2, -1, 2, 1};
    cout << solution->maxSubArrayLen(nums2, 1) << "\n";
    return 0;
}