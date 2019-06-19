#include<bits/stdc++.h>

using namespace std;

/*
Given a string s and a string t, check if s is subsequence 
of t.
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (t.empty()) return false;
        int i = 0; int j = 0;
        while (i < s.length() && j < t.length()){
            if (t[j++] == s[i]) i++;
            if (i == s.length()) return true;
        }
        
        return false;
    }
}; Solution solution;


int main(){
    string s = "abc"; string t = "ahbgdc";
    bool res1 = solution.isSubsequence(s, t);
    cout << res1 << endl;

    s = "axc";
    bool res2 = solution.isSubsequence(s, t);
    cout << res2 << endl;

    return 0;
}
