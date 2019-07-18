#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int findSubstringInWraproundString(string p){
        vector<int> cnt(26, 0);
        int maxlen = 0;
        for (int i = 0; i < p.length(); ++i){
            if (i > 0 && (p[i-1] - 'a'+1) % 26 == p[i] - 'a'){
                maxlen++;
            }
            else { maxlen = 1; }
            cnt[p[i] - 'a'] = max(maxlen, cnt[p[i] - 'a']);
        }

        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};

int main(){
    string p = "zab";
    Solution* solution = new Solution();
    cout << solution->findSubstringInWraproundString(p) << endl;
}