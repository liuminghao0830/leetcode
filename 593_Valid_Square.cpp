#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p{p1, p2, p3, p4}; unordered_map<int, int> m;
        
        for (int i = 0; i < p.size() - 1; ++i){
            for (int j = i + 1; j < p.size(); ++j){
                int len = (p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) + (p[i][1] - p[j][1]) * (p[i][1] - p[j][1]);
                m[len]++;
                if (len == 0) return false;
            }
        }
        
        return m.size() <= 2;
    }
};

int main(){
    vector<int> p1{0, 0}; vector<int> p2{1, 1};
    vector<int> p3{1, 0}; vector<int> p4{0, 1};
    Solution* solution = new Solution();
    cout << solution->validSquare(p1, p2, p3, p4) << endl;

    return 0;
}