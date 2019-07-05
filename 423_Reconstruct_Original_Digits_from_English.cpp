#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<int, string> m;
        m[0] = "zero"; m[1] = "one"; m[2] = "two"; m[3] = "three"; 
        m[4] = "four"; m[5] = "five"; m[6] = "six"; m[7] = "seven"; 
        m[8] = "eight", m[9] = "nine";
        
        vector<int> nums{0, 2, 4, 6, 8, 1, 3, 5, 7, 9}; 
        
        string res = ""; unordered_map<char, int> d;
        
        for (char c : s) d[c]++;
        
        for (int i : nums){
            int min_cnt = INT_MAX;
            for (char c : m[i]) min_cnt = min(min_cnt, d[c]);
            for (char c : m[i]) d[c] -= min_cnt;
            for (int j = 0; j < min_cnt; j++){
                res += i + '0';
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
}; Solution solution;

int main(){
    string s = "zeroonetwothreefourfivesixseveneightnine";
    string res = solution.originalDigits(s);
    cout << res << endl;
    return 0;
}