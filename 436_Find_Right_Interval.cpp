#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> start; int n = intervals.size();
        map<int, int> s_to_idx;
        for (int i = 0; i < n; ++i){
            start.push_back(intervals[i][0]);
            s_to_idx[intervals[i][0]] = i;
        }
        
        vector<int> res;
        for (int i = 0; i < n; ++i){
            auto lb = s_to_idx.lower_bound(intervals[i][1]);
            if (lb != s_to_idx.end()) res.push_back(lb->second);
            else res.push_back(-1);
        }
        
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<vector<int>> intervals{{3,4}, {2,3}, {1,2}};
    auto res = solution->findRightInterval(intervals);

    for (auto n : res) cout << n << " ";
    cout << "\n";
    return 0;
}