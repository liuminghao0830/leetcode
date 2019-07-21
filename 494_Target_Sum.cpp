#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int cnt = 0;
public:
    void recursion(vector<int>& nums, int p, long long int s){
        if (p >= nums.size()){
            if (s == 0) cnt++;
            return;
        }
        
        recursion(nums, p + 1, s - nums[p]);
        recursion(nums, p + 1, s + nums[p]);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        recursion(nums, 0, S);
        return cnt;
    }
};

int main(){
    vector<int> nums{1, 1, 1, 1, 1};
    Solution* solution = new Solution();
    cout << solution->findTargetSumWays(nums, 3) << endl;
    return 0;
}