#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i){
            vector<bool> vis(n, false);
            int cur = i; int cnt = 0;
            while (!vis[cur]){
                vis[cur] = true;
                int next = (n + (cur + nums[cur]) % n) % n;
                if ((nums[next] * nums[i] < 0) || (next == cur)) break;
                else if (vis[next] && (cnt > 0)) return true;
                cur = next; cnt++;
            }
        }
        
        return false;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> nums{2, -1, 1, 2, 2};
    cout << solution->circularArrayLoop(nums) << endl;
    return 0;
}