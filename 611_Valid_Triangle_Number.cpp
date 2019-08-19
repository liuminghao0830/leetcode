#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int triangleNumber(vector<int>& nums){
        /*binary search O(n^2*log(n)) : 34% */
        int n = nums.size(); int cnt = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i){
            for (int j = i + 1; j < n - 1; ++j){
                int right = n, left = j + 1;
                int target = nums[i] + nums[j];
                while (left < right){
                    int mid = (left + right) / 2;
                    if (nums[mid] < target) left = mid + 1;
                    else right = mid;
                }
                cnt += right - j - 1;
            }
        }
        return cnt;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> nums{2, 2, 3, 4};
    cout << solution->triangleNumber(nums) << endl;
    return 0;
}