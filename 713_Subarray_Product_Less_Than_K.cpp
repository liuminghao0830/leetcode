#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*sliding window O(n) : 60% */
        int product = 1, left = 0, cnt = 0;
        for (int i = 0; i < nums.size(); ++i){
            product *= nums[i];
            while (product >= k) {
                product /= nums[left++];
            }
            cnt += i - left + 1;
        }
        return cnt;
    }
};

int main(){
    vector<int> nums{10, 5, 2, 6};
    Solution* solution = new Solution();
    cout << solution->numSubarrayProductLessThanK(nums, 100) << endl;
    return 0;
}