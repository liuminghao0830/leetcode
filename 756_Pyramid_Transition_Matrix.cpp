#include<bits/stdc++.h>

using namespace std;

class Solution{
private:
    bool helper(string bottom, unordered_map<string, string>& m, string next, int p){
        if (bottom.length() == 1) return true;
        if (p >= bottom.length() - 1) return helper(next, m, "", 0);

        string str = bottom.substr(p, 2);
        if (!m.count(str)) return false;
        for (auto c : m[str]){
            if (helper(bottom, m, next + c, p + 1)) return true;
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        /* 100% */
        unordered_map<string, string> m;
        for (auto a : allowed) m[a.substr(0, 2)] += a.substr(2, 1);

        return helper(bottom, m, "", 0);
    }
};

int main(){
    Solution* solution = new Solution();
    vector<string> allowed{"BCG", "CDE", "GEA", "FFF"};
    cout << solution->pyramidTransition("BCD", allowed) << endl;
    return 0;
}