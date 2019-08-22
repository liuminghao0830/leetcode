#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_set<string> yes, no;
        int cnt = 0;
        for (string word : words){
            if (yes.count(word) || no.count(word)){
                if (yes.count(word)) cnt++; 
                continue;
            }
            int i = 0;
            for (char c : S){
                if (c == word[i]) i++;
                if (i == word.length()) { cnt++; break; }
            }
            if (i == word.length()) yes.insert(word);
            else no.insert(word);
        }
        return cnt;
    }
};

int main(){
    Solution* solution = new Solution();
    string S = "abcde"; 
    vector<string> words{"a", "bb", "acd", "ace"};
    cout << solution->numMatchingSubseq(S, words) << endl;
    return 0;
}