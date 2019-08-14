#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        /* sort O(nlogn) : 10% */
        sort(d.begin(), d.end(), [](string a, string b){
            if (a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });
        
        for (string word : d){
            int i = 0;
            for (char c : s){
                if (c == word[i]) i++;
            }
            if (i == word.size()) return word;
        }
        
        return "";
    }

    string findLongestWord_harsh_table(string s, vector<string>& d) {
        /* harsh table O(n) : 67% */
        unordered_map<int, string> m;
        int max_len = 0;
        
        for (auto w : d){
            int i = 0;
            for (char c : s){
                if (c == w[i]) i++;
            }
            if (i == w.length()){
                if (!m.count(i) || w < m[i]) m[i] = w;
                max_len = max(max_len, i);
            }
        }
        
        return max_len == 0 ? "" : m[max_len];
    }
};

int main(){
    Solution* solution = new Solution();
    string s = "abpcplea";
    vector<string> d{"ale", "apple", "monkey", "plea"};

    cout << solution->findLongestWord(s, d) << endl;

    return 0;
}