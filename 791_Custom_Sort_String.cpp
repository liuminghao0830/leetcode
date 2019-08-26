#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    string customSortString(string S, string T) {
        /*O(num(T)) : 67% */
        vector<int> cnt(26, 0);
        for (char c : T) cnt[c - 'a']++;
        string res = "";
        for (char c : S){
            if (!cnt[c - 'a']) continue;
            for (int i = 0; i < cnt[c - 'a']; ++i){
                res += c;
            }
            cnt[c - 'a'] = 0;
        }
        for (char c : T){
            if (cnt[c - 'a']) res += c;
        }
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->customSortString("cba", "abcd") << endl;
    return 0;
}