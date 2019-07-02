#include<bits/stdc++.h>

using namespace std;

class Trie {
public:
    struct TrieNode{
        char letter;
        TrieNode* children[26];
        bool WordEnd = false;
    };
    
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (const char &a : word){
            int idx = a - 'a';
            if (!p->children[idx]) {
                p->children[idx] = new TrieNode();
                p->children[idx]->letter = a;
            }
            p = p->children[idx];
        }
        p->WordEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (const char &a : word){
            int idx = a - 'a';
            if (!p->children[idx]) return false;
            p = p->children[idx];
        }
        return p->WordEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (const char &a : prefix){
            int idx = a - 'a';
            if (!p->children[idx]) return false;
            p = p->children[idx];
        }
        return true;
    }
};


int main(){
	Trie *trie = new Trie();
	trie->insert("apple");
	cout << trie->search("apple") << endl;
	cout << trie->search("app") << endl;
	cout << trie->startsWith("app") << endl;
	trie->insert("app");
	trie->search("app");
    return 0;
}
