#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        int cnt = 0; int last = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i){
            if (intervals[i][0] < last){
                cnt++; 
                last = min(intervals[i][1], last);
            }
            else last = intervals[i][1];
        }
        
        return cnt;
    }
};

int main(){
    vector<vector<int>> intervals;
    intervals.push_back({1, 2});
    intervals.push_back({2, 3});
    intervals.push_back({3, 4});
    intervals.push_back({1, 3});
    Solution* solution = new Solution();
    cout << solution->eraseOverlapIntervals(intervals) << endl;
    return 0;
}