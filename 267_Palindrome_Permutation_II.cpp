#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
private:
    void recursion(unordered_map<char, int>& cnt, string out, 
                                vector<string>& res, int n){
        if (n == 0) { res.push_back(out); return; }
        for (auto it : cnt){
            if (it.second == 0) continue;
            out += it.first;
            cnt[it.first]--;
            recursion(cnt, out, res, n - 1);
            cnt[it.first]++;
            out.pop_back();
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> cnt;
        for (char c : s) cnt[c]++;
        int f = 0; char c;
        for (auto it : cnt){
            f += it.second % 2;
            if (f > 1) return {};
            if (it.second % 2) c = it.first;
            cnt[it.first] = it.second / 2;
        }
        
        vector<string> res;
        recursion(cnt, "", res, (int)s.length() / 2);

        for (int i = 0; i < res.size(); ++i){
            string t = res[i]; reverse(t.begin(), t.end());
            res[i] += c + t;
        }
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    auto res = solution->generatePalindromes("abab");
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << "\n";
    }
    return 0;
}