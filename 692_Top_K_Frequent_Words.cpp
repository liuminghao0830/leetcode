#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        /* O(nlog2) : 83% */
        sort(words.begin(), words.end());
        unordered_map<string, int> m;
        for (auto w : words) m[w]++;

        map<int, vector<string>> mk;
        for (auto a : m) {
            mk[m[a.first]].push_back(a.first);
        }

        vector<string> res;
        for (auto it = mk.rbegin(); it != mk.rend(); ++it){
            vector<string> t = it->second;
            sort(t.begin(), t.end());
            for (auto c : t){
                if (k <= 0) break;
                res.push_back(c);
                k--;
            }
            if (k <= 0) break;
        }
        return res;
    }
};

int main(){
    vector<string> words{"i", "love", "coding", "i", "love", "leetcode"};
    Solution* solution = new Solution();
    auto res = solution->topKFrequent(words, 2);
    for (auto w : res) cout << w << " ";
    cout << "\n";
    return 0;
}