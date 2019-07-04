#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        unordered_map<int, int> m; m[0] = -1;
        int cnt = 0; int max_len = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            cnt += nums[i] == 0 ? -1 : 1;
            if (!m.count(cnt)) m[cnt] = i;
            max_len = max(max_len, i - m[cnt]);
        }
        
        return max_len;
    }
}; Solution solution;

int main(){
	vector<int> nums{0, 0, 1};
	cout << solution.findMaxLength(nums) << endl;
    return 0;
}
