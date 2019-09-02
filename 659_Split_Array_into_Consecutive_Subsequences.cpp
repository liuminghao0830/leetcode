#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool isPossible(vector<int>& nums) {
        /*O(n) : 50% */
        unordered_map<int, int> freq;
        for (auto num : nums) freq[num]++;
        unordered_map<int, int> tail;
        for (int i = 0; i < nums.size(); ++i){
            if (!freq[nums[i]]) continue;
            else if (tail[nums[i]] > 0){
                tail[nums[i]]--;
                tail[nums[i] + 1]++;
            }
            else if (freq[nums[i] + 1] && freq[nums[i] + 2]){
                freq[nums[i] + 1]--;
                freq[nums[i] + 2]--;
                tail[nums[i] + 3]++;
            }
            else return false;
            freq[nums[i]]--;
        }
        return true;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> nums{1, 2, 3, 3, 4, 5};
    cout << solution->isPossible(nums) << endl;
    vector<int> nums{1, 2, 3, 3, 4, 4, 5, 5};
    cout << solution->isPossible(nums) << endl;
    vector<int> nums{1, 2, 3, 4, 4, 5};
    cout << solution->isPossible(nums) << endl;
    return 0;
}