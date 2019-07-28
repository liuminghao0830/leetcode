#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int maxProduct(vector<string> words){
        if (words.empty()) return 0;
        
        unordered_map<string, int> m;
        for (string w : words){
            for (char c : w){
                m[w] |= 1 << (c - 'a');
            }
        }

        int max_len = 0;
        for (int i = 0; i < words.size() - 1; ++i){
            for (int j = i + 1; j < words.size(); ++j){
                if (!(m[words[i]] & m[words[j]])){
                    max_len = max(max_len, (int)words[i].length()*(int)words[j].length());
                }
            }
        }

        return max_len;
    }
};

int main(){
    vector<string> words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    Solution* solution = new Solution();
    cout << solution->maxProduct(words) << endl;
    return 0;
}