#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        /* O(n) : 58% */
        int d1 = INT_MAX;
        for (auto g : ghosts){
            d1 = min(d1, abs(g[0] - target[0]) + abs(g[1] - target[1]));
        }
        int d2 = abs(target[0]) + abs(target[1]);
        return d2 < d1;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<vector<int>> ghosts{{1, 0}, {0, 3}};
    vector<int> target{0, 1};
    cout << solution->escapeGhosts(ghosts, target) << endl;
    return 0;
}