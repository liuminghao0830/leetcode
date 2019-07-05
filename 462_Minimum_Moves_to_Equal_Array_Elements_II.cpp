#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums){
        sort(nums.begin(), nums.end());
        long long int mid = nums[nums.size() / 2];
        long long int res = 0;
        for (long long num : nums) res += abs(num - mid);

        return res;
    }
}; Solution solution;

int main(){
    std::vector<int> nums{1, 2, 3};
    int res = solution.minMoves2(nums);

    cout << res << endl;
    return 0;
}