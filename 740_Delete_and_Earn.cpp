#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int deleteAndEarn(vector<int>& nums) {
        /* dp O(n) : 95% */
        vector<int> sum(10001, 0);
        for (int num : nums) sum[num] += num;

        for (int i = 2; i < 10001; ++i){
            sum[i] = max(sum[i - 2] + sum[i], sum[i - 1]);
        }
        return sum.back();
    }
    int deleteAndEarn2(vector<int>& nums) {
        vector<int> sum(10001, 0);
        for (int num : nums) sum[num] += num;

        int take = 0, skip = 0;
        for (int i = 0; i < 10001; ++i){
            int takei = skip + sum[i];
            int skipi = max(skip, take);
            take = takei; skip = skipi;
        }
        return max(take, skip);
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> nums{3, 4, 2};
    cout << solution->deleteAndEarn2(nums) << endl;
    return 0;
}