#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m;
        for (char c : s1) m[c]++;
        
        int s = 0;
        for (int i = 0; i < s2.length(); ++i){
            if (--m[s2[i]] < 0){
                while (++m[s2[s++]] != 0) {}
            }
            else if (i - s + 1 == s1.length()) return true;
        }
        
        return false;
    }
};

int main(){
    Solution* solution = new Solution();
    string s1 = "ab"; string s2 = "eidbaooo";
    cout << solution->checkInclusion(s1, s2) << endl;
    return 0;
}