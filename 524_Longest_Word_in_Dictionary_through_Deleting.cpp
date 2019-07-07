#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
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
};

int main(){
    Solution* solution = new Solution();
    string s = "abpcplea";
    vector<string> d{"ale", "apple", "monkey", "plea"};

    cout << solution->findLongestWord(s, d) << endl;

    return 0;
}