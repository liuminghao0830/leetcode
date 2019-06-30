#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() <= 1) return false;
        map<long long, int> m; int j = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            if (i - j > k) {m.erase(nums[j]); j++;}
            
            auto lb = m.lower_bound((long long)nums[i] - t);
            if (lb != m.end() && abs((long long)nums[i] - (long long)lb->first) <= t) return true;
            m[nums[i]] = i;
        }
        
        return false;
    }
}; Solution solution;

int main(){
    vector<int> nums{1, 2, 3, 1};
    auto res = solution.containsNearbyAlmostDuplicate(nums, 3, 0);

    cout << res << endl;
    return 0;
}
