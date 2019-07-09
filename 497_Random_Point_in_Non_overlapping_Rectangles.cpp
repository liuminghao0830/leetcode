#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int tot_area = 0;
    vector<vector<int>> _rect;
    map<int, int> area_to_idx;

public:
    Solution(vector<vector<int>>& rects) {
        _rect = rects;
        for (int i = 0; i < rects.size(); i++){
            tot_area += (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            area_to_idx[tot_area] = i;
        }
    }
    
    vector<int> pick() {
        int area = rand() % tot_area;
        int idx = area_to_idx.upper_bound(area)->second;
        auto rect = _rect[idx];
        int x = rand() % (rect[2] - rect[0] + 1) + rect[0];
        int y = rand() % (rect[3] - rect[1] + 1) + rect[1];
        
        return {x, y};
    }
};

int main(){
    vector<vector<int>> rects;
    rects.push_back({-2, -2, -1, -1});
    rects.push_back({1, 0, 3, 0});
    Solution* solution = new Solution(rects);

    auto p1 = solution->pick();
    for (auto n : p1) cout << n << " ";
    cout << "\n";
    return 0;
}