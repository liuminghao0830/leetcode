#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int max_cnt = INT_MIN;
        unordered_map<int, int> m;

        for (auto row : wall){
            int c = 0;
            for (int w = 0; w < row.size() - 1; ++w){
                c += row[w];
                m[c]++;
                max_cnt = max(max_cnt, m[c]);
            }
        }

        return max_cnt == INT_MIN ? wall.size() : wall.size() - max_cnt;
    }
}; Solution solution;

int main(){
    vector<vector<int>> wall;
    wall.push_back({1, 2, 2, 1});
    wall.push_back({3, 1, 2});
    wall.push_back({1, 3, 2});
    wall.push_back({2, 4});
    wall.push_back({3, 1, 2});
    wall.push_back({1, 3, 1, 1});
    cout << solution.leastBricks(wall) << endl;
    
    return 0;
}
