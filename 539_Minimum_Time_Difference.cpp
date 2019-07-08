#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int to_minute(string time){
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3));
        return h * 60 + m;
    }
    
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;  int n = timePoints.size();
        for (int i = 0; i < n; ++i){
            auto t = to_minute(timePoints[i]);
            times.push_back(t);
        }
        
        sort(times.begin(), times.end());
        int diff = INT_MAX;
        
        for (int i = 1; i < n; ++i){
            diff = min(diff, times[i] - times[i - 1]);
        }
        
        return min(diff, 1440 + times[0] - times.back());
    }
};

int main(){
    Solution* solution = new Solution();
    vector<string> timePoints{"23:59", "00:00"};
    cout << solution->findMinDifference(timePoints) << endl;
    return 0;
}