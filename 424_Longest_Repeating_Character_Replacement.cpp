#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int characterReplacement(string s, int k) {
        vector<int> letter_cnt(26, 0);
        int t = 0; int max_ocur = 0; int max_len = 0;
        
        for (int i = 0; i < s.length(); ++i){
            letter_cnt[s[i] - 'A']++;
            max_ocur = max(max_ocur, letter_cnt[s[i] - 'A']);
            while (i - t + 1 - max_ocur > k){
                letter_cnt[s[t++] - 'A']--;
            }
            max_len = max(max_len, i - t + 1);
        }
        
        return max_len;
    }   
};

int main(){
    Solution* solution = new Solution();
    string s = "AAABAB";
    cout << solution->characterReplacement(s, 2) << endl;
    return 0;
}