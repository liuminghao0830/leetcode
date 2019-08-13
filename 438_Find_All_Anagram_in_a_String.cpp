#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams_1(string s, string p) {
        /* O(n*m) : 8% */
        vector<int> m(128, 0);
        for (auto c : p) m[c]++;
        
        int w = p.length(); int n = s.length();
        
        vector<int> res;
        for (int i = 0; i <= n - w; ++i){
            auto m1 = m; bool find = true;
            for (int j = i; j < i + w; ++j) {
                if (--m1[s[j]] < 0) { find = false; break; }
            }
            if (find) res.push_back(i);
        }
        return res;
    }
    vector<int> findAnagrams_2(string s, string p) {
        /* sliding window O(n) : 94% */
        vector<int> mp(128, 0); vector<int> ms(128, 0);
        int w = p.length(); int n = s.length();
        
        for (int i = 0; i < w; ++i){
            ms[s[i]]++; mp[p[i]]++;
        }
        
        vector<int> res;
        if (ms == mp) res.push_back(0);
        
        for (int i = 1; i <= n - w; ++i){
            ms[s[i + w - 1]]++; ms[s[i - 1]]--;
            if (ms == mp) res.push_back(i);
        }
        return res;
    }
};

int main(){
    vector<int> nums{3, 1, 3, 3, 7, 10, 10, 3, 6, 9, 10, 3, 7, 6, 7};
    Solution* solution = new Solution();
    cout << solution->makesquare(nums) << endl;
    return 0;
}