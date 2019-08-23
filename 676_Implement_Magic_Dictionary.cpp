#include<bits/stdc++.h>

using namespace std;

class MagicDictionary {
private:
    vector<string> _dict;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        _dict = dict;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (auto s : _dict){
            if (s.length() != word.length()) continue;
            int cnt = 0;
            for (int i = 0; i < word.length(); ++i){
                if (word[i] != s[i]) cnt++;
                if (cnt > 1) break;
            }
            if (cnt == 1) return true;
        }
        return false;
    }
};

int main(){
    MagicDictionary* MD = new MagicDictionary();
    MD->buildDict({"hello", "leetcode"});
    cout << MD->search("hello") << endl;
    cout << MD->search("hhllo") << endl;
    cout << MD->search("hell") << endl;
    cout << MD->search("leetcoded") << endl;
    return 0;
}