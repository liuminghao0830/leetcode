#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isPalindromic(int i, int j, string s){
        while (i < j){
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    void countPalindromic(int i, int j, string s, int& cnt){
        while (i >= 0 && j <= s.length() && s[i] == s[j]){
            cnt++; i--; j++;
        }
    }
public:
    int countSubstrings(string s) {
        /* O(n^3) : 5%*/
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; ++i){
            for (int j = i; j < n; ++j){
                if (isPalindromic(i, j, s)) cnt++;
            }
        }
        return cnt;
    }
    int countSubstrings2(string s) {
        /* O(n^2) : 55%*/
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; ++i){
            countPalindromic(i, i, s, cnt);
            countPalindromic(i, i + 1, s, cnt);
        }
        return cnt;
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->countSubstrings2("abc") << endl;
    cout << solution->countSubstrings2("aaa") << endl;   
    return 0;
}