#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n - 2; ++i){
            int left = i + 1, right = n - 1;
            while (left < right) {
                int s = nums[i] + nums[left] + nums[right];
                if (s >= target) right--;
                else {
                    cnt += right - left;
                    left++;
                }
            }
        }
        return cnt;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> nums{-2, 0, 1, 3};
    cout <<  solution->threeSumSmaller(nums, 4) << "\n";
    return 0;
}