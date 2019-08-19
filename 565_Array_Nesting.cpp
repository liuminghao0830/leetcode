#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int arrayNesting(vector<int>& nums){
        /* O(n) : 96% */
        if (nums.empty()) return 0;
        vector<int> vis(nums.size(), 0);
        int max_len = 0;

        for (int i = 0; i < nums.size(); ++i){
            if (vis[i]) continue;
            int cnt = 0; int j = i;
            while (!vis[j]){
                vis[j] = 1; j = nums[j];
                cnt++;
            }
            max_len = max(max_len, cnt);
        }
        return max_len;
    }
};

int main(){
    vector<int> nums{5, 4, 0, 3, 1, 6, 2};
    Solution* solution = new Solution();
    cout << solution->arrayNesting(nums) << endl;
    return 0;
}