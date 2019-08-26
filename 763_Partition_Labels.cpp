#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        /*O(n) : 100% */
        unordered_map<char, int> m; int n = S.length();
        for (int i = 0; i < n; ++i) m[S[i]] = i;
        vector<int> res; int start = 0, last = 0;
        for (int i = 0; i < n; ++i){
            last = max(last, m[S[i]]);
            if (i == last) {
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
    vector<int> partitionLabels2(string S) {
        /* merge intervals O(nlogn) : 50% */
        int n = S.length(); 
        vector<vector<int>> intervals(26, vector<int>(2, -1));
        for (int i = 0; i < n; ++i) {
            int c = S[i] - 'a';
            if (intervals[c][0] == -1){
                intervals[c][0] = i;
            }
            intervals[c][1] = i;
        }
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        vector<int> len;
        for (int i = 0; i < 26; ++i){
            if (intervals[i][0] == -1) continue;
            if (res.empty()) res.push_back(intervals[i]);
            if (res.back()[1] >= intervals[i][0]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else {
                len.push_back(res.back()[1] - res.back()[0] + 1);
                res.push_back(intervals[i]);
            }
        }
        len.push_back(res.back()[1] - res.back()[0] + 1);
        return len;
    }
};

int main(){
    string S = "caedbdedda";
    Solution* solution = new Solution();
    auto res = solution->partitionLabels2(S);

    for (auto r : res) cout << r << " ";
    cout << "\n";
    return 0;
}