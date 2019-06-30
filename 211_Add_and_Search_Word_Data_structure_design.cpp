#include<bits/stdc++.h>

using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        char letter;
        bool WordEnd = false;
        TrieNode *children[26];
    };
    
    TrieNode *root = new TrieNode();
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for (const char a : word){
            int idx = a - 'a';
            if (!p->children[idx]){
                p->children[idx] = new TrieNode();
                p->children[idx]->letter = a;
            }
            p = p->children[idx];
        }
        p->WordEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return SearchWord(word, root, 0);
    }
    
    bool SearchWord(string word, TrieNode *head, int s){
        if (s >= word.length()) return head->WordEnd;
        TrieNode *p = head;
        for (int i = s; i < word.length(); ++i){
            if (word[i] == '.') {
                bool res = false;
                for (auto child : p->children) {
                    if (child) res = res || SearchWord(word, child, i + 1);
                }
                return res;
            }
            int idx = word[i] - 'a';
            if (!p->children[idx]) return false;
            p = p->children[idx];
        }
        return p->WordEnd;
    }
};


int main(){
	WordDictionary* worddic = new WordDictionary();
	worddic->addWord("bad");
	worddic->addWord("dad");
	worddic->addWord("mad");
	cout << worddic->search("pad") << endl;
	cout << worddic->search("bad") << endl;
	cout << worddic->search(".ad") << endl;
	cout << worddic->search("b..") << endl;
    return 0;
}
