#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        // Time complexity O(m * n) : 16%
        unordered_map<string, vector<string>> m;
        for (string s : strings){
            string t = "0 ";
            for (int i = 1; i < s.length(); ++i){
                t = t + to_string((s[i] - s[0] + 26) % 26) + " ";
            }
            m[t].push_back(s);
        }
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); ++it){
            res.push_back(it->second);
        }
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    cout << "First example:\n";
    vector<string> strings = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    auto res = solution->groupStrings(strings);
    for (auto v : res){
        for (auto r : v) cout << r << " ";
        cout << "\n";
    }
    cout << "Second example:\n";
    vector<string> strings2 = {"abc", "am"};
    auto res2 = solution->groupStrings(strings2);
    for (auto v : res2){
        for (auto r : v) cout << r << " ";
        cout << "\n";
    }
    return 0;
}