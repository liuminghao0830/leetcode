#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool LCS(string a, string b){
        if (b.size() < a.size()) return false;
        int i = 0;
        for (char c : b){
            if (a[i] == c) i++;
            if (i == a.size()) break;
        }
        return i == a.size();
    }
    
    int findLUSlength(vector<string>& strs){
        if (strs.empty()) return -1;
        int res = -1;

        for (int i = 0; i < strs.size(); ++i){
            int j = 0;
            for (; j < strs.size(); ++j){
                if (i == j) continue;
                if (LCS(strs[i], strs[j])) break;
            }
            if (j == strs.size()) res = max(res, (int)strs[i].size());
        }

        return res;
    }   
};

int main(){
    Solution* solution = new Solution();
    vector<string> strs{"aba", "cdc", "eae"};

    cout << solution->findLUSlength(strs) << endl;
    
    return 0;
}