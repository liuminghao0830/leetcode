#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty()) return {};
        
        vector<vector<int>> res; multimap<int, vector<int>> m;
        int cnt1 = min(k, (int)nums1.size()); int cnt2 = min(k, (int)nums2.size()); 
        
        for (int i = 0; i < cnt1; ++i){
            for (int j = 0; j < cnt2; ++j){
                m.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        }
        
        auto it = m.begin();
        for (int i = 0; i < min(k, (int)m.size()); ++i){
            res.push_back(it->second);
            it++;
        }
        
        return res;
    }
}; Solution solution;


int main(){
	vector<int> nums1{1, 7, 11}; vector<int> nums2{2, 4, 6};
	vector<vector<int>> res = solution.kSmallestPairs(nums1, nums2, 3);

	for (auto n : res) cout << n[0] << " " << n[1] << endl;

    return 0;
}
