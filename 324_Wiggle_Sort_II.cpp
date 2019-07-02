#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> dn = nums;
        sort(dn.begin(), dn.end(), greater<>());
        
        int n = nums.size();
        
        for (int i = 0; i < n; i++){
            nums[i] = i % 2 == 0 ? dn[n / 2 + i / 2] : dn[(i - 1)/ 2];
        }
    }
}; Solution solution;


int main(){
    vector<int> nums{1, 5, 1, 1, 6, 4};
    solution.wiggleSort(nums);

    for (auto n : nums) cout << n << " ";
    cout << "\n";

    return 0;
}
